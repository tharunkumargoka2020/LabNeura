cmake_minimum_required(VERSION 3.12)
project(labneura)

# Check if we're on macOS and using Apple M1
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
        # Check if LLVM Clang++ exists
        if (EXISTS "/opt/homebrew/opt/llvm/bin/clang++")
            set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")
        else()
            message(FATAL_ERROR "LLVM Clang++ not found. Please install it via Homebrew.")
        endif()
        if (EXISTS "/opt/homebrew/opt/libomp")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp -lomp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib")
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Xpreprocessor -fopenmp -lomp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib")
        else()
            message(FATAL_ERROR "OpenMP not found. Please install OpenMP on your system.")
        endif()
    else()
        message(FATAL_ERROR "Unsupported architecture on macOS. Only Apple M1 is supported.")
    endif()
endif()
set(CMAKE_CXX_STANDARD 11)

# Check for pybind11
find_package(pybind11 QUIET)
if (NOT pybind11_FOUND)
    message(STATUS "pybind11 not found, attempting to install...")
    execute_process(COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} ${CMAKE_COMMAND} -P "${CMAKE_SOURCE_DIR}/cmake/InstallPybind11.cmake")
    find_package(pybind11 REQUIRED)
else()
    message(STATUS "pybind11 found")
endif()

# Check for Eigen3
find_package(Eigen3 QUIET)
if (NOT Eigen3_FOUND)
    message(STATUS "Eigen3 not found, attempting to install...")
    execute_process(COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR} ${CMAKE_COMMAND} -P "${CMAKE_SOURCE_DIR}/cmake/InstallEigen3.cmake")
    find_package(Eigen3 REQUIRED)
else()
    message(STATUS "Eigen3 found")
endif()

# Include directories
include_directories(${EIGEN3_INCLUDE_DIR} ${PYBIND11_INCLUDE_DIR})

# Add OpenMP support
find_package(OpenMP REQUIRED)
# Set OpenMP flags
if (OpenMP_C_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()
if (OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# Include directories
include_directories(include)

# Add library for Algorithms
add_library(labneura MODULE bindings/interface.cpp 
    src/algorithms/sorting.cpp 
    src/algorithms/graph.cpp 
    src/ml/linear_regression.cpp)
target_link_libraries(labneura PRIVATE pybind11::module OpenMP::OpenMP_CXX Eigen3::Eigen)
set_target_properties(labneura PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")

if (CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    target_compile_options(labneura PRIVATE -mcpu=apple-m1)
else()
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(labneura PRIVATE -march=native)
    endif()
endif()

# Enable testing
#enable_testing()

# Find Google Test package
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
#add_executable(test_linear_regression ../tests/tests_cpp/test_linear_regression.cpp)

# Link the test executable with Google Test
#target_link_libraries(test_linear_regression ${GTEST_LIBRARIES} pthread)

# Add the test to CTest
#add_test(NAME test_linear_regression COMMAND test_linear_regression)

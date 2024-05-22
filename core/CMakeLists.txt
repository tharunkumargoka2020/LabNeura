cmake_minimum_required(VERSION 3.12)
project(MLCPP)

# Add pybind11
find_package(pybind11 REQUIRED)

# Include directories
include_directories(include)

# Add library
add_library(mlcpp MODULE bindings/cpp_interface.cpp src/ml/linear_regression.cpp)
target_link_libraries(mlcpp PRIVATE pybind11::module)
set_target_properties(mlcpp PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")

# Enable testing
enable_testing()

# Find Google Test package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
#add_executable(test_linear_regression ../tests/tests_cpp/test_linear_regression.cpp)

# Link the test executable with Google Test
#target_link_libraries(test_linear_regression ${GTEST_LIBRARIES} pthread)

# Add the test to CTest
#add_test(NAME test_linear_regression COMMAND test_linear_regression)

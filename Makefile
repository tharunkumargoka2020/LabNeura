# Makefile for building, installing, testing, and coverage

.PHONY: all build install test clean cpp_build cpp_test python_test coverage

# Variables
BUILD_DIR=build
CORE_DIR=core
PYTHON_DIR=.
TESTS_DIR=tests
CPP_TEST_DIR=$(TESTS_DIR)/tests_cpp
PYTHON_TEST_DIR=$(TESTS_DIR)/tests_python
PYTHON_PACKAGE=labneura
CMAKE=cmake
GCOV=gcov
LCOV=lcov
GENHTML=genhtml
COVERAGE_DIR=$(BUILD_DIR)/coverage

# Default target
all: build install test coverage

# Build the C++ code
build:
	pip3 install pybind11[global]
	pip3 install coverage
	@echo "Building C++ code..."
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE) ../$(CORE_DIR) && $(CMAKE) --build .

# Install the Python package
install: build
	@echo "Installing Python package..."
	cd $(PYTHON_DIR) && python setup.py install

# Run C++ tests
cpp_test: build
	@echo "Running C++ tests..."
	cd $(BUILD_DIR) && ctest

# Run Python tests
python_test: install
	@echo "Running Python tests..."
	pytest $(PYTHON_DIR)

# Run all tests
test: python_test

# Generate coverage reports
coverage: python_test
	@echo "Generating coverage report for Python..."
	coverage run --source=$(PYTHON_PACKAGE) -m pytest $(PYTHON_DIR)
	coverage report -m
	coverage html -d $(COVERAGE_DIR)/python
	@echo "Coverage report generated for Python in $(COVERAGE_DIR)/python"
	pytest --cov=./ --cov-report=xml --cov-report=term
	
publish: 
	python setup.py sdist bdist_wheel
	twine upload dist/* 
# Clean the build directory
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)
	cd $(PYTHON_DIR) && python setup.py clean --all
	rm -rf $(PYTHON_DIR)/build
	rm -rf $(PYTHON_DIR)/dist
	rm -rf $(PYTHON_DIR)/*.egg-info
	find . -type f -name '*.pyc' -delete
	find . -type d -name '__pycache__' -delete
	rm -rf $(PYTHON_DIR)/.pytest_cache
	rm -rf $(PYTHON_DIR)/htmlcov
	rm ${PYTHON_DIR}/.coverage
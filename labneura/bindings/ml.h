#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ml/linear_regression.h"

namespace py = pybind11;

void bind_linear_regression(py::module &m){
    py::class_<LinearRegression>(m, "LinearRegression")
        .def(py::init<std::vector<double>&,std::vector<double>&>())
        .def("fit", &LinearRegression::fit)
        .def("predict", &LinearRegression::predict)
        .def_property_readonly("slope_", &LinearRegression::getSlope)
        .def_property_readonly("intercept_", &LinearRegression::getIntercept)
        .def_property_readonly("weights_", &LinearRegression::getWeights)
        .def_readwrite("X", &LinearRegression::X)
        .def_readwrite("Y", &LinearRegression::Y);
}
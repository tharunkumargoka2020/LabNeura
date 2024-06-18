#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
#include "ml/linear_regression.h"

namespace py = pybind11;

void bind_linear_regression(py::module &m){
    py::class_<LinearRegression>(m, "LinearRegression")
        .def(py::init<double, int>(), py::arg("learning_rate") = 0.01, py::arg("iterations") = 1000)
        .def("fit", &LinearRegression::fit, py::arg("X"), py::arg("y"))
        .def("predict", &LinearRegression::predict, py::arg("X"))
        .def("cost", &LinearRegression::cost, py::arg("X"), py::arg("y"));
}
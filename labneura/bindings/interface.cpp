#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "algorithms/sorting.h"
#include "algorithms/graph.h"
#include "ml/linear_regression.h"
#include <vector>

namespace py = pybind11;

PYBIND11_MODULE(labneura, m) {
    py::class_<Sorting>(m, "Sorting")
        .def(py::init<std::vector<int>>())
        .def("selection", &Sorting::selection)
        .def("insertion", &Sorting::insertion)
        .def("bubble", &Sorting::bubble)
        .def("merge", &Sorting::merge)
        .def("quick", &Sorting::quick)
        .def_property("data", &Sorting::getData, &Sorting::setData)
        .def_property_readonly("no_timesteps", &Sorting::getTimeSteps)
        .def_property_readonly("no_swaps", &Sorting::getSwaps)
        .def_property_readonly("no_recursive_calls", &Sorting::getRecursiveCalls);

    py::class_<Graph>(m, "Graph")
        .def(py::init<int>());

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
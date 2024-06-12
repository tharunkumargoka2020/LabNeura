#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "algorithms/sorting.h"
#include "algorithms/graph.h"

namespace py=pybind11;

void bind_sorting(py::module &m) {
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
}

void bind_graph(py::module &m) {
    py::class_<Graph>(m, "Graph")
        .def(py::init<int>())
        .def("addEdge", &Graph::addEdge)
        .def("displayGraph", &Graph::displayGraph);
}
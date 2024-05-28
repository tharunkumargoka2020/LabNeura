#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "algorithms/sorting.h"
#include <vector>

namespace py = pybind11;

PYBIND11_MODULE(algocpp, m) {
    py::class_<Sorting>(m, "Sorting")
        .def(py::init<std::vector<int>>())
        .def("selection", &Sorting::selection)
        .def("insertion", &Sorting::insertion)
        .def("bubble", &Sorting::bubble)
        .def("merge", &Sorting::merge)
        .def("quick", &Sorting::quick)
        .def_property("data", &Sorting::getData, &Sorting::setData);
}
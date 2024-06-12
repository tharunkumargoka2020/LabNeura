#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include "data.h"
#include "algorithms.h"
#include "ml.h"

PYBIND11_MODULE(labneura, m) {
    bind_linear_regression(m);
    bind_sorting(m);
    bind_graph(m);
    bind_vector_wrapper<py::object>(m);
    bind_vector<int>(m, "Int");
    bind_vector<float>(m, "Float");
    bind_vector<double>(m, "Double");
    bind_vector<std::string>(m, "String");
    bind_list_wrapper<py::object>(m);
    bind_list<int>(m, "Int");
    bind_list<float>(m, "Float");
    bind_list<double>(m, "Double");
    bind_list<std::string>(m, "String");
    bind_stack_wrapper<py::object>(m);
    bind_stack<int>(m, "Int");
    bind_stack<float>(m, "Float");
    bind_stack<double>(m, "Double");
    bind_stack<std::string>(m, "String");
    bind_queue_wrapper<py::object>(m);
    bind_queue<int>(m, "Int");
    bind_queue<float>(m, "Float");
    bind_queue<double>(m, "Double");
    bind_queue<std::string>(m, "String");
}
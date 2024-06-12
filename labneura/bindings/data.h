#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "data/list.h"
#include "data/queue.h"
#include "data/stack.h"
#include "data/vector.h"

namespace py = pybind11;

template <typename T>
void bind_vector_wrapper(py::module &m) {
    py::class_<VectorWrapper<T>>(m, "Vector")
        .def(py::init<>())
        .def("push_back", &VectorWrapper<T>::push_back)
        .def("at", &VectorWrapper<T>::at)
        .def("empty", &VectorWrapper<T>::empty)
        .def("clear", &VectorWrapper<T>::clear)
        .def("remove", &VectorWrapper<T>::remove)
        .def("size", &VectorWrapper<T>::size)
        .def("insert", &VectorWrapper<T>::insert)
        .def("print", &VectorWrapper<T>::print);
}

template <typename T>
void bind_vector(py::module &m, const std::string &type) {
    py::class_<VectorWrapper<T>>(m, ("Vector" + type).c_str())
        .def(py::init<>())
        .def("push_back", &VectorWrapper<T>::push_back)
        .def("at", &VectorWrapper<T>::at)
        .def("empty", &VectorWrapper<T>::empty)
        .def("clear", &VectorWrapper<T>::clear)
        .def("remove", &VectorWrapper<T>::remove)
        .def("size", &VectorWrapper<T>::size)
        .def("insert", &VectorWrapper<T>::insert)
        .def("print", &VectorWrapper<T>::print);
}

template <typename T>
void bind_list_wrapper(py::module &m) {
    py::class_<ListWrapper<T>>(m, "List")
        .def(py::init<>())
        .def("push_back", &ListWrapper<T>::push_back)
        .def("pop_back", &ListWrapper<T>::pop_back)
        .def("back", &ListWrapper<T>::back)
        .def("empty", &ListWrapper<T>::empty)
        .def("size", &ListWrapper<T>::size)
        .def("insert", &ListWrapper<T>::insert)
        .def("remove", &ListWrapper<T>::remove)
        .def("print", &ListWrapper<T>::print)
        .def("at", &ListWrapper<T>::at);
}

template <typename T>
void bind_list(py::module &m, const std::string &type) {
    py::class_<ListWrapper<T>>(m, ("List" + type).c_str())
        .def(py::init<>())
        .def("push_back", &ListWrapper<T>::push_back)
        .def("pop_back", &ListWrapper<T>::pop_back)
        .def("back", &ListWrapper<T>::back)
        .def("empty", &ListWrapper<T>::empty)
        .def("size", &ListWrapper<T>::size)
        .def("insert", &ListWrapper<T>::insert)
        .def("remove", &ListWrapper<T>::remove)
        .def("print", &ListWrapper<T>::print)
        .def("at", &ListWrapper<T>::at);
}

template <typename T>
void bind_queue_wrapper(py::module &m) {
    py::class_<QueueWrapper<T>>(m, "Queue")
        .def(py::init<>())
        .def("push", &QueueWrapper<T>::push)
        .def("pop", &QueueWrapper<T>::pop)
        .def("front", &QueueWrapper<T>::front)
        .def("empty", &QueueWrapper<T>::empty)
        .def("size", &QueueWrapper<T>::size)
        .def("print", &QueueWrapper<T>::print);
}

template <typename T>
void bind_queue(py::module &m, const std::string &type) {
    py::class_<QueueWrapper<T>>(m, ("Queue" + type).c_str())
        .def(py::init<>())
        .def("push", &QueueWrapper<T>::push)
        .def("pop", &QueueWrapper<T>::pop)
        .def("front", &QueueWrapper<T>::front)
        .def("empty", &QueueWrapper<T>::empty)
        .def("size", &QueueWrapper<T>::size)
        .def("print", &QueueWrapper<T>::print);
}

template <typename T>
void bind_stack_wrapper(py::module &m) {
    py::class_<StackWrapper<T>>(m, "Stack")
        .def(py::init<>())
        .def("push", &StackWrapper<T>::push)
        .def("pop", &StackWrapper<T>::pop)
        .def("top", &StackWrapper<T>::top)
        .def("empty", &StackWrapper<T>::empty)
        .def("size", &StackWrapper<T>::size)
        .def("print", &StackWrapper<T>::print);
}

template <typename T>
void bind_stack(py::module &m, const std::string &type) {
    py::class_<StackWrapper<T>>(m, ("Stack" + type).c_str())
        .def(py::init<>())
        .def("push", &StackWrapper<T>::push)
        .def("pop", &StackWrapper<T>::pop)
        .def("top", &StackWrapper<T>::top)
        .def("empty", &StackWrapper<T>::empty)
        .def("size", &StackWrapper<T>::size)
        .def("print", &StackWrapper<T>::print);
}
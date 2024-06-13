#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "data/list.h"
#include "data/queue.h"
#include "data/stack.h"
#include "data/vector.h"
#include "data/deque.h"
#include "data/forward_list.h"

namespace py = pybind11;

template <typename T>
void bind_vector_wrapper(py::module &m) {
    py::class_<VectorWrapper<T>>(m, "Vector")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::vector<T>>())

        .def("size", &VectorWrapper<T>::size)
        .def("max_size", &VectorWrapper<T>::max_size)
        .def("resize", &VectorWrapper<T>::resize)
        .def("capacity", &VectorWrapper<T>::capacity)
        .def("empty", &VectorWrapper<T>::empty)
        .def("reserve", &VectorWrapper<T>::reserve)
        .def("shrink_to_fit", &VectorWrapper<T>::shrink_to_fit)

        .def("at", &VectorWrapper<T>::at)
        .def("__getitem__", &VectorWrapper<T>::operator[])
        .def("__len__", &VectorWrapper<T>::__len__)
        .def("front", &VectorWrapper<T>::front)
        .def("back", &VectorWrapper<T>::back)
        .def_property_readonly("data", &VectorWrapper<T>::getData, py::return_value_policy::reference_internal)

        .def("push_back", &VectorWrapper<T>::push_back)
        .def("pop_back", &VectorWrapper<T>::pop_back)
        .def("insert", &VectorWrapper<T>::insert)
        .def("erase", &VectorWrapper<T>::erase)
        .def("clear", &VectorWrapper<T>::clear)
        .def("swap", &VectorWrapper<T>::swap)

        .def("__iter__", [](VectorWrapper<T> &v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__reversed__", [](VectorWrapper<T> &v) { return py::make_iterator(v.rbegin(), v.rend()); },
             py::keep_alive<0, 1>());
}

template <typename T>
void bind_vector(py::module &m, const std::string &typestr) {
    py::class_<VectorWrapper<T>>(m, ("Vector" + typestr).c_str())
        .def(py::init<>())
        .def(py::init<size_t>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::vector<T>>())

        .def("size", &VectorWrapper<T>::size)
        .def("max_size", &VectorWrapper<T>::max_size)
        .def("resize", &VectorWrapper<T>::resize)
        .def("capacity", &VectorWrapper<T>::capacity)
        .def("empty", &VectorWrapper<T>::empty)
        .def("reserve", &VectorWrapper<T>::reserve)
        .def("shrink_to_fit", &VectorWrapper<T>::shrink_to_fit)

        .def("at", &VectorWrapper<T>::at)
        .def("__getitem__", &VectorWrapper<T>::operator[])
        .def("__len__", &VectorWrapper<T>::__len__)
        .def("front", &VectorWrapper<T>::front)
        .def("back", &VectorWrapper<T>::back)
        .def_property_readonly("data", &VectorWrapper<T>::getData, py::return_value_policy::reference_internal)

        .def("push_back", &VectorWrapper<T>::push_back)
        .def("pop_back", &VectorWrapper<T>::pop_back)
        .def("insert", &VectorWrapper<T>::insert)
        .def("erase", &VectorWrapper<T>::erase)
        .def("clear", &VectorWrapper<T>::clear)
        .def("swap", &VectorWrapper<T>::swap)

        .def("__iter__", [](VectorWrapper<T> &v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__reversed__", [](VectorWrapper<T> &v) { return py::make_iterator(v.rbegin(), v.rend()); },
             py::keep_alive<0, 1>());
}

template <typename T>
void bind_deque_wrapper(py::module &m) {
    py::class_<DequeWrapper<T>>(m, "Deque")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::deque<T>>())

        .def("size", &DequeWrapper<T>::size)
        .def("max_size", &DequeWrapper<T>::max_size)
        .def("resize", &DequeWrapper<T>::resize)
        .def("empty", &DequeWrapper<T>::empty)
        .def("shrink_to_fit", &DequeWrapper<T>::shrink_to_fit)
        .def("at", &DequeWrapper<T>::at)
        .def("__getitem__", &DequeWrapper<T>::operator[])
        .def_property_readonly("data", &DequeWrapper<T>::getData, py::return_value_policy::reference_internal)
        .def("front", &DequeWrapper<T>::front)
        .def("back", &DequeWrapper<T>::back)

        .def("push_back", &DequeWrapper<T>::push_back)
        .def("push_front", &DequeWrapper<T>::push_front)
        .def("pop_back", &DequeWrapper<T>::pop_back)
        .def("pop_front", &DequeWrapper<T>::pop_front)
        .def("insert", &DequeWrapper<T>::insert)
        .def("erase", &DequeWrapper<T>::erase)
        .def("clear", &DequeWrapper<T>::clear)
        .def("swap", &DequeWrapper<T>::swap)

        .def("__iter__", [](DequeWrapper<T> &v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__reversed__", [](DequeWrapper<T> &v) { return py::make_iterator(v.rbegin(), v.rend()); },
             py::keep_alive<0, 1>())
        .def("__len__", &DequeWrapper<T>::__len__);
}

template <typename T>
void bind_deque(py::module &m, const std::string &type) {
    py::class_<DequeWrapper<T>>(m, ("Deque" + type).c_str())
         .def(py::init<>())
        .def(py::init<size_t>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::deque<T>>())

        .def("size", &DequeWrapper<T>::size)
        .def("max_size", &DequeWrapper<T>::max_size)
        .def("resize", &DequeWrapper<T>::resize)
        .def("empty", &DequeWrapper<T>::empty)
        .def("shrink_to_fit", &DequeWrapper<T>::shrink_to_fit)
        .def("at", &DequeWrapper<T>::at)
        .def("__getitem__", &DequeWrapper<T>::operator[])
        .def_property_readonly("data", &DequeWrapper<T>::getData, py::return_value_policy::reference_internal)
        .def("front", &DequeWrapper<T>::front)
        .def("back", &DequeWrapper<T>::back)

        .def("push_back", &DequeWrapper<T>::push_back)
        .def("push_front", &DequeWrapper<T>::push_front)
        .def("pop_back", &DequeWrapper<T>::pop_back)
        .def("pop_front", &DequeWrapper<T>::pop_front)
        .def("insert", &DequeWrapper<T>::insert)
        .def("erase", &DequeWrapper<T>::erase)
        .def("clear", &DequeWrapper<T>::clear)
        .def("swap", &DequeWrapper<T>::swap)

        .def("__iter__", [](DequeWrapper<T> &v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__reversed__", [](DequeWrapper<T> &v) { return py::make_iterator(v.rbegin(), v.rend()); },
             py::keep_alive<0, 1>())
        .def("__len__", &DequeWrapper<T>::__len__);
}

template <typename T>
void bind_list_wrapper(py::module &m) {
    py::class_<ListWrapper<T>>(m, "List")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::list<T>>())

        .def("size", &ListWrapper<T>::size)
        .def("empty", &ListWrapper<T>::empty)

        .def("push_back", &ListWrapper<T>::push_back)
        .def("push_front", &ListWrapper<T>::push_front)
        .def("pop_back", &ListWrapper<T>::pop_back)
        .def("pop_front", &ListWrapper<T>::pop_front)
        .def("clear", &ListWrapper<T>::clear)
        .def("insert", &ListWrapper<T>::insert)
        .def("erase", &ListWrapper<T>::erase)

        .def("front", &ListWrapper<T>::front)
        .def("back", &ListWrapper<T>::back)
        .def_property_readonly("data", &ListWrapper<T>::getData)
        .def("__len__", &ListWrapper<T>::size)  // Python's len() function
        .def("__iter__", [](ListWrapper<T>& v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__reversed__", [](ListWrapper<T>& v) { return py::make_iterator(v.rbegin(), v.rend()); },
             py::keep_alive<0, 1>());
}

template <typename T>
void bind_list(py::module &m, const std::string &type) {
    py::class_<ListWrapper<T>>(m, ("List" + type).c_str())
        .def(py::init<>())
        .def(py::init<size_t>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::list<T>>())

        .def("size", &ListWrapper<T>::size)
        .def("empty", &ListWrapper<T>::empty)

        .def("push_back", &ListWrapper<T>::push_back)
        .def("push_front", &ListWrapper<T>::push_front)
        .def("pop_back", &ListWrapper<T>::pop_back)
        .def("pop_front", &ListWrapper<T>::pop_front)
        .def("clear", &ListWrapper<T>::clear)
        .def("insert", &ListWrapper<T>::insert)
        .def("erase", &ListWrapper<T>::erase)

        .def("front", &ListWrapper<T>::front)
        .def("back", &ListWrapper<T>::back)
        .def_property_readonly("data", &ListWrapper<T>::getData)
        .def("__len__", &ListWrapper<T>::size)  // Python's len() function
        .def("__iter__", [](ListWrapper<T>& v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__reversed__", [](ListWrapper<T>& v) { return py::make_iterator(v.rbegin(), v.rend()); },
             py::keep_alive<0, 1>());
}

template <typename T>
void bind_forward_list_wrapper(py::module &m) {
    py::class_<ForwardListWrapper<T>>(m, "ForwardList")
        .def(py::init<>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::forward_list<T>>())
        .def("empty", &ForwardListWrapper<T>::empty)
        .def("front", &ForwardListWrapper<T>::front)
        .def("push_front", &ForwardListWrapper<T>::push_front)
        .def("pop_front", &ForwardListWrapper<T>::pop_front)
        .def("clear", &ForwardListWrapper<T>::clear)
        .def("insert_after", &ForwardListWrapper<T>::insert_after)
        .def("erase_after", &ForwardListWrapper<T>::erase_after)
        .def("__iter__", [](ForwardListWrapper<T> &v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__len__", [](const ForwardListWrapper<T> &v) { return std::distance(v.begin(), v.end()); });
}

template <typename T>
void bind_forward_list(py::module &m, const std::string &type) {
    py::class_<ForwardListWrapper<T>>(m, ("ForwardList" + type).c_str())
        .def(py::init<>())
        .def(py::init<size_t, const T&>())
        .def(py::init<std::forward_list<T>>())
        .def("empty", &ForwardListWrapper<T>::empty)
        .def("front", &ForwardListWrapper<T>::front)
        .def("push_front", &ForwardListWrapper<T>::push_front)
        .def("pop_front", &ForwardListWrapper<T>::pop_front)
        .def("clear", &ForwardListWrapper<T>::clear)
        .def("insert_after", &ForwardListWrapper<T>::insert_after)
        .def("erase_after", &ForwardListWrapper<T>::erase_after)
        .def("__iter__", [](ForwardListWrapper<T> &v) { return py::make_iterator(v.begin(), v.end()); },
             py::keep_alive<0, 1>())
        .def("__len__", [](const ForwardListWrapper<T> &v) { return std::distance(v.begin(), v.end()); });
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
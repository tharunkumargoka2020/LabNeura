import unittest
from labneura import *

class TestList(unittest.TestCase):
    def test_list_creation(self):
        lst = List()
        self.assertEqual(lst.size(), 0)

    def test_list_insert(self):
        lst = List()
        lst.insert(0, 1)
        lst.insert(1, 2)
        self.assertEqual(lst.at(0), 1)
        self.assertEqual(lst.at(1), 2)

    def test_list_creation1(self):
        lst_int = ListInt()
        lst_float = ListFloat()
        lst_double = ListDouble()
        lst_string = ListString()
        self.assertEqual(lst_int.size(), 0)
        self.assertEqual(lst_float.size(), 0)
        self.assertEqual(lst_double.size(), 0)
        self.assertEqual(lst_string.size(), 0)

    def test_list_insert1(self):
        lst_int = ListInt()
        lst_float = ListFloat()
        lst_double = ListDouble()
        lst_string = ListString()
        lst_int.insert(0, 1)
        lst_float.insert(0, 1.0)
        lst_double.insert(0, 1.0)
        lst_string.insert(0, "one")
        self.assertEqual(lst_int.at(0), 1)
        self.assertAlmostEqual(lst_float.at(0), 1.0)
        self.assertAlmostEqual(lst_double.at(0), 1.0)
        self.assertEqual(lst_string.at(0), "one")

class TestVector(unittest.TestCase):
    def test_vector_creation(self):
        vec = Vector()
        self.assertEqual(vec.size(), 0)

    def test_vector_push_back(self):
        vec = Vector()
        vec.push_back(1)
        vec.push_back(2)
        self.assertEqual(vec.at(0), 1)
        self.assertEqual(vec.at(1), 2)
    
    def test_vector_creation1(self):
        vec_int = VectorInt()
        vec_float = VectorFloat()
        vec_double = VectorDouble()
        vec_string = VectorString()
        self.assertEqual(vec_int.size(), 0)
        self.assertEqual(vec_float.size(), 0)
        self.assertEqual(vec_double.size(), 0)
        self.assertEqual(vec_string.size(), 0)

    def test_vector_push_back1(self):
        vec_int = VectorInt()
        vec_float = VectorFloat()
        vec_double = VectorDouble()
        vec_string = VectorString()
        vec_int.push_back(1)
        vec_float.push_back(1.0)
        vec_double.push_back(1.0)
        vec_string.push_back("one")
        self.assertEqual(vec_int.at(0), 1)
        self.assertAlmostEqual(vec_float.at(0), 1.0)
        self.assertAlmostEqual(vec_double.at(0), 1.0)
        self.assertEqual(vec_string.at(0), "one")

class TestStack(unittest.TestCase):
    def test_stack_push_pop(self):
        stack = Stack()
        stack.push(1)
        stack.push(2)
        self.assertEqual(stack.top(), 2)
        stack.pop()
        self.assertEqual(stack.top(), 1)

    def test_stack_push_pop1(self):
        stack_int = StackInt()
        stack_float = StackFloat()
        stack_double = StackDouble()
        stack_string = StackString()
        stack_int.push(1)
        stack_float.push(1.0)
        stack_double.push(1.0)
        stack_string.push("one")
        self.assertEqual(stack_int.top(), 1)
        self.assertAlmostEqual(stack_float.top(), 1.0)
        self.assertAlmostEqual(stack_double.top(), 1.0)
        self.assertEqual(stack_string.top(), "one")

class TestQueue(unittest.TestCase):
    def test_queue_enqueue_dequeue(self):
        queue = Queue()
        queue.push(1)
        queue.push(2)
        self.assertEqual(queue.front(), 1)
        queue.pop()
        self.assertEqual(queue.front(), 2)
    
    def test_queue_enqueue_dequeue1(self):
        queue_int = QueueInt()
        queue_float = QueueFloat()
        queue_double = QueueDouble()
        queue_string = QueueString()
        queue_int.push(1)
        queue_float.push(1.0)
        queue_double.push(1.0)
        queue_string.push("one")
        self.assertEqual(queue_int.front(), 1)
        self.assertAlmostEqual(queue_float.front(), 1.0)
        self.assertAlmostEqual(queue_double.front(), 1.0)
        self.assertEqual(queue_string.front(), "one")

if __name__ == '__main__':
    unittest.main()

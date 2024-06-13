import unittest
import labneura

class TestDequeWrapper(unittest.TestCase):

    def test_deque_object(self):
        deque = labneura.Deque()
        self.assertEqual(len(deque), 0)
        
        deque.push_back(1)
        deque.push_back("hello")
        deque.push_back(3.5)
        self.assertEqual(len(deque), 3)
        self.assertEqual(deque[0], 1)
        self.assertEqual(deque[1], "hello")
        self.assertEqual(deque[2], 3.5)
        self.assertEqual(deque.front(), 1)
        self.assertEqual(deque.back(), 3.5)

        deque.push_front("start")
        self.assertEqual(len(deque), 4)
        self.assertEqual(deque[0], "start")
        self.assertEqual(deque.front(), "start")

        deque.pop_front()
        self.assertEqual(len(deque), 3)
        self.assertEqual(deque.front(), 1)

        deque.clear()
        self.assertEqual(len(deque), 0)
        with self.assertRaises(IndexError):
            deque.pop_back()
        with self.assertRaises(IndexError):
            deque.pop_front()
        with self.assertRaises(IndexError):
            deque.front()
        with self.assertRaises(IndexError):
            deque.back()

    def test_deque_insert_erase(self):
        deq = labneura.Deque()
        deq.push_back(1)
        deq.push_back(2)
        deq.push_back(3)
        deq.insert(1, 4)
        self.assertEqual(list(deq), [1, 4, 2, 3])
        
        deq.erase(1)
        self.assertEqual(list(deq), [1, 2, 3])
        
        with self.assertRaises(IndexError):
            deq.insert(10, 5)
        with self.assertRaises(IndexError):
            deq.erase(10)

    def test_deque_string(self):
        deque_str = labneura.DequeString()
        self.assertEqual(len(deque_str), 0)

        deque_str.push_back("apple")
        deque_str.push_back("banana")
        deque_str.push_back("cherry")
        self.assertEqual(len(deque_str), 3)
        self.assertEqual(deque_str[0], "apple")
        self.assertEqual(deque_str[1], "banana")
        self.assertEqual(deque_str[2], "cherry")
        self.assertEqual(deque_str.front(), "apple")
        self.assertEqual(deque_str.back(), "cherry")

        deque_str.push_front("orange")
        self.assertEqual(len(deque_str), 4)
        self.assertEqual(deque_str[0], "orange")
        self.assertEqual(deque_str.front(), "orange")

        deque_str.pop_front()
        self.assertEqual(len(deque_str), 3)
        self.assertEqual(deque_str.front(), "apple")

        deque_str.clear()
        self.assertEqual(len(deque_str), 0)
        with self.assertRaises(IndexError):
            deque_str.pop_back()
        with self.assertRaises(IndexError):
            deque_str.pop_front()
        with self.assertRaises(IndexError):
            deque_str.front()
        with self.assertRaises(IndexError):
            deque_str.back()

if __name__ == '__main__':
    unittest.main()


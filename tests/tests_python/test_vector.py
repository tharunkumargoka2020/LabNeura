import unittest
import labneura

class TestVectorWrapper(unittest.TestCase):

    def test_vector_object(self):
        vec = labneura.Vector()
        self.assertEqual(len(vec), 0)
        
        vec.push_back(1)
        vec.push_back("hello")
        vec.push_back(3.5)
        self.assertEqual(len(vec), 3)
        self.assertEqual(vec[0], 1)
        self.assertEqual(vec[1], "hello")
        self.assertEqual(vec[2], 3.5)
        self.assertEqual(vec.front(), 1)
        self.assertEqual(vec.back(), 3.5)
        vec.clear()
        self.assertEqual(len(vec), 0)
        with self.assertRaises(IndexError):
            vec.pop_back()
        with self.assertRaises(IndexError):
            vec.front()
        with self.assertRaises(IndexError):
            vec.back()

    def test_vector_insert_erase(self):
        vec = labneura.Vector()
        vec.push_back(1)
        vec.push_back(2)
        vec.push_back(3)
        vec.insert(1, 4)
        self.assertEqual(list(vec), [1, 4, 2, 3])
        
        vec.erase(1)
        self.assertEqual(list(vec), [1, 2, 3])
        
        with self.assertRaises(IndexError):
            vec.insert(10, 5)
        with self.assertRaises(IndexError):
            vec.erase(10)


    def test_vector_string(self):
        vec_str = labneura.VectorString()
        self.assertEqual(len(vec_str), 0)

        vec_str.push_back("apple")
        vec_str.push_back("banana")
        vec_str.push_back("cherry")
        self.assertEqual(len(vec_str), 3)
        self.assertEqual(vec_str[0], "apple")
        self.assertEqual(vec_str[1], "banana")
        self.assertEqual(vec_str[2], "cherry")
        self.assertEqual(vec_str.front(), "apple")
        self.assertEqual(vec_str.back(), "cherry")

        vec_str.clear()
        self.assertEqual(len(vec_str), 0)
        with self.assertRaises(IndexError):
            vec_str.pop_back()
        with self.assertRaises(IndexError):
            vec_str.front()
        with self.assertRaises(IndexError):
            vec_str.back()

if __name__ == '__main__':
    unittest.main()


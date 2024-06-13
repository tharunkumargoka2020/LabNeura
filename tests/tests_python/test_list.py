import unittest
import labneura

class TestListWrapper(unittest.TestCase):

    def test_list_object(self):
        lst = labneura.List()
        self.assertEqual(len(lst), 0)

        lst.push_back(1)
        lst.push_back("hello")
        lst.push_back(3.5)
        self.assertEqual(len(lst), 3)
        self.assertEqual(lst.front(), 1)
        self.assertEqual(lst.back(), 3.5)
        self.assertEqual(list(lst), [1, "hello", 3.5])
        self.assertEqual(list(reversed(lst)), [3.5, "hello", 1])

        lst.push_front("world")
        self.assertEqual(lst.front(), "world")
        self.assertEqual(list(lst), ["world", 1, "hello", 3.5])
        self.assertEqual(list(reversed(lst)), [3.5, "hello", 1, "world"])

        lst.insert(2, "inserted")
        self.assertEqual(list(lst), ["world", 1, "inserted", "hello", 3.5])
        
        lst.erase(2)
        self.assertEqual(list(lst), ["world", 1, "hello", 3.5])

        lst.clear()
        self.assertEqual(len(lst), 0)

        with self.assertRaises(IndexError):
            lst.pop_back()
        with self.assertRaises(IndexError):
            lst.pop_front()
        with self.assertRaises(IndexError):
            lst.front()
        with self.assertRaises(IndexError):
            lst.back()

    def test_list_string(self):
        lst_str = labneura.ListString()
        self.assertEqual(len(lst_str), 0)

        lst_str.push_back("apple")
        lst_str.push_back("banana")
        lst_str.push_back("cherry")
        self.assertEqual(len(lst_str), 3)
        self.assertEqual(lst_str.front(), "apple")
        self.assertEqual(lst_str.back(), "cherry")
        self.assertEqual(list(lst_str), ["apple", "banana", "cherry"])
        self.assertEqual(list(reversed(lst_str)), ["cherry", "banana", "apple"])

        lst_str.push_front("apricot")
        self.assertEqual(lst_str.front(), "apricot")
        self.assertEqual(list(lst_str), ["apricot", "apple", "banana", "cherry"])
        self.assertEqual(list(reversed(lst_str)), ["cherry", "banana", "apple", "apricot"])

        lst_str.insert(2, "blueberry")
        self.assertEqual(list(lst_str), ["apricot", "apple", "blueberry", "banana", "cherry"])
        
        lst_str.erase(2)
        self.assertEqual(list(lst_str), ["apricot", "apple", "banana", "cherry"])

        lst_str.clear()
        self.assertEqual(len(lst_str), 0)
        
        with self.assertRaises(IndexError):
            lst_str.pop_back()
        with self.assertRaises(IndexError):
            lst_str.pop_front()
        with self.assertRaises(IndexError):
            lst_str.front()
        with self.assertRaises(IndexError):
            lst_str.back()

if __name__ == '__main__':
    unittest.main()

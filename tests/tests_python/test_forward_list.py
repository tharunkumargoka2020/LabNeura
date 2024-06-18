import unittest
import labneura

class TestForwardListWrapper(unittest.TestCase):

    def test_forward_list_object(self):
        fwd_list = labneura.ForwardList()
        self.assertTrue(fwd_list.empty())

        fwd_list.push_front(1)
        fwd_list.push_front("hello")
        fwd_list.push_front(3.5)
        self.assertEqual(fwd_list.find(1),2)
        self.assertEqual(fwd_list.find(0),-1)
        self.assertFalse(fwd_list.empty())
        self.assertEqual(fwd_list.front(), 3.5)

        fwd_list.pop_front()
        self.assertEqual(fwd_list.front(), "hello")

        with self.assertRaises(IndexError):
            fwd_list.pop_front()
            fwd_list.pop_front()
            fwd_list.pop_front()

    def test_forward_list_string(self):
        fwd_list_str = labneura.ForwardListString()
        self.assertTrue(fwd_list_str.empty())

        fwd_list_str.push_front("apple")
        fwd_list_str.push_front("banana")
        fwd_list_str.push_front("cherry")
        self.assertEqual(fwd_list_str.find("banana"),1)
        self.assertEqual(fwd_list_str.find("tharun"), -1)
        self.assertFalse(fwd_list_str.empty())
        self.assertEqual(fwd_list_str.front(), "cherry")

        fwd_list_str.pop_front()
        self.assertEqual(fwd_list_str.front(), "banana")

        with self.assertRaises(IndexError):
            fwd_list_str.pop_front()
            fwd_list_str.pop_front()
            fwd_list_str.pop_front()

    def test_forward_list_insert_erase(self):
        fwd_list = labneura.ForwardList()
        fwd_list.push_front(1)
        fwd_list.push_front(2)
        fwd_list.push_front(3)
        fwd_list.insert_after(1, 4)
        self.assertEqual(list(fwd_list), [3, 2, 4, 1])
        
        fwd_list.erase_after(1)
        self.assertEqual(list(fwd_list), [3, 2, 1])
        
        with self.assertRaises(IndexError):
            fwd_list.insert_after(10, 5)
        with self.assertRaises(IndexError):
            fwd_list.erase_after(10)

if __name__ == '__main__':
    unittest.main()

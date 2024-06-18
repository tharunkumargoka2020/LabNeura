import unittest
import labneura

class TestSetWrapper(unittest.TestCase):

    def test_set_int(self):
        s = labneura.SetInt()
        self.assertEqual(len(s), 0)
        
        s.insert(1)
        s.insert(2)
        s.insert(3)
        self.assertEqual(len(s), 3)
        self.assertTrue(s.contains(1))
        self.assertFalse(s.contains(4))
        
        s.erase(2)
        self.assertEqual(len(s), 2)
        self.assertFalse(s.contains(2))
        
        s.clear()
        self.assertEqual(len(s), 0)
        self.assertFalse(s.contains(1))

    def test_set_string(self):
        s = labneura.SetString()
        self.assertEqual(len(s), 0)

        s.insert("apple")
        s.insert("banana")
        s.insert("cherry")
        self.assertEqual(len(s), 3)
        self.assertTrue(s.contains("apple"))
        self.assertFalse(s.contains("date"))
        
        s.erase("banana")
        self.assertEqual(len(s), 2)
        self.assertFalse(s.contains("banana"))
        
        s.clear()
        self.assertEqual(len(s), 0)
        self.assertFalse(s.contains("cherry"))

if __name__ == '__main__':
    unittest.main()

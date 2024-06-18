import unittest
import labneura

class TestUnorderedSetWrapper(unittest.TestCase):
    def test_unordered_set(self):
        uset = labneura.UnorderedSetInt()

        # Test empty
        self.assertTrue(uset.empty(), "Unordered set should be empty initially")

        # Test insert
        uset.insert(1)
        uset.insert(2)
        uset.insert(3)

        self.assertEqual(len(uset), 3, "Unordered set should contain 3 elements")
        self.assertFalse(uset.empty(), "Unordered set should not be empty")

        # Test count and contains
        self.assertEqual(uset.count(1), 1, "Unordered set should contain the element 1")
        self.assertTrue(uset.contains(2), "Unordered set should contain the element 2")
        self.assertFalse(uset.contains(4), "Unordered set should not contain the element 4")

        # Test find
        self.assertNotEqual(uset.find(2), -1, "Unordered set should find the element 2")
        self.assertEqual(uset.find(4), -1, "Unordered set should not find the element 4")

        # Test bucket interface
        self.assertGreater(uset.bucket_count(), 0, "Unordered set should have at least one bucket")
        self.assertGreater(uset.bucket_size(uset.bucket(1)), 0, "Bucket size should be greater than 0 for existing element")

        # Test load factor and max load factor
        self.assertGreater(uset.load_factor(), 0, "Load factor should be greater than 0")

        # Test rehash and reserve
        uset.rehash(10)
        self.assertGreaterEqual(uset.bucket_count(), 10, "Bucket count should be at least 10 after rehash")

        uset.reserve(20)
        self.assertLessEqual(len(uset), 20, "Set size should be less than or equal to 20 after reserve")

        # Test clear
        uset.clear()
        self.assertTrue(uset.empty(), "Unordered set should be empty after clear")

        # Test iterators
        uset.insert(1)
        uset.insert(2)
        uset.insert(3)

        count = 0
        for elem in uset:
            count += 1
        self.assertEqual(count, 3, "Unordered set should iterate over 3 elements")

if __name__ == '__main__':
    unittest.main()

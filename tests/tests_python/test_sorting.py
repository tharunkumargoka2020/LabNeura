import unittest
from labneura import Sorting

class TestSortingAlgorithms(unittest.TestCase):
    
    def setUp(self):
        self.arr1 = [10, 7, 8, 9, 1, 5]
        self.arr2 = [3, 6, 8, 10, 1, 2, 1]
        self.arr3 = []
        self.arr4 = [1]

    def test_selection(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        sorting1 = Sorting(self.arr1)
        sorting1.selection()
        self.assertEqual(sorting1.data, sorted_arr)
        self.assertEqual(sorting1.no_timesteps, 15)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        sorting2 = Sorting(self.arr2)
        sorting2.selection()
        self.assertEqual(sorting2.data, sorted_arr)
        self.assertEqual(sorting2.no_timesteps, 21)

        sorted_arr = []
        sorting3 = Sorting(self.arr3)
        sorting3.selection()
        self.assertEqual(sorting3.data, sorted_arr)
        self.assertEqual(sorting3.no_timesteps, 0)

        sorted_arr = [1]
        sorting4 = Sorting(self.arr4)
        sorting4.selection()
        self.assertEqual(sorting4.data, sorted_arr)
        self.assertEqual(sorting4.no_timesteps, 0)


    def test_bubble(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        sorting1 = Sorting(self.arr1)
        sorting1.bubble()
        self.assertEqual(sorting1.data, sorted_arr)
        self.assertEqual(sorting1.no_timesteps, 15)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        sorting2 = Sorting(self.arr2)
        sorting2.bubble()
        self.assertEqual(sorting2.data, sorted_arr)
        self.assertEqual(sorting2.no_timesteps, 21)

        sorted_arr = []
        sorting3 = Sorting(self.arr3)
        sorting3.bubble()
        self.assertEqual(sorting3.data, sorted_arr)
        self.assertEqual(sorting3.no_timesteps, 0)

        sorted_arr = [1]
        sorting4 = Sorting(self.arr4)
        sorting4.bubble()
        self.assertEqual(sorting4.data, sorted_arr)
        self.assertEqual(sorting4.no_timesteps, 0)

    def test_insertion(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        sorting1 = Sorting(self.arr1)
        sorting1.insertion()
        self.assertEqual(sorting1.data, sorted_arr)
        self.assertEqual(sorting1.no_timesteps, 11)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        sorting2 = Sorting(self.arr2)
        sorting2.insertion()
        self.assertEqual(sorting2.data, sorted_arr)
        self.assertEqual(sorting2.no_timesteps, 16)
        
        sorted_arr = []
        sorting3 = Sorting(self.arr3)
        sorting3.insertion()
        self.assertEqual(sorting3.data, sorted_arr)
        self.assertEqual(sorting3.no_timesteps, 0)

        sorted_arr = [1]
        sorting4 = Sorting(self.arr4)
        sorting4.insertion()
        self.assertEqual(sorting4.data, sorted_arr)
        self.assertEqual(sorting4.no_timesteps, 0)

    def test_merge(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        sorting1 = Sorting(self.arr1)
        sorting1.merge()
        self.assertEqual(sorting1.data, sorted_arr)
        self.assertEqual(sorting1.no_timesteps, 32)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        sorting2 = Sorting(self.arr2)
        sorting2.merge()
        self.assertEqual(sorting2.data, sorted_arr)
        self.assertEqual(sorting2.no_timesteps, 40)

        sorted_arr = []
        sorting3 = Sorting(self.arr3)
        sorting3.merge()
        self.assertEqual(sorting3.data, sorted_arr)
        self.assertEqual(sorting3.no_timesteps, 0)

        sorted_arr = [1]
        sorting4 = Sorting(self.arr4)
        sorting4.merge()
        self.assertEqual(sorting4.data, sorted_arr)
        self.assertEqual(sorting4.no_timesteps, 0)
        
    def test_quick(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        sorting1 = Sorting(self.arr1)
        sorting1.quick()
        self.assertEqual(sorting1.data, sorted_arr)
        self.assertEqual(sorting1.no_timesteps, 11)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        sorting2 = Sorting(self.arr2)
        sorting2.quick()
        self.assertEqual(sorting2.data, sorted_arr)
        self.assertEqual(sorting2.no_timesteps, 12)
        
        sorted_arr = []
        sorting3 = Sorting(self.arr3)
        sorting3.quick()
        self.assertEqual(sorting3.data, sorted_arr)
        self.assertEqual(sorting3.no_timesteps, 0)

        sorted_arr = [1]
        sorting4 = Sorting(self.arr4)
        sorting4.quick()
        self.assertEqual(sorting4.data, sorted_arr)
        self.assertEqual(sorting4.no_timesteps, 0)
        
if __name__ == '__main__':
    unittest.main()

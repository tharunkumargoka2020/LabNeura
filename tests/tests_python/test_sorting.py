import unittest
from labneura.algorithms.sorting import Sorting

class TestSortingAlgorithms(unittest.TestCase):
    
    def setUp(self):
        self.arr1 = [10, 7, 8, 9, 1, 5]
        self.arr2 = [3, 6, 8, 10, 1, 2, 1]
        self.arr3 = []
        self.arr4 = [1]

    def test_selection_cpp(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.selection_cpp()
        self.assertEqual(self.sorting1.data, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.selection_cpp()
        self.assertEqual(self.sorting2.data, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.selection_cpp()
        self.assertEqual(self.sorting3.data, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.selection_cpp()
        self.assertEqual(self.sorting4.data, sorted_arr)

    def test_selection(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.selection()
        self.assertEqual(self.arr1, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.selection()
        self.assertEqual(self.arr2, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.selection()
        self.assertEqual(self.arr3, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.selection()
        self.assertEqual(self.arr4, sorted_arr)

    def test_bubble_sort(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.bubble_sort()
        self.assertEqual(self.arr1, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.bubble_sort()
        self.assertEqual(self.arr2, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.bubble_sort()
        self.assertEqual(self.arr3, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.bubble_sort()
        self.assertEqual(self.arr4, sorted_arr)

    def test_bubble_cpp(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.bubble_cpp()
        self.assertEqual(self.sorting1.data, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.bubble_cpp()
        self.assertEqual(self.sorting2.data, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.bubble_cpp()
        self.assertEqual(self.sorting3.data, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.bubble_cpp()
        self.assertEqual(self.sorting4.data, sorted_arr)
    
    def test_insertion(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.insertion()
        self.assertEqual(self.arr1, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.insertion()
        self.assertEqual(self.arr2, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.insertion()
        self.assertEqual(self.arr3, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.insertion()
        self.assertEqual(self.arr4, sorted_arr)

    def test_insertion_cpp(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.insertion_cpp()
        self.assertEqual(self.sorting1.data, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.insertion_cpp()
        self.assertEqual(self.sorting2.data, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.insertion_cpp()
        self.assertEqual(self.sorting3.data, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.insertion_cpp()
        self.assertEqual(self.sorting4.data, sorted_arr)

    def test_merge(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.merge()
        self.assertEqual(self.arr1, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.merge()
        self.assertEqual(self.arr2, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.merge()
        self.assertEqual(self.arr3, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.merge()
        self.assertEqual(self.arr4, sorted_arr)

    # def test_merge_cpp(self):
    #     sorted_arr = [1, 5, 7, 8, 9, 10]
    #     self.sorting1 = Sorting(self.arr1)
    #     self.sorting1.merge_cpp()
    #     self.assertEqual(self.sorting1.data, sorted_arr)

    #     sorted_arr = [1, 1, 2, 3, 6, 8, 10]
    #     self.sorting2 = Sorting(self.arr2)
    #     self.sorting2.merge_cpp()
    #     self.assertEqual(self.sorting2.data, sorted_arr)

    #     sorted_arr = []
    #     self.sorting3 = Sorting(self.arr3)
    #     self.sorting3.merge_cpp()
    #     self.assertEqual(self.sorting3.data, sorted_arr)

    #     sorted_arr = [1]
    #     self.sorting4 = Sorting(self.arr4)
    #     self.sorting4.merge_cpp()
    #     self.assertEqual(self.sorting4.data, sorted_arr)
        
    def test_quick(self):
        sorted_arr = [1, 5, 7, 8, 9, 10]
        self.sorting1 = Sorting(self.arr1)
        self.sorting1.quick()
        self.assertEqual(self.arr1, sorted_arr)

        sorted_arr = [1, 1, 2, 3, 6, 8, 10]
        self.sorting2 = Sorting(self.arr2)
        self.sorting2.quick()
        self.assertEqual(self.arr2, sorted_arr)

        sorted_arr = []
        self.sorting3 = Sorting(self.arr3)
        self.sorting3.quick()
        self.assertEqual(self.arr3, sorted_arr)

        sorted_arr = [1]
        self.sorting4 = Sorting(self.arr4)
        self.sorting4.quick()
        self.assertEqual(self.arr4, sorted_arr)

    # def test_quick_cpp(self):
    #     sorted_arr = [1, 5, 7, 8, 9, 10]
    #     self.sorting1 = Sorting(self.arr1)
    #     self.sorting1.quick_cpp()
    #     self.assertEqual(self.sorting1.data, sorted_arr)

    #     sorted_arr = [1, 1, 2, 3, 6, 8, 10]
    #     self.sorting2 = Sorting(self.arr2)
    #     self.sorting2.quick_cpp()
    #     self.assertEqual(self.sorting2.data, sorted_arr)

    #     sorted_arr = []
    #     self.sorting3 = Sorting(self.arr3)
    #     self.sorting3.quick_cpp()
    #     self.assertEqual(self.sorting3.data, sorted_arr)

    #     sorted_arr = [1]
    #     self.sorting4 = Sorting(self.arr4)
    #     self.sorting4.quick_cpp()
    #     self.assertEqual(self.sorting4.data, sorted_arr)

if __name__ == '__main__':
    unittest.main()

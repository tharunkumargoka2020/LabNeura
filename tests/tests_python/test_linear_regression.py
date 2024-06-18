import unittest
import numpy as np
import labneura  # Assuming your Python bindings are available as 'labneura'

class TestLinearRegression(unittest.TestCase):

    def setUp(self):
        self.lr_single = labneura.LinearRegression(learning_rate=0.01, iterations=1000)
        self.lr_multi = labneura.LinearRegression(learning_rate=0.01, iterations=1000)

    def test_single_variable(self):
        X = np.array([[1], [2], [3], [4], [5]])
        y = np.array([1, 2, 3, 4, 5])

        self.lr_single.fit(X, y)
        predictions = self.lr_single.predict(X)
        
        for pred, actual in zip(predictions, y):
            self.assertAlmostEqual(pred, actual, places=1)

    def test_multi_variable(self):
        X = np.array([[1, 2], [2, 3], [3, 4], [4, 5], [5, 6]])
        y = np.array([2, 3, 4, 5, 6])

        self.lr_multi.fit(X, y)
        predictions = self.lr_multi.predict(X)
        
        for pred, actual in zip(predictions, y):
            self.assertAlmostEqual(pred, actual, places=1)

if __name__ == '__main__':
    unittest.main()

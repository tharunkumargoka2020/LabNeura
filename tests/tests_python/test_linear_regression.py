from labneura.ml.linear_regression import LinearRegression

def test_linear_regression():
    lr =  LinearRegression([1, 2, 3], [2, 4, 6])
    lr.fit()
    assert lr.predict(4) == 8.0

if __name__ == "__main__":
    test_linear_regression()
    print("Test passed!")
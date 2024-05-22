import mlcpp

def test_linear_regression():
    lr = mlcpp.LinearRegression()
    lr.fit([1, 2, 3], [2, 4, 6])
    assert lr.predict(4) == 8.0

if __name__ == "__main__":
    test_linear_regression()
    print("Test passed!")
#pragma once
#include <vector>

class LinearRegression {
public:
    LinearRegression() = default;
    void fit(const std::vector<double>& x, const std::vector<double>& y);
    double predict(double x);

private:
    double slope = 0.0;
    double intercept = 0.0;
};
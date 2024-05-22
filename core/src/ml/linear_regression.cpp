#include "ml/linear_regression.h"
#include <numeric>

void LinearRegression::fit(const std::vector<double>& x, const std::vector<double>& y) {
    double x_mean = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
    double y_mean = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

    double num = 0.0, den = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        num += (x[i] - x_mean) * (y[i] - y_mean);
        den += (x[i] - x_mean) * (x[i] - x_mean);
    }

    slope = num / den;
    intercept = y_mean - slope * x_mean;
}

double LinearRegression::predict(double x) {
    return slope * x + intercept;
}

#include "ml/linear_regression.h"
#include <numeric>
#include <iostream>
#include <map>

LinearRegression::LinearRegression(std::vector<double>& x, std::vector<double>& y){
    X = x;
    Y = y;
    weights_["slope"] = slope_ = 0.0;
    weights_["intercept"] = intercept_ = 0.0;
}
void LinearRegression::fit() {
    double x_mean = std::accumulate(X.begin(), X.end(), 0.0) / X.size();
    double y_mean = std::accumulate(Y.begin(),Y.end(), 0.0) / Y.size();

    double num = 0.0, den = 0.0;
    for (size_t i = 0; i < X.size(); ++i) {
        num += (X[i] - x_mean) * (Y[i] - y_mean);
        den += (X[i] - x_mean) * (X[i] - x_mean);
    }

    slope_ = num / den;
    intercept_ = y_mean - slope_ * x_mean;
    weights_["slope"] = slope_;
    weights_["intercept"] = intercept_;
}

double LinearRegression::predict(double x) {
    return slope_ * x + intercept_;
}

double LinearRegression::getSlope() {
    return slope_;
}

double LinearRegression::getIntercept() {
    return intercept_;
}

std::map<std::string, double>& LinearRegression::getWeights() {
    return weights_;
}
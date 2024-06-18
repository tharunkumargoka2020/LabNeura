#include "ml/linear_regression.h"
#include <iostream>

LinearRegression::LinearRegression(double learning_rate, int iterations)
    : learning_rate(learning_rate), iterations(iterations), bias(0) {}

void LinearRegression::fit(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) {
    int m = X.rows();
    int n = X.cols();
    weights = Eigen::VectorXd::Zero(n);
    bias = 0.0;

    for (int i = 0; i < iterations; ++i) {
        gradient_descent(X, y);
        if (i % 100 == 0) {
            std::cout << "Iteration " << i << " - Cost: " << cost(X, y) << std::endl;
        }
    }
}

void LinearRegression::gradient_descent(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) {
    int m = X.rows();
    Eigen::VectorXd predictions = X * weights + Eigen::VectorXd::Constant(m, bias);
    Eigen::VectorXd errors = predictions - y;

    weights -= (learning_rate / m) * (X.transpose() * errors);
    bias -= (learning_rate / m) * errors.sum();
}

Eigen::VectorXd LinearRegression::predict(const Eigen::MatrixXd& X) {
    return X * weights + Eigen::VectorXd::Constant(X.rows(), bias);
}

double LinearRegression::cost(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) {
    int m = X.rows();
    Eigen::VectorXd predictions = X * weights + Eigen::VectorXd::Constant(m, bias);
    Eigen::VectorXd errors = predictions - y;
    return (1.0 / (2 * m)) * errors.array().square().sum();
}

#pragma once

#include <Eigen/Dense>

class LinearRegression {
public:
    LinearRegression(double learning_rate = 0.01, int iterations = 1000);

    void fit(const Eigen::MatrixXd& X, const Eigen::VectorXd& y);
    Eigen::VectorXd predict(const Eigen::MatrixXd& X);
    double cost(const Eigen::MatrixXd& X, const Eigen::VectorXd& y);

private:
    double learning_rate;
    int iterations;
    Eigen::VectorXd weights;
    double bias;

    void gradient_descent(const Eigen::MatrixXd& X, const Eigen::VectorXd& y);
};


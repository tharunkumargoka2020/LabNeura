#pragma once
#include <vector>
#include <string>
#include <map>

class LinearRegression {
public:
    LinearRegression(std::vector<double>& x, std::vector<double>& y);
    void fit();
    double predict(double x);
    double getSlope();
    double getIntercept();
    std::map<std::string, double>& getWeights();

    std::vector<double> X;
    std::vector<double> Y;
private:
    double slope_;
    double intercept_;
    std::map<std::string, double> weights_;
};
#include "ml/linear_regression.h"
#include <gtest/gtest.h>

TEST(LinearRegressionTest, BasicAssertions) {
    LinearRegression lr;
    std::vector<double> x = {1, 2, 3};
    std::vector<double> y = {2, 4, 6};
    lr.fit(x, y);
    ASSERT_DOUBLE_EQ(lr.predict(4), 8.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
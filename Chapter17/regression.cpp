#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

// Function to calculate the mean of a vector
template <typename T>
T calculateMean(const std::vector<T>& data) {
    T sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Function to calculate the linear regression coefficients
template <typename T>
std::pair<T, T> calculateLinearRegression(const std::vector<T>& x, const std::vector<T>& y) {
    T xMean = calculateMean(x);
    T yMean = calculateMean(y);

    T numerator = 0.0;
    T denominator = 0.0;

    for (size_t i = 0; i < x.size(); i++) {
        numerator += (x[i] - xMean) * (y[i] - yMean);
        denominator += std::pow(x[i] - xMean, 2);
    }

    T slope = numerator / denominator;
    T intercept = yMean - slope * xMean;

    return std::make_pair(slope, intercept);
}

// Function to predict the housing price using linear regression
template <typename T>
T predictPrice(const std::pair<T, T>& coefficients, T x) {
    return coefficients.first * x + coefficients.second;
}

int main() {
    // Input features (house sizes)
    std::vector<double> houseSizes = { 1000, 1500, 2000, 2500, 3000 };

    // Corresponding housing prices
    std::vector<double> prices = { 300000, 450000, 500000, 600000, 700000 };

    // Calculate the linear regression coefficients
    std::pair<double, double> regressionCoefficients = calculateLinearRegression(houseSizes, prices);

    // Predict the price for a new house size
    double newHouseSize = 1800;
    double predictedPrice = predictPrice(regressionCoefficients, newHouseSize);

    // Display the results
    std::cout << "Linear Regression Equation: y = " << regressionCoefficients.first << "x + " << regressionCoefficients.second << std::endl;
    std::cout << "Predicted price for a house of size " << newHouseSize << " sq. ft.: " << predictedPrice << std::endl;

    return 0;
}

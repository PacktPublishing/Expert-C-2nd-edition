#include <iostream>
#include <Eigen/Dense>

Eigen::MatrixXd calculateCovarianceMatrix(const Eigen::MatrixXd& data) {
    int numVariables = data.cols();
    int numSamples = data.rows();

    // Calculate centered data
    Eigen::MatrixXd centeredData = data.rowwise() - data.colwise().mean();

    // Calculate covariance matrix
    Eigen::MatrixXd covarianceMatrix = (centeredData.transpose() * centeredData) / (numSamples - 1);

    return covarianceMatrix;
}

int main() {
    // Create a data matrix with 5 samples and 3 variables
    Eigen::MatrixXd data(5, 3);
    data << 1.2, 2.3, 3.4,
            2.5, 3.6, 4.7,
            3.7, 4.8, 5.9,
            4.1, 5.2, 6.3,
            5.6, 6.7, 7.8;

    // Calculate the covariance matrix
    Eigen::MatrixXd covarianceMatrix = calculateCovarianceMatrix(data);

    // Print the covariance matrix
    std::cout << "Covariance Matrix:\n" << covarianceMatrix << std::endl;

    return 0;
}



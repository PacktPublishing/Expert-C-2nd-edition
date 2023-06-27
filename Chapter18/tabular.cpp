#include <iostream>
#include <vector>

int main() {
    // Sample tabular data
    std::vector<std::vector<int>> tabularData = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Display the tabular data
    for (const auto& row : tabularData) {
        for (const auto& cell : row) {
            std::cout << cell << '\t';
        }
        std::cout << std::endl;
    }

    // Calculate the sum of each row
    std::vector<int> rowSums;
    for (const auto& row : tabularData) {
        int rowSum = 0;
        for (const auto& cell : row) {
            rowSum += cell;
        }
        rowSums.push_back(rowSum);
    }

    // Display the row sums
    std::cout << "Row Sums:" << std::endl;
    for (const auto& sum : rowSums) {
        std::cout << sum << std::endl;
    }

    return 0;
}

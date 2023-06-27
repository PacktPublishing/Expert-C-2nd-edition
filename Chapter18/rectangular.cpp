#include <iostream>
#include <vector>

int main() {
    // Rectangular data represented as a vector of vectors
    std::vector<std::vector<int>> rectangularData = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    // Accessing and modifying rectangular data
    int element = rectangularData[1][2];  // Accessing a specific element
    std::cout << "Element at [1][2]: " << element << std::endl;

    rectangularData[2][1] = 100;  // Modifying an element
    std::cout << "Modified element at [2][1]: " << rectangularData[2][1] << std::endl;

    // Iterating over rectangular data
    std::cout << "Rectangular Data:" << std::endl;
    for (const auto& row : rectangularData) {
        for (const auto& element : row) {
            std::cout << element << '\t';
        }
        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Function to remove duplicates from a vector
template <typename T>
void removeDuplicates(std::vector<T>& data) {
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
}

// Function to normalize data between 0 and 1
template <typename T>
void normalizeData(std::vector<T>& data) {
    T minVal = *std::min_element(data.begin(), data.end());
    T maxVal = *std::max_element(data.begin(), data.end());
    T range = maxVal - minVal;
    std::transform(data.begin(), data.end(), data.begin(),
        [minVal, range](T val) { return (val - minVal) / range; });
}

int main() {
    // Create a vector with some duplicate values and missing data
    std::vector<double> values = { 1.2, 2.5, 3.7, 4.1, 2.5, 5.6, -1.0, 6.7, 4.1, 7.8 };

    // Remove duplicates from the vector
    removeDuplicates(values);

    // Handle missing data by removing -1 values
    values.erase(std::remove(values.begin(), values.end(), -1.0), values.end());

    // Normalize the data between 0 and 1
    normalizeData(values);

    // Display the unique values after data cleansing and normalization
    std::cout << "Unique values (after data cleansing and normalization):\n";
    for (const auto& value : values) {
        std::cout << value << std::endl;
    }

    return 0;
}

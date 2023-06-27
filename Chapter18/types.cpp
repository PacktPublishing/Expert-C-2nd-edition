#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    // Numerical Data
    std::vector<double> numericalData = {4.5, 2.3, 1.8, 3.2, 5.1};

    // Calculating the median
    std::sort(numericalData.begin(), numericalData.end());
    size_t size = numericalData.size();
    double median;
    if (size % 2 == 0) {
        median = (numericalData[size / 2 - 1] + numericalData[size / 2]) / 2.0;
    } else {
        median = numericalData[size / 2];
    }

    std::cout << "Numerical Median: " << median << std::endl;

    // Categorical Data
    std::vector<std::string> categoricalData = {"Apple", "Orange", "Banana", "Apple", "Grape"};

    // Counting the frequency of each category
    std::map<std::string, int> categoryCounts;
    for (const auto& category : categoricalData) {
        categoryCounts[category]++;
    }

    // Print the category counts
    std::cout << "Category Counts:" << std::endl;
    for (const auto& pair : categoryCounts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Ordinal Data
    std::vector<int> ordinalData = {2, 1, 3, 2, 2, 1, 3};

    // Calculating the mode (most frequent value) of the ordinal data
    std::map<int, int> ordinalCounts;
    for (const auto& value : ordinalData) {
        ordinalCounts[value]++;
    }

    int mode = 0;
    int maxCount = 0;
    for (const auto& pair : ordinalCounts) {
        if (pair.second > maxCount) {
            mode = pair.first;
            maxCount = pair.second;
        }
    }

    std::cout << "Ordinal Mode: " << mode << std::endl;

    return 0;
}

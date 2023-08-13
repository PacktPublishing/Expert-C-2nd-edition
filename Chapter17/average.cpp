#include <iostream>
#include <vector>

// Function to calculate the average of a vector of numbers
double calculateAverage(const std::vector<double>& data) {
    if(data.size() == 0) {
        return 0.0;
    }
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

int main() {
    // Create a vector of numbers
    std::vector<double> numbers = {1.2, 2.5, 3.7, 4.1, 5.6};

    // Calculate the average using the calculateAverage function
    double average = calculateAverage(numbers);

    // Print the average to the console
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}

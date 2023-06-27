#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Input features (house sizes)
    std::vector<double> houseSizes = { 1000, 1500, 2000, 2500, 3000 };

    // Corresponding housing prices
    std::vector<double> prices = { 300000, 450000, 500000, 600000, 700000 };

    // Create a data file for plotting
    std::ofstream dataFile("data.dat");
    for (size_t i = 0; i < houseSizes.size(); i++) {
        dataFile << houseSizes[i] << " " << prices[i] << std::endl;
    }
    dataFile.close();

    // Generate the gnuplot script for plotting
    std::ofstream scriptFile("script.plt");
    scriptFile << "set xlabel 'House Size (sq. ft.)'" << std::endl;
    scriptFile << "set ylabel 'Price'" << std::endl;
    scriptFile << "plot 'data.dat' with points" << std::endl;
    scriptFile.close();

    // Execute the gnuplot command
    std::string command = "c:\\gnuplot\\bin\\gnuplot script.plt";
    if (std::system(command.c_str()) != 0) {
        std::cerr << "Failed to execute gnuplot command." << std::endl;
        return 1;
    }

    return 0;
}

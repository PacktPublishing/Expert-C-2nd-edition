#include <iostream>
#include <vector>
#include <algorithm>

// Data structure for storing records
struct Record {
    int id;
    std::string name;
    int age;
};

// Function to process records
void processData(const std::vector<Record>& records) {
    // Sort records by age
    std::vector<Record> sortedRecords = records;
    std::sort(sortedRecords.begin(), sortedRecords.end(), [](const Record& a, const Record& b) {
        return a.age < b.age;
    });

    // Print sorted records
    std::cout << "Sorted Records by Age:\n";
    for (const auto& record : sortedRecords) {
        std::cout << "ID: " << record.id << ", Name: " << record.name << ", Age: " << record.age << std::endl;
    }

    // Perform data processing operations
    // ...
}

int main() {
    // Create a sample dataset
    std::vector<Record> records = {
        {1, "John", 35},
        {2, "Alice", 28},
        {3, "Michael", 42},
        {4, "Emily", 32},
        {5, "David", 40}
    };

    // Process the data
    processData(records);

    return 0;
}

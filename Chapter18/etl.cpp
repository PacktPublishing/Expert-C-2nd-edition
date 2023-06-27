#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <sqlite3.h>

// Function to split a string based on a delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to transform the data
std::map<std::string, double> transformData(const std::vector<std::vector<std::string>>& data) {
    std::map<std::string, double> transformedData;
    for (const auto& row : data) {
        std::string customer = row[0];
        double sales = std::stod(row[1]);
        transformedData[customer] += sales;
    }
    return transformedData;
}

// Function to load transformed data into the database
void loadIntoDatabase(const std::map<std::string, double>& transformedData) {
    sqlite3* db;
    sqlite3_open("sales.db", &db);

    std::string createTableQuery = "CREATE TABLE IF NOT EXISTS sales (customer TEXT PRIMARY KEY, total_sales REAL);";
    sqlite3_exec(db, createTableQuery.c_str(), nullptr, nullptr, nullptr);

    std::string insertQuery = "INSERT INTO sales (customer, total_sales) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, insertQuery.c_str(), -1, &stmt, nullptr);

    for (const auto& pair : transformedData) {
        sqlite3_bind_text(stmt, 1, pair.first.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 2, pair.second);
        sqlite3_step(stmt);
        sqlite3_clear_bindings(stmt);
        sqlite3_reset(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    std::ifstream inputFile("data.csv");
    if (!inputFile) {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> row = split(line, ',');
        data.push_back(row);
    }

    inputFile.close();

    std::map<std::string, double> transformedData = transformData(data);

    loadIntoDatabase(transformedData);

    std::cout << "ETL pipeline executed successfully." << std::endl;

    return 0;
}

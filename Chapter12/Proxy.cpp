#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Subject Interface
class StockData {
public:
    virtual ~StockData() {}
    virtual std::vector<std::string> getSymbols() = 0;
    virtual float getPrice(const std::string& symbol) = 0;
};

// Real Subject
class MySQLDatabase : public StockData {
public:
    std::vector<std::string> getSymbols() override {
        // Query the database for the list of symbols here
        std::vector<std::string> symbols = {"AAPL", "MSFT"};
        return symbols;
    }

    float getPrice(const std::string& symbol) override {
        // Query the database for the stock price here
        std::cout << "Retrieving stock price for " << symbol << " from MySQL database" << std::endl;
        float price = 0.0f;
        // ...
        return price;
    }
};

// Proxy
class StockDataProxy : public StockData {
private:
    StockData* realSubject;
    std::unordered_map<std::string, float> cache;

public:
    StockDataProxy(StockData* realSubject) : realSubject(realSubject) {}

    std::vector<std::string> getSymbols() override {
        return realSubject->getSymbols();
    }

    float getPrice(const std::string& symbol) override {
        // Check if the stock price is in the cache
        auto it = cache.find(symbol);
        if (it != cache.end()) {
            std::cout << "Retrieving stock price for " << symbol << " from proxy cache" << std::endl;
            return it->second;
        }

        // If the stock price is not in the cache, forward the request to the real subject
        float price = realSubject->getPrice(symbol);
        cache[symbol] = price;  // Update the proxy cache
        return price;
    }
};

// Client
int main() {
    StockData* stockData = new StockDataProxy(new MySQLDatabase());

    // Retrieve the price of MSFT twice
    std::cout << "Price of MSFT: " << stockData->getPrice("MSFT") << std::endl;
    std::cout << "Price of MSFT: " << stockData->getPrice("MSFT") << std::endl;

    delete stockData;
    return 0;
}

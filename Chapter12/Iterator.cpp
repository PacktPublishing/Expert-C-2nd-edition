#include <iostream>
#include <string>
#include <vector>

class StockPrice {
public:
    virtual ~StockPrice() {}
    virtual float getPrice() = 0;
    virtual std::string getSymbol() = 0;
};

class StockPriceData : public StockPrice {
public:
    StockPriceData(const std::string& symbol, float price) : symbol(symbol), price(price) {}

    float getPrice() override {
        return price;
    }

    std::string getSymbol() override {
        return symbol;
    }

private:
    std::string symbol;
    float price;
};

class StockPriceCollection {
public:
    virtual ~StockPriceCollection() {}
    virtual StockPrice* next() = 0;
    virtual bool hasMore() = 0;
};

class StockPriceList : public StockPriceCollection {
public:
    StockPriceList() {
        // Add some stock prices to the list
        data.emplace_back(new StockPriceData("AAPL", 134.16f));
        data.emplace_back(new StockPriceData("MSFT", 252.46f));
        data.emplace_back(new StockPriceData("GOOG", 2362.01f));
    }

    StockPrice* next() override {
        if (index >= data.size()) {
            return nullptr;
        }
        return data[index++];
    }

    bool hasMore() override {
        return index < data.size();
    }

private:
    std::vector<StockPrice*> data;
    int index = 0;
};

int main() {
    StockPriceCollection* stockPrices = new StockPriceList();

    while (stockPrices->hasMore()) {
        StockPrice* stockPrice = stockPrices->next();
        std::cout << "Price of " << stockPrice->getSymbol() << ": " << stockPrice->getPrice() << std::endl;
    }

    delete stockPrices;
    return 0;
}

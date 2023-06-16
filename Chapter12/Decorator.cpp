#include <iostream>
#include <string>

// Component Interface
class StockPrice {
public:
    virtual ~StockPrice() {}
    virtual float getPrice(const std::string& symbol) = 0;
};

// Concrete Component
class StockPriceData : public StockPrice {
public:
    float getPrice(const std::string& symbol) override {
        // Get the stock price from a data store or web service here
        float price = 0.0f;
        if (symbol == "AAPL") {
            price = 134.16f;
        } else if (symbol == "MSFT") {
            price = 252.46f;
        } else if (symbol == "GOOG") {
            price = 2362.01f;
        }
        return price;
    }
};

// Component Interface
class ExchangeRate {
public:
    virtual ~ExchangeRate() {}
    virtual float getRate(const std::string& fromCurrency, const std::string& toCurrency) = 0;
};

// Concrete Component
class ExchangeRateData : public ExchangeRate {
public:
    float getRate(const std::string& fromCurrency, const std::string& toCurrency) override {
        // Query the external API for the exchange rate here
        std::cout << "Retrieving exchange rate for " << fromCurrency << " to " << toCurrency << " from external API" << std::endl;
        float rate = 1.5f;
        // ...
        return rate;
    }
};

// Decorator
class StockPriceDecorator : public StockPrice {
protected:
    StockPrice* component;

public:
    StockPriceDecorator(StockPrice* component) : component(component) {}

    float getPrice(const std::string& symbol) override {
        return component->getPrice(symbol);
    }
};

// Concrete Decorator
class StockPriceExchangeRateConverter : public StockPriceDecorator {
public:
    StockPriceExchangeRateConverter(StockPrice* component, ExchangeRate* exchangeRate)
        : StockPriceDecorator(component), exchangeRate(exchangeRate) {}

    float getPrice(const std::string& symbol) override {
        float price = component->getPrice(symbol);
        float rate = exchangeRate->getRate("USD", "EUR"); // Convert to EUR
        float convertedPrice = price * rate;
        return convertedPrice;
    }

private:
    ExchangeRate* exchangeRate;
};

int main() {
    StockPrice* stockPrice = new StockPriceExchangeRateConverter(new StockPriceData(), new ExchangeRateData());

    std::cout << "Price of AAPL in EUR: " << stockPrice->getPrice("AAPL") << std::endl;
    std::cout << "Price of MSFT in EUR: " << stockPrice->getPrice("MSFT") << std::endl;

    delete stockPrice;
    return 0;
}

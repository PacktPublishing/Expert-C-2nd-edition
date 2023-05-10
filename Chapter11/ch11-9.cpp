#include <string>
#include <iostream>

class Product {
    private:
        std::string name;
        std::string description;
        double price;
        int inventoryLevel;
    public:
        // Constructor
        Product(std::string name, std::string description, double price, int inventoryLevel)
            : name(name), description(description), price(price), inventoryLevel(inventoryLevel) {}

        // Getters
        std::string getName() {
            return name;
        }
        std::string getDescription() {
            return description;
        }
        double getPrice() {
            return price;
        }
        int getInventoryLevel() {
            return inventoryLevel;
        }
};

class ProductBuilder {
    private:
        std::string name;
        std::string description;
        double price;
        int inventoryLevel;
    public:
        ProductBuilder() {}

        ProductBuilder& setName(std::string name) {
            this->name = name;
            return *this;
        }

        ProductBuilder& setDescription(std::string description) {
            this->description = description;
            return *this;
        }

        ProductBuilder& setPrice(double price) {
            this->price = price;
            return *this;
        }

        ProductBuilder& setInventoryLevel(int inventoryLevel) {
            this->inventoryLevel = inventoryLevel;
            return *this;
        }

        Product build() {
            return Product(name, description, price, inventoryLevel);
        }
};

int main() {
    Product product = ProductBuilder()
        .setName("Samsung TV")
        .setDescription("A 55-inch 4K smart TV from Samsung.")
        .setPrice(899.99)
        .setInventoryLevel(10)
        .build();

    // Use the Product object
    std::cout << "Product name: " << product.getName() << std::endl;
    std::cout << "Product description: " << product.getDescription() << std::endl;
    std::cout << "Product price: $" << product.getPrice() << std::endl;
    std::cout << "Product inventory level: " << product.getInventoryLevel() << std::endl;

    return 0;
}
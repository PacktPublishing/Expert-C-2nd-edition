#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Product;

class Observer {
public:
    virtual void update(Product* product) = 0;
protected:
    static std::vector<Product*> products;
};
std::vector<Product*> Observer::products;

class Product {
    private:
        std::string name;
        std::string description;
        double price;
        int inventoryLevel;
        std::vector<Observer*> observers;
    public:
        // Constructor
        Product(std::string name, std::string description, double price, int inventoryLevel) {
            this->name = name;
            this->description = description;
            this->price = price;
            this->inventoryLevel = inventoryLevel;
        }

        // Getters and setters
        std::string getName() {
            return name;
        }
        void setName(std::string name) {
            this->name = name;
        }
        std::string getDescription() {
            return description;
        }
        void setDescription(std::string description) {
            this->description = description;
        }
        double getPrice() {
            return price;
        }
        void setPrice(double price) {
            this->price = price;
        }
        int getInventoryLevel() {
            return inventoryLevel;
        }
        void setInventoryLevel(int inventoryLevel) {
            this->inventoryLevel = inventoryLevel;
            notify();
        }

        // Observer pattern methods
        void attach(Observer* observer) {
            observers.push_back(observer);
        }
        void detach(Observer* observer) {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }
        void notify() {
            for (auto observer : observers) {
                observer->update(this);
            }
        }
};

class Cart : public Observer {
    private:
        std::vector<Product*> products;
    public:
        void addProduct(Product* product) {
            products.push_back(product);
            product->attach(this);
        }
        void update(Product* product) {
            // Check if the product is in the cart and remove it if inventory level reaches zero
            for (auto it = products.begin(); it != products.end(); it++) {
                if ((*it) == product && product->getInventoryLevel() == 0) {
                    products.erase(it);
                    break;
                }
            }
        }
        size_t size() {
            return products.size();
        }
};

class Checkout : public Observer {
    private:
        double totalPrice;
        std::vector<Product*> products;
    public:
        void update(Product* product) {
            // Recalculate total price when inventory level changes
            totalPrice = 0;
            // Loop through all products in the cart and recalculate the total price
            // This assumes that the cart is already populated with products
            for (auto product : products) {
                totalPrice += product->getPrice();
            }
        }
        void addProduct(Product* product) {
            products.push_back(product);
            product->attach(this);
            update(product);
        }
        double getTotalPrice() {
            return totalPrice;
        }
};

int main() {
    // Create a product with an initial inventory level of 10
    Product product = Product("Samsung TV", "A 55-inch 4K smart TV from Samsung.", 899.99, 10);

    // Create a shopping cart and add the product to the cart
    Cart cart = Cart();
    cart.addProduct(&product);

    // Create a checkout object and add it as an observer of the product
    Checkout checkout = Checkout();
    product.attach(&checkout);

    // Reduce the inventory level of the product and observe the effect on the cart and checkout
    product.setInventoryLevel(9);
    std::cout << "Cart size: " << cart.size() << std::endl;
    std::cout << "Total price: $" << checkout.getTotalPrice() << std::endl;

    // Reduce the inventory level of the product to zero and observe the effect on the cart and checkout
    product.setInventoryLevel(0);
    std::cout << "Cart size: " << cart.size() << std::endl;
    std::cout << "Total price: $" << checkout.getTotalPrice() << std::endl;

    return 0;
}

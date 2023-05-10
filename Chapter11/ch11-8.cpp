#include <string>

class Product {
    private:
        std::string name;
        std::string description;
        double price;
        int inventoryLevel;
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
        }
};

class Electronic : public Product {
    private:
        std::string brand;
        std::string model;
    public:
        // Constructor
        Electronic(std::string name, std::string description, double price, int inventoryLevel, std::string brand, std::string model)
            : Product(name, description, price, inventoryLevel) {
            this->brand = brand;
            this->model = model;
        }

        // Getters and setters
        std::string getBrand() {
            return brand;
        }
        void setBrand(std::string brand) {
            this->brand = brand;
        }
        std::string getModel() {
            return model;
        }
        void setModel(std::string model) {
            this->model = model;
        }
};

class TV : public Electronic {
    private:
        std::string screenType;
        int screenSize;
        std::string resolution;
    public:
        // Constructor
        TV(std::string name, std::string description, double price, int inventoryLevel, std::string brand, std::string model, std::string screenType, int screenSize, std::string resolution)
            : Electronic(name, description, price, inventoryLevel, brand, model) {
            this->screenType = screenType;
            this->screenSize = screenSize;
            this->resolution = resolution;
        }

        // Getters and setters
        std::string getScreenType() {
            return screenType;
        }
        void setScreenType(std::string screenType) {
            this->screenType = screenType;
        }
        int getScreenSize() {
            return screenSize;
        }
        void setScreenSize(int screenSize) {
            this->screenSize = screenSize;
        }
        std::string getResolution() {
            return resolution;
        }
        void setResolution(std::string resolution) {
            this->resolution = resolution;
        }
};


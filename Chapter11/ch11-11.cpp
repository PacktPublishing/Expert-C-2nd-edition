#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Product;

class Review {
public:
    virtual void update(Product* product) = 0;
};

class Product {
private:
    std::string name;
    std::string description;
    double price;
    int inventoryLevel;
    std::vector<Review*> reviews;
    double averageReviewScore;

public:
    // Constructor
    Product(std::string name, std::string description, double price, int inventoryLevel) {
        this->name = name;
        this->description = description;
        this->price = price;
        this->inventoryLevel = inventoryLevel;
        this->averageReviewScore = 0.0;
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
    double getAverageReviewScore() {
        return averageReviewScore;
    }

    // Observer pattern methods
    void attach(Review* review) {
        reviews.push_back(review);
    }
    void detach(Review* review) {
        reviews.erase(std::remove(reviews.begin(), reviews.end(), review), reviews.end());
    }
    void notify() {
        for (auto review : reviews) {
            review->update(this);
        }
    }

    // Review methods
    void addReview(double score) {
        // Update the average review score
        double totalScore = averageReviewScore * reviews.size() + score;
        averageReviewScore = totalScore / (reviews.size() + 1);

        // Notify all reviews of the updated average review score
        notify();
    }
};

class UserReview : public Review {
private:
    std::string username;
    double score;

public:
    UserReview(std::string username, double score) {
        this->username = username;
        this->score = score;
    }

    void update(Product* product) {
        // Update the score of the user review
        score = product->getAverageReviewScore();

        // Print the updated score
        std::cout << "User " << username << " updated review score for product " << product->getName() << std::endl;
    }
};

int main() {
    // Create a new product
    Product product("Example Product", "This is an example product", 9.99, 100);

    // Create two user reviews and attach them to the product
    UserReview userReview1("John", 4.5);
    product.attach(&userReview1);

    UserReview userReview2("Mary", 3.0);
    product.attach(&userReview2);

    // Add a new user review
    product.addReview(4.0);

    // Detach one of the user reviews
    product.detach(&userReview2);

    // Add another user review
    product.addReview(5.0);

    // Print the final average review score of the product
    std::cout << "Final average review score for " << product.getName() << ": " << product.getAverageReviewScore() << std::endl;

    return 0;
}
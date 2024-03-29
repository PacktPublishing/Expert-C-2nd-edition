#include<iostream>
#include<string>
class Product {
public:
  Product() = default; // default constructor
  Product(const Product&); // copy constructor
  Product(Product&&); // move constructor

  Product& operator=(const Product&) = default;
  Product& operator=(Product&&) = default;
  // destructor is not declared, should be generated by the compiler
public:
  void set_name(const std::string& name) { name_ = name; }
	std::string name() const { return name_; }

	void set_price(double price) { price_ = price; }
	double price() const { return price_; }

	void set_rating(int rating) { rating_ = rating; }
	int rating() const { return rating_; }

	void set_available(bool available) { available_ = available; }
	bool available() const { return available_; }

private:
  std::string name_;
  double price_;
  int rating_;
  bool available_;
};

std::ostream& operator<<(std::ostream& os, const Product& product) {
	os << product.name() << " (Price: " << product.price() << ", Rating: " << product.rating() << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Product& product) {
	std::string name;
	double price;
	int rating;
	bool available;

	// Read input from stream and set the product properties accordingly
	is >> name >> price >> rating >> available;
	product.set_name(name);
	product.set_price(price);
	product.set_rating(rating);
	product.set_available(available);

	return is;
}

void create_apple(Product& apple) {
	apple.set_name("Red apple");
	apple.set_price(0.2);
	apple.set_rating(5);
	apple.set_available(true);
}

int main() {
	Product red_apple;
	create_apple(red_apple);

	Product book;
	create_apple(book); // Assuming you want to create a book this way, not using 'create_apple' function for a book.

	// Print book and apple details
	std::cout << "I'm reading " << book << " and I bought an apple for " << red_apple << std::endl;

	// Destructor calls are not required as they will be automatically handled by the compiler.
}

class Product {
public:
  Product() = default; // default constructor
  Product(const Product&); // copy constructor
  Product(Product&&); // move constructor

  Product& operator=(const Product&) = default;
  Product& operator=(Product&&) = default;
  // destructor is not declared, should be generated by the compiler
public:
  void set_name(const std::string&);
  std::string name() const;
  void set_availability(bool);
  bool available() const;
  // code omitted for brevity

private:
  std::string name_;
  double price_;
  int rating_;
  bool available_;
};

std::ostream& operator<<(std::ostream&, const Product&);
std::istream& operator>>(std::istream&, Product&);

Product create_apple() {
  Product apple;
  apple.set_name("Red apple");
  apple.set_price("0.2");
  apple.set_rating(5);
  apple.set_available(true);
  return apple;
}

int main() {
  Product red_apple = create_apple();
  Product book;
  Product* ptr = &book;
  ptr->set_name("Alice in Wonderland");
  ptr->set_price(6.80);
  std::cout << "I'm reading " << book.name() 
            << " and I bought an apple for " << red_apple.price()
            << std::endl;
}

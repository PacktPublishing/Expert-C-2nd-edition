#include <iostream>
#include <string>

class Product {
public:
  Product() = default;
  // ...

  // Add members to the Product class
  std::string name;
  int rating;
  double price;
};

static Product global_prod;

Product* foo() {
  Product* heap_prod = new Product();
  heap_prod->name = "Sample";
  return heap_prod;
}

int main() {
  Product stack_prod;
  if (true) {
        Product tmp;
        tmp.rating = 3;
    }
    stack_prod.price = 4.2;
    Product* returned_product = foo();

    // Printing the details of the returned product
    std::cout << "Name: " << returned_product->name << std::endl;
    std::cout << "Rating: " << returned_product->rating << std::endl;
    std::cout << "Price: " << returned_product->price << std::endl;

    delete returned_product;

    return 0;
}

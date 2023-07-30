#include <functional>
#include <iostream>

void print_it(int a) {
  std::cout << a;
}

std::function<void(int)> function_object = print_it;
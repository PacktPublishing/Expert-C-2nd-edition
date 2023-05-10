#include <thread> 
#include <iostream>
#include <mutex>

int counter = 0;

std::mutex m;
void foo(){
  std::lock_guard g{m};
  counter++; 
}

int main() {
  std::thread A { foo };
  std::thread B { foo };
  std::thread C {[] { foo(); } };
  std::thread D {[] {
    for (int i = 0; i < 10; ++i) {
      foo();
    }
  }};
  std::cout << "Count: " << counter << std::endl;
}

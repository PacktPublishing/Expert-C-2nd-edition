#include <iostream>

struct BeforeMain { 
    BeforeMain() { 
        std::cout << "Constructing BeforeMain" << std::endl; 
    }  

};

BeforeMain b;

int main() {

    std::cout << "Calling main()" << std::endl; 

    return 0;  
}
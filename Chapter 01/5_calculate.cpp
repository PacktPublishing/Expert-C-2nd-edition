#include <iostream>

int sum(int n, int m) { return n + m; }

int max(int x, int y) {  
    int res = x > y ? x : y; 
    return res;  
}  

int calculate(int a, int b) {
    return sum(a, b) + max(a, b);
}  

int main() { 
    auto result = calculate(11, 22); std::cout << result; // outputs 55  
} 
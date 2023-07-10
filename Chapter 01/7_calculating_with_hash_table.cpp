import <iostream>;
import <unordered_map>; 

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) { return (b == 0) ? 0 : a / b; }

int main() {  

    std::unordered_map<char, int (*)(int, int)> operations;

    operations['+'] = &add;
    operations['-'] = &subtract;
    operations['*'] = &multiply;
    operations['/'] = &divide;

    // read the input 
    char op;
    int num1, num2;
    std::cin >> num1 >> num2 >> op;

    // perform the operation, as follows
    operations[op](num1, num2);
}
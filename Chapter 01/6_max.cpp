#include <iostream>

int max(int a, int b) {
    int max;
    if (a > b) {
        // the if block
        max = a;
    } else {
        // the else block
        max = b;
    }
    return max;
}

int main()
{
    std::cout << max(1, 6);
}

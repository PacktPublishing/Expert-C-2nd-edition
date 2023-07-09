#include <iostream>
#include <list>

void print(const std::list<int>& list)
{
    for (const auto &i : list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> l1 = { 0, 1, 2, 5, 7, 12 };
    std::list<int> l2 = { -3, 6, 8 };
    l1.merge(l2);
    print(l1); // prints –3 0 1 2 5 6 7 8 12
    print(l2); // prints nothing because l2 is empty

    std::list<int> l3 = { 4, 9, 15, 23 };
    l1.splice(l1.begin(), l3);
    print(l1); // prints 4 9 15 23 –3 0 1 2 5 6 7 8 12
    print(l3); // prints nothing because l3 is also empty
}
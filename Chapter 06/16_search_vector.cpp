#include <iostream>
#include <vector>

template <typename T>
int search(const std::vector<T>& vec, const T& item)
{
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (vec[ix] == item) {
            return ix;
        }
    }
    return -1; // not found
}

int main()
{
    std::vector<int> intVector = { 1, 2, 3, 4, 5 };
    int itemToFind = 3;
    int index = search(intVector, itemToFind);
    if (index != -1) {
        std::cout << "Item found at index: " << index << std::endl;
    }
    else {
        std::cout << "Item not found." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

template <typename Iter, typename T>
int search(Iter first, Iter last, const T& elem)
{
    for (std::size_t count = 0; first != last; first++, ++count)
    {
        if (*first == elem)
            return static_cast<int>(count);
    }
    return -1;
}

int main()
{
    std::vector<int> vec = { 10, 20, 30, 40, 50 };

    int searchValue = 30;
    int index = search(vec.begin(), vec.end(), searchValue);

    if (index != -1)
    {
        std::cout << "Found " << searchValue << " at index " << index << std::endl;
    }
    else
    {
        std::cout << "Value " << searchValue << " not found in the vector." << std::endl;
    }

    return 0;
}

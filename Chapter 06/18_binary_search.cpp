#include <iostream>
#include <vector>

template <typename T>
int binsearch(const std::vector<T>& vec, const T& item, int start, int end)
{
    if (start > end) return -1;
    int mid = start + (end - start) / 2;
    if (vec[mid] == item) {
        return mid; // found
    }
    if (vec[mid] > item) {
        return binsearch(vec, item, start, mid - 1);
    }
    return binsearch(vec, item, mid + 1, end);
}

int main()
{
    std::vector<int> sortedVec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int searchItem = 5;
    int result = binsearch(sortedVec, searchItem, 0, sortedVec.size() - 1);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << "Element not found." << std::endl;
    }
    return 0;
}

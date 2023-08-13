#include <iostream> 
#include <iterator> 
#include <vector> 
#include <type_traits>

template <typename IterType>
int dist(IterType start, IterType end)
{
    if constexpr (std::is_same_v<typename std::iterator_traits<IterType>::iterator_category, std::random_access_iterator_tag>)
        return end - start;
    else
    {
        int count = 0;
        while (start != end)
        {
            ++count;
            ++start;
        }
        return count;
    }
}

int main() {
    std::vector<int> vec{ 3, 6, 8, 9, 12 };
    std::cout << dist(vec.begin(), vec.end());
    return 0;
}

#include <iostream> 
#include <iterator> 
#include <vector> 
  
template <typename IterType> 
int dist(IterType start, IterType end) 
{ 
    if constexpr(std::random_access_iterator<IterType>) return end - start; 
    else 
    { 
        int count = 0; 
        while(start != end) 
        { 
            ++count; 
            ++start; 
        } 
        return count; 
    } 
} 

int main(){ 
    std::vector<int> vec {3,6,8,9,12}; 
    std::cout << dist(vec.begin(),vec.end()); 
} 
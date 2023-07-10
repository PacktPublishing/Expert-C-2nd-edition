#include <iostream> 
#include <queue>

template <typename T> 
void print(T container) 
{ 
    while(!container.empty()) 
    { 
        std::cout << container.top() << " "; 
        container.pop(); 
    } 
    std::cout << std::endl; 
} 

int main() 
{ 
    std::vector vec{2, 6, 3, 0, 12, -7}; 
    std::priority_queue<int> p1; 
    for(int i : vec) 
    { 
        p1.push(i); 
    } 
    print(p1); // prints 12 6 3 2 0 –7 since the default underlying 	 
               // data structure for a priority_queue is a max heap 
    std::priority_queue<int,std::vector<int>, std::greater<int>> p2; 
               // by passing std::greater<int> we turn our priority_queue to a  
               // min heap 
    for(int i : vec) 
    { 
        p2.push(i); 
    } 
    print(p2); // prints –7 0 2 3 6 12 
} 
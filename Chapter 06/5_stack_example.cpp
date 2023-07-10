#include <iostream> 
#include <stack> 

int main() 
{ 
    std::stack<int> st; 
    st.push(1); 
    st.push(2); 
    st.push(3); 

    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }

    //after the cycle it is printed 1 2 3 
    std::cout << st.top(); // crashes application as we try to remove a  
                        // nonexistent item 
} 
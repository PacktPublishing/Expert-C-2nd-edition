template <typename T> 
struct Node { 
    T m_data; 
    Node<T>* npx; // traditionally called npx meaning next,   
                  // previous, XOR 
}; 
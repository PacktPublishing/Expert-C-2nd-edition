template <typename T>
class XOR_list 
{ 
public: 
    XOR_list() : head(nullptr){} //the head should always be nullptr at first 
private: 
    template <typename> 
    struct Node { 
        T m_data; 
        Node<T>* npx; 
    }; 
private: 
    Node<T>* head; 
}; 
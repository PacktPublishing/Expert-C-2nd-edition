#include <cinttypes> 
#include <iostream>
#include<memory>
template <typename T> 
class XOR_list 
{ 
private: 
    template <typename> 
    struct Node { 
        T m_data; 
        std::shared_ptr<Node<T>> npx; 
    }; 

    // note that the function cannot be called xor because it is a keyword // and can be used instead of symbol ^ 
    Node<T>* Xor(Node<T>* addr1, Node<T>* addr2)    { 
        return reinterpret_cast<Node<T>*>( 
        reinterpret_cast<uintptr_t>(addr1) 
        ^ reinterpret_cast<uintptr_t>(addr2)); 
    } 
public: 
    XOR_list() : head(NULL) {} 
    void insert(T data) 
    { 
        std::shared_ptr<Node<T>> new_node = new Node<T>(); 
        new_node->m_data = data; 
        new_node->npx = head; 
        if (head != nullptr)  
        { 
            head->npx = Xor(new_node, head->npx); 
        } 
        head = new_node; 
    } 
    void print() 
    { 
        std::shared_ptr<Node<T>> current_node = head; 
        std::shared_ptr<Node<T>> previous_node = nullptr; 
        std::shared_ptr<Node<T>> next_node; 
        std::cout<<"{"; 
        while (current_node != NULL)  
        { 
            std::cout << current_node->m_data; 
            if (current_node->npx != previous_node) { 
                std::cout << ","; 
            } 
            else 
            { 
                std::cout << "}"; 
            } 
            next_node = Xor(previous_node, current_node->npx); 
            previous_node = current_node; 
            current_node = next_node; 
        } 
    } 
private:  
    std::shared_ptr<Node<T>> head; 
};
template <class valueType> 
class TwoThreeTree { 
private: 
    template <typename> 
    struct node { 
        valueType _small_value; 
        valueType _large_value;  
        node <valueType>* _left_node; 
        node <valueType>* _mid_node;  
        node <valueType>* _right_node; 
        node <valueType>* _parent_node; 
        bool isLeaf() const; 
        bool isTwoNode() const; 
        bool isThreeNode() const; 
    }; 
private:  
    node <valueType>* _root; 
public:  
    // code omitted for brevity 
    void insert(valueType item); 
    void delete_item(valueType item); 
    bool find(valueType item) const; 
}; 
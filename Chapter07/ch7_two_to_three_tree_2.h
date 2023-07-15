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
bool isLeaf() const 
{ 
return ((_left_node == nullptr) && (_right_node == nullptr)); 
} 
bool isTwoNode() const 
{ 
return (_mid_node == nullptr); 
} 
bool isThreeNode() const 
{
return (_mid_node != nullptr); 
} 
}; 
private:  
node <valueType>* _root; 
private: 
//code omitted for brevity  
bool innerFind(node<valueType>* , const valueType& ) const; 
public:  
// code omitted for brevity 
bool find(const valueType& target) const; 
}; 
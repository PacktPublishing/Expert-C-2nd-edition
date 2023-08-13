#include "ch7_two_to_three_tree_2.h"

template <class valueType>
bool TwoThreeTree<valueType>::find(const valueType& target) const
{
    return innerFind(_root, target);
}

template <class valueType> 
bool TwoThreeTree<valueType>::innerFind(node<valueType>* root, const valueType& target) const 
{ 
    if (target == root->_small_value || target == root->_large_value) 
    { 
        return true; 
    } 
    else if (root->isLeaf()) 
    { 
        return false; 
    }
    else if (root->isTwoNode()) 
    { 
        if (target < root->_small_value) 
        { 
            return innerFind(root->_left_node, target); 
        } 
        else 
        { 
            return  innerFind (root->_right_node, target); 
        } 
    } 
    else if (root->isThreeNode()) 
    { 
        if (target < root->_small_value) 
        { 
            return innerFind(root->_left_node, target); 
        } 
        else if (target < root->_large_value) 
        { 
            return innerFind(root->_mid_node, target); 
        } 
        else if (target > root->_large_value) 
        { 
            return innerFind(root->_right_node, target); 
        } 
    }
    return false;
}

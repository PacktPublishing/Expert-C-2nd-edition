#include <iostream> 
#include <vector>  

class ItalianFood { 
public: 
    virtual ~ItalianFood() {} 
    virtual int price() const = 0; 
}; 

  
class Pizza : public ItalianFood { 
public: 
    int price() const override { 
        return 8; 
    } 
}; 

  
class Topping : public ItalianFood { 
protected: 
    ItalianFood* m_component; 
public: 
    Topping(ItalianFood* component) : m_component(component) {} 
    int price() const override { 
        return this->m_component->price(); 
    } 
}; 


class Pepperoni : public Topping { 
public: 
    Pepperoni(ItalianFood* component) : Topping(component) {} 
    int price() const override { 
        return 2 + Topping::price(); 
    } 
}; 


class Ham : public Topping { 
public: 
    Ham(ItalianFood* component) : Topping(component) {} 
    int price() const override { 
        return 3 + Topping::price(); 
    } 
}; 


//helper function to display the total price  
void displayTotal(ItalianFood *component) {  
    std::cout << "The total is " << component->price() << '$'; 
}  

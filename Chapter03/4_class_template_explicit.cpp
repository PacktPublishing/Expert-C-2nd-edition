#include <iostream>

//explicit instantiation declaration means we do not want to 
//instantiate such type in a template, you can set this flag 
//to 1 to save some compile time
#define USE_EXPLICIT_INST_DECLARATION_4_INT 0

using namespace std;
template <typename T>
struct A {
	A(T init=0) : val(init) {}
	virtual T foo();
	T val;
};

template <class T> //T in this line is template parameter
T A<T>::foo() {    //the 1st T refers to function return type, the T in <> specifies that this
				   //function's template parameter is also the class template parameter
	return val;
}

//explicit instantiation definitation, it forces instantiation of struct A for <doubel> type
template struct A<double>;

#if USE_EXPLICIT_INST_DECLARATION_4_INT
	//explicit instantiation decalration of struct A for <int> type
	//if we do not want to use A<int>, the explicit instantiation decalration
	//could save some compile time for real world big projects
	extern template struct A<int>;
#else
	//explicit instantiation definitation for <int> 
	template struct A<int>;
#endif


int main(void) {
	A<double> x(5.1);

#if !USE_EXPLICIT_INST_DECLARATION_4_INT
	A<int> y(5);
	cout << "fD="<<x.foo() <<", fI="<< y.foo() << endl;
#else
	cout << "fD="<<x.foo() << endl;
#endif

	return 0;
}
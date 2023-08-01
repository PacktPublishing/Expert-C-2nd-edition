#ifndef __CH4_5_H__
#define __CH4_5_H__

#include <iostream>

template <class T>
class X {
public:
	X() = default;
	~X() = default;
	void f() { std::cout << "X::f()" << std::endl; };
	void g() { char blabla; };
};

#endif
#ifndef __CH3_5_H__
#define __CH3_5_H__

#include <iostream>

template <class T>
class X {
public:
    X() = default;
    ~X() = default;
    void f() { std::cout << "X::f()" << endl; };
    void g() { std::cout << "X::g()" << endl; };
    void h() { std::cout << "X::h()" << std::endl; };
};

#endif

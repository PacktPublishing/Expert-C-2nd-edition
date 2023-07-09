#ifndef __CH3_5_H__
#define __CH3_5_H__

#include <iostream>

using namespace std;

template <class T>
class X {
public:
    X() = default;
    ~X() = default;
    void f() { cout << "X::f()" << endl; };
    void g() { cout << "X::g()" << endl; };
};

#endif
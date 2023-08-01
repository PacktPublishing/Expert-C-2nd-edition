#include <iostream>
#include<string>

//Part A: define a primary template
template <typename T>
    T app_max (T a, T b) {
    return (a>b?a:b);
}

//Part B: explicit specialization for T=std::string
template <>
    std::string app_max (std::string a, std::string b){
    return (a[0]>b[0]?a:b);
}

//part C: test function
using namespace std;

int main(){
    string a = "abc", b="efg";
    cout << app_max(5, 6) << endl;   //line A
    cout << app_max(a, b) << endl;   //line B
    //question: what's the output if un-comment lines C and D?
    //char *x = "abc", *y="efg";     //Line C
    //cout << app_max(x, y) << endl; //line D
    return 0;
}
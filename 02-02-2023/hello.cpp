#include <iostream>
using namespace std;

class A
{  
    public:
        int o = 3;
};

A change_a(A a)
{
    a.o = 4;
    return a;
}

int main()
{
    A u;
    cout << u.o << '\n';
    cout << change_a(u).o << '\n';
    cout << u.o << '\n';
    return 0;
}
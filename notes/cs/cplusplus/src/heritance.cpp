#include <iostream>
using namespace std;

class Top {
public:
    int a;
};

class Left : virtual public Top {
public:
    int l;
};

class Right : virtual public Top {
public:
    int r;
};

class Bottom : public Left, public Right {
public:
    int b;
};

int main(){
    Bottom *b = new Bottom();
    cout << b << endl;
    cout << &b->a<<endl;
    cout << &b->l<<endl;
    cout << &b->r<<endl;
    cout << &b->b<<endl;

    cout << endl;
    Left *l = new Left();
    cout << &l->a <<endl;
    cout << &l->l <<endl;
    cout << endl;
    Right *r = new Right();
    cout << &r->a <<endl;
    cout << &r->r <<endl;
    cout << endl;

    Left *l2 = b;
    cout << l2 << endl;
    cout << b << endl;

    Right *r2 = b;
    cout << r2 << endl;
    cout << b << endl;

    if (r2 == b) cout << "shit\n";
    return 0;
}

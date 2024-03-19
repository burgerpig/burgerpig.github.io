#include <iostream>

using namespace std;

class O {
public:
    int o;
    O():o(999){}
    virtual void funo(){
        cout << "O funo()\n";
    }
    virtual ~O(){}
};

class A : public virtual O{
public:
    int a;
    A() : a(123) {}
    virtual void funa() {
        cout << "A::funa()\n";
    }
    virtual ~A() {
        cout << "~A()\n";
    }
};

class B : public virtual O{
public:
    int i;
    B() : i(234) {};
    virtual void funb() {
        cout << "B funb\n";
    }
    virtual ~B() {
        cout << "~B()\n";
    }
};

class D:public B{ 
public:
    int j;

    D(){};

    virtual void fund2(){
        cout << "D fund2\n";
    }

    virtual void fund(){
        cout << "D fund\n";
    }
    virtual void funb(){
        cout << "D funb\n";
    }
    virtual ~D() {cout << "~D()\n";}

};

class G: public D {
public:
    int k;
    G() {};

    void fund(){
        cout << "G fund\n";
    }

    ~G(){
        cout << "~G()\n";
    }
};

class H : public A, public B {
public:
    int h;
    H():h(345){}

    void funa(){
        cout << "H funa()\n";
    }

    void funb() {
        cout << "H funb()\n";
    }

    virtual void funh() {
        cout << "H funh()\n";
    }

    virtual ~H(){
        cout << "~H()" << endl;
    }
};

typedef void (*f_t)(void);

void test1(){

    // B->D->G
    //
    // A,B->H
    
    B *pb = new B();
    D *pd = new D();
    G *pg = new G();

    cout << "pb    " << pb << endl;
    cout << "&B::i " << &pb->i << endl;
    cout << "*pb   " << *(void **)pb<<endl;

    cout << endl;

    cout << "pd    " << pd << endl;
    cout << "&D::i " << &pd->i << endl;
    cout << "&D::j " << &pd->j << endl;
    cout << "*pd   " << *(void **)pd << endl;

    cout << endl;

    cout << "pg    " << pg << endl;
    cout << "&G::i " << &pg->i << endl;
    cout << "&G::j " << &pg->j << endl;
    cout << "&G::k " << &pg->j << endl;
    cout << "*pg   " << *(void **)pg << endl;

    cout << endl;

    cout << "D" << endl;
    void **vtab = (void **)(*(void **)pd);
    cout << "call pd vtab[0]:\n";
    f_t fu = (f_t)vtab[0];
    fu();

    cout << "call pd vtab[1]:\n";
    fu = (f_t)vtab[1];
    fu();

    cout << "call pd vtab[3]:\n";
    fu = (f_t)vtab[3];
    fu();

    cout << "call pd vtab[4]:\n";
    fu = (f_t)vtab[4];
    fu();

    cout << endl;
    cout << "G"<< endl;
    cout << endl;

    vtab = (void **)(*(void **)pg);
    cout << "call pg vtab[0]:\n";
    fu = (f_t)vtab[0];
    fu();
    cout << "call pg vtab[1]:\n";
    fu = (f_t)vtab[1];
    fu();
    cout << "call pg vtab[3]:\n";
    fu = (f_t)vtab[3];
    fu();
    cout << "call pg vtab[4]:\n";
    fu = (f_t)vtab[4];
    fu();
    cout << "end" << endl;

}

// test for multiple inheritance
void test2()
{
    H *ph = new H();
    cout << "ph    " << ph << endl;
    cout << "&H::o " << &ph->o << endl;
    cout << "&H::a " << &ph->a << endl;
    cout << "&H::i " << &ph->i << endl;
    cout << "&H::h " << &ph->h << endl;
    cout << "*ph   " << *(void **)ph << endl;
    cout << "*ph2  " << *((void **)ph+2) << endl;

    cout << endl;

    void **vtab = (void **)(*(void **)ph);
    cout << "call ph vtab[0]:\n";
    f_t fu = (f_t)vtab[0];
    cout << vtab[0]<<endl;
    fu();

    //cout << "call ph vtab[1]:\n";
    //fu = (f_t)vtab[2];
    //fu();

    cout << "call ph vtab[3]:\n";
    fu = (f_t)vtab[3];
    fu();

    cout << "call ph vtab[4]:\n";
    fu = (f_t)vtab[4];
    fu();
    cout << vtab[4]<<endl;

    cout << endl;
    cout << "v_ptr 2" << endl;

    void **vtab2 = (void **)(*((void **)ph + 2));
    cout << "call ph vtab[0]:\n";
    fu = (f_t)vtab2[0];
    cout << vtab2[0]<<endl;
    fu();

    //cout << "call ph vtab[2]:\n";
    //fu = (f_t)vtab2[2];
    //fu();

    cout << "ending\n";

}


int main(){

//    test1();
    test2();
    return 0;
}

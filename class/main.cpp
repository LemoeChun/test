#include <iostream>
#include <ostream>
#include <string>

using std::string;
using std::cout;
using namespace std;
class A {
public:
    int a;
    virtual string name() = 0;
    virtual ~A() = default; 
};
class B : public A{
public:
    int a =10;
    string name() override {
        return "Hello, world";
    }
};

int main(){
    B b;
    cout << b.name()  << endl;
    cout << b.a << endl;
}


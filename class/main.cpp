#include <functional>
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
    virtual void print(string& msg);

};
class B : public A{
public:
    int a =10;
    string name() override {
        return "Hello, world";
    }
    void print(string& msg) override{
        cout << msg << endl;
    }
};
int main(){
    B b;
    const function<void(string&)> _print = &b.print;
    cout << b.name()  << endl;
    cout << b.a << endl;
}


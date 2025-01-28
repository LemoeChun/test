#include <string>
#include <iostream>

using namespace std;
int main()
{

    string str = "Hello";
    const char* chr = str.data();
    cout << chr << endl;
}

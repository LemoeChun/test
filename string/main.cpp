#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <print>
#include <vector>

using std::string;
using std::println;
int main(){

    string a = ">hi ni hao";
    println("a[0]:{} \n a[1]: {}",a[0],a[1]);
    if (a.at(0)=='>'){
        a.erase(0,1);
        println("a.erase(0): {}",a);
        std::vector<string> b;
        std::istringstream c;
        c.str(a);
        for (string line;std::getline(c,line,' ');){
            b.push_back(line);
        }
        for (auto i : b){ std::cout << i << "\n"; }

        string::size_type n;
        n = a.find(' ');
        std::cout << "在位置" << n << "找到 \' \'， substr(" << n+1 << ") =" << a.substr(n+1) << std::endl;
    }

}

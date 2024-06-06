#include <cstdlib>
#include <iostream>
#include <ostream>
int main(){
    int result = std::system("g++ std-system.cpp");
    std::cout << result << std::endl;
}

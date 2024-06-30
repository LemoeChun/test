#include <cstdlib>
#include <iostream>
#include <ostream>
int main(const int argc, const char** argv){
    int result = std::system(argv[1]);
    std::cout << "result = "<< result << std::endl;
}

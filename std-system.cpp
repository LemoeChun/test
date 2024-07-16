#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <ostream>
int main(const int argc, const char** argv){
    std::filesystem::current_path(std::filesystem::path(".."));
    int result = std::system(argv[1]);
    std::cout << "result = "<< result << std::endl;
}

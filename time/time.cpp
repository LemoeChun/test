#include <chrono>
#include <ctime>
#include <boost/filesystem.hpp>
#include <iostream>
#include <ostream>

int main(const int agrc, const char** argv){
    
    auto path = boost::filesystem::path(argv[1]);
    std::time_t time = boost::filesystem::last_write_time(path);
    std::cout << time << std::endl;
}

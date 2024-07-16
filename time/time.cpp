#include <chrono>
#include <ctime>
#include <boost/filesystem.hpp>
#include <iostream>
#include <ostream>
// #include <leveldb/>

int main(){
    
    auto path = boost::filesystem::path("time.cpp");
    std::time_t time = boost::filesystem::last_write_time(path);
    std::cout << time << std::endl;
}

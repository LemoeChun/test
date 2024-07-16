#include <boost/process.hpp>
#include <boost/process/detail/child_decl.hpp>
#include <boost/process/io.hpp>
#include <boost/process/pipe.hpp>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <filesystem>

namespace process=boost::process;

int main(const int argc,const char* argv[]){
//    std::vector<std::string> command;
    std::string command;
    std::vector<std::string> args(argv + 1, argv + argc);
    for (std::string a : args){
        command += ' ' + a;
//        std::cout << command <<std::endl;
//        << sizeof(argv[i]) << std::endl;
//        command.push_back(argv[i]);
    }
//    std::cout << command << std::endl;
    std::filesystem::current_path(std::filesystem::path(".."));
    boost::process::ipstream pipe_stream;
    boost::process::child cmd(command, boost::process::std_out > pipe_stream);

    std::string line;

    while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
    std::cerr << line << std::endl;

    cmd.wait();

}

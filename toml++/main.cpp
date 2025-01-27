#include <iostream>
#include <iterator>
#include <ostream>
#include <toml++/toml.hpp>

auto main(int argc,const char** argv) -> int
{
try{
    toml::table config = toml::parse_file(argv[1]);
    std::cout<<config<<std::endl;
} catch (const toml::parse_error& err)
    {
        std::cerr<< err << std::endl;
    }

}

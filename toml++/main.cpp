#include <iostream>
#include <iterator>
#include <optional>
#include <ostream>
#include <toml++/toml.hpp>

auto main(int argc,const char** argv) -> int
{
try{
    toml::table config = toml::parse_file(argv[1]);
    std::cout<<config<<std::endl;
    std::optional<std::string> token = config["bot"]["token"].value<std::string>();
    std::cout << "token:" << *token<< std::endl;
} catch (const toml::parse_error& err)
    {
        std::cerr<< err << std::endl;
    }

}

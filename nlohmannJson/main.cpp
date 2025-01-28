#include <fstream>
#include <nlohmann/json.hpp>
#include <print>
#include <string>

using nlohmann::json;
using std::string;
int main(){
    std::ifstream f("config.json");
    auto j = json::parse(f);
    std::string a = j["Name"];
    std::println("{}",a);
    // std::println("{}",j["Name"]); Error,说明不能直接转到string给println用
    std::println("{}",string(j["Name"]));
    std::println("{}",j["Name"].get<std::string>());
    string b = j["Name"].get<std::string>();
    println("{}",b);
}

#include <fstream>
#include <ostream>
#include <string>
#include <yaml-cpp/yaml.h>
#include <print>

// using YAML;


int main(){
    auto config = YAML::LoadFile("config.yaml");
    std::string name = config["Cat"]["name"].as<std::string>();
    std::print("{}{}",name,"\n");
    config["Cat"]["name"]= "Neko";
    auto file = std::ofstream("config.yaml");
    file << config;
}

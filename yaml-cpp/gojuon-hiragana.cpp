#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/parse.h"
#include <print>
#include <string>
#include <yaml-cpp/yaml.h>

int main(const int argc, const char** argv){
    YAML::Node node = YAML::LoadFile("gojuon-hiragana.yaml");
    for(auto it = node["map"].begin();it != node["map"].end(); it++){
        std::print(" {} 的罗马音为 {} \n",it -> first.as<std::string>(),it -> second.as<std::string>());
    };
    std::print("gojuon-hiragana的大小为:{}",std::to_string(node["map"].size()));
//    auto name = node["map"].begin() -> first;
//    auto value = node["map"].begin() -> second;

}

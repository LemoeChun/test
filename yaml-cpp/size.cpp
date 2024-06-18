#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

// using YAML;


int main(int argc,char* agrv[]){
    if (argc != 2){
    return -1;
    }
    auto config = YAML::LoadFile(agrv[1]);
    std::cout<< agrv[1] << "的大小为：" << config.size() << std::endl;
}

#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/parse.h"
#include <yaml-cpp/yaml.h>

int main(){
    YAML::Node node = YAML::LoadFile("gojuon-hiragana.yaml");
}

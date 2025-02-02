// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
// Copyright Antony Polukhin, 2015-2025.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

//#include "b2_workarounds.hpp" // contains dll_test::replace_with_full_path

//[callplugcpp_tutorial1
#include <algorithm>
#include <boost/dll/import.hpp> // for import_alias
#include <boost/filesystem.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <map>

#include "my_plugin_api.hpp"

namespace dll = boost::dll;
namespace fs = boost::filesystem;

using apiPtr = boost::shared_ptr<my_plugin_api>;
void loadPlugin(std::map<std::string,apiPtr>& plugins,fs::path path){
    auto plugin = boost::dll::import_symbol<my_plugin_api>(path,"plugin",dll::load_mode::append_decorations);
    plugins[plugin->name()] = std::move(plugin);
    };
int main(int argc, char* argv[]) {
    std::map<std::string,apiPtr> plugins;
    fs::path plugins_dir = "plugins";
    for (auto entry : fs::directory_iterator(plugins_dir)){
        if(fs::is_regular_file(entry)){
            loadPlugin(plugins,entry);
            }
        std::cout << "path:" <<entry<< std::endl;
        }
    for (const auto& [key,value]: plugins){
        std::cout << key << std::endl;
    }
    std::cout << "dll::load_mode::append_decorations:" << dll::load_mode::append_decorations << std::endl;

    std::cout << "plugin->calculate(1.5, 1.5) call:  " << plugins["sum"]->calculate(1.5, 1.5) << std::endl;
}
//]

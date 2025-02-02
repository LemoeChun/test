// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
// Copyright Antony Polukhin, 2015-2025.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>


//[plugcpp_my_plugin_sum
#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT
#include "my_plugin_api.hpp"


class power final: public my_plugin_api {
public:
    power() {
        std::cout << "Constructing my_plugin_sum" << std::endl;
    }

    std::string name() const override {
        return "power";
    }

    float calculate(float x, float y) override {
        for(int i = 0;i <=y;i++){
            x*=x;
        }
        return x * y;
    }
   
    ~power() {
        std::cout << "Destructing my_plugin_sum ;o)" << std::endl;
    }
};

// Exporting `my_namespace::plugin` variable with name `plugin`
extern "C" BOOST_SYMBOL_EXPORT power plugin;
power plugin;



//]

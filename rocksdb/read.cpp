#include <string>
#include <vector>
#include <iostream>
#include <rocksdb/db.h>
#include <ostream>

namespace leveldb = rocksdb;
leveldb::DB* db;
leveldb::Options options;

int main(const int argc,char** argv){

    if(argc < 2){
        std::cout << "Usage: ./本程式 Key" << std::endl;
        return -1;
    }

    std::vector<std::string> args(argv + 1, argv + argc);

    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

    if(!status.ok()){
        std::cerr << "Unable to open/create db ./test.db" << std::endl;
        return -1;
    }

    for ( std::string value;std::string key : args ){
        auto status = db -> Get(leveldb::ReadOptions(),key,&value);
        if (status.ok()){
            std::cout << key << "的值是:" << value << std::endl;
            } else {
            std::cout << "没有找到" << key << "的值" <<std::endl;
         }
    }
    delete db;
    return 0;
    

}

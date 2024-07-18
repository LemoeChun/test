#include <iostream>
#include <rocksdb/db.h>
#include <ostream>
namespace leveldb = rocksdb;
leveldb::DB* db;
leveldb::Options options;

int main(const int argc,char** argv){

    if(argc != 3){
        std::cout << "Usage: ./本程式 Key Value" << std::endl;
        return -1;
    }

    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

    if(!status.ok()){
        std::cerr << "Unable to open/create db ./test.db" << std::endl;
        return -1;
    }

    db -> Put(leveldb::WriteOptions(),argv[1],argv[2]);
    delete db;
    return 0;
    

}

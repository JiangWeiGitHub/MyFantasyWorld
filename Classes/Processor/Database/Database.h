#ifndef __DATABASE_H__
#define __DATABASE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "./Sqlite/sqlite3.h"
#include "../JsonCpp/json/json.h"

namespace jiangweigithub {

  class Database
  {
  public:
    static Database* getDatabaseInstance();
    ~Database();

    int addData(std::string json_format);
    int deleteData(std::string json_format);
    std::string findData(std::string json_format);
    int editData(std::string json_format);
  
  private:
    int _sqliteInit();
    sqlite3* _sqlitedb;
  };

}

#endif // __DATABASE_H__
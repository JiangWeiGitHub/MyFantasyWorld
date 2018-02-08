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
    ~Database();
    // int openDatabase();
    // int closeDatabase();

    static Database* getDatabaseInstance();

    int runSQL(std::string sql, void * hehe);

    int addData(std::string json_format);
    int deleteData(std::string json_format);
    std::string findData(std::string json_format);
    int editData(std::string json_format);
  
  private:
    Database();
    int _initDatabase();
    static int _sqlite_callback(void *param, int f_num, char **f_value, char **f_name);

    static Database* _databaseInstance;
    static sqlite3* _sqlitedb;
    static std::map<std::string, std::string> _data;
  };

}

#endif // __DATABASE_H__
#include "./Database.h"

namespace jiangweigithub {

  Database::Database()
  {
    _sqlitedb = NULL;
    _sqliteInit();
  }

  Database::~Database()
  {
    _sqlitedb = NULL;
  }

  Database* Database::_instance = new Database();
  Database* Database::getDatabaseInstance()
  {
    return _instance;
  }

  int Database::_sqliteInit()
  {
    std::string dbPath = cocos2d::FileUtils::getInstance()->getWritablePath() + "mydatabase.db";

    int result = sqlite3_open(dbPath.c_str(), &_sqlitedb);

    if(result == SQLITE_OK)
      std::cout << "open database successful!" << std::endl;
    else   
      std::cout << "open database failed!" << std::endl;    
  }

  int Database::addData(std::string json_format)
  {
    Json::Reader reader;
    Json::Value json_object;
    bool tmp = 0;
    if (!(tmp = reader.parse(json_format, json_object)))
    {
      std::cout <<json_object<< std::endl;
    }
  }

  int Database::deleteData(std::string json_format)
  {

  }

  std::string Database::findData(std::string json_format)
  {

  }

  int Database::editData(std::string json_format)
  {

  }
}
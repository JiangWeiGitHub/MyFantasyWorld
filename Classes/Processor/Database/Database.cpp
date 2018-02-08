#include "./Database.h"

namespace jiangweigithub {

  Database::Database()
  {
    _sqlitedb = NULL;
    _initDatabase();
  }

  Database::~Database()
  {
    sqlite3_close(_sqlitedb);
  }

  Database* Database::_databaseInstance = NULL;
  sqlite3* Database::_sqlitedb;
  std::map<std::string, std::string> Database::_data;

  Database* Database::getDatabaseInstance()
  {
    if(NULL == _databaseInstance)
    {
      if(NULL == _databaseInstance)
      {
        _databaseInstance = new Database;
      }
    }

    return _databaseInstance;
  }

  int Database::_initDatabase()
  {
    int result = sqlite3_open("/home/john/git/MyFantasyWorld/Resources/database/coreData.db", &_sqlitedb);

    if(result == SQLITE_OK)
    {
      std::cout << "open database successful!" << std::endl;
    }
    else
    {
      std::cout << "open database failed!" << std::endl;
      sqlite3_close(_sqlitedb);
    }

    return 0;
  }

  // int Database::openDatabase()
  // {
  //   int result = sqlite3_open("database/coreData.db", &_sqlitedb);

  //   if(result == SQLITE_OK)
  //   {
  //     std::cout << "open database successful!" << std::endl;
  //   }
  //   else
  //   {
  //     std::cout << "open database failed!" << std::endl;
  //   }
  // }
// 
  // int Database::closeDatabase()
  // {
  //   sqlite3_close(_sqlitedb);
  // }

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

  int Database::runSQL(std::string sql, void * storeData)
  {
    char* errmsg;

    int nResult = sqlite3_exec(_sqlitedb, sql.c_str(), _sqlite_callback, storeData, &errmsg);
    if (nResult != SQLITE_OK)
    {
      std::cout<<"nResult: "<<nResult<<std::endl;
      // sqlite3_close(_sqlitedb);
      // sqlite3_free(errmsg);

      return 0;
    }

    // storeData = _data;

    // std::cout<<"aaaaaa"<<std::endl;
    // std::map<std::string, std::string>::iterator iter;  
  
    // for(iter = storeData.begin(); iter != storeData.end(); iter++)
    // {
    //   std::cout<<iter->first<<' '<<iter->second<<std::endl;
    // }
    // std::cout<<"bbbbbbbb"<<std::endl;
       

    return 0;
  }

  std::string Database::findData(std::string json_format)
  {
    // char* errmsg;

    // int nResult = sqlite3_exec(_sqlitedb, "select * from system", find_callback, NULL, &errmsg);

    // if (nResult != SQLITE_OK)
    // {
    //   sqlite3_close(_sqlitedb);
    //   sqlite3_free(errmsg);

    //   return 0;
    // }
  }

  int Database::editData(std::string json_format)
  {

  }

  int Database::_sqlite_callback(void *param, int f_num, char **f_value, char **f_name)
  {
    if(*f_value != NULL || *f_name!= NULL)
    {
      int i;
      for(i = 0; i < f_num; i++)
      {
        std::cout<<*(f_name + i)<<": "<<*(f_value + i)<<std::endl;
        ((std::map<std::string, std::string>*)(param))->insert(std::pair<std::string, std::string>(*(f_name + i), *(f_value + i)));  
      }
    }
  }
}
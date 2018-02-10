#include "./Database.h"

namespace jiangweigithub {

  Database* Database::_databaseInstance = NULL;
  sqlite3* Database::_sqlitedb;
  char* Database::_errmsg;
  std::map<std::string, std::string> Database::_data;

  Database::Database()
  {
    _sqlitedb = NULL;
    _initDatabase();
  }

  Database::~Database()
  {
    if(_sqlitedb != NULL)
    {
      sqlite3_close(_sqlitedb);
    }

    if(_errmsg != NULL)
    {
      sqlite3_free(_errmsg);
    }
  }

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

  int Database::runSQL(std::string sql, void* dataCallback)
  {
    int result = sqlite3_exec(_sqlitedb, sql.c_str(), _sqlite_callback, dataCallback, &_errmsg);
    if(result == SQLITE_OK)
    {
      std::cout<<"SQLITE_OK: Operation Done."<<std::endl;
    }
    else if(result == SQLITE_ABORT)
    {
      std::cout<<"SQLITE_ABORT: Get Some Data."<<std::endl;
    }
    else
    {
      std::cout<<"result of sqlite3_exec: "<<result<<std::endl;
      if(_errmsg != NULL)
      {
        sqlite3_free(_errmsg);
      }
    }

    return 0;
  }

  int Database::_sqlite_callback(void *param, int f_num, char **f_value, char **f_name)
  {
    if(*f_value != NULL || *f_name!= NULL)
    {
      int i;
      for(i = 0; i < f_num; i++)
      {
        ((std::map<std::string, std::string>*)(param))->insert(std::pair<std::string, std::string>(*(f_name + i), *(f_value + i)));  
      }
    }
  }
}
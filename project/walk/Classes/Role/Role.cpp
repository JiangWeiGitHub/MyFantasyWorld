#include "Role.h"

USING_NS_CC;

Role::Role()
{
  log("Only for test");
}

Role::~Role()
{}

void Role::setName(std::string name)
{
  this->_name = name;
  log("Only for test");
}

std::string Role::getName()
{
  return this->_name;
}
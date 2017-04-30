#include "Role.h"

USING_NS_CC;

Role::Role()
{}

Role::~Role()
{}

void Role::setName(std::string name)
{
  this->_name = name;
}

std::string Role::getName()
{
  return this->_name;
}
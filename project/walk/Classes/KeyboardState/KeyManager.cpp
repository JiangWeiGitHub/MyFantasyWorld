#include "./KeyManager.h"

// KeyManager::KeyManager(KeyboardState* initState)
// {
//   this->_state = initState;
// }

KeyManager::KeyManager()
{
  this->_state = NULL;
}

KeyManager::~KeyManager()
{
  delete _state;
}

void KeyManager::setState(KeyboardState* state)
{
  delete _state;
  this->_state = state;
}

KeyboardState* KeyManager::getState()
{
  return this->state;
}

void KeyManager::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  this->_state->pressTop(sprite, x, y);
}

void KeyManager::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  this->_state->pressBottom(sprite, x, y);
}

void KeyManager::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
{
  this->_state->pressLeft(sprite, x, y);
}

void KeyManager::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  this->_state->pressRight(sprite, x, y);
}


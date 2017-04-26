#include "./KeyManager.h"

KeyManager::KeyManager(KeyboardState* initState)
{
  this->_state = initState;

  this->_keyTop = new KeyTop(this);
  this->_keyBottom = new KeyBottom(this);
  this->_keyLeft = new KeyLeft(this);
  this->_keyRight = new KeyRight(this);
  this->_keyStop = new KeyStop(this); 
}

KeyManager::KeyManager()
{
  this->_keyTop = new KeyTop(this);
  this->_keyBottom = new KeyBottom(this);
  this->_keyLeft = new KeyLeft(this);
  this->_keyRight = new KeyRight(this);
  this->_keyStop = new KeyStop(this);

  this->_state = _keyStop;
}

KeyManager::~KeyManager()
{

}

void KeyManager::setState(KeyboardState* state)
{
  this->_state = state;
}

KeyboardState* KeyManager::getStateTop()
{
  return this->_keyTop;
}

KeyboardState* KeyManager::getStateBottom()
{
  return this->_keyBottom;
}

KeyboardState* KeyManager::getStateLeft()
{
  return this->_keyLeft;
}

KeyboardState* KeyManager::getStateRight()
{
  return this->_keyRight;
}

KeyboardState* KeyManager::getStateStop()
{
  return this->_keyStop;
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


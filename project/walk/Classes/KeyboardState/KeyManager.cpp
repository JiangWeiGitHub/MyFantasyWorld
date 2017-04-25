#include "./KeyManager.h"

KeyManager::KeyManager()
{
  keyTop = new KeyTop();
  keyBottom = new KeyBottom();
  keyLeft = new KeyLeft();
  keyRight = new KeyRight();
  keyStop = new KeyStop();
}

void KeyManager::setInitState(KeyboardState* initState)
{
  this->state = initState;
}

void KeyManager::pressTop(cocos2d::Sprite* sprite, float x, float y)
{
  // this->state->setState(TOPWALK);
  this->state->pressTop(sprite, x, y);
}

void KeyManager::pressBottom(cocos2d::Sprite* sprite, float x, float y)
{
  // this->state->setState(BOTTOMWALK);
  this->state->pressBottom(sprite, x, y);
}

void KeyManager::pressLeft(cocos2d::Sprite* sprite, float x, float y)
{
  // this->state->setState(LEFTWALK);
  this->state->pressLeft(sprite, x, y);
}

void KeyManager::pressRight(cocos2d::Sprite* sprite, float x, float y)
{
  // this->state->setState(RIGHTWALK);
  this->state->pressRight(sprite, x, y);
}

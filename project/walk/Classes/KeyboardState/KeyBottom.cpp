#include "./KeyBottom.h"

KeyBottom::KeyBottom(KeyManager* keyManager)
{
  this->keyManager = keyManager;
}

KeyBottom::~KeyBottom()
{

}

void KeyBottom::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_top == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressTop(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    // y += 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    this->keyManager->setState(this->keyManager->getStateTop());
    this->keyManager->pressTop(sprite, x, y);

    return;
  }

  // y += 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  this->keyManager->setState(this->keyManager->getStateTop());
  this->keyManager->pressTop(sprite, x, y);

  return;
}

void KeyBottom::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_bottom == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressBottom(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    y -= 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  y -= 1;
  sprite->setPosition(cocos2d::Vec2(x, y));

  return;
}

void KeyBottom::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_left == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressLeft(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_right == true)
  {
    // x -= 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    this->keyManager->setState(this->keyManager->getStateLeft());
    this->keyManager->pressLeft(sprite, x, y);

    return;
  }

  // x -= 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  this->keyManager->setState(this->keyManager->getStateLeft());
  this->keyManager->pressLeft(sprite, x, y);
  
  return;
}

void KeyBottom::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_right == true)
  {
    this->keyManager->setState(this->keyManager->getStateStop());
    this->keyManager->pressRight(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true)
  {
    // x += 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    this->keyManager->setState(this->keyManager->getStateRight());
    this->keyManager->pressRight(sprite, x, y);

    return;
  }

  // x += 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  this->keyManager->setState(this->keyManager->getStateRight());
  this->keyManager->pressRight(sprite, x, y);
  
  return;
}

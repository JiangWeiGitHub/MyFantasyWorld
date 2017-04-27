#include "./KeyBottom.h"
#include "./KeyManager.h"

KeyBottom::KeyBottom(KeyManager* km)
{
  keyManager = km;
}

KeyBottom::~KeyBottom()
{

}

void KeyBottom::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle->getTopState() == true)
  {
    if(obstacle->getException() == Obstacle::TOP)
    {
      keyManager->setState(keyManager->getStateTop());
    }
    else
    {
      keyManager->setState(keyManager->getStateStop());
    }

    keyManager->pressTop(sprite, x, y);

    return;

    return;
  }

  if(KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
  {
    // y += 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    keyManager->setState(keyManager->getStateTop());
    keyManager->pressTop(sprite, x, y);

    return;
  }

  // y += 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  keyManager->setState(keyManager->getStateTop());
  keyManager->pressTop(sprite, x, y);

  return;
}

void KeyBottom::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle->getBottomState() == true)
  {
    if(obstacle->getException() == Obstacle::BOTTOM)
    {
      y -= 1;
      sprite->setPosition(cocos2d::Vec2(x, y));
    }
    else
    {
      keyManager->setState(keyManager->getStateStop());
      keyManager->pressBottom(sprite, x, y);
    }    

    return;
  }

  if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
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
  if(KeyboardState::obstacle->getLeftState() == true)
  {
    if(obstacle->getException() == Obstacle::LEFT)
    {
      keyManager->setState(keyManager->getStateLeft());
    }
    else
    {
      keyManager->setState(keyManager->getStateStop());
    }

    keyManager->pressLeft(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getRightState() == true)
  {
    // x -= 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    keyManager->setState(keyManager->getStateLeft());
    keyManager->pressLeft(sprite, x, y);

    return;
  }

  // x -= 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  keyManager->setState(keyManager->getStateLeft());
  keyManager->pressLeft(sprite, x, y);
  
  return;
}

void KeyBottom::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle->getRightState() == true)
  {
    if(obstacle->getException() == Obstacle::RIGHT)
    {
      keyManager->setState(keyManager->getStateRight());
    }
    else
    {
      keyManager->setState(keyManager->getStateStop());
    }

    keyManager->pressRight(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getLeftState() == true)
  {
    // x += 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    keyManager->setState(keyManager->getStateRight());
    keyManager->pressRight(sprite, x, y);

    return;
  }

  // x += 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  keyManager->setState(keyManager->getStateRight());
  keyManager->pressRight(sprite, x, y);
  
  return;
}

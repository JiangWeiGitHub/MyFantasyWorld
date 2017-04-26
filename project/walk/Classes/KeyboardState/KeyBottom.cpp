#include "./KeyBottom.h"

void KeyBottom::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_top == true)
  {
    (KeyboardState::keyManager)->setState(new KeyStop());
    (KeyboardState::keyManager)->getState()->pressTop(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    // y += 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    (KeyboardState::keyManager)->setState(new KeyTop());
    (KeyboardState::keyManager)->getState()->pressTop(sprite, x, y);

    return;
  }

  // y += 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  (KeyboardState::keyManager)->setState(new KeyTop());
  (KeyboardState::keyManager)->getState()->pressTop(sprite, x, y);

  return;
}

void KeyBottom::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_bottom == true)
  {
    (KeyboardState::keyManager)->setState(new KeyStop());
    (KeyboardState::keyManager)->getState()->pressBottom(sprite, x, y);

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
    (KeyboardState::keyManager)->setState(new KeyStop());
    (KeyboardState::keyManager)->getState()->pressLeft(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_right == true)
  {
    // x -= 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    (KeyboardState::keyManager)->setState(new KeyLeft());
    (KeyboardState::keyManager)->getState()->pressLeft(sprite, x, y);

    return;
  }

  // x -= 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  (KeyboardState::keyManager)->setState(new KeyLeft());
  (KeyboardState::keyManager)->getState()->pressLeft(sprite, x, y);
  
  return;
}

void KeyBottom::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_right == true)
  {
    (KeyboardState::keyManager)->setState(new KeyStop());
    (KeyboardState::keyManager)->getState()->pressRight(sprite, x, y);

    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true)
  {
    // x += 1;
    // sprite->setPosition(cocos2d::Vec2(x, y));

    (KeyboardState::keyManager)->setState(new KeyRight());
    (KeyboardState::keyManager)->getState()->pressRight(sprite, x, y);

    return;
  }

  // x += 1;
  // sprite->setPosition(cocos2d::Vec2(x, y));

  (KeyboardState::keyManager)->setState(new KeyRight());
  (KeyboardState::keyManager)->getState()->pressRight(sprite, x, y);
  
  return;
}

#include "./KeyStop.h"

void KeyStop::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_top == true)
  {
    return;
  }

  if(KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    (KeyboardState::keyManager)->setState(new KeyTop());
    (KeyboardState::keyManager)->getState()->pressTop(sprite, x, y);

    return;
  }

  (KeyboardState::keyManager)->setState(new KeyTop());
  (KeyboardState::keyManager)->getState()->pressTop(sprite, x, y);

  return;
}

void KeyStop::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_bottom == true)
  {
    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_left == true || KeyboardState::obstacle_right == true)
  {
    (KeyboardState::keyManager)->setState(new KeyBottom());
    (KeyboardState::keyManager)->getState()->pressBottom(sprite, x, y);

    return;
  }

  (KeyboardState::keyManager)->setState(new KeyBottom());
  (KeyboardState::keyManager)->getState()->pressBottom(sprite, x, y);

  return;
}

void KeyStop::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_left == true)
  {
    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_right == true)
  {
    (KeyboardState::keyManager)->setState(new KeyLeft());
    (KeyboardState::keyManager)->getState()->pressLeft(sprite, x, y);

    return;
  }

  (KeyboardState::keyManager)->setState(new KeyLeft());
  (KeyboardState::keyManager)->getState()->pressLeft(sprite, x, y);
  
  return;
}



void KeyStop::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
{
  if(KeyboardState::obstacle_right == true)
  {
    return;
  }

  if(KeyboardState::obstacle_top == true || KeyboardState::obstacle_bottom == true || KeyboardState::obstacle_left == true)
  {
    (KeyboardState::keyManager)->setState(new KeyRight());
    (KeyboardState::keyManager)->getState()->pressRight(sprite, x, y);

    return;
  }

  (KeyboardState::keyManager)->setState(new KeyRight());
  (KeyboardState::keyManager)->getState()->pressRight(sprite, x, y);
  
  return;
}

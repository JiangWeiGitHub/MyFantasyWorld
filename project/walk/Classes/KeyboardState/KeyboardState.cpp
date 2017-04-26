#include "./KeyboardState.h"

KeyboardState::KeyboardState()
{
  this->keyManager = new KeyManager();

  obstacle_top = obstacle_bottom = obstacle_left = obstacle_right = false;
}

KeyboardState::~KeyboardState()
{
  delete this->keyManager;
}

void KeyboardState::setKeyManager(KeyManager* keyManager)
{
  this->keyManager = keyManager;
}
#include "./KeyboardState.h"
#include "./KeyManager.h"

KeyboardState::KeyboardState()
{
  obstacle = Obstacle::getInstance();
}

KeyboardState::~KeyboardState()
{
  delete obstacle;
}
#include "./KeyManager.h"

void KeyManager::createAllState()
{
  keyTop = new KeyTop();
  keyBottom = new KeyBottom();
  keyLeft = new KeyLeft();
  keyRight = new KeyRight();
  keyStop = new keyStop();
}

void KeyManager::run()
{
  if(key == down)
  {
    keyTop->pressTop();
  }
}
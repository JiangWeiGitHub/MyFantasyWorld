#ifndef __LOADINGSPRITE_H__
#define __LOADINGSPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

class LoadingSprite
{
public:
  LoadingSprite();
  ~LoadingSprite();

  cocos2d::Sprite* getLoadingSprite();
  cocos2d::Label* getLoadingTitle();

private:
  bool setAnimation();
  bool createTitle(std::string name);

  cocos2d::Sprite* loadingSprite;
  cocos2d::Label* loadingTitle;
};

#endif // __LOADINGSPRITE_H__
#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Sprite/Loading/LoadingSprite.h"

class LoadingLayer
{
public:
  LoadingLayer();
  ~LoadingLayer();

  cocos2d::Layer* getLoadingLayer();

private:
  cocos2d::Layer* loadingLayer;
  cocos2d::Sprite* loadingSprite;
  cocos2d::Label* loadingTitle;
};

#endif // __LOADINGLAYER_H__
#ifndef __LOADING_H__
#define __LOADING_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Layer/Loading/LoadingLayer.h"

class LoadingScene
{
public:
  LoadingScene();
  ~LoadingScene();

  cocos2d::Scene* getLoadingScene();

private:
  cocos2d::Scene* loadingScene;
};

#endif // __LOADING_H__
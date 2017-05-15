#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../Scene/Loading/LoadingScene.h"

static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1280, 720);

namespace jiangweigithub {

  class Director
  {
  public:
    // Director();
    // ~Director();

    // cocos2d::Director* getDirector();

    static void initDirector();
    static void openLoadingScene();
    static void loadingSceneCallback();
    static void loginSceneCallback();

    static cocos2d::Director* director;
  };

}

#endif // __DIRECTOR_H__
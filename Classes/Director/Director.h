#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../Global/Global.h"
#include "../Processor/Database/Database.h"
#include "../Scene/Init/Introduce.h"
#include "../Scene/Init/Loading.h"

static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1280, 720);

namespace jiangweigithub {

  class Director
  {
  public:
    static void initDirector();
    static void switchLoginScene();

    static void openLoadingScene();
    static void openIntroduceScene();
    static void loadingSceneCallback();
    static void loginSceneCallback();

    static enum CHAPTER getChapter();
    static void setChapter(enum CHAPTER chapter);

    static void playBackgroundMusic(std::string name);
    static void stopBackgroundMusic();
    static void setBackgroundMusicVolume(float volume);

    static void playEffectMusic(std::string name);
    static void stopEffectMusic();
    static void setEffectMusicVolume(float volume);

    static int getBGMVolume();
    static int setBGMVolume(int volume);

    static int getLanguage();
    static int setLanguage(enum LANGUAGE type);

    static cocos2d::Director* director;

  // private:
    static enum CHAPTER _chapter;
  };

}

#endif // __DIRECTOR_H__
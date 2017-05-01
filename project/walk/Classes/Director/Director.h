#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class Director
  {
  public:
    Director();
    ~Director();

    cocos2d::Director* getDirector();

    void loadingSceneCallback();

  private:    
    cocos2d::Director* director;
  };

}

#endif // __DIRECTOR_H__
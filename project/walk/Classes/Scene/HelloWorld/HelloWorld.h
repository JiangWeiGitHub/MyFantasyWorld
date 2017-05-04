#ifndef __HELLOWORLD_H__
#define __HELLOWORLD_H__

#pragma once

#include "iostream"
#include <unistd.h>
#include "cocos2d.h"

#include "../../Layer/Loading/LoadingLayer.h"
#include "../../Scene/Main/Login/Login.h"

namespace jiangweigithub {

  class HelloWorld: public cocos2d::Layer
  {
  public:
    cocos2d::Sprite* ballOne;
    cocos2d::Sprite* ballTwo;
    cocos2d::PhysicsWorld* m_world; 

    void setPhyWorld(cocos2d::PhysicsWorld* world)
    {
      m_world = world;
    };

    static cocos2d::Scene* createScene();
    virtual bool init();

    cocos2d::Vec2 verts[] = {};
    int counter = 0;
    float objectX, objectY;

    CREATE_FUNC(HelloWorld); 
  };
  
}

#endif // __HELLOWORLD_H__
#ifndef __MAINLAYER_H__
#define __MAINLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Sprite/Main/MainSprite.h"
#include "../../../Sprite/Role/Human/Leader.h"
#include "../../../Producer/KeyboardState/KeyManager.h"
#include "../../../Producer/Obstacle/Obstacle.h"

namespace jiangweigithub {
  
  class HomeLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getHomeLayer();
    virtual bool init();

    CREATE_FUNC(HomeLayer);

    enum WALKINGDIRECTION
    {
      TOP = 1,
      BOTTOM = 2,
      LEFT = 3,
      RIGHT = 4,
      NONE = 5
    };

    void update(float delta) override;

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    bool onContactBegin(const cocos2d::PhysicsContact& contact);
    bool onContactSeparate(const cocos2d::PhysicsContact& contact);

  private:
    float _xxx, _yyy;
    
    // cocos2d::Rect rectangle;
    // cocos2d::Vec2 rectangleZone;
    bool stop_top, stop_bottom, stop_left, stop_right;
    cocos2d::Sprite* leaderSprite;
    cocos2d::Sprite* test;

    bool durationTop, durationBottom, durationLeft, durationRight;
    bool flag_obstacle_top, flag_obstacle_bottom, flag_obstacle_left, flag_obstacle_right;

    cocos2d::Animation* animation_bottom;
    cocos2d::Animation* animation_top;
    cocos2d::Animation* animation_left;
    cocos2d::Animation* animation_right;

    KeyManager* keyManager;
    Obstacle* obstacle;

    //  map;
    float objectX, objectY;
    // drawNode;

    bool kissed = false;

    int heroMask = 1 << 0;
    int wallMask = 1 << 1;

    WALKINGDIRECTION dir = NONE;

  };

}

#endif // __MAINLAYER_H__
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


    void update(float delta) override;

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

  private:
    float _xxx, _yyy;
    
    cocos2d::Rect rectangle;
    cocos2d::Vec2 rectangleZone;
    bool stop_top, stop_bottom, stop_left, stop_right;
    cocos2d::Sprite* leaderSprite;
    cocos2d::Sprite* test;

    bool flag_top, flag_bottom, flag_left, flag_right;
    bool flag_obstacle_top, flag_obstacle_bottom, flag_obstacle_left, flag_obstacle_right;

    cocos2d::Animation* animation_bottom;
    cocos2d::Animation* animation_top;
    cocos2d::Animation* animation_left;
    cocos2d::Animation* animation_right;

    KeyManager* keyManager;
    Obstacle* obstacle;

    cocos2d::Vec2 verts[50];
    int counter = 0;

    cocos2d::TMXTiledMap* map;
    float objectX, objectY;
    cocos2d::DrawNode* drawNode;

  };

}

#endif // __MAINLAYER_H__
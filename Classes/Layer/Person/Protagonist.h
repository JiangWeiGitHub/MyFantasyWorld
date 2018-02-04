#ifndef __PROTAGONISTLAYER_H__
#define __PROTAGONISTLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Material/Login.h"
#include "../../Material/Role/Role.h"
#include "../../Material/Role/Human/Leader.h"
#include "../../Processor/KeyboardState/KeyManager.h"
#include "../../Processor/Obstacle/Obstacle.h"

namespace jiangweigithub {
  
  class ProtagonistLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getProtagonistLayer();
    virtual bool init();

    CREATE_FUNC(ProtagonistLayer);

    void update(float delta) override;

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    bool onContactBegin(const cocos2d::PhysicsContact& contact);
    bool onContactSeparate(const cocos2d::PhysicsContact& contact);

  private:
    bool _calculateContactPixel(const cocos2d::PhysicsContact& contact);
    // void _nextStringCallback(cocos2d::Ref* pSender);

    float _heroPositionX = 280, _heroPositionY = 350;
   
    cocos2d::Sprite* leaderSprite;

    bool _durationTop = false;
    bool _durationBottom = false;
    bool _durationLeft = false;
    bool _durationRight = false;

    bool _contactedTop = false;
    bool _contactedBottom = false;
    bool _contactedLeft = false;
    bool _contactedRight = false;
    bool _contactedTopLeft = false;
    bool _contactedTopRight = false;
    bool _contactedBottomLeft = false;
    bool _contactedBottomRight = false;

    std::stack<std::string> _keyboardNameCache;

    KeyManager* keyManager = new KeyManager("STOP");
    Obstacle* obstacle = Obstacle::getInstance();

    int heroMask = 1 << 0;
    int wallMask = 1 << 1;

    cocos2d::Label* _nameLine;
    cocos2d::Label* _firstLine;
    cocos2d::Label* _secondLine;
    cocos2d::Label* _thirdLine;
  };

}

#endif // __PROTAGONISTLAYER_H__
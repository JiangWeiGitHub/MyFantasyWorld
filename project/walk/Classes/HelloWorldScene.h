#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Role/Role.h"

#include "KeyboardState/KeyboardState.h"
#include "KeyboardState/KeyManager.h"

#include "./KeyboardState/KeyTop.h"
#include "./KeyboardState/KeyBottom.h"
#include "./KeyboardState/KeyLeft.h"
#include "./KeyboardState/KeyRight.h"
#include "./KeyboardState/KeyStop.h"

#include "./Obstacle/Obstacle.h"

class HelloWorld : public cocos2d::Layer
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();
  
  // a selector callback
  void menuCloseCallback(cocos2d::Ref* pSender);

  void update(float delta) override;

  void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

  void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
  
  // implement the "static create()" method manually
  CREATE_FUNC(HelloWorld);

private:
  float _xxx, _yyy;
  cocos2d::Rect rectangle;
  cocos2d::Vec2 rectangleZone;
  bool stop_top, stop_bottom, stop_left, stop_right;
  cocos2d::Sprite* sprite;
  cocos2d::Sprite* test;

  bool flag_top, flag_bottom, flag_left, flag_right;
  bool flag_obstacle_top, flag_obstacle_bottom, flag_obstacle_left, flag_obstacle_right;

  KeyManager* keyManager;
  Obstacle* obstacle;
};

#endif // __HELLOWORLD_SCENE_H__

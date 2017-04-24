#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Role/Role.h"

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
  int _xxx, _yyy;
  cocos2d::Sprite* sprite;
  cocos2d::Sprite* test;

  bool flag_top, flag_bottom, flag_left, flag_right;
};

#endif // __HELLOWORLD_SCENE_H__

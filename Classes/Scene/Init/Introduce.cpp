#include "./Introduce.h"

namespace jiangweigithub {

  cocos2d::Scene* IntroduceScene::getIntroduceScene()
  {
    auto tmp = IntroduceScene::create();

    return tmp;
  }

  void IntroduceScene::update(float delta)
  {
    if(this->counter > DEFAULT_SWITCH_TIME)
    {
      auto thanksScene = jiangweigithub::ThanksScene::getThanksScene();
      cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(DEFAULT_SWITCH_TRANSITION, thanksScene, cocos2d::Color3B(0,0,0)));

      this->unscheduleUpdate();
    }
    else
    {
      this->counter++;
    }
  }

  bool IntroduceScene::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    auto IntroduceTitle = cocos2d::Label::createWithTTF("John's Production", "fonts/MSYHBD.TTF", 28);
    IntroduceTitle->enableBold();
    IntroduceTitle->setAdditionalKerning(1);    
    IntroduceTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(IntroduceTitle, 0);

    this->scheduleUpdate();

    return true;
  }

}
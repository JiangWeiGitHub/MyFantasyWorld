#include "./Thanks.h"

namespace jiangweigithub {

  cocos2d::Scene* ThanksScene::getThanksScene()
  {
    auto tmp = ThanksScene::create();

    return tmp;
  }

  void ThanksScene::update(float delta)
  {
     if(this->counter > DEFAULT_SWITCH_TIME * 4)
    {      
      auto loadingScene = jiangweigithub::LoadingScene::getLoadingScene();
      cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(DEFAULT_SWITCH_TRANSITION, loadingScene, cocos2d::Color3B(0,0,0)));

      this->unscheduleUpdate();
    }
    else
    {
      this->counter++;
    }
  }

  bool ThanksScene::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    auto ThanksTitle = cocos2d::Label::createWithTTF("- Thanks -", "fonts/MSYHBD.TTF", 28);
    ThanksTitle->enableBold();
    ThanksTitle->setAdditionalKerning(1);    
    ThanksTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
    this->addChild(ThanksTitle, 0);

    auto nameOne = cocos2d::Label::createWithTTF("I", "fonts/MSYHBD.TTF", 24);
    nameOne->enableBold();
    nameOne->setAdditionalKerning(1);    
    nameOne->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(nameOne, 0);

    auto nameTwo = cocos2d::Label::createWithTTF("Me", "fonts/MSYHBD.TTF", 24);
    nameTwo->enableBold();
    nameTwo->setAdditionalKerning(1);    
    nameTwo->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50));
    this->addChild(nameTwo, 0);

    auto nameThree = cocos2d::Label::createWithTTF("Myself", "fonts/MSYHBD.TTF", 24);
    nameThree->enableBold();
    nameThree->setAdditionalKerning(1);    
    nameThree->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
    this->addChild(nameThree, 0);

    this->scheduleUpdate();

    return true;
  }

}
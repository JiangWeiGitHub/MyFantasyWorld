#include "./Introduce.h"

namespace jiangweigithub {

  cocos2d::Scene* IntroduceScene::getIntroduceScene()
  {
    auto tmp = IntroduceScene::create();

    return tmp;
  }

  bool IntroduceScene::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    auto IntroduceTitle = cocos2d::Label::createWithTTF("John's Production", "fonts/MSYHBD.TTF", 24);
    IntroduceTitle->enableBold();
    IntroduceTitle->setAdditionalKerning(1);    
    IntroduceTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(IntroduceTitle, 0);

    return true;
  }

}
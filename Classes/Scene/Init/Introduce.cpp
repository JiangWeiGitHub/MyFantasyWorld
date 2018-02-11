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

    std::cout<<"ssdsfdfsdfsfdsd: "<<jiangweigithub::Director::getLanguage()<<std::endl;



    auto _prefaceContents = cocos2d::FileUtils::getInstance()->getStringFromFile("database/language.json");
    Json::Reader reader;
    Json::Value json_object;
    int tmp = 0;
    if (!(tmp = reader.parse(_prefaceContents, json_object)))
    {
      std::cout <<tmp<< std::endl;
    }

std::cout <<json_object<< std::endl;

    // unsigned int i = 0;
    // std::vector<std::string> _line;
    // for(i = 0; i < json_object["script"]["contents"].size(); i++)
    // {
    //   unsigned int _tmpPosition = 0;
    //   while(_tmpPosition <= json_object["script"]["contents"][i].asString().size())
    //   {
    //     _line.push_back(json_object["script"]["contents"][i].asString().substr(_tmpPosition, PREFACE_WIDTH));
    //     _tmpPosition += PREFACE_WIDTH;
    //   }
    // }





    auto IntroduceTitle = cocos2d::Label::createWithTTF("John's Production", "fonts/MSYHBD.TTF", 28);
    IntroduceTitle->enableBold();
    IntroduceTitle->setAdditionalKerning(1);    
    IntroduceTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(IntroduceTitle, 0);
    
    this->scheduleUpdate();

    return true;
  }

}
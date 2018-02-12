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

    // std::cout<<"ssdsfdfsdfsfdsd: "<<jiangweigithub::Director::getLanguage()<<std::endl;



    auto _prefaceContents = cocos2d::FileUtils::getInstance()->getStringFromFile("database/language.json");
    Json::Reader reader;
    Json::Value json_object;
    int tmp = 0;
    if (!(tmp = reader.parse(_prefaceContents, json_object)))
    {
      std::cout <<tmp<< std::endl;
    }

    unsigned int i = 0;
    for(i = 0; i < json_object.size(); i++)
    {
      if(json_object[i]["name"] == "introduce")
      {
        unsigned int j = 0;
        for(j = 0; j < json_object[i]["fill"].size(); j++)
        {
          if(json_object[i]["fill"][j]["id"].asInt() == jiangweigithub::Director::getLanguage())
          {
            unsigned int k = 0;
            for(k = 0; k < json_object[i]["fill"][j]["info"].size(); k++)
            {
              auto IntroduceTitle = cocos2d::Label::createWithTTF(json_object[i]["fill"][j]["info"][k]["content"].asString(), json_object[i]["fill"][j]["info"][k]["font"].asString(), json_object[i]["fill"][j]["info"][k]["size"].asInt());
              IntroduceTitle->enableBold();
              IntroduceTitle->setAdditionalKerning(1);
              if(json_object[i]["fill"][j]["info"][k]["position_x"].asString() == "center" && json_object[i]["fill"][j]["info"][k]["position_y"].asString() == "center")
              {
                IntroduceTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
              }
              else
              {
                IntroduceTitle->setPosition(cocos2d::Vec2(json_object[i]["fill"][j]["info"][k]["position_x"].asInt(), json_object[i]["fill"][j]["info"][k]["position_y"].asInt()));
              }

              this->addChild(IntroduceTitle, k);
            }
          }
        }

        break;
      }




      // unsigned int _tmpPosition = 0;
      // while(_tmpPosition <= json_object["script"]["contents"][i].asString().size())
      // {
      //   _line.push_back(json_object["script"]["contents"][i].asString().substr(_tmpPosition, PREFACE_WIDTH));
      //   _tmpPosition += PREFACE_WIDTH;
      // }
    }





    // auto IntroduceTitle = cocos2d::Label::createWithTTF("John's Production", "fonts/MSYHBD.TTF", 28);
    // IntroduceTitle->enableBold();
    // IntroduceTitle->setAdditionalKerning(1);    
    // IntroduceTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    // this->addChild(IntroduceTitle, 0);
    
    this->scheduleUpdate();

    return true;
  }

}
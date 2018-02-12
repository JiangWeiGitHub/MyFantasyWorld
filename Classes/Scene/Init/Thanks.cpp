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

    auto jsonData = cocos2d::FileUtils::getInstance()->getStringFromFile("database/language.json");
    Json::Reader reader;
    Json::Value json_object;
    int tmp = 0;
    if (!(tmp = reader.parse(jsonData, json_object)))
    {
      std::cout <<tmp<< std::endl;
    }

    unsigned int i = 0;
    for(i = 0; i < json_object.size(); i++)
    {
      if(json_object[i]["name"] == "thanks")
      {
        unsigned int j = 0;
        for(j = 0; j < json_object[i]["fill"].size(); j++)
        {
          if(json_object[i]["fill"][j]["id"].asInt() == jiangweigithub::Director::getLanguage())
          {
            unsigned int k = 0;
            for(k = 0; k < json_object[i]["fill"][j]["info"].size(); k++)
            {
              auto IntroduceTitle = cocos2d::Label::createWithTTF(json_object[i]["fill"][j]["info"][k]["content"].asString(), 
                                                                  json_object[i]["fill"][j]["info"][k]["font"].asString(), 
                                                                  json_object[i]["fill"][j]["info"][k]["size"].asInt());
              IntroduceTitle->enableBold();
              IntroduceTitle->setAdditionalKerning(1);

              int tmpx, tmpy;
              if(json_object[i]["fill"][j]["info"][k]["position_x"].asInt() == 9999)
              {
                tmpx = 0;
              }
              else
              {
                tmpx = json_object[i]["fill"][j]["info"][k]["position_x"].asInt();
              }

              if(json_object[i]["fill"][j]["info"][k]["position_y"].asInt() == 9999)
              {
                tmpy = 0;
              }
              else
              {
                tmpy = json_object[i]["fill"][j]["info"][k]["position_y"].asInt();
              }

              IntroduceTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 + tmpx, 
                                                        visibleSize.height / 2 + tmpy));

              this->addChild(IntroduceTitle, k);
            }
          }
        }

        break;
      }
    }

    this->scheduleUpdate();

    return true;
  }

}
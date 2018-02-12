#include "./Loading.h"

namespace jiangweigithub {

  bool LoadingLayer::init()
  {
    if ( !Layer::init() )
    {
      return false;
    }

    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage("sabin.png");

    // right
    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));

    cocos2d::Vector<cocos2d::SpriteFrame*> right;
    right.pushBack(frame1);
    right.pushBack(frame2);
    right.pushBack(frame3);
    right.pushBack(frame4);

    auto loadingSprite = Protagonist::createWithSpriteFrame(frame1);

    auto animationRight = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

    loadingSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationRight)));

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    loadingSprite->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(loadingSprite, 0);

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
      if(json_object[i]["name"] == "loading")
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

    return true;
  }

  cocos2d::Layer* LoadingLayer::getLoadingLayer()
  {
    auto tmp = LoadingLayer::create();

    return tmp;
  }

}
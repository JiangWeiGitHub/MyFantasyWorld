#include "./HomeLayer.h"

namespace jiangweigithub {

  cocos2d::Layer* HomeLayer::getHomeLayer()
  {
    auto tmp = HomeLayer::create();

    return tmp;
  }

  bool HomeLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    // auto leaderSprite = Leader::getLeader();

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();


    auto textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage("sabin.png");
    cocos2d::SpriteFrame* frame0 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(270,0,30,50));
    auto leaderSprite = cocos2d::Sprite::createWithSpriteFrame(frame0);
    leaderSprite->setPosition(cocos2d::Vec2(visibleSize.width/2,visibleSize.height/2));





    // cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage("sabin.png");

    // top
    // cocos2d::SpriteFrame* frame0 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(270,0,30,50));
    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(330,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(300,0,30,50));

    // bottom
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(0,0,30,50));
    cocos2d::SpriteFrame* frame5 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));
    cocos2d::SpriteFrame* frame6 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(60,0,30,50));
    cocos2d::SpriteFrame* frame7 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(30,0,30,50));

    // left
    cocos2d::SpriteFrame* frame8 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(90,0,30,50));
    cocos2d::SpriteFrame* frame9 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));
    cocos2d::SpriteFrame* frame10 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(150,0,30,50));
    cocos2d::SpriteFrame* frame11 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(120,0,30,50));

    // right
    cocos2d::SpriteFrame* frame12 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
    cocos2d::SpriteFrame* frame13 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
    cocos2d::SpriteFrame* frame14 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
    cocos2d::SpriteFrame* frame15 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
      
    cocos2d::Vector<cocos2d::SpriteFrame*> top;
    top.pushBack(frame0);
    top.pushBack(frame1);
    top.pushBack(frame2);
    top.pushBack(frame3);

    cocos2d::Vector<cocos2d::SpriteFrame*> bottom;
    bottom.pushBack(frame4);
    bottom.pushBack(frame5);
    bottom.pushBack(frame6);
    bottom.pushBack(frame7);

    cocos2d::Vector<cocos2d::SpriteFrame*> left;
    left.pushBack(frame8);
    left.pushBack(frame9);
    left.pushBack(frame10);
    left.pushBack(frame11);

    cocos2d::Vector<cocos2d::SpriteFrame*> right;
    right.pushBack(frame12);
    right.pushBack(frame13);
    right.pushBack(frame14);
    right.pushBack(frame15);








    // auto haha = (new Leader());
    // std::cout<<"name: "<<haha->getName()<<std::endl;
    // std::cout<<"HP: "<<haha->getHP()<<std::endl;
    // leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(cocos2d::Animation::createWithSpriteFrames(top,0.2f))));
// std::cout<<"size: "<<Leader::getAnimationTop()->getFrames()).size()<<std::endl;
    leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));


    auto homeTitle = MainSprite::getHomeTitle();
    auto tileMapSprite = MainSprite::getTileMapSprite();
    auto obstacle = MainSprite::getObstacle();

    auto mapSpriteSize = tileMapSprite->getContentSize();
    auto homeTitleSpriteSize = homeTitle->getContentSize();


    tileMapSprite->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    homeTitle->setPosition(cocos2d::Vec2((visibleSize.width - homeTitleSpriteSize.width) / 2, 660));
    leaderSprite->setPosition(cocos2d::Vec2(280, 350));

    this->addChild(tileMapSprite, -1);
    this->addChild(homeTitle, 0);
    this->addChild(leaderSprite, 1);

    return true;
  }

}
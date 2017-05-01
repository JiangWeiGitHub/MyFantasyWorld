#include "./MainSprite.h"

namespace jiangweigithub {

  // MainSprite::MainSprite()
  // {
  //   tileMapSprite = NULL;
  //   homeTitle = NULL;
  //   leaderSprite = NULL;
  //   obstacle = cocos2d::Rect(0, 0, 0, 0);

  //   createTitle("Home");
  //   createLeaderSprite();
  //   createMapSprite();
  // }

  // MainSprite::~MainSprite()
  // {
  //   obstacle = cocos2d::Rect(0, 0, 0, 0);
  //   delete leaderSprite;
  //   delete homeTitle;
  //   delete tileMapSprite;
  // }

  cocos2d::Label* MainSprite::getHomeTitle()
  {
    auto homeTitle = cocos2d::Label::createWithTTF("Home", "fonts/arial.ttf", 24);
    homeTitle->enableBold();
    homeTitle->setAdditionalKerning(1);

    return homeTitle;
  }

  cocos2d::TMXTiledMap* MainSprite::getTileMapSprite()
  {
    auto tileMapSprite = cocos2d::TMXTiledMap::create("home.tmx");

    return tileMapSprite;
  }

  cocos2d::Sprite* MainSprite::getLeaderSprite()
  {
    cocos2d::Texture2D* textTure = cocos2d::TextureCache::getInstance()->addImage("sabin.png");

    // top
    cocos2d::SpriteFrame* frame0 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(270,0,30,50));
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

    auto leaderSprite = cocos2d::Sprite::createWithSpriteFrame(frame0);

    auto animation_top = cocos2d::Animation::createWithSpriteFrames(bottom,0.2f);
    auto animation_bottom = cocos2d::Animation::createWithSpriteFrames(top,0.2f);
    auto animation_left = cocos2d::Animation::createWithSpriteFrames(left,0.2f);
    auto animation_right = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

    leaderSprite->setPosition(cocos2d::Vec2(100,360));

    auto animationTop = cocos2d::Animation::createWithSpriteFrames(top,0.2f);

    leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationTop)));


    return leaderSprite;
  }

  cocos2d::Rect MainSprite::getObstacle()
  {
    auto obstacle = cocos2d::Rect(0, 0, 0, 0);

    return obstacle;
  }

  bool MainSprite::createTitle(std::string name)
  {
    homeTitle = cocos2d::Label::createWithTTF(name, "fonts/arial.ttf", 24);
    homeTitle->enableBold();
    homeTitle->setAdditionalKerning(1);
  }

  bool MainSprite::createLeaderSprite()
  {
    cocos2d::Texture2D* textTure = cocos2d::TextureCache::getInstance()->addImage("sabin.png");

    // top
    cocos2d::SpriteFrame* frame0 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(270,0,30,50));
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

    leaderSprite = cocos2d::Sprite::createWithSpriteFrame(frame0);

    auto animation_top = cocos2d::Animation::createWithSpriteFrames(bottom,0.2f);
    auto animation_bottom = cocos2d::Animation::createWithSpriteFrames(top,0.2f);
    auto animation_left = cocos2d::Animation::createWithSpriteFrames(left,0.2f);
    auto animation_right = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

    leaderSprite->setPosition(cocos2d::Vec2(100,360));

    auto animationTop = cocos2d::Animation::createWithSpriteFrames(top,0.2f);

    leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationTop)));
  }

  bool MainSprite::createMapSprite()
  {
    tileMapSprite = cocos2d::TMXTiledMap::create("home.tmx");
  }

  bool MainSprite::createObstacle()
  {

  }

}


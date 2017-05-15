#include "./MainSprite.h"

namespace jiangweigithub {

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
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage("sabin.png");

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

    leaderSprite->setPosition(cocos2d::Vec2(100,360));

    auto animationTop = cocos2d::Animation::createWithSpriteFrames(top,0.2f);

    leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationTop)));


    return leaderSprite;
  }

  cocos2d::Sprite* MainSprite::getBackgroundSprite()
  {
    auto tmp = cocos2d::Sprite::create("login.jpg");

    return tmp;
  }

  cocos2d::MenuItemLabel* MainSprite::getNewGame()
  {
    auto myLabel = cocos2d::Label::createWithTTF("New Game", "fonts/arial.ttf", 30);
    myLabel->enableShadow();
    myLabel->enableBold();
    myLabel->enableOutline(cocos2d::Color4B::BLACK, 1);

    auto tmp = cocos2d::MenuItemLabel::create(myLabel);

    return tmp;
  }

  cocos2d::MenuItemLabel* MainSprite::getLoadGame()
  {
    cocos2d::TTFConfig ttfConfig("fonts/arial.ttf", 30, cocos2d::GlyphCollection::DYNAMIC, NULL, false, 1);

    auto tmp = cocos2d::MenuItemLabel::
         create(cocos2d::Label::createWithTTF(ttfConfig, "Load Game"));

    return tmp;
  }

  cocos2d::MenuItemLabel* MainSprite::getConfigGame()
  {
    cocos2d::TTFConfig ttfConfig("fonts/arial.ttf", 30, cocos2d::GlyphCollection::DYNAMIC, NULL, false, 1);

    auto tmp = cocos2d::MenuItemLabel::
         create(cocos2d::Label::createWithTTF(ttfConfig, "Config"));

    return tmp;
  }

  cocos2d::DrawNode* MainSprite::getDrawFrame()
  {
    cocos2d::DrawNode* tmp = cocos2d::DrawNode::create();

    cocos2d::Vec2 point[4];
    point[0] = cocos2d::Vec2(20, 25);
    point[1] = cocos2d::Vec2(1260, 25);
    point[2] = cocos2d::Vec2(1260, 210);
    point[3] = cocos2d::Vec2(20, 210);
    drawNode->drawPolygon(point, 4, cocos2d::Color4F(66/255.0f, 66/255.0f, 66/255.0f, 0.5f), 1, cocos2d::Color4F(243/255.0f, 198/255.0f, 108/255.0f, 0.7f));    

    return tmp;
  }

  cocos2d::Sprite* MainSprite::getFrameLeftFlowers()
  {
    auto tmp =  cocos2d::Sprite::create("golderFlower.png");
    tmp->setScale(0.6);
    tmp->setOpacity(235);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setRotation(180);
    tmp->setPosition(cocos2d::Vec2(1265, 225));

    return tmp;
  }

  cocos2d::Sprite* MainSprite::getFrameRightFlowers()
  {
    auto tmp =  cocos2d::Sprite::create("golderFlower.png");
    tmp->setScale(0.6);
    tmp->setOpacity(235);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setPosition(cocos2d::Vec2(15, 15));

    return tmp;
  }

  cocos2d::Label* MainSprite::getFirstLine()
  {
    auto tmp = cocos2d::Label::createWithTTF("Today is a good day.", "fonts/arial.ttf", 22);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setTextColor(cocos2d::Color4B(255,255,255,200));
    tmp->enableShadow();
    tmp->setPosition(cocos2d::Vec2(350, 125));

    return tmp;
  }

  cocos2d::Label* MainSprite::getSecondLine()
  {
    auto tmp = cocos2d::Label::createWithTTF("I've watched a good movie this evening!", "fonts/arial.ttf", 22);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setTextColor(cocos2d::Color4B(255,255,255,200));
    tmp->enableShadow();
    tmp->setPosition(cocos2d::Vec2(350, 90));

    return tmp;
  }

  cocos2d::Label* MainSprite::getThirdLine()
  {
    auto tmp = cocos2d::Label::createWithTTF("Have a good dream, stranger.", "fonts/arial.ttf", 22);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setTextColor(cocos2d::Color4B(255,255,255,200));
    tmp->enableShadow();
    tmp->setPosition(cocos2d::Vec2(350, 55));

    return tmp;
  }

  cocos2d::Label* MainSprite::getPeopleName()
  {
    auto tmp = cocos2d::Label::createWithTTF("Hero:", "fonts/arial.ttf", 26);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setTextColor(cocos2d::Color4B(255,255,255,200));
    tmp->enableShadow();
    tmp->setPosition(cocos2d::Vec2(320, 165));

    return tmp;
  }

  cocos2d::Sprite* MainSprite::getAvatar();
  {
    auto tmp =  cocos2d::Sprite::create("avatar.png");
    tmp->setScale(0.9);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setPosition(cocos2d::Vec2(21, 26));

    return tmp;
  }

}


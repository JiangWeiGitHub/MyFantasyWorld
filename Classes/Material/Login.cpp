#include "./Login.h"

namespace jiangweigithub {

  cocos2d::Label* LoginMaterial::_firstLine = NULL;
  cocos2d::Label* LoginMaterial::_secondLine = NULL;
  cocos2d::Label* LoginMaterial::_thirdLine = NULL;
  cocos2d::Label* LoginMaterial::_peopleName = NULL;
  cocos2d::Sprite* LoginMaterial::_avatar = NULL;
  cocos2d::MenuItemImage* LoginMaterial::_nextPageItem = NULL;

  cocos2d::Label* LoginMaterial::getHomeTitle()
  {
    auto homeTitle = cocos2d::Label::createWithTTF("家", "fonts/MSYHBD.TTF", 24);
    // homeTitle->enableBold();
    homeTitle->setAdditionalKerning(1);

    return homeTitle;
  }

  cocos2d::TMXTiledMap* LoginMaterial::getTileMapSprite()
  {
    auto tileMapSprite = cocos2d::TMXTiledMap::create("home.tmx");

    return tileMapSprite;
  }

  cocos2d::Sprite* LoginMaterial::getLeaderSprite()
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

  cocos2d::Sprite* LoginMaterial::getBackgroundSprite()
  {
    auto tmp = cocos2d::Sprite::create("login.jpg");

    return tmp;
  }

  cocos2d::MenuItemLabel* LoginMaterial::getNewGame()
  {
    auto myLabel = cocos2d::Label::createWithTTF("New Game", "fonts/MSYHBD.TTF", 26);
    myLabel->enableShadow();
    // myLabel->enableBold();
    myLabel->enableOutline(cocos2d::Color4B(0, 0, 0, 100), 1);

    auto tmp = cocos2d::MenuItemLabel::create(myLabel);

    return tmp;
  }

  cocos2d::MenuItemLabel* LoginMaterial::getLoadGame()
  {
    auto myLabel = cocos2d::Label::createWithTTF("Load Game", "fonts/MSYHBD.TTF", 26);
    myLabel->enableShadow();
    // myLabel->enableBold();
    myLabel->enableOutline(cocos2d::Color4B(0, 0, 0, 100), 1);

    auto tmp = cocos2d::MenuItemLabel::create(myLabel);

    return tmp;
  }

  cocos2d::MenuItemLabel* LoginMaterial::getConfigGame()
  {
    auto myLabel = cocos2d::Label::createWithTTF("Configuration", "fonts/MSYHBD.TTF", 26);
    myLabel->enableShadow();
    // myLabel->enableBold();
    myLabel->enableOutline(cocos2d::Color4B(0, 0, 0, 100), 1);

    auto tmp = cocos2d::MenuItemLabel::create(myLabel);

    return tmp;
  }

  cocos2d::DrawNode* LoginMaterial::getDrawFrame()
  {
    cocos2d::DrawNode* tmp = cocos2d::DrawNode::create();

    cocos2d::Vec2 point[4];
    point[0] = cocos2d::Vec2(20, 25);
    point[1] = cocos2d::Vec2(1260, 25);
    point[2] = cocos2d::Vec2(1260, 210);
    point[3] = cocos2d::Vec2(20, 210);
    tmp->drawPolygon(point, 4, cocos2d::Color4F(66/255.0f, 66/255.0f, 66/255.0f, 0.5f), 1, cocos2d::Color4F(243/255.0f, 198/255.0f, 108/255.0f, 0.7f));    

    return tmp;
  }

  cocos2d::Sprite* LoginMaterial::getFrameLeftFlowers()
  {
    auto tmp =  cocos2d::Sprite::create("golderFlower.png");
    tmp->setScale(0.6);
    tmp->setOpacity(235);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setRotation(180);
    tmp->setPosition(cocos2d::Vec2(1265, 225));

    return tmp;
  }

  cocos2d::Sprite* LoginMaterial::getFrameRightFlowers()
  {
    auto tmp =  cocos2d::Sprite::create("golderFlower.png");
    tmp->setScale(0.6);
    tmp->setOpacity(235);
    tmp->setAnchorPoint(cocos2d::Vec2(0, 0));
    tmp->setPosition(cocos2d::Vec2(15, 15));

    return tmp;
  }

  cocos2d::Label* LoginMaterial::getFirstLine(std::string contents)
  {
    _firstLine = cocos2d::Label::createWithTTF(contents, "fonts/MSYHBD.TTF", 22);
    _firstLine->setAnchorPoint(cocos2d::Vec2(0, 0));
    _firstLine->setTextColor(cocos2d::Color4B(255,255,255,200));
    _firstLine->enableShadow();
    _firstLine->setPosition(cocos2d::Vec2(350, 125));

    return _firstLine;
  }

  cocos2d::Label* LoginMaterial::getSecondLine(std::string contents)
  {
    _secondLine = cocos2d::Label::createWithTTF(contents, "fonts/MSYHBD.TTF", 22);
    _secondLine->setAnchorPoint(cocos2d::Vec2(0, 0));
    _secondLine->setTextColor(cocos2d::Color4B(255,255,255,200));
    _secondLine->enableShadow();
    _secondLine->setPosition(cocos2d::Vec2(350, 90));

    return _secondLine;
  }

  cocos2d::Label* LoginMaterial::getThirdLine(std::string contents)
  {
    _thirdLine = cocos2d::Label::createWithTTF(contents, "fonts/MSYHBD.TTF", 22);
    _thirdLine->setAnchorPoint(cocos2d::Vec2(0, 0));
    _thirdLine->setTextColor(cocos2d::Color4B(255,255,255,200));
    _thirdLine->enableShadow();
    _thirdLine->setPosition(cocos2d::Vec2(350, 55));

    return _thirdLine;
  }

  cocos2d::Label* LoginMaterial::getPeopleName(std::string contents)
  {
    _peopleName = cocos2d::Label::createWithTTF(contents, "fonts/MSYHBD.TTF", 22);
    _peopleName->setAnchorPoint(cocos2d::Vec2(0, 0));
    _peopleName->enableOutline(cocos2d::Color4B(0, 0, 0, 200), 2);
    // _peopleName->setTextColor(cocos2d::Color4B(255,255,255,200));
    // _peopleName->enableShadow();
    _peopleName->setPosition(cocos2d::Vec2(320, 165));

    return _peopleName;
  }

  cocos2d::Sprite* LoginMaterial::getAvatar(std::string contents)
  {
    _avatar = cocos2d::Sprite::create(contents);
    _avatar->setScale(0.9);
    _avatar->setAnchorPoint(cocos2d::Vec2(0, 0));
    _avatar->setPosition(cocos2d::Vec2(21, 26));

    return _avatar;
  }

  cocos2d::MenuItemImage* LoginMaterial::getNextPageItem()
  {
    _nextPageItem = cocos2d::MenuItemImage::create(
                                                    "CloseNormal.png",
                                                    "CloseSelected.png"
                                                  );
    _nextPageItem->setPosition(cocos2d::Vec2(1200, 60));

    return _nextPageItem;
  }

  cocos2d::Menu* LoginMaterial::getNextPage()
  {
    auto tmp = cocos2d::Menu::create(_nextPageItem, NULL);
    tmp->setPosition(cocos2d::Vec2::ZERO);

    return tmp;
  }

  void LoginMaterial::setFirstLine(std::string contents)
  {
    _firstLine->setString(contents);
    _firstLine->updateContent();
  }

  void LoginMaterial::setSecondLine(std::string contents)
  {
    _secondLine->setString(contents);
    _secondLine->updateContent();
  }

  void LoginMaterial::setThirdLine(std::string contents)
  {
    _thirdLine->setString(contents);
    _thirdLine->updateContent();
  }

  void LoginMaterial::setPeopleName(std::string contents)
  {
    _peopleName->setString(contents);
    _peopleName->updateContent();
  }

  void LoginMaterial::setAvatar(std::string contents)
  {
    _avatar->setTexture(contents);
  }

  cocos2d::DrawNode* LoginMaterial::getLittleTalkFrame(int width, int height, TALK_FRAME_ARROW_DIRECTION direction,
                       float lineWidth, cocos2d::Color4F lineColor, cocos2d::Color4F fillColor
                     )
  {
    cocos2d::DrawNode* tmp = cocos2d::DrawNode::create();

    cocos2d::Vec2 point[11];

    if(direction == LEFT)
    {
      point[0] = cocos2d::Vec2(width / 2 + TALK_FRAME_ARROW_WIDTH / 2, 0);
      point[1] = cocos2d::Vec2(width / 2 - TALK_FRAME_ARROW_WIDTH / 2 / 2, -TALK_FRAME_ARROW_HEIGHT);
      point[2] = cocos2d::Vec2(width / 2 - TALK_FRAME_ARROW_WIDTH / 2, 0);
      point[3] = cocos2d::Vec2(TALK_FRAME_EDGE, 0);
      point[4] = cocos2d::Vec2(0, TALK_FRAME_EDGE);
      point[5] = cocos2d::Vec2(0, height - TALK_FRAME_EDGE);
      point[6] = cocos2d::Vec2(TALK_FRAME_EDGE, height);
      point[7] = cocos2d::Vec2(width - TALK_FRAME_EDGE, height);
      point[8] = cocos2d::Vec2(width, height - TALK_FRAME_EDGE);
      point[9] = cocos2d::Vec2(width, TALK_FRAME_EDGE);
      point[10] = cocos2d::Vec2(width - TALK_FRAME_EDGE, 0);
    }
    else if(direction == RIGHT)
    {
      point[0] = cocos2d::Vec2(width / 2 + TALK_FRAME_ARROW_WIDTH / 2, 0);
      point[1] = cocos2d::Vec2(width / 2 + TALK_FRAME_ARROW_WIDTH / 2 / 2, -TALK_FRAME_ARROW_HEIGHT);
      point[2] = cocos2d::Vec2(width / 2 - TALK_FRAME_ARROW_WIDTH / 2, 0);
      point[3] = cocos2d::Vec2(TALK_FRAME_EDGE, 0);
      point[4] = cocos2d::Vec2(0, TALK_FRAME_EDGE);
      point[5] = cocos2d::Vec2(0, height - TALK_FRAME_EDGE);
      point[6] = cocos2d::Vec2(TALK_FRAME_EDGE, height);
      point[7] = cocos2d::Vec2(width - TALK_FRAME_EDGE, height);
      point[8] = cocos2d::Vec2(width, height - TALK_FRAME_EDGE);
      point[9] = cocos2d::Vec2(width, TALK_FRAME_EDGE);
      point[10] = cocos2d::Vec2(width - TALK_FRAME_EDGE, 0);
    }

    tmp->drawPolygon(point, 11, fillColor, lineWidth, lineColor);

    // tmp->setContentSize(cocos2d::Size(width + TALK_FRAME_ARROW_WIDTH,
    //                                   height + TALK_FRAME_ARROW_HEIGHT
    //                                  ));

    tmp->setContentSize(cocos2d::Size(width, height));

    return tmp;
  }



}


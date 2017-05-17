#include "./TalkFrame.h"

namespace jiangweigithub {

  cocos2d::Layer* TalkFrame::getTalkFrame()
  {
    auto tmp = TalkFrame::create();

    return tmp;
  }

  bool TalkFrame::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    auto drawFrame = MainSprite::getDrawFrame();
    auto leftFlower = MainSprite::getFrameLeftFlowers();
    auto rightFlower = MainSprite::getFrameRightFlowers();

    auto avatar = MainSprite::getAvatar();
    auto firstLine = MainSprite::getFirstLine();
    auto secondeLine = MainSprite::getSecondLine();
    auto thirdLine = MainSprite::getThirdLine();
    auto peopleName = MainSprite::getPeopleName();

    auto nextPageItem = MainSprite::getNextPageItem();
    nextPageItem->setCallback(CC_CALLBACK_1(TalkFrame::_NextPageCallback, this));

    auto nextPage = MainSprite::getNextPage();

    // auto background = MainSprite::getBackgroundSprite();
    // auto newGame = MainSprite::getNewGame();
    // auto loadGame = MainSprite::getLoadGame();
    // auto configGame = MainSprite::getConfigGame();

    // newGame->setCallback(CC_CALLBACK_1(LoginLayer::onNewGame, this));
    // loadGame->setCallback(CC_CALLBACK_1(LoginLayer::onLoadGame, this));
    // configGame->setCallback(CC_CALLBACK_1(LoginLayer::onConfigGame, this));

    // auto tmp = cocos2d::Menu::create(newGame, loadGame, configGame, NULL);
    // tmp->alignItemsVerticallyWithPadding(10);

    // auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    // background->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    // tmp->setPosition(cocos2d::Vec2(visibleSize.width / 2, 100));

    this->addChild(drawFrame, 0);
    this->addChild(leftFlower, 2);
    this->addChild(rightFlower, 2);
    this->addChild(avatar, 1);
    this->addChild(firstLine, 1);
    this->addChild(secondeLine, 1);
    this->addChild(thirdLine, 1);
    this->addChild(peopleName, 1);
    this->addChild(nextPage, 1);

    return true;
  }

  void TalkFrame::_NextPageCallback(cocos2d::Ref* pSender)
  {
    MainSprite::setFirstLine("Tomorrow is another day!");
    MainSprite::setSecondLine("See you then.");
    MainSprite::setThirdLine("");
    MainSprite::setPeopleName("God");
  }

}
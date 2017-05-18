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

    _talkContents = "";
    _lineCounter = 0;
    _avatar = "avatar.png";
    _firstLine = "";
    _secondLine = "";
    _thirdLine = "";
    _peopleName = "Hero";

    auto drawFrame = MainSprite::getDrawFrame();
    auto leftFlower = MainSprite::getFrameLeftFlowers();
    auto rightFlower = MainSprite::getFrameRightFlowers();

    _readTalkContents(1);
    _dealTalkContents(1);

    auto avatar = MainSprite::getAvatar(_avatar);
    auto firstLine = MainSprite::getFirstLine(_firstLine);
    auto secondeLine = MainSprite::getSecondLine(_secondLine);
    auto thirdLine = MainSprite::getThirdLine(_thirdLine);
    auto peopleName = MainSprite::getPeopleName(_peopleName);

    auto nextPageItem = MainSprite::getNextPageItem();
    nextPageItem->setCallback(CC_CALLBACK_1(TalkFrame::_nextPageCallback, this));

    auto nextPage = MainSprite::getNextPage();

    MainSprite::setFirstLine(_line[(_counter++) % 3]);
    MainSprite::setSecondLine(_line[(_counter++) % 3]);
    MainSprite::setThirdLine(_line[(_counter++) % 3]);

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

  void TalkFrame::_nextPageCallback(cocos2d::Ref* pSender)
  {
    // _dealTalkContents(1);

    MainSprite::setFirstLine(_line[(_counter++) % 3]);
    MainSprite::setSecondLine(_line[(_counter++) % 3]);
    MainSprite::setThirdLine(_line[(_counter++) % 3]);
  }

  void TalkFrame::_readTalkContents(int id)
  {
    _talkContents = "Artificial intelligence (AI) is intelligence exhibited by machines. \
In computer science, the field of AI research defines itself as the study of \"intelligent agents\": \
any device that perceives its environment and takes actions that maximize its chance of success \
at some goal. Colloquially, the term \"artificial intelligence\" is applied when a machine \
mimics \"cognitive\" functions that humans associate with other human minds, such as \"learning\" \
and \"problem solving\". ";
  }

  void TalkFrame::_dealTalkContents(int id)
  {
    int tmp = 0;
    while((tmp = _talkContents.find(". ", _position)) > 0)
    {
      _line.push_back(_talkContents.substr(_position, tmp + 2 - _position));
      _position = (tmp + 2);
    }
  }

}
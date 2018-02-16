#include "Role.h"

namespace jiangweigithub {

  bool Creature::setName(std::string name)
  {
    this->_name = name;

    return true;
  }

  std::string Creature::getName()
  {
    return this->_name;
  }

  bool Creature::setPP(unsigned int pp)
  {
    this->_physicalPoint = pp;

    return true;
  }

  unsigned int Creature::getPP()
  {
    return this->_physicalPoint;
  }

  bool Creature::setMP(unsigned int mp)
  {
    this->_mentalPoint = mp;

    return true;
  }

  unsigned int Creature::getMP()
  {
    return this->_mentalPoint;
  }

  bool Creature::setPAP(unsigned int pap)
  {
    this->_physicalAttackPoint = pap;

    return true;
  }

  unsigned int Creature::getPDP()
  {
    return this->_physicalAttackPoint;
  }

  bool Creature::setPDP(unsigned int pdp)
  {
    this->_physicalDefencePoint = pdp;

    return true;
  }

  bool Creature::setMAP(unsigned int map)
  {
    this->_mentalAttackPoint = map;

    return true;
  }

  unsigned int Creature::getMAP()
  {
    return this->_mentalAttackPoint;
  }

  bool Creature::setMDP(unsigned int mdp)
  {
    this->_mentalDefencePoint = mdp;

    return true;
  }

  unsigned int Creature::getMDP()
  {
    return this->_mentalDefencePoint;
  }

  bool Creature::setSP(unsigned int sp)
  {
    this->_speedPoint = sp;

    return true;
  }

  unsigned int Creature::getSP()
  {
    return this->_speedPoint;
  }

  bool Creature::setHP(unsigned int hp)
  {
    this->_hitPoint = hp;

    return true;
  }

  unsigned int Creature::getHP()
  {
    return this->_hitPoint;
  }

  bool Creature::setEP(unsigned int ep)
  {
    this->_evasionPoint = ep;

    return true;
  }

  unsigned int Creature::getEP()
  {
    return this->_evasionPoint;
  }

  bool Creature::setLP(unsigned int lp)
  {
    this->_luckPoint = lp;

    return true;
  }

  unsigned int Creature::getLP()
  {
    return this->_luckPoint;
  }

  bool Creature::setTextureFile(std::string path)
  {
    this->_textureFilePath = path;

    return true;
  }

  std::string Creature::getTextureFile()
  {
    return this->_textureFilePath;
  }

  cocos2d::Animation* Creature::getAnimationTop(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_topFrameVector).pushBack(tmp);
    }

    this->_animationTop = cocos2d::Animation::createWithSpriteFrames(this->_topFrameVector, FRAMES_DELAY);

    return this->_animationTop;
  }

  cocos2d::Animation* Creature::getAnimationBottom(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_bottomFrameVector).pushBack(tmp);
    }

    this->_animationBottom = cocos2d::Animation::createWithSpriteFrames(this->_bottomFrameVector, FRAMES_DELAY);

    return this->_animationBottom;
  }

  cocos2d::Animation* Creature::getAnimationLeft(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_leftFrameVector).pushBack(tmp);
    }

    this->_animationLeft = cocos2d::Animation::createWithSpriteFrames(this->_leftFrameVector, FRAMES_DELAY);

    return this->_animationLeft;
  }

  cocos2d::Animation* Creature::getAnimationRight(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_rightFrameVector).pushBack(tmp);
    }

    this->_animationRight = cocos2d::Animation::createWithSpriteFrames(this->_rightFrameVector, FRAMES_DELAY);

    return this->_animationRight;
  }

}
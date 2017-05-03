#include "./Home.h"

namespace jiangweigithub {

  cocos2d::Scene* Home::getHomeScene()
  {
    auto tmp = Home::create();

    return tmp;
  }

  bool Home::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    auto tmp = HomeLayer::getHomeLayer();
    this->addChild(tmp);


  rectangle = cocos2d::Rect(0,0,500,500);
  rectangleZone = cocos2d::Vec2(0, 0); //init

  flag_obstacle_top = flag_obstacle_bottom = flag_obstacle_left = flag_obstacle_right = false;

  obstacle = Obstacle::getInstance();

  this->flag_top = false;
  this->flag_bottom = false;
  this->flag_left = false;
  this->flag_right = false;

  // sprite = Sprite::createWithSpriteFrame(frame0);
  // sprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
  // this->addChild(sprite, 100);

  // auto animation_top = Leader::getAnimationTop();
  // auto animation_bottom = Leader::getAnimationBottom();
  // auto animation_left = Leader::getAnimationLeft();
  // auto animation_right = Leader::getAnimationRight();

  // sprite->runAction(RepeatForever::create(Animate::create(animation_bottom)));

  // position the sprite on the center of the screen
  this->_xxx = visibleSize.width/2 + origin.x;
  this->_yyy = visibleSize.height/2 + origin.y;
  // sprite->setPosition(Vec2(this->_xxx, this->_yyy));

  // add the sprite as a child to this layer
  // this->addChild(sprite, 0);

  stop_top = stop_bottom = stop_left = stop_right = false;

  keyManager = new KeyManager("STOP");

  animation_bottom = Leader::getAnimationBottom();
  animation_top = Leader::getAnimationTop();
  animation_left = Leader::getAnimationLeft();
  animation_right = Leader::getAnimationRight();


    this->scheduleUpdate();

    return true;
  }

  void Home::update(float delta)
  {
    rectangleZone = cocos2d::Vec2(this->_xxx, this->_yyy);

    if(rectangle.containsPoint(rectangleZone))
    {
      if(this->flag_top == true)
      {
        if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        {
          obstacle->setException(jiangweigithub::Obstacle::BOTTOM);
        }

        obstacle->obstacleTop();

        keyManager->pressTop(this->sprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_bottom == true)
      {
        if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        {
          obstacle->setException(jiangweigithub::Obstacle::TOP);
        }

        obstacle->obstacleBottom();

        keyManager->pressBottom(this->sprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_left == true)
      {
        if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        {
          obstacle->setException(jiangweigithub::Obstacle::RIGHT);
        }

        obstacle->obstacleLeft();

        keyManager->pressLeft(this->sprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_right == true)
      {
        if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        {
          obstacle->setException(jiangweigithub::Obstacle::LEFT);
        }

        obstacle->obstacleRight();

        keyManager->pressRight(this->sprite, this->_xxx, this->_yyy);
      }
    }
    else
    {
      obstacle->setException(jiangweigithub::Obstacle::NONE);

      obstacle->unObstacleTop();
      obstacle->unObstacleBottom();
      obstacle->unObstacleLeft();
      obstacle->unObstacleRight();

      if(this->flag_top == true)
      {
        keyManager->pressTop(this->sprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_bottom == true)
      {
        keyManager->pressBottom(this->sprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_left == true)
      {
        keyManager->pressLeft(this->sprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_right == true)
      {
        keyManager->pressRight(this->sprite, this->_xxx, this->_yyy);
      }
    }
  }

  void Home::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->flag_top = true;

        sprite->stopAllActions();
        sprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animation_bottom)));
        break;
      case 29:
        // bottom
        this->flag_bottom = true;

        sprite->stopAllActions();
        sprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animation_top)));
        break;
      case 26:
        // left
        this->flag_left = true;

        sprite->stopAllActions();
        sprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animation_left)));
        break;
      case 27:
        // right
        this->flag_right = true;

        sprite->stopAllActions();
        sprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animation_right)));
        break;
      default:
        break;
    }
  }

  void Home::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->flag_top = false;
        break;
      case 29:
        // bottom
        this->flag_bottom = false;
        break;
      case 26:
        // left
        this->flag_left = false;
        break;
      case 27:
        // right
        this->flag_right = false;
        break;
      default:
        break;
    }
  }

}
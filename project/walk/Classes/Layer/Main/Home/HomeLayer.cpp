#include "./HomeLayer.h"

namespace jiangweigithub {

  cocos2d::Layer* HomeLayer::getHomeLayer()
  {
    auto tmp = HomeLayer::create();

    return tmp;
  }

  bool HomeLayer::init()
  {
    if(!Layer::init())
    {
      return false;
    }

    // clean keyboardName Cache
    if(this->_keyboardNameCache.size() != 0)
    {
      while(this->_keyboardNameCache.empty() == false)
      {
        this->_keyboardNameCache.pop();
      }
    }

    // get view size
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    // create hero with physicsBody
    leaderSprite = cocos2d::Sprite::create();    
    cocos2d::PhysicsBody* physicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(30, 20), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, cocos2d::Vec2(15, 10));
    physicsBody->setDynamic(false);
    leaderSprite->setPhysicsBody(physicsBody);
    leaderSprite->getPhysicsBody()->setCategoryBitmask(heroMask);
    leaderSprite->getPhysicsBody()->setContactTestBitmask(heroMask | wallMask);
    leaderSprite->getPhysicsBody()->setCollisionBitmask(0x00);
    leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));

    // create background
    auto homeTitle = MainSprite::getHomeTitle();
    auto tileMapSprite = MainSprite::getTileMapSprite();
    auto mapSpriteSize = tileMapSprite->getContentSize();
    auto homeTitleSpriteSize = homeTitle->getContentSize();

    tileMapSprite->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    homeTitle->setPosition(cocos2d::Vec2((visibleSize.width - homeTitleSpriteSize.width) / 2, 660));
    leaderSprite->setPosition(cocos2d::Vec2(this->_heroPositionX, this->_heroPositionY));

    // add to the layer
    this->addChild(tileMapSprite, -1);
    this->addChild(homeTitle, 0);
    this->addChild(leaderSprite, 1);

    // add keyboard listener
    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HomeLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HomeLayer::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // get background barrier
    cocos2d::TMXTiledMap* map = cocos2d::TMXTiledMap::create("homePath.tmx");
    auto objectGroup = map->getObjectGroup("path");
    auto objects = objectGroup->getObjects();

    for (auto object: objects)
    {
      auto dic= object.asValueMap();
      auto objectX = dic.at("x").asFloat();
      auto objectY = dic.at("y").asFloat();        

      auto pointsVector = dic.at("polylinePoints").asValueVector();
      auto size = pointsVector.size();

      cocos2d::Vec2 verts[size] = {};
      int counter = 0;

      if (size>0)
      {
        for (auto pointValue:pointsVector)
        {
          auto dicp = pointValue.asValueMap();
          auto x  = dicp.at("x").asFloat();
          auto y  = -dicp.at("y").asFloat();

          verts[counter].setPoint(x + (1280 - 960) / 2, y + (720 - 480) / 2 + 480);
          counter++;
        }
      }

      cocos2d::Sprite* edgeSpace=cocos2d::Sprite::create(); 
      cocos2d::PhysicsBody* boundBody=cocos2d::PhysicsBody::createEdgePolygon(verts, counter, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 1);

      edgeSpace->setPhysicsBody(boundBody); 
      edgeSpace->setPosition(objectX , objectY - 480);
      this->addChild(edgeSpace, 0); 

      edgeSpace->getPhysicsBody()->setCategoryBitmask(wallMask);
      edgeSpace->getPhysicsBody()->setContactTestBitmask(heroMask | wallMask);
      edgeSpace->getPhysicsBody()->setCollisionBitmask(0x00);
    }

    // add physics listener
    cocos2d::EventListenerPhysicsContact* contactListener = cocos2d::EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HomeLayer::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(HomeLayer::onContactSeparate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    // enable frame update
    this->scheduleUpdate();

    return true;
  }

  void HomeLayer::update(float delta)
  {
    if(this->_keyboardNameCache.empty() == false)
    {
      if(this->_keyboardNameCache.top().compare("TOP") == 0)
      {
        if(this->_durationTop == true)
        {
          keyManager->pressTop(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        }        
      }
      if(this->_keyboardNameCache.top().compare("BOTTOM") == 0)
      {
        if(this->_durationBottom == true)
        {
          keyManager->pressBottom(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        } 
      }
      if(this->_keyboardNameCache.top().compare("LEFT") == 0)
      {
        if(this->_durationLeft == true)
        {
          keyManager->pressLeft(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        }
      }
      if(this->_keyboardNameCache.top().compare("RIGHT") == 0)
      {
        if(this->_durationRight == true)
        {
          keyManager->pressRight(this->leaderSprite, this->_heroPositionX, this->_heroPositionY);
        }
      }
    }
  }

  void HomeLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->_durationTop = true;
        this->_keyboardNameCache.push("TOP");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
        break;
      case 29:
        // bottom
        this->_durationBottom = true;
        this->_keyboardNameCache.push("BOTTOM");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
        break;
      case 26:
        // left
        this->_durationLeft = true;
        this->_keyboardNameCache.push("LEFT");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
        break;
      case 27:
        // right
        this->_durationRight = true;
        this->_keyboardNameCache.push("RIGHT");

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
        break;
      default:
        break;
    }
  }

  void HomeLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->_durationTop = false;

        if(this->_keyboardNameCache.top().compare("TOP") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("BOTTOM") == 0 && this->_durationBottom == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
          }
          else if(this->_keyboardNameCache.top().compare("LEFT") == 0 && this->_durationLeft == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
          }
          else if(this->_keyboardNameCache.top().compare("RIGHT") == 0 && this->_durationRight == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
          }
        }

        break;
      case 29:
        // bottom
        this->_durationBottom = false;

        if(this->_keyboardNameCache.top().compare("BOTTOM") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("TOP") == 0 && this->_durationTop == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
          }
          else if(this->_keyboardNameCache.top().compare("LEFT") == 0 && this->_durationLeft == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
          }
          else if(this->_keyboardNameCache.top().compare("RIGHT") == 0 && this->_durationRight == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
          }
        }

        break;
      case 26:
        // left
        this->_durationLeft = false;

        if(this->_keyboardNameCache.top().compare("LEFT") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("BOTTOM") == 0 && this->_durationBottom == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
          }
          else if(this->_keyboardNameCache.top().compare("TOP") == 0 && this->_durationTop == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
          }
          else if(this->_keyboardNameCache.top().compare("RIGHT") == 0 && this->_durationRight == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationRight())));
          }
        }

        break;
      case 27:
        // right
        this->_durationRight = false;

        if(this->_keyboardNameCache.top().compare("RIGHT") == 0)
        {
          this->_keyboardNameCache.pop();
        }

        if(this->_keyboardNameCache.empty() == false)
        {
          if(this->_keyboardNameCache.top().compare("BOTTOM") == 0 && this->_durationBottom == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
          }
          else if(this->_keyboardNameCache.top().compare("LEFT") == 0 && this->_durationLeft == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
          }
          else if(this->_keyboardNameCache.top().compare("TOP") == 0 && this->_durationTop == true)
          {
            leaderSprite->stopAllActions();
            leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
          }
        }

        break;
      default:
        break;
    }
  }

  bool HomeLayer::onContactBegin(const cocos2d::PhysicsContact& contact)
  {

    // if((contact.getShapeA()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    // {  

    // }

    // if((contact.getShapeB()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    // {  

    // }

    // if((contact.getShapeA()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    // {  

    // }

    // if((contact.getShapeB()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    // {  

    // }

    if(this->_keyboardNameCache.top().compare("TOP") == 0)
    {
      obstacle->obstacleTop();
      obstacle->unObstacleBottom();
      obstacle->unObstacleLeft();
      obstacle->unObstacleRight();
    }
    if(this->_keyboardNameCache.top().compare("BOTTOM") == 0)
    {
      obstacle->obstacleBottom();
      obstacle->unObstacleTop();
      obstacle->unObstacleLeft();
      obstacle->unObstacleRight();
    }
    if(this->_keyboardNameCache.top().compare("LEFT") == 0)
    {
      obstacle->obstacleLeft();
      obstacle->unObstacleTop();
      obstacle->unObstacleBottom();
      obstacle->unObstacleRight();
    }
    if(this->_keyboardNameCache.top().compare("RIGHT") == 0)
    {
      obstacle->obstacleRight();
      obstacle->unObstacleTop();
      obstacle->unObstacleLeft();
      obstacle->unObstacleBottom();
    }

    return true;
  }

  bool HomeLayer::onContactSeparate(const cocos2d::PhysicsContact& contact)
  {

    // if((contact.getShapeA()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    // {  

    // }

    // if((contact.getShapeB()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    // {  

    // }

    // if((contact.getShapeA()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    // {  

    // }

    // if((contact.getShapeB()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    // {  

    // } 

    obstacle->unObstacleTop();
    obstacle->unObstacleBottom();
    obstacle->unObstacleLeft();
    obstacle->unObstacleRight();

    return true;
  }

}
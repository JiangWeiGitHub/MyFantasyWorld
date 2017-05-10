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

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    leaderSprite = cocos2d::Sprite::create();
    
    cocos2d::PhysicsBody* physicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(30, 20), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, cocos2d::Vec2(15, 10));

    physicsBody->setDynamic(false);

    leaderSprite->setPhysicsBody(physicsBody);

    leaderSprite->getPhysicsBody()->setCategoryBitmask(heroMask);
    leaderSprite->getPhysicsBody()->setContactTestBitmask(heroMask | wallMask);
    leaderSprite->getPhysicsBody()->setCollisionBitmask(0x00);

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

    flag_obstacle_top = flag_obstacle_bottom = flag_obstacle_left = flag_obstacle_right = false;

    this->obstacle = Obstacle::getInstance();

    this->durationTop = false;
    this->durationBottom = false;
    this->durationLeft = false;
    this->durationRight = false;

    this->_xxx = 280;
    this->_yyy = 350;

    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HomeLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HomeLayer::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    stop_top = stop_bottom = stop_left = stop_right = false;

    keyManager = new KeyManager("STOP");


    cocos2d::TMXTiledMap* map = cocos2d::TMXTiledMap::create("homePath.tmx");

    auto objectGroup = map->getObjectGroup("path");
    auto objects = objectGroup->getObjects();    

    for (auto object: objects)
    {

      auto dic= object.asValueMap();
      objectX = dic.at("x").asFloat();
      objectY = dic.at("y").asFloat();        

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

    cocos2d::EventListenerPhysicsContact* contactListener = cocos2d::EventListenerPhysicsContact::create(); 

    contactListener->onContactBegin = CC_CALLBACK_1(HomeLayer::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(HomeLayer::onContactSeparate, this); 

    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


    this->scheduleUpdate();

    return true;
  }

  void HomeLayer::update(float delta)
  {
    // rectangleZone = cocos2d::Vec2(this->_xxx, this->_yyy);

    if(this->kissed == true)
    {
      if(this->durationTop == true)
      {
        // if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        // {
        //   obstacle->setException(jiangweigithub::Obstacle::BOTTOM);
        // }

        // obstacle->obstacleTop();
        // if(this->dir == TOP)
        // {
        // obstacle->obstacleTop();
        // obstacle->unObstacleBottom();
        // obstacle->unObstacleLeft();
        // obstacle->unObstacleRight();
        // }

        keyManager->pressTop(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->durationBottom == true)
      {
        // if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        // {
        //   obstacle->setException(jiangweigithub::Obstacle::TOP);
        // }

        // obstacle->obstacleBottom();
        // obstacle->obstacleBottom();
        // obstacle->unObstacleTop();
        // obstacle->unObstacleLeft();
        // obstacle->unObstacleRight();

        keyManager->pressBottom(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->durationLeft == true)
      {
        // if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        // {
        //   obstacle->setException(jiangweigithub::Obstacle::RIGHT);
        // }

        // obstacle->obstacleLeft();
        // obstacle->obstacleLeft();
        // obstacle->unObstacleBottom();
        // obstacle->unObstacleTop();
        // obstacle->unObstacleRight();

        keyManager->pressLeft(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->durationRight == true)
      {
        // if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        // {
        //   obstacle->setException(jiangweigithub::Obstacle::LEFT);
        // }

        // obstacle->obstacleRight();

        // obstacle->obstacleRight();
        // obstacle->unObstacleBottom();
        // obstacle->unObstacleLeft();
        // obstacle->unObstacleTop();

        keyManager->pressRight(this->leaderSprite, this->_xxx, this->_yyy);
      }
    }
    else
    {
      // obstacle->setException(jiangweigithub::Obstacle::NONE);

      // obstacle->unObstacleTop();
      // obstacle->unObstacleBottom();
      // obstacle->unObstacleLeft();
      // obstacle->unObstacleRight();

      if(this->durationTop == true)
      {
        keyManager->pressTop(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->durationBottom == true)
      {
        keyManager->pressBottom(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->durationLeft == true)
      {
        keyManager->pressLeft(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->durationRight == true)
      {
        keyManager->pressRight(this->leaderSprite, this->_xxx, this->_yyy);
      }
    }

    // if(rectangle.containsPoint(rectangleZone))
    // {

    // }
    // else
    // {

    // }

    // this->kissed = false;
  }

  void HomeLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->durationTop = true;
        this->durationBottom = false;
        this->durationLeft = false;
        this->durationRight = false;
        this->dir = TOP;

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
        break;
      case 29:
        // bottom
        this->durationBottom = true;
        this->durationTop = false;
        this->durationLeft = false;
        this->durationRight = false;
        this->dir = BOTTOM;

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
        break;
      case 26:
        // left
        this->durationLeft = true;
        this->durationTop = false;
        this->durationBottom = false;
        this->durationRight = false;
        this->dir = LEFT;

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
        break;
      case 27:
        // right
        this->durationRight = true;
        this->durationTop = false;
        this->durationLeft = false;
        this->durationBottom = false;
        this->dir = RIGHT;

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
        this->durationTop = false;
        this->durationBottom = false;
        this->durationLeft = false;
        this->durationRight = false;
        this->dir = NONE;
        break;
      case 29:
        // bottom
        this->durationTop = false;
        this->durationBottom = false;
        this->durationLeft = false;
        this->durationRight = false;
        this->dir = NONE;
        break;
      case 26:
        // left
        this->durationTop = false;
        this->durationBottom = false;
        this->durationLeft = false;
        this->durationRight = false;
        this->dir = NONE;
        break;
      case 27:
        // right
        this->durationTop = false;
        this->durationBottom = false;
        this->durationLeft = false;
        this->durationRight = false;
        this->dir = NONE;
        break;
      default:
        break;
    }
  }

  bool HomeLayer::onContactBegin(const cocos2d::PhysicsContact& contact)
  {

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  
      this->kissed = true;
    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  
      this->kissed = true;
    }

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {  
      this->kissed = true;
    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {  
      this->kissed = true;
    }

    // if(this->dir == TOP)
    // {
    //   obstacle->obstacleTop();
    // }
    // else if(this->dir == BOTTOM)
    // {
    //   obstacle->obstacleBottom();
    // }
    // else if(this->dir == LEFT)
    // {
    //   obstacle->obstacleLeft();
    // }
    // else if(this->dir == RIGHT)
    // {
    //   obstacle->obstacleRight();
    // }

    if(this->durationTop == true)
    {
      obstacle->obstacleTop();
      obstacle->unObstacleBottom();
      obstacle->unObstacleLeft();
      obstacle->unObstacleRight();
    }
    else if(this->durationBottom == true)
    {
      obstacle->obstacleBottom();
      obstacle->unObstacleTop();
      obstacle->unObstacleLeft();
      obstacle->unObstacleRight();
    }
    else if(this->durationLeft == true)
    {
      obstacle->obstacleLeft();
      obstacle->unObstacleTop();
      obstacle->unObstacleBottom();
      obstacle->unObstacleRight();
    }
    else if(this->durationRight == true)
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

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  
      this->kissed = false;
    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & heroMask) == heroMask)
    {  
      this->kissed = false;
    }

    if((contact.getShapeA()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {  
      this->kissed = false;
    }

    if((contact.getShapeB()->getBody()->getCategoryBitmask() & wallMask) == wallMask)
    {  
      this->kissed = false;
    } 

    obstacle->unObstacleTop();
    obstacle->unObstacleBottom();
    obstacle->unObstacleLeft();
    obstacle->unObstacleRight();

    return true;
  }

}
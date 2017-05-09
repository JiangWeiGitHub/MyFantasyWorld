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
    
    cocos2d::PhysicsBody* physicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(30, 50), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

    // physicsBody->setCollisionBitmask(0x0);
    // physicsBody->setMass(0);

    physicsBody->setDynamic(false);

    leaderSprite->setPhysicsBody(physicsBody);
    leaderSprite->setTag(1);


      // cocos2d::Sprite* ballOne = cocos2d::Sprite::create("CloseNormal.png"); 
      // ballOne->setPosition(visibleSize.width/2,visibleSize.height/2); 

      // cocos2d::PhysicsBody* ballBodyOne=cocos2d::PhysicsBody::createCircle(ballOne->getContentSize().width/2,cocos2d::PHYSICSBODY_MATERIAL_DEFAULT); 

      // ballBodyOne->getShape(0)->setRestitution(1.0f); 

      // ballBodyOne->getShape(0)->setFriction(0.0f); 

      // ballBodyOne->getShape(0)->setDensity(1.0f); 

      // ballBodyOne->setGravityEnable(false); 

      // cocos2d::Vect force=cocos2d::Vect(500000.0f, 500000.0f); 
      // ballBodyOne->applyImpulse(force); 

      // ballOne->setPhysicsBody(ballBodyOne); 
 
      // ballOne->setTag(1); 
      // this->addChild(ballOne); 


    leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));

    auto homeTitle = MainSprite::getHomeTitle();
    auto tileMapSprite = MainSprite::getTileMapSprite();
    auto obstacle = MainSprite::getObstacle();

    auto mapSpriteSize = tileMapSprite->getContentSize();
    auto homeTitleSpriteSize = homeTitle->getContentSize();

    tileMapSprite->setPosition(cocos2d::Vec2((visibleSize.width - mapSpriteSize.width) / 2, (visibleSize.height - mapSpriteSize.height) / 2));
    homeTitle->setPosition(cocos2d::Vec2((visibleSize.width - homeTitleSpriteSize.width) / 2, 660));
    leaderSprite->setPosition(cocos2d::Vec2(1200, 700));

    this->addChild(tileMapSprite, -1);
    this->addChild(homeTitle, 0);
    this->addChild(leaderSprite, 1);

    


  rectangle = cocos2d::Rect(0,0,1,1);
  rectangleZone = cocos2d::Vec2(0, 0); //init

  flag_obstacle_top = flag_obstacle_bottom = flag_obstacle_left = flag_obstacle_right = false;

  this->obstacle = Obstacle::getInstance();

  this->flag_top = false;
  this->flag_bottom = false;
  this->flag_left = false;
  this->flag_right = false;

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

      boundBody->setCollisionBitmask(0x1);
      // boundBody->getShape(0)->setFriction(0.0f); 
      // boundBody->getShape(0)->setRestitution(1.0f); 

      edgeSpace->setPhysicsBody(boundBody); 
      edgeSpace->setPosition(objectX , objectY - 480);
      this->addChild(edgeSpace, 200); 
      edgeSpace->setTag(0);

// http://www.cnblogs.com/HangZhe/p/5762552.html
// http://www.cocoachina.com/bbs/read.php?tid=221969
// http://blog.csdn.net/w18767104183/article/details/39241151


    }

// cocos2d::Sprite* hero = cocos2d::Sprite::create();
// this->addChild(hero, 0);
// hero->setPosition(Vec2(winSize.width / 2, hero->getContentSize().height / 2 + 10));
// //auto herobody = PhysicsBody::createBox(hero->getContentSize()); //这样设置不太精准
// cocos2d::PhysicsBody* herobody = cocos2d::PhysicsBody::create();
// Vec2 verts[] = {Vec2(0, 55), Vec2(50, -30), Vec2(-50, -30)}; //根据点组成一个多边形，这样设置的PhysicsBody是一个三角形,这里面的点的先后顺序必须可以连成一条线，不能随便写的，不然会停止运行
// //herobody->addShape(PhysicsShapeEdgePolygon::create(verts, 3));（如果是边界的话用这句）

// herobody->addShape(PhysicsShapePolygon::create(verts, 3));
// herobody->setCollisionBitmask(0x0); //不进行碰撞模拟
// herobody->setContactTestBitmask(HERO_CONTACTMASKBIT);

// herobody->setPositionOffset(Vec2(30, 0));
// hero->setPhysicsBody(herobody);

      // cocos2d::Sprite* ballOne = cocos2d::Sprite::create("CloseNormal.png"); 
      // ballOne->setPosition(visibleSize.width/2,visibleSize.height/2); 

      // cocos2d::PhysicsBody* ballBodyOne=cocos2d::PhysicsBody::createCircle(ballOne->getContentSize().width/2,cocos2d::PHYSICSBODY_MATERIAL_DEFAULT); 

      // ballBodyOne->getShape(0)->setRestitution(1.0f); 

      // ballBodyOne->getShape(0)->setFriction(0.0f); 

      // ballBodyOne->getShape(0)->setDensity(1.0f); 

      // ballBodyOne->setGravityEnable(false); 

      // cocos2d::Vect force=cocos2d::Vect(500000.0f, 500000.0f); 
      // ballBodyOne->applyImpulse(force); 

      // ballOne->setPhysicsBody(ballBodyOne); 
 
      // ballOne->setTag(1); 
      // this->addChild(ballOne); 


      // cocos2d::Sprite* ballTwo=cocos2d::Sprite::create("CloseNormal.png"); 
      // ballTwo->setPosition(visibleSize.width/2 + 100,visibleSize.height/2 + 50); 
      // cocos2d::PhysicsBody* ballBodyTwo=cocos2d::PhysicsBody::createCircle(ballOne->getContentSize().width/2,cocos2d::PHYSICSBODY_MATERIAL_DEFAULT); 

      // ballBodyTwo->getShape(0)->setRestitution(1.0f); 
      // ballBodyTwo->getShape(0)->setFriction(0.0f); 
      // ballBodyTwo->getShape(0)->setDensity(1.0f); 

      // ballBodyTwo->setGravityEnable(false); 


      // force=cocos2d::Vect(-500000.0f, -500000.0f); 
      // ballBodyTwo->applyImpulse(force); 
      // ballTwo->setPhysicsBody(ballBodyTwo); 
      // ballTwo->setTag(2); 
      // this->addChild(ballTwo); 


        cocos2d::EventListenerPhysicsContact* contactListener = cocos2d::EventListenerPhysicsContact::create(); 

        contactListener->onContactBegin = CC_CALLBACK_1(HomeLayer::hello, this); 

        _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this); 

// http://blog.csdn.net/w18767104183/article/details/39241151


    this->scheduleUpdate();

    return true;
  }






  void HomeLayer::update(float delta)
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

        keyManager->pressTop(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_bottom == true)
      {
        if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        {
          obstacle->setException(jiangweigithub::Obstacle::TOP);
        }

        obstacle->obstacleBottom();

        keyManager->pressBottom(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_left == true)
      {
        if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        {
          obstacle->setException(jiangweigithub::Obstacle::RIGHT);
        }

        obstacle->obstacleLeft();

        keyManager->pressLeft(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_right == true)
      {
        if(obstacle->getException() == jiangweigithub::Obstacle::NONE)
        {
          obstacle->setException(jiangweigithub::Obstacle::LEFT);
        }

        obstacle->obstacleRight();

        keyManager->pressRight(this->leaderSprite, this->_xxx, this->_yyy);
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
        keyManager->pressTop(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_bottom == true)
      {
        keyManager->pressBottom(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_left == true)
      {
        keyManager->pressLeft(this->leaderSprite, this->_xxx, this->_yyy);
      }
      else if(this->flag_right == true)
      {
        keyManager->pressRight(this->leaderSprite, this->_xxx, this->_yyy);
      }
    }
  }

  void HomeLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        this->flag_top = true;

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationBottom())));
        break;
      case 29:
        // bottom
        this->flag_bottom = true;

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationTop())));
        break;
      case 26:
        // left
        this->flag_left = true;

        leaderSprite->stopAllActions();
        leaderSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(Leader::getAnimationLeft())));
        break;
      case 27:
        // right
        this->flag_right = true;

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

  bool HomeLayer::hello(const cocos2d::PhysicsContact& contact)
  {
std::cout<<"aaaaa"<<std::endl;

return true;
  }

}
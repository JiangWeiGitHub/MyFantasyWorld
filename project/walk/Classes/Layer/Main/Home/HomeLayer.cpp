#include "./HomeLayer.h"

namespace jiangweigithub {

  cocos2d::Layer* HomeLayer::getHomeLayer()
  {
    auto tmp = HomeLayer::create();

    return tmp;
  }

  bool HomeLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    leaderSprite = cocos2d::Sprite::create();
    leaderSprite->setPosition(cocos2d::Vec2(visibleSize.width/2,visibleSize.height/2));
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

    


  rectangle = cocos2d::Rect(0,0,500,500);
  rectangleZone = cocos2d::Vec2(0, 0); //init

  flag_obstacle_top = flag_obstacle_bottom = flag_obstacle_left = flag_obstacle_right = false;

  this->obstacle = Obstacle::getInstance();

  this->flag_top = false;
  this->flag_bottom = false;
  this->flag_left = false;
  this->flag_right = false;

  this->_xxx = visibleSize.width/2 + origin.x;
  this->_yyy = visibleSize.height/2 + origin.y;

  auto listener = cocos2d::EventListenerKeyboard::create();
  listener->onKeyPressed = CC_CALLBACK_2(HomeLayer::onKeyPressed, this);
  listener->onKeyReleased = CC_CALLBACK_2(HomeLayer::onKeyReleased, this);

  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

  stop_top = stop_bottom = stop_left = stop_right = false;

  keyManager = new KeyManager("STOP");



// auto map = cocos2d::TMXTiledMap::create("homePath.tmx");
// // map->setPosition(Point(winSize.width / 2 - map->getContentSize().width / 2,winSize.height / 2 - map->getContentSize().height / 2));
// // addChild(map,0,1);
// auto group = map->getObjectGroup("path");
// auto obj = group->getObject("can");
// // auto dict = obj.asValueMap();
// // float cx = dict["x"].asFloat();
// // float cy = dict["y"].asFloat();
// // int index = dict["index"].asInt();
// cocos2d::Value haha = obj["x"];
// std::cout<< "cx: "  <<haha.asFloat()<<std::endl;
// // std::cout<< "cy: "  <<cy<<std::endl;
// // std::cout<< "index: "  <<index<<std::endl;



auto map = cocos2d::TMXTiledMap::create("homePath.tmx");

    auto objectGroup = map->getObjectGroup("path");
    auto objects = objectGroup->getObjects();

    for (auto object: objects)
    {

        auto dic= object.asValueMap();
        float objectX = dic.at("x").asFloat();
std::cout<< "objectX: " <<objectX<<std::endl;
        float objectY = dic.at("y").asFloat();
std::cout<< "objectY: " <<objectY<<std::endl;
        auto drawNode= cocos2d::DrawNode::create();

        auto pointsVector = dic.at("polylinePoints").asValueVector();

        auto size = pointsVector.size();

        if (size>0)
        {
            cocos2d::Vec2* points= new cocos2d::Vec2[size];
            int i =0 ;

            for (auto pointValue:pointsVector)
            {

                auto dicp = pointValue.asValueMap();
                auto x  = dicp.at("x").asFloat();

                auto y  = -dicp.at("y").asFloat();//y取负值
                points[i]= cocos2d::Vec2( x , y );
                i++;
            }

            drawNode->drawPoly(points, size, false, cocos2d::Color4F::RED);
            delete[] points;
            drawNode->setPosition(objectX+160, objectY+120);
            this->addChild(drawNode,10);
        }
    }




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

}
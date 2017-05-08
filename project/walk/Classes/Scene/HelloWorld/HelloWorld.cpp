#include "./HelloWorld.h"

namespace jiangweigithub {

  cocos2d::Scene* HelloWorld::createScene()
  {
    cocos2d::Scene* scene=cocos2d::Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
    HelloWorld* layer=HelloWorld::create();

    // layer->setPhyWorld(scene->getPhysicsWorld());
    scene->addChild(layer);

    return scene;  
  }

  bool HelloWorld::init()
  {
    if(!cocos2d::Layer::init()) 
      { 
          return false; 
      } 

      cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize(); 
      cocos2d::Point origin = cocos2d::Director::getInstance()->getVisibleOrigin(); 

      ballOne = cocos2d::Sprite::create("CloseNormal.png"); 
      ballOne->setPosition(visibleSize.width/2,visibleSize.height/2); 

      cocos2d::PhysicsBody* ballBodyOne=cocos2d::PhysicsBody::createCircle(ballOne->getContentSize().width/2,cocos2d::PHYSICSBODY_MATERIAL_DEFAULT); 

      ballBodyOne->getShape(0)->setRestitution(1.0f); 

      ballBodyOne->getShape(0)->setFriction(0.0f); 

      ballBodyOne->getShape(0)->setDensity(1.0f); 

      ballBodyOne->setGravityEnable(false); 

      cocos2d::Vect force=cocos2d::Vect(500000.0f, 500000.0f); 
      ballBodyOne->applyImpulse(force); 

      ballOne->setPhysicsBody(ballBodyOne); 
 
      ballOne->setTag(1); 
      this->addChild(ballOne); 


      ballTwo=cocos2d::Sprite::create("CloseNormal.png"); 
      ballTwo->setPosition(visibleSize.width/2 + 100,visibleSize.height/2 + 50); 
      cocos2d::PhysicsBody* ballBodyTwo=cocos2d::PhysicsBody::createCircle(ballOne->getContentSize().width/2,cocos2d::PHYSICSBODY_MATERIAL_DEFAULT); 

      ballBodyTwo->getShape(0)->setRestitution(1.0f); 
      ballBodyTwo->getShape(0)->setFriction(0.0f); 
      ballBodyTwo->getShape(0)->setDensity(1.0f); 

      ballBodyTwo->setGravityEnable(false); 


      force=cocos2d::Vect(-500000.0f, -500000.0f); 
      ballBodyTwo->applyImpulse(force); 
      ballTwo->setPhysicsBody(ballBodyTwo); 
      ballTwo->setTag(2); 
      this->addChild(ballTwo); 

 




// auto map = cocos2d::TMXTiledMap::create("homePath.tmx");

//     auto objectGroup = map->getObjectGroup("path");
//     auto objects = objectGroup->getObjects();

//     for (auto object: objects)
//     {

//         auto dic= object.asValueMap();
//         objectX = dic.at("x").asFloat();
// std::cout<< "objectX: " <<objectX<<std::endl;
//         objectY = dic.at("y").asFloat();
// std::cout<< "objectY: " <<objectY<<std::endl;
//         auto drawNode= cocos2d::DrawNode::create();

//         auto pointsVector = dic.at("polylinePoints").asValueVector();

//         auto size = pointsVector.size();

//         if (size>0)
//         {
//             cocos2d::Vec2* points= new cocos2d::Vec2[size];
//             int i =0 ;

//             for (auto pointValue:pointsVector)
//             {

//                 auto dicp = pointValue.asValueMap();
//                 auto x  = dicp.at("x").asFloat();
// std::cout<< "x: " <<x<<std::endl;
//                 auto y  = -dicp.at("y").asFloat();//y取负值
// std::cout<< "y: " <<y<<std::endl;
//                 verts->add(cocos2d::Vec2(x , y));

//                 points[i]= cocos2d::Vec2( x , y );
//                 i++;
//             }

//             counter = i;

//             // drawNode->drawPoly(points, size, false, cocos2d::Color4F::RED);
//             delete[] points;
//             // drawNode->setPosition(objectX+160, objectY+120);
//             // this->addChild(drawNode,10);
//         }
//     }




      cocos2d::Sprite* edgeSpace=cocos2d::Sprite::create(); 
    //   cocos2d::PhysicsBody* boundBody=cocos2d::PhysicsBody::createEdgeBox(visibleSize,cocos2d::PHYSICSBODY_MATERIAL_DEFAULT,3); 


cocos2d::Vec2 aaa[] = {
                        cocos2d::Vec2(200, 100),
                        cocos2d::Vec2(200, -100),
                        cocos2d::Vec2(100, -200),
                        cocos2d::Vec2(-100, -200),
                        cocos2d::Vec2(-200, -100),
                        cocos2d::Vec2(-200, 100),
                        cocos2d::Vec2(-100, 200),
                        cocos2d::Vec2(100, 200),
                      };
      cocos2d::PhysicsBody* boundBody=cocos2d::PhysicsBody::createEdgePolygon(aaa, 8, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 1);

      boundBody->getShape(0)->setFriction(0.0f); 
      boundBody->getShape(0)->setRestitution(1.0f); 

      edgeSpace->setPhysicsBody(boundBody); 
      edgeSpace->setPosition(cocos2d::Point(visibleSize.width/2,visibleSize.height/2)); 
      this->addChild(edgeSpace); 
      edgeSpace->setTag(0);




        // verts[0] = {cocos2d::Vec2(0, 55)};
        // verts[1] = {cocos2d::Vec2(50, -30)};
        // verts[2] = {cocos2d::Vec2(-50, -30)};
        
        // cocos2d::Sprite* edgeSpace = cocos2d::Sprite::create();
        // this->addChild(edgeSpace, 100);
        // edgeSpace->setPosition(cocos2d::Vec2(objectX+160, objectY+120));

        // cocos2d::PhysicsBody* boundBody = cocos2d::PhysicsBody::create();
        // boundBody->addShape(cocos2d::PhysicsShapeEdgePolygon::create(verts, 3));
        // boundBody->getShape(0)->setFriction(0.0f); 
        // boundBody->getShape(0)->setRestitution(1.0f); 
     
        // edgeSpace->setPhysicsBody(boundBody);
        // edgeSpace->setTag(0); 
 
        this->addChild(edgeSpace); 



      return true; 
  }

}
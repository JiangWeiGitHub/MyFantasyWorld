#include "./Preface.h"

namespace jiangweigithub {

  cocos2d::Scene* PrefaceScene::getPrefaceScene()
  {
    auto tmp = PrefaceScene::create();

    return tmp;
  }

  bool PrefaceScene::init()
  {
    if(!cocos2d::Scene::init()) 
    {
      return false;
    }

    // auto tmp = PrefaceLayer::getPrefaceLayer();
    // this->addChild(tmp, 0);

    auto aaa  = this->drawRoundRect(285, 285, 0.5, cocos2d::Color4F(1, 1, 1, 1.0), 15, 50);

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    // cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    // aaa->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    // auto tmp = aaa->getContentSize();
    // std::cout<<tmp.width<<std::endl;
    // std::cout<<tmp.height<<std::endl;


    cocos2d::ClippingNode* cliper = cocos2d::ClippingNode::create();

    cliper->setStencil(aaa);  
    cliper->setAnchorPoint(cocos2d::Vec2(0, 0));
    cliper->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));

    auto hehe = cocos2d::Sprite::create("login.jpg");
    cliper->addChild(hehe);

    this->addChild(cliper, 1);


    // this->addChild(aaa, 1);

    return true;
  }





  cocos2d::DrawNode* PrefaceScene::drawRoundRect(int width, int height, float lineWidth, cocos2d::Color4F color,int radius, unsigned int segments)
  {
    radius || (radius = 15);
    cocos2d::DrawNode* roundRect = cocos2d::DrawNode::create();

    glLineWidth(1.0f);

    roundRect->drawSegment(cocos2d::Vec2(radius,0), cocos2d::Vec2(width-radius,0), lineWidth, color);
    roundRect->drawQuadBezier(cocos2d::Vec2(width-radius,0), cocos2d::Vec2(width,0), cocos2d::Vec2(width,radius), segments, color);
    roundRect->drawSegment(cocos2d::Vec2(width,radius), cocos2d::Vec2(width,height-radius), lineWidth, color);
    roundRect->drawQuadBezier(cocos2d::Vec2(width,height-radius), cocos2d::Vec2(width,height), cocos2d::Vec2(width - radius,height), segments, color);
    roundRect->drawSegment(cocos2d::Vec2(width - radius,height), cocos2d::Vec2(radius,height), lineWidth, color);
    roundRect->drawQuadBezier(cocos2d::Vec2(radius,height), cocos2d::Vec2(0,height), cocos2d::Vec2(0,height - radius), segments, color);
    roundRect->drawSegment(cocos2d::Vec2(0,height - radius), cocos2d::Vec2(0,radius), lineWidth, color);
    roundRect->drawQuadBezier(cocos2d::Vec2(0,radius), cocos2d::Vec2(0,0), cocos2d::Vec2(radius,0), segments, color);

    return roundRect;
  }






}
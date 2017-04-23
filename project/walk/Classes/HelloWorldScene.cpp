#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    auto textTure = Director::getInstance()->getTextureCache()->addImage("sabin.png");
    // top
    SpriteFrame* frame0 = SpriteFrame::createWithTexture(textTure, Rect(270,0,30,50));
    SpriteFrame* frame1 = SpriteFrame::createWithTexture(textTure, Rect(300,0,30,50));
    SpriteFrame* frame2 = SpriteFrame::createWithTexture(textTure, Rect(330,0,30,50));
    SpriteFrame* frame3 = SpriteFrame::createWithTexture(textTure, Rect(300,0,30,50));

    // bottom
    SpriteFrame* frame4 = SpriteFrame::createWithTexture(textTure, Rect(0,0,30,50));
    SpriteFrame* frame5 = SpriteFrame::createWithTexture(textTure, Rect(30,0,30,50));
    SpriteFrame* frame6 = SpriteFrame::createWithTexture(textTure, Rect(60,0,30,50));
    SpriteFrame* frame7 = SpriteFrame::createWithTexture(textTure, Rect(30,0,30,50));

    // left
    SpriteFrame* frame8 = SpriteFrame::createWithTexture(textTure, Rect(90,0,30,50));
    SpriteFrame* frame9 = SpriteFrame::createWithTexture(textTure, Rect(120,0,30,50));
    SpriteFrame* frame10 = SpriteFrame::createWithTexture(textTure, Rect(150,0,30,50));
    SpriteFrame* frame11 = SpriteFrame::createWithTexture(textTure, Rect(120,0,30,50));

    // right
    SpriteFrame* frame12 = SpriteFrame::createWithTexture(textTure, Rect(180,0,30,50));
    SpriteFrame* frame13 = SpriteFrame::createWithTexture(textTure, Rect(210,0,30,50));
    SpriteFrame* frame14 = SpriteFrame::createWithTexture(textTure, Rect(240,0,30,50));
    SpriteFrame* frame15 = SpriteFrame::createWithTexture(textTure, Rect(210,0,30,50));
     
    Vector<SpriteFrame*> top;
    top.pushBack(frame0);
    top.pushBack(frame1);
    top.pushBack(frame2);
    top.pushBack(frame3);

    Vector<SpriteFrame*> bottom;
    bottom.pushBack(frame4);
    bottom.pushBack(frame5);
    bottom.pushBack(frame6);
    bottom.pushBack(frame7);

    Vector<SpriteFrame*> left;
    left.pushBack(frame8);
    left.pushBack(frame9);
    left.pushBack(frame10);
    left.pushBack(frame11);

    Vector<SpriteFrame*> right;
    right.pushBack(frame12);
    right.pushBack(frame13);
    right.pushBack(frame14);
    right.pushBack(frame15);
 
    sprite = Sprite::createWithSpriteFrame(frame0);
    sprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    addChild(sprite);
     
    auto animation_top = Animation::createWithSpriteFrames(top,0.2f);
    auto animation_bottom = Animation::createWithSpriteFrames(bottom,0.2f);
    auto animation_left = Animation::createWithSpriteFrames(left,0.2f);
    auto animation_right = Animation::createWithSpriteFrames(right,0.2f);

    sprite->runAction(RepeatForever::create(Animate::create(animation_top)));

    // position the sprite on the center of the screen
    this->_xxx = visibleSize.width/2 + origin.x;
    this->_yyy = visibleSize.height/2 + origin.y;
    sprite->setPosition(Vec2(this->_xxx, this->_yyy));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);



  // creating a keyboard event listener
  auto listener = EventListenerKeyboard::create();
  listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
  listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);

  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

// Implementation of the keyboard event callback function prototype
void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    auto textTure = Director::getInstance()->getTextureCache()->addImage("sabin.png");
    // top
    SpriteFrame* frame0 = SpriteFrame::createWithTexture(textTure, Rect(270,0,30,50));
    SpriteFrame* frame1 = SpriteFrame::createWithTexture(textTure, Rect(300,0,30,50));
    SpriteFrame* frame2 = SpriteFrame::createWithTexture(textTure, Rect(330,0,30,50));
    SpriteFrame* frame3 = SpriteFrame::createWithTexture(textTure, Rect(300,0,30,50));

    // bottom
    SpriteFrame* frame4 = SpriteFrame::createWithTexture(textTure, Rect(0,0,30,50));
    SpriteFrame* frame5 = SpriteFrame::createWithTexture(textTure, Rect(30,0,30,50));
    SpriteFrame* frame6 = SpriteFrame::createWithTexture(textTure, Rect(60,0,30,50));
    SpriteFrame* frame7 = SpriteFrame::createWithTexture(textTure, Rect(30,0,30,50));

    // left
    SpriteFrame* frame8 = SpriteFrame::createWithTexture(textTure, Rect(90,0,30,50));
    SpriteFrame* frame9 = SpriteFrame::createWithTexture(textTure, Rect(120,0,30,50));
    SpriteFrame* frame10 = SpriteFrame::createWithTexture(textTure, Rect(150,0,30,50));
    SpriteFrame* frame11 = SpriteFrame::createWithTexture(textTure, Rect(120,0,30,50));

    // right
    SpriteFrame* frame12 = SpriteFrame::createWithTexture(textTure, Rect(180,0,30,50));
    SpriteFrame* frame13 = SpriteFrame::createWithTexture(textTure, Rect(210,0,30,50));
    SpriteFrame* frame14 = SpriteFrame::createWithTexture(textTure, Rect(240,0,30,50));
    SpriteFrame* frame15 = SpriteFrame::createWithTexture(textTure, Rect(210,0,30,50));
     
    Vector<SpriteFrame*> top;
    top.pushBack(frame0);
    top.pushBack(frame1);
    top.pushBack(frame2);
    top.pushBack(frame3);

    Vector<SpriteFrame*> bottom;
    bottom.pushBack(frame4);
    bottom.pushBack(frame5);
    bottom.pushBack(frame6);
    bottom.pushBack(frame7);

    Vector<SpriteFrame*> left;
    left.pushBack(frame8);
    left.pushBack(frame9);
    left.pushBack(frame10);
    left.pushBack(frame11);

    Vector<SpriteFrame*> right;
    right.pushBack(frame12);
    right.pushBack(frame13);
    right.pushBack(frame14);
    right.pushBack(frame15);
 
    auto animation_top = Animation::createWithSpriteFrames(top,0.2f);
    auto animation_bottom = Animation::createWithSpriteFrames(bottom,0.2f);
    auto animation_left = Animation::createWithSpriteFrames(left,0.2f);
    auto animation_right = Animation::createWithSpriteFrames(right,0.2f);



  log("Key with keycode %d pressed", keyCode);
  switch((int)keyCode)
  {
    case 28:
      // top
      this->_yyy += 5;
      sprite->stopAllActions();
      sprite->setPosition(Vec2(this->_xxx, this->_yyy));
      sprite->runAction(RepeatForever::create(Animate::create(animation_bottom)));
      break;
    case 29:
      // bottom
      this->_yyy -= 5;
      sprite->stopAllActions();
      sprite->setPosition(Vec2(this->_xxx, this->_yyy));
      sprite->runAction(RepeatForever::create(Animate::create(animation_top)));
      break;
    case 26:
      // left
      this->_xxx -= 5;
      sprite->stopAllActions();
      sprite->setPosition(Vec2(this->_xxx, this->_yyy));
      sprite->runAction(RepeatForever::create(Animate::create(animation_left)));
      break;
    case 27:
      // right
      this->_xxx += 5;
      sprite->stopAllActions();
      sprite->setPosition(Vec2(this->_xxx, this->_yyy));
      sprite->runAction(RepeatForever::create(Animate::create(animation_right)));
      break;
    default:
      break;
  }
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
  log("Key with keycode %d released", keyCode);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}

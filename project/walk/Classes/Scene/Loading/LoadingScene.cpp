#include "./LoadingScene.h"

namespace jiangweigithub {

  // LoadingScene::LoadingScene()
  // {
  //   loadingScene = NULL;
  // }

  // LoadingScene::~LoadingScene()
  // {
  //   delete loadingScene;
  // }

  bool LoadingScene::init()
  {
    if(!Scene::init())
    {
      return false;
    }

    auto tmp = LoadingLayer::getLoadingLayer();

    this->addChild(tmp);



    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = cocos2d::MenuItemImage::create(
                                            "CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(LoadingScene::menuCloseCallback, this));
    
    closeItem->setPosition(cocos2d::Vec2(1100 ,100));

    // create menu, it's an autorelease object
    auto menu = cocos2d::Menu::create(closeItem, NULL);
    menu->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(menu, 1);



    // std::thread tA(&LoadingScene::myThreadA,this);
    // tA.detach();

    return true;
  }

  void LoadingScene::myThreadA()
  {
    std::cout<<"aaaaaaaaaaaa"<<std::endl;
    sleep(5);
    std::cout<<"bbbbbbbbbbbb"<<std::endl;
    
    auto homeScene = jiangweigithub::Home::getHomeScene();
    cocos2d::Director::getInstance()->replaceScene(homeScene);

    std::cout<<"cccccccccccc"<<std::endl;
  }

  cocos2d::Scene* LoadingScene::getLoadingScene()
  {
    // loadingScene = cocos2d::Scene::create();

// cocos2d::Label* label1 = cocos2d::Label::createWithTTF("My Game", "Marker Felt.ttf", 36);
//  loadingScene->addChild(label1);

    // loadingScene->addChild((new LoadingLayer())->getLoadingLayer());

    auto tmp = LoadingScene::create();
    return tmp;
  }

  void LoadingScene::loadingSceneCallback(Ref* pSender)
  {
    // std::cout<<"aaaaaaaaaaaa"<<std::endl;
    // sleep(5);
    // std::cout<<"bbbbbbbbbbbbbbbbb"<<std::endl;

    // // cocos2d::Scene* myScene = cocos2d::Scene::create();

    // // std::cout<<"ccccccccccccccc"<<std::endl;

    // // cocos2d::Layer* haha = cocos2d::Layer::create();
    // // cocos2d::Label* label1 = cocos2d::Label::createWithTTF("wawawa", "fonts/arial.ttf", 24);
    // // label1->setPosition(cocos2d::Vec2(200, 200));

    // // std::cout<<"ddddddddddddddddd"<<std::endl;
    // // CCLOG("my scene: %p", scene);

    // // haha->addChild(label1);
    // // myScene->addChild(haha);

    // // std::cout<<"eeeeeeeeeeeeeeeeeeeee"<<std::endl;

    // // (*callback)->replaceScene(*scene);
    // cocos2d::Director::getInstance()->replaceScene(pSender);

    // // cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5, scene, cocos2d::Color3B(0,255,255)));
    // std::cout<<"fffffffffffffffffffff"<<std::endl;
    // sleep(55);
  }  

  void LoadingScene::menuCloseCallback(Ref* pSender)
  {
    //Close the cocos2d-x game scene and quit the application

    auto homeScene = jiangweigithub::Home::getHomeScene();
    // cocos2d::Director::getInstance()->end();
    cocos2d::Director::getInstance()->replaceScene(homeScene);

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
      exit(0);
    #endif
      
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);    
  }


}
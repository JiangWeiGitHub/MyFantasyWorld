#include "./Director.h"

namespace jiangweigithub {

  cocos2d::Director* Director::director = cocos2d::Director::getInstance();

  void Director::initDirector()
  {
    director = cocos2d::Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
      glview = cocos2d::GLViewImpl::createWithRect("walk", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
    #else
      glview = cocos2d::GLViewImpl::create("walk");
    #endif
    
      director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
      director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
      director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
      director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }
  }

  void Director::openLoadingScene()
  {
    auto scene = LoadingScene::getLoadingScene();
    director->runWithScene(scene);
  }

  void Director::loadingSceneCallback()
  {
    auto loginScene = jiangweigithub::Login::getLoginScene();
    director->replaceScene(loginScene);
  }

  void Director::loginSceneCallback()
  {
    auto homeScene = jiangweigithub::Home::getHomeScene();
    director->replaceScene(homeScene);
  }

  // Director::Director()
  // {
  //   this->_director = cocos2d::Director::getInstance();

  //   auto glview = this->_director->getOpenGLView();

  //   if(!glview) {
  //     glview = cocos2d::GLViewImpl::create("walk");    
  //     director->setOpenGLView(glview);
  //   }

  //   // turn on display FPS
  //   this->_director->setDisplayStats(true);

  //   // set FPS. the default value is 1.0/60 if you don't call this
  //   this->_director->setAnimationInterval(1.0f / 60);

  //   // Set the design resolution
  //   glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::NO_BORDER);

  //   auto frameSize = glview->getFrameSize();

  //   // this->_director->setContentScaleFactor(1280, 720);
  // }
  
  // Director::~Director()
  // {

  // }  

  // cocos2d::Director* Director::getDirector()
  // {
  //   return this->_director;
  // }

}
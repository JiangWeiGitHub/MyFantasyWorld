#include "./Director.h"

namespace jiangweigithub {

  Director::Director()
  {
    director = cocos2d::Director::getInstance();


    auto glview = director->getOpenGLView();

    if(!glview) {
      glview = cocos2d::GLViewImpl::create("walk");    
      director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::NO_BORDER);

    auto frameSize = glview->getFrameSize();

    // director->setContentScaleFactor(1280, 720);
  }
  
  Director::~Director()
  {
    delete director;
  }  

  cocos2d::Director* Director::getDirector()
  {
    return director;
  } 

  void Director::loadingSceneCallback()
  {

  }

}
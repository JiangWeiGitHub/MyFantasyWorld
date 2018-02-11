#include "./Director.h"

namespace jiangweigithub {

  cocos2d::Director* Director::director = cocos2d::Director::getInstance();
  enum CHAPTER Director::_chapter = CHAPTER::HOME;

  void Director::initDirector()
  {
    auto glview = director->getOpenGLView();
    if(!glview)
    {
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
      glview = cocos2d::GLViewImpl::createWithRect("My Fantasy World", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
    #else
      glview = cocos2d::GLViewImpl::create("My Fantasy World");
    #endif
    
      director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0f / 60);

    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    if (frameSize.height > mediumResolutionSize.height)
    {        
      director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    else if (frameSize.height > smallResolutionSize.height)
    {        
      director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    else
    {        
      director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }
  }

  void Director::switchLoginScene()
  {
    auto loginScene = jiangweigithub::LoginScene::getLoginScene();
    director->runWithScene(loginScene);
  }

  void Director::openLoadingScene()
  {
    auto LoadingScene = jiangweigithub::LoadingScene::getLoadingScene();
    director->runWithScene(LoadingScene);
  }

  void Director::openIntroduceScene()
  {
    auto introduceScene = jiangweigithub::IntroduceScene::getIntroduceScene();

    director->runWithScene(introduceScene);
  }

  void Director::loadingSceneCallback()
  {
    auto loginScene = jiangweigithub::LoginScene::getLoginScene();
    director->replaceScene(loginScene);
  }

  void Director::loginSceneCallback()
  {
    auto homeScene = jiangweigithub::HomeScene::getHomeScene();
    director->replaceScene(homeScene);
  }

  void Director::setChapter(enum CHAPTER chapter)
  {
    _chapter = chapter;
  }

  enum CHAPTER Director::getChapter()
  {
    return _chapter;
  }

  void Director::playBackgroundMusic(std::string name)
  {
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic(name.c_str(), true);
  }

  void Director::stopBackgroundMusic()
  {

  }

  void Director::setBackgroundMusicVolume(float volume)
  {
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->setBackgroundMusicVolume(volume / 100);
  }

  void Director::playEffectMusic(std::string name)
  {
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playEffect(name.c_str(), false, 1.0f, 1.0f, 1.0f);
  }

  void Director::stopEffectMusic()
  {

  }

  void Director::setEffectMusicVolume(float volume)
  {

  }

  int Director::getBGMVolume()
  {
    std::map<std::string, std::string> returnResult;
    std::map<std::string, std::string>::iterator iter;
    jiangweigithub::Database* tmpSQLite = jiangweigithub::Database::getDatabaseInstance();

    int _musicVolume, _bgmVolume, _subtitle;

    std::string tmp = "SELECT musicVolume,bgmVolume,subtitle FROM system";
    std::cout<<tmp<<std::endl;
    tmpSQLite->runSQL(tmp, (void *)(&returnResult));
    for(iter = returnResult.begin(); iter != returnResult.end(); iter++)
    {
      // std::cout<<iter->first<<' '<<iter->second<<std::endl;
      if(iter->first == "musicVolume")
      {
        std::istringstream iss(iter->second);
        iss >> _musicVolume;
      }
      else if(iter->first == "bgmVolume")
      {
        std::istringstream iss(iter->second);  
        iss >> _bgmVolume;

        return _bgmVolume;
      }
      else if(iter->first == "subtitle")
      {
        std::istringstream iss(iter->second);  
        iss >> _subtitle;
      }
    }
  }

  int Director::setBGMVolume(int volume)
  {

  }

  int Director::getLanguage()
  {
    std::map<std::string, std::string> returnResult;
    std::map<std::string, std::string>::iterator iter;
    jiangweigithub::Database* tmpSQLite = jiangweigithub::Database::getDatabaseInstance();

    int _musicVolume, _bgmVolume, _subtitle;

    std::string tmp = "SELECT musicVolume,bgmVolume,subtitle FROM system";
    std::cout<<tmp<<std::endl;
    tmpSQLite->runSQL(tmp, (void *)(&returnResult));
    for(iter = returnResult.begin(); iter != returnResult.end(); iter++)
    {
      // std::cout<<iter->first<<' '<<iter->second<<std::endl;
      if(iter->first == "musicVolume")
      {
        std::istringstream iss(iter->second);
        iss >> _musicVolume;
      }
      else if(iter->first == "bgmVolume")
      {
        std::istringstream iss(iter->second);  
        iss >> _bgmVolume;
      }
      else if(iter->first == "subtitle")
      {
        std::istringstream iss(iter->second);  
        iss >> _subtitle;

        return _subtitle;
      }
    }
  }

  int Director::setLanguage(enum LANGUAGE type)
  {

  }

}
#include "AppDelegate.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
  // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
  GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

  GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
  return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
  register_all_packages();

  jiangweigithub::Director::initDirector();

  // std::map<std::string, std::string> returnResult;
  // std::map<std::string, std::string>::iterator iter;
  // jiangweigithub::Database* tmpSQLite = jiangweigithub::Database::getDatabaseInstance();

  // int _musicVolume, _bgmVolume, _subtitle;

  // std::string tmp = "SELECT musicVolume,bgmVolume,subtitle FROM system";
  // std::cout<<tmp<<std::endl;
  // tmpSQLite->runSQL(tmp, (void *)(&returnResult));
  // for(iter = returnResult.begin(); iter != returnResult.end(); iter++)
  // {
  //   // std::cout<<iter->first<<' '<<iter->second<<std::endl;
  //   if(iter->first == "musicVolume")
  //   {
  //     std::istringstream iss(iter->second);
  //     iss >> _musicVolume;
  //   }
  //   else if(iter->first == "bgmVolume")
  //   {
  //     std::istringstream iss(iter->second);  
  //     iss >> _bgmVolume;
  //   }
  //   else if(iter->first == "subtitle")
  //   {
  //     std::istringstream iss(iter->second);  
  //     iss >> _subtitle;
  //   }
  // }

  jiangweigithub::Director::playBackgroundMusic("music/background/The Sixth Station.mp3");
  jiangweigithub::Director::setBackgroundMusicVolume(jiangweigithub::Director::getBGMVolume());

  jiangweigithub::Director::openIntroduceScene();

  return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
  Director::getInstance()->stopAnimation();

  // if you use SimpleAudioEngine, it must be paused
  // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
  Director::getInstance()->startAnimation();

  // if you use SimpleAudioEngine, it must resume here
  // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

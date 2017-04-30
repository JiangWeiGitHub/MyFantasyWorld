#include "./LoadingScene.h"

LoadingScene::LoadingScene()
{
  loadingScene = NULL;
}

LoadingScene::~LoadingScene()
{
  delete loadingScene;
}

cocos2d::Scene* LoadingScene::getLoadingScene()
{
  loadingScene = cocos2d::Scene::create();
  loadingScene->addChild((new LoadingLayer())->getLoadingLayer());
  return loadingScene;
}
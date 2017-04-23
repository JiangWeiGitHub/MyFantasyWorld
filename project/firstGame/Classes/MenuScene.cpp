#include "MenuScene.h"
#include "MenuLayer.h"
#include "Audio.h"
#include "StartScene.h"

bool MenuScene::init()
{
	if(!Scene::init())
	{
		return false;
	}

	Audio::getInstance()->playBGM();

    this->addChild(StartScene::create(), 0, "startlayer");
	this->addChild(MenuLayer::create(), 1, "menulayer");

    scheduleOnce(schedule_selector(MenuScene::run_startScene), 0.0f);

	return true;
}

void MenuScene::run_startScene(float dt)
{
    if(this->getNumberOfRunningActions() == 0)
    {
        ((StartScene*)(this->getChildByName("startlayer")))->run();

        scheduleOnce(schedule_selector(MenuScene::run_menuScene), 16.0f);
    }
}

void MenuScene::run_menuScene(float dt)
{
    if(this->getNumberOfRunningActions() == 0)
    {
    	((MenuLayer*)(this->getChildByName("menulayer")))->run();
    }
}

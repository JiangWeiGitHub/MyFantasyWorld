#include "MenuLayer.h"
#include "GameScene.h"
#include "GameData.h"
#include "Audio.h"
bool MenuLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* background = Sprite::create("material_6.jpg");
	background->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(background,-1);

    auto button = Button::create("test.png", "test2.png", "test.png");
    button->addClickEventListener(CC_CALLBACK_0(MenuLayer::startGame,this));
    button->setPosition(Vec2(visibleSize.width/2,visibleSize.height/3));
    this->addChild(button);

	return true;
}

void MenuLayer::startGame()
{
	CCLOG("START!");
	GAMEDATA::getInstance()->init();
	Director::getInstance()->replaceScene(GameScene::create());
}

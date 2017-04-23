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

	return true;
}

void MenuLayer::run()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* background = Sprite::create("../Resources/background.jpg");
	background->setPosition(visibleSize.width/2,visibleSize.height/2);
	background->setOpacity(0);

    auto fadeIn_my_background = FadeIn::create(3.0f);

	this->addChild(background,0);

    auto seq_background = Sequence::create(fadeIn_my_background, nullptr);
    background->runAction(seq_background);

    ////////////////////////////////////
	auto my_title = Label::createWithTTF("John's Dream World", "../Resources/fonts/Verdana Bold.ttf", 66);
	my_title->setPosition(visibleSize.width/2,visibleSize.height/1.5);
	my_title->setOpacity(0);
	my_title->enableShadow(Color4B::BLACK, Size(2 ,-2), 0);

	auto fadeIn_my_title = FadeIn::create(3.0f);

	this->addChild(my_title,0);

	auto seq_title = Sequence::create(fadeIn_my_title, nullptr);
	my_title->runAction(seq_title);

    ////////////////////////////////////
    auto button = Button::create("start_menu_normal.png", "start_menu_clicked.png", "start_menu_clicked.png");
    button->addClickEventListener(CC_CALLBACK_0(MenuLayer::startGame, this));
    button->setPosition(Vec2(visibleSize.width/2,visibleSize.height/3));
    button->setOpacity(0);

    auto fadeIn_my_button = FadeIn::create(5.0f);

    this->addChild(button);

    auto seq_button = Sequence::create(fadeIn_my_button, nullptr);
    button->runAction(seq_button);
}

void MenuLayer::startGame()
{
	CCLOG("START!");
	GAMEDATA::getInstance()->init();
	Director::getInstance()->replaceScene(GameScene::create());
}

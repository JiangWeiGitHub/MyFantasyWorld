#include "StartScene.h"
#include "Audio.h"

bool StartScene::init()
{
	if(!Layer::init())
	{
		return false;
	}

	return true;
}

void StartScene::run()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto logo_layer = LayerColor::create();
	this->addChild(logo_layer);

	auto my_logo = Sprite::create("logo_1.png");
	my_logo->setPosition(visibleSize.width/2,visibleSize.height/2);
	my_logo->setOpacity(0);
	my_logo->setScale(0.2f);

	auto fadeIn_my_logo = FadeIn::create(3.0f);
	auto fadeOut_my_logo = FadeOut::create(3.0f);

	logo_layer->addChild(my_logo,0);

	auto seq = Sequence::create(fadeIn_my_logo, fadeOut_my_logo, nullptr);
	my_logo->runAction(seq);

	///////////////////////////////////
	auto thanks_layer = LayerColor::create();
	this->addChild(thanks_layer);

	auto my_thanks = Label::createWithTTF("JOHN'S PRODUCT", "fonts/Verdana Bold.ttf", 66);
	my_thanks->setPosition(visibleSize.width/2,visibleSize.height/2);
	my_thanks->setOpacity(0);
	my_thanks->enableOutline(Color4B::GRAY, 3);

	auto fadeIn_my_thanks = FadeIn::create(3.0f);
	auto fadeOut_my_thanks = FadeOut::create(3.0f);

	thanks_layer->addChild(my_thanks,0);

	auto delay = DelayTime::create(8.0f);

	auto seq1 = Sequence::create(delay, fadeIn_my_thanks, fadeOut_my_thanks, nullptr);
	my_thanks->runAction(seq1);
}

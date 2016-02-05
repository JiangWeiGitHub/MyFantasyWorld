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

	Size visibleSize = Director::getInstance()->getVisibleSize();

	///////////////////////////////////
    auto start_layer = Layer::create();
    this->addChild(start_layer);

    Sprite* my_start_bg = Sprite::create("material_6.png");
    my_start_bg->setPosition(visibleSize.width/2,visibleSize.height/2);
    my_start_bg->setOpacity(0);

    auto fadeIn_my_start_bg = FadeIn::create(3.0f);
    auto fadeOut_my_start_bg = FadeOut::create(3.0f);

	start_layer->addChild(my_start_bg);

    auto delay1 = DelayTime::create(13.0f);

    auto seq2 = Sequence::create(delay1, fadeIn_my_start_bg, fadeOut_my_start_bg, nullptr);
    my_start_bg->runAction(seq2);

    ///////////////////////////////////
    /*auto logo_layer = LayerColor::create();
    this->addChild(logo_layer);

    auto my_logo = Sprite::create("test2.png");
    my_logo->setPosition(visibleSize.width/2,visibleSize.height/2);
    my_logo->setOpacity(0);

    auto fadeIn_my_logo = FadeIn::create(3.0f);
    auto fadeOut_my_logo = FadeOut::create(3.0f);

	logo_layer->addChild(my_logo,0);

    auto seq = Sequence::create(fadeIn_my_logo, fadeOut_my_logo, nullptr);
    my_logo->runAction(seq);

	///////////////////////////////////
    auto thanks_layer = LayerColor::create();
    this->addChild(thanks_layer);

    auto my_thanks = Sprite::create("test.png");
    my_thanks->setPosition(visibleSize.width/2,visibleSize.height/2);
    my_thanks->setOpacity(0);

    auto fadeIn_my_thanks = FadeIn::create(3.0f);
    auto fadeOut_my_thanks = FadeOut::create(3.0f);

	thanks_layer->addChild(my_thanks,0);

    auto delay = DelayTime::create(8.0f);

    auto seq1 = Sequence::create(delay, fadeIn_my_thanks, fadeOut_my_thanks, nullptr);
    my_thanks->runAction(seq1);*/






    //Director::getInstance()->pushScene(StartScene::create());

    //Director::getInstance()->popScene();

    Director::getInstance()->replaceScene(StartScene::create());

	//this->addChild(MenuLayer::create());

	return true;
}


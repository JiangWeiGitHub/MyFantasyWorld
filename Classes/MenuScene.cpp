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

    //auto black_scene = LayerColor::create();
	//this->addChild(black_scene);

    ///////////////////////////////////
    //auto logo_scene = LayerColor::create();
    //this->addChild(logo_scene);

    auto my_logo = Sprite::create("test2.png");
    my_logo->setPosition(visibleSize.width/2,visibleSize.height/2);
    my_logo->setOpacity(0);

    auto fadeIn_my_logo = FadeIn::create(3.0f);
    auto fadeOut_my_logo = FadeOut::create(3.0f);

	this->addChild(my_logo,0);

    auto seq = Sequence::create(fadeIn_my_logo, fadeOut_my_logo, nullptr);
    my_logo->runAction(seq);

	///////////////////////////////////
    //auto thanks_scene = LayerColor::create();
    //this->addChild(thanks_scene);

    auto my_thanks = Sprite::create("test.png");
    my_thanks->setPosition(visibleSize.width/2,visibleSize.height/2);
    my_thanks->setOpacity(0);

    auto fadeIn_my_thanks = FadeIn::create(3.0f);
    auto fadeOut_my_thanks = FadeOut::create(3.0f);

	this->addChild(my_thanks,0);

    auto delay = DelayTime::create(8.0f);

    auto seq1 = Sequence::create(delay, fadeIn_my_thanks, fadeOut_my_thanks, nullptr);
    my_thanks->runAction(seq1);

    CCLOG("hahahhahaha!");

    //usleep(6000000);



    Director::getInstance()->pushScene(StartScene::create());

    //Director::getInstance()->popScene();

    //Director::getInstance()->replaceScene(StartScene::create());

	//this->addChild(MenuLayer::create());

	return true;
}


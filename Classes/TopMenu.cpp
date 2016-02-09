#include "TopMenu.h"

bool TopMenu::init()
{
	if(!Node::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	highestScore = Label::create(
		"Highest Score: " + cocos2d::String::createWithFormat("%d",GAMEDATA::getInstance()->getHistoryScore())->_string,
		"../Resources/Verdana Bold.ttf",30
	);
	highestScore->setPosition(visibleSize.width/2,visibleSize.height - 50);
	this->addChild(highestScore);

	level = Label::create(
		"Level: " + cocos2d::String::createWithFormat("%d",GAMEDATA::getInstance()->getNextLevel())->_string,
		"../Resources/Verdana Bold.ttf",30
	);
	level->setPosition(visibleSize.width/2,visibleSize.height - 100);
	this->addChild(level);

	targetScore = Label::create(
		"Goal: " + cocos2d::String::createWithFormat("%d",GAMEDATA::getInstance()->getNextScore())->_string + "Gold",
		"../Resources/Verdana Bold.ttf",30
	);

	targetScore->setPosition(visibleSize.width/2,visibleSize.height - 150);
	this->addChild(targetScore);

	curScore = Label::create(
	    cocos2d::String::createWithFormat("%d",GAMEDATA::getInstance()->getCurScore())->_string,
		"../Resources/Verdana Bold.ttf",50
	);
	curScore->setPosition(visibleSize.width/2,visibleSize.height - 200);
	this->addChild(curScore);

	return true;
}

void TopMenu::refresh()
{
	char buf[64];
	sprintf(buf,"%d",GAMEDATA::getInstance()->getCurScore());
	curScore->setString(buf);

	string history = "Highest Score: " + cocos2d::String::createWithFormat("%d",GAMEDATA::getInstance()->getHistoryScore())->_string;
	highestScore->setString(history);

	string guanqia = "Level: " + cocos2d::String::createWithFormat("%d",GAMEDATA::getInstance()->getNextLevel())->_string;
	level->setString(guanqia);

	string target = "Goal: " + cocos2d::String::createWithFormat("%d",GAMEDATA::getInstance()->getNextScore())->_string + "Gold: ";
	targetScore->setString(target);
}

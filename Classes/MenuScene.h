#ifndef _MENUSCENE_H_
#define _MENUSCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class MenuScene : public Scene
{
public:
	virtual bool init();
	CREATE_FUNC(MenuScene);

	void run_startScene(float dt);
	void run_menuScene(float dt);
};

#endif

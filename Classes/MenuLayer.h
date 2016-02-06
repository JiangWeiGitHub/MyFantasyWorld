#ifndef _MENULAYER_H_
#define _MENULAYER_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

class MenuLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(MenuLayer);

	void run();

	void startGame();
};
#endif

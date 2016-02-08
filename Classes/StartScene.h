#ifndef _STARTLAYER_H_
#define _STARTLAYER_H_

#include "cocos2d.h"
//#include "ui/CocosGUI.h"

using namespace cocos2d;
//using namespace ui;

class StartScene : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(StartScene);

	void run();
};

#endif

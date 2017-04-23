#ifndef _STARTLAYER_H_
#define _STARTLAYER_H_

#include "cocos2d.h"

using namespace cocos2d;

class StartScene : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(StartScene);

	void run();
};

#endif

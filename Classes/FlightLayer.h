#ifndef _FLIGHT_LAYER_H_
#define _FLIGHT_LAYER_H_

#include "cocos2d.h"
#include <list>
#include <algorithm>
#include <deque>
#include "Role.h"

using namespace std;
using namespace cocos2d;

class Role;

typedef Role** Role_Ptr;
class FlightLayer : public Layer
{
friend class Role;

public:
	virtual bool init();
	CREATE_FUNC(FlightLayer);
	void addRole(Role* r);
	std::list<Role_Ptr> getRolesArray(){return m_rolesArray;}

private:
	virtual void update(float delta);
	void initListener();
	bool comparePosY(Role_Ptr a,Role_Ptr b);
	void refreshLocalZOrder();
	void cleanNullPtrInArray();
	void updateMyControl();
	void updateMonster();

	void updateSkill();

	virtual bool onTouchBegan(Touch* touch,Event* event);
	virtual void onTouchMoved(Touch* touch,Event* event);
	virtual void onTouchEnded(Touch* touch,Event* event);

	void addBullet(Role* sender,Role_Ptr targetPtr);

private:
	std::list<Role_Ptr> m_rolesArray;
	Role* m_cur_control;
	Role_Ptr m_cur_controlPtr;
};

#endif

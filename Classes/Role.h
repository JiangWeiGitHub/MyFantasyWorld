#ifndef _ROLE_H_
#define _ROLE_H_

#include "cocos2d.h"
#include "CocoStudio.h"
#include "RoleProtocol.h"
#include "FlightLayer.h"
#include "cocos-ext.h"
#include <string>

USING_NS_CC_EXT;
using namespace cocos2d;

class Role : public Node, public RoleProtocol
{
public:
	enum ROLE_STAT
	{
		ROLE_ATTACK = 1,
		ROLE_DEFENCE,
		ROLE_MAD,
		ROLE_CONFUSE,
		ROLE_SLEEP,
		ROLE_POISONED,
		ROLE_SPEECHLESS,
		ROLE_FROZEN,
		ROLE_IMMUNE,
		ROLE_INVINCIBLE,
		ROLE_PIGGY,
		ROLE_DIE,
	};
	
	enum ROLE_ATTACK_TYPE
	{
		PHYSICAL,
		MAGIC,
		SKILL,
		ESCAPE,
		GAMBLE,
	};

	enum ROLE_PHYSICAL_TYPE
	{
		SWORD,
		STAFF,
		GLOVE,
		KNIFE
	};

	enum ROLE_MAGIC_TYPE
	{
		FIRE,
		WATER,
		THUNDER,
		EARTH,
		CURE,
		SURVIVE
	};

	enum ROLE_SKILL_TYPE
	{
		BOOST,
		PROTECT,
		PROVOKE,
		SUMMON
	};

	enum ROLE_GAMBLE_TYPE
	{
		KILL_ONE,
		KILL_ALL,
		SUICIDE_ONE,
		SUICIDE_ALL,
		CURE_ONE,
		CURE_ALL,
		DAMAGE_ONE,
		DAMAGE_ALL
	};

	enum ROLE_TYPE
	{
		ROLE_TYPE_NULL = 1,
		ROLE_TYPE_HERO,
		ROLE_TYPE_MONSTER,
		ROLE_TYPE_FRIEND
	};

public:
	Role();
	virtual ~Role(){};

	static Role* create(const std::string& name);
	virtual bool init(const std::string& name);

public:
	virtual void stand();
	virtual void move();
	virtual void attack();
	virtual void skill();
	virtual void injured(int effect,int damage=0);
	virtual void die();

	virtual bool onTouchBegan(Touch* touch,Event* event);
	virtual void onTouchMoved(Touch* touch,Event* event);
	virtual void onTouchEnded(Touch* touch,Event* event);

public:
	inline int getSpeed(){return m_speed;}
	inline void setSpeed(int speed){m_speed = speed;}
	inline int getInitSpeed(){return m_initSpeed;}
	inline void setInitSpeed(int speed){m_initSpeed = speed;}

	inline int getAtkSpeed(){return m_atkSpeed;}
	inline void setAtkSpeed(int speed){m_atkSpeed = speed;}
	inline int getInitAtkSpeed(){return m_initAtkSpeed;}
	inline void setInitAtkSpeed(int speed){m_initAtkSpeed = speed;}

	inline int getHp(){return m_hp;}
	inline void setHp(int hp){m_hp = hp;}
	inline int getInitHp(){return m_initHp;}
	inline void setInitHp(int hp){m_initHp = hp;}

	inline int getAtk(){return m_atk;}
	inline void setAtk(int atk){m_atk = atk;}
	inline int getInitAtk(){return m_initAtk;}
	inline void setInitAtk(int atk){m_initAtk = atk;}
	
	inline void setDefence(int defence){m_defence = defence;}
	inline int getDefence(){return m_defence;}
	inline void setInitDefence(int def){m_initDefence = def;}
	inline int getInitDefence(){return m_initDefence;}

protected:
	int m_id;

	ROLE_STAT en_stat;
	ROLE_TYPE m_type;
	
	int m_hp;
	int m_initHp;

	int m_mp;
	int m_initMp;

	int m_atk;
	int m_initAtk;

	int m_defence;
	int m_initDefence;
	
	int m_magicAtk;
	int m_initMagicAtk;

	int m_magicDefence;
	int m_initMagicDefence;

	int m_speed;
	int m_initSpeed;

	int m_evade;
	int m_initEvade;

	int m_atkSpeed;
	int m_initAtkSpeed;

	int m_luck;
	int m_initLuck;
};

#endif

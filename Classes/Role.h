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
using namespace cocostudio;

class FlightLayer;
class Role : public Node,public RoleProtocol{
friend class FlightLayer;
public:
	enum ROLE_STAT{
		ROLE_STAND,
		ROLE_MOVE,
		ROLE_ATTACK,
		ROLE_SKILL,
		ROLE_INJURED,
		ROLE_DIE,
		ROLE_NULL
	};
	
	enum ROLE_TYPE{
		ROLE_TYPE_NULL,
		ROLE_TYPE_HERO,
		ROLE_TYPE_MONSTER
	};
public:
	Role();
/*create ֮ǰ,����ȷ���Ѿ����ļ���ӵ�ArmatureManager*/
	static Role* create(const std::string& name,FlightLayer* layer);
	virtual bool init(const std::string& name,FlightLayer* layer);
	void setControlable(bool b);
	virtual Rect getBoundingBox();
	void setHeightLight(bool b);
	void setEndPoint(const Point& p);
	Point getEndPoint();
	virtual inline void setArmOffsetX(int x){m_arm_offsetX = x;}
	virtual inline void setArmOffsetY(int y){m_arm_offsetY = y;}

protected:
	void initHpSlider();
	virtual Point getHpSliderPos();

protected:
/*update��ص�*/
	virtual void update(float delta);
	virtual void update_checkHL();
	virtual void update_trace();
	virtual void update_pos();
	virtual void update_attackTarget();
	virtual void update_hp();

/*��RoleProtocol�м̳������ķ���*/
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

	void onBondAnimationFinish(Armature* arm,MovementEventType type,const std::string& name);

protected:
	/*����ʾ��ص�*/
	bool m_controlable;
	Armature* m_arm;
	int m_arm_offsetX;
	int m_arm_offsetY;

	Sprite* m_trace;
	Point m_endPoint;
	bool m_armFaceTo;	//����Ĭ��Ϊtrue������
	bool m_isHL;	//�Ƿ������ʾ
	Color3B m_defalutColor;
	ControlSlider* m_hpSlider;
	Sprite* m_selectCircle;


public:
	/*�ⲿ���ýӿ�*/
	virtual inline void setDesPoint(const Point& p){m_desPoint = p;}

	virtual void setAttackTarget(Role** targetPtr);
	inline Role** getAttackTarget(){return m_attackTargetPtr;}
	//ID
	virtual inline int getId(){return m_id;}
	
	//��ɫ״̬������
	inline ROLE_STAT getRoleStat(){return en_stat;}
	inline ROLE_TYPE getRoleType(){return m_type;}
	
	//�����ӵ�
	void sendBullet();

	//�ܼ���Ч�����ڱ�����Ч��
	void runSkillEffect(int skill_id,int loop =1);

public:
	//����get/set

	//�ƶ��ٶ�
	inline int getSpeed(){return m_speed;}
	inline void setSpeed(int speed){m_speed = speed;}
	inline int getInitSpeed(){return m_initSpeed;}
	inline void setInitSpeed(int speed){m_initSpeed = speed;}

	//�����ٶ�
	inline double getAtkSpeed(){return m_atkSpeed;}
	inline void setAtkSpeed(double speed){m_atkSpeed = speed;}
	inline double getInitAtkSpeed(){return m_initAtkSpeed;}
	inline void setInitAtkSpeed(double speed){m_initAtkSpeed = speed;}

	//����ֵ
	inline int getHp(){return m_hp;}
	inline void setHp(int hp){m_hp = hp;}
	inline int getInitHp(){return m_initHp;}
	inline void setInitHp(int hp){m_initHp = hp;}

	//��������
	inline int getAttackDistance(){return m_attackDistance;}
	inline void setAttackDistance(int distance){m_attackDistance = distance;}
	inline int getInitAttackDistance(){return m_initAttackDistance;}
	inline void setInitAttackDistance(int distance){m_initAttackDistance = distance;}

	//������
	inline int getAtk(){return m_atk;}
	inline void setAtk(int atk){m_atk = atk;}
	inline int getInitAtk(){return m_initAtk;}
	inline void setInitAtk(int atk){m_initAtk = atk;}
	
	//�������ӳ��ֵ
	inline int getAtkHateValue(){return m_atkHateValue;}
	inline void setAtkHateValue(int value){m_atkHateValue = value;}
	
	//������
	inline void setDefence(int defence){m_defence = defence;}
	inline int getDefence(){return m_defence;}
	inline void setInitDefence(int def){m_initDefence = def;}
	inline int getInitDefence(){return m_initDefence;}


	//�ǲ�������
	inline bool isNaima(){return m_isNaima;}
	inline void setNaima(bool b){m_isNaima = b;}
    
	//�ӵ�ͼƬ
	std::string getBulletImg();
	void setBulletImg(std::string img);
	
	//�ӵ��ٶ�
	inline int getBulletSpeed(){return m_bulletSpeed;}
	inline void setBulletSpeed(int speed){m_bulletSpeed = speed;}
	inline int getInitBulletSpeed(){return m_initBulletSpeed;}
	inline void setInitBulletSpeed(int speed){m_initBulletSpeed = speed;}

	//��ȡ���ؼ�
	inline FlightLayer* getLayer(){return m_layer;}
	
protected:
	/*��ս����ص����*/
	int m_id;	//id
	
	Role* m_attackTarget;
	Role** m_attackTargetPtr;//����Ŀ��

	Point m_desPoint;//Ŀ��λ��
	
	ROLE_STAT en_stat;	//��ǰ״̬
	
	FlightLayer* m_layer;	//���ؼ�


	int m_speed;	//�ƶ��ٶ�
	int m_initSpeed;
	
	int m_attackDistance;	//��������
	int m_initAttackDistance;

	int m_hp;//����ֵ
	int m_initHp;

	int m_atk;//������
	int m_initAtk;

	int m_defence;//������
	int m_initDefence;

	ROLE_TYPE m_type;//��ɫ���ͣ�Monster Or Hero
	
	int m_atkHateValue;//����������

	bool m_isNaima;//�ǲ�������
	
	std::string m_bulletImg;//�ӵ�

	int m_bulletSpeed;//�ӵ��ٶ�
	int m_initBulletSpeed;

	double m_atkSpeed;//�����ٶ�
	double m_initAtkSpeed;

};
#endif

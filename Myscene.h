#pragma once
#ifndef __MYSCENE_SCENE_H__
#define ___MYSCENE_SCENE_H__

#include <vector>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
class Myscene : public cocos2d::Layer
{
public:
	Myscene();
	~Myscene();
	Sprite* kuang;
	Sprite* rootnode;
	Sprite* kuang1;
	Sprite* kuang3;
	Sprite* chanzi;
	Sprite* queding;
	Sprite* xiangrikui;
	Sprite* wandou;
	Sprite *tt1;
	Label *lb1;
	struct jj
	{
		int x;
		int y;
		int tag;
		Node* aa;
		int sta;
	};
	std::vector<jj> zhiwu;
	/*std::vector<jj>::iterator jg1;*/

	struct zhiwuka
	{
		int x;
		int y;
		int tag;
		Sprite* aa1;
	};
	std::vector<zhiwuka> zhiwu1;
	/*std::vector<zhiwuka>::iterator jg2;*/

	struct Plant
	{
		int bh;
		int ch;
		int dh;
		int pl;
		int type;
		int hp;
		BOOL issun=false;
		BOOL ispao=false;
		cocostudio::Armature* aa;
	};
	std::vector<Plant> plant;
	std::vector<Plant>::iterator plantt;
	std::vector<Plant>::iterator planttt;

	struct Zha
	{
		int type;
		cocostudio::Armature* bb;
	};
	std::vector<Zha> zha;
	std::vector<Zha>::iterator bzha;

	struct Tao
	{
		int type;
		cocostudio::Armature* ff; 
	};
	std::vector<Tao> tao;
	std::vector<Tao>::iterator taoo;

	struct Wogua
	{
		int type;
		cocostudio::Armature* hh;
	};
	std::vector<Wogua> wogua;
	std::vector<Wogua>::iterator woguaa;

	struct Car
	{
		int x;
		int y;
		Sprite *caa;
	};
	std::vector<Car> car;
	std::vector<Car>::iterator carr;

	cocos2d::Vector<Node*> sun;
	std::vector<Node*>::iterator sunn;

	struct CorPse
	{
		int x;
		int y;
		int hp=10;
		int cps;
		BOOL ist = false;
		cocostudio::Armature* cc;
		cocostudio::Armature* tou;
	};
	std::vector<CorPse> corpse;
	std::vector<CorPse>::iterator corpses;
	std::vector<CorPse>::iterator corpsess;

	std::vector<Node*> paos;
	std::vector<Node*>::iterator paoss;
	int a;
	int row;
	int col;
	int myx;
	int myy;
	int ztime = 0;
	int ztime1 = 0;
	int ttime = 0;
	int ttime1 = 0;
	int wtime = 0;
	int wtime1 = 0;
	int mf1=1000;
	int tmm=0;
	int yy = 5;
	int rr = 0;
	std::string suns;
	int vx = 200;
	int map[9][9];
	BOOL cc = false;
	BOOL iss=false;
	BOOL iaa = false;
	BOOL isc = false;
	BOOL isv = false;
	virtual bool init();
	virtual bool onTouchBegan(Touch * touch, Event * event);
	virtual void onTouchEnded(Touch * touch, Event * event);
	virtual void onTouchMoved(Touch * touch, Event * event);
	static cocos2d::Scene * createScene();
	void sunTime(float dt);
	void sun1Time(float ddt);
	void pao(float ftt);
	void corpseTime(float ct);
	void corpsev(float cct);
	void istime(float mmt);
	void dd(Node * n);
	void baozhao(Node *n);
	void iszha(float mrt);
	void iszha1(float mot);
	void guauu(float mot);
	void bao1(Node * n);
	void iscar(float mot);
	void endss(float mmt);
	void df(Node *n);
	CREATE_FUNC(Myscene);
};
#endif


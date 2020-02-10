#ifndef __MYSCENE_SCENE_H__
#define ___MYSCENE_SCENE_H__

#include <vector>
#include "cocos2d.h"
USING_NS_CC;

class MyScence : public cocos2d::Layer
{
public:
	MyScence();
	~MyScence();
	Sprite* kuang;
	Sprite* kuang1;
	Sprite* kuang3;
	Sprite* chanzi;
	Sprite* queding;
	Sprite* xiangrikui;
	Sprite* wandou;
	
	struct jj
	{
		int x;
		int y;
		int tag;
		Node* aa;
	};
	std::vector<jj> zhiwu;
	std::vector<jj>::iterator jg1;
	struct zhiwuka
	{
		int x;
		int y;
		int tag;
		Sprite* aa1;
	};
	std::vector<zhiwuka> zhiwu1;
	std::vector<zhiwuka>::iterator jg2;
	virtual bool init();
	virtual bool onTouchBegan(Touch * touch, Event * event);
	virtual void onTouchEnded(Touch * touch, Event * event);
	virtual void onTouchMoved(Touch * touch, Event * event);
	static cocos2d::Scene* createScene();
	CREATE_FUNC(MyScence);
};
#endif
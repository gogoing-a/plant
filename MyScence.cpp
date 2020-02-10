#include "MyScence.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "HelloWorldScene.h"
USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocostudio;
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
MyScence::MyScence()
{
}

MyScence::~MyScence()
{
}

cocos2d::Scene * MyScence::createScene()
{
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyScence::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MyScence::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(MyScence::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(MyScence::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(MyScence::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto rootNode = Sprite::create("background1.jpg");
	int a = 270;
	int b = 320;
 	rootNode->setPosition(Vec2(a,b));
	rootNode->setScaleY(1.1);
// 	auto yidong = CCMoveTo::create(4, Vec2(visibleSize.width/2+50, visibleSize.height/2));
// 	rootNode->runAction(yidong);
 	this->addChild(rootNode,20);

	kuang = Sprite::create("2.png");
	kuang->setPosition(Vec2(300,600));	
	kuang->setScaleY(0.9);
	kuang->setScaleX(1.3);
	this->addChild(kuang,20);

	kuang1 = Sprite::create("1.png");
	kuang1->setPosition(Vec2(650, 600));
	this->addChild(kuang1, 20);

	chanzi = Sprite::create("chanzi.png");
	chanzi->setPosition(Vec2(650, 600));
	chanzi->setScale(0.5);
	this->addChild(chanzi, 20);

	kuang3 = Sprite::create("3.png");
	kuang3->setPosition(300, 300);
	this->addChild(kuang3, 20);

	queding = Sprite::create("queding.png");
	queding->setPosition(300,30);
	this->addChild(queding, 20);

// 	xiangrikui = Sprite::create("xiangrikui.png");
// 	xiangrikui->setScale(0.6);
// 	xiangrikui->setPosition(130,490);
// 	xiangrikui->setTag(300);
// 	this->addChild(xiangrikui, 20);
// 
// 	wandou = Sprite::create("wandou.png");
// 	wandou->setPosition(250,490);
// 	this->addChild(wandou, 20);

	for (int i=0;i<10;i++)
	{
			jj n;
			n.tag = i;
			n.x = 120 + i % 4 * 120;
			n.y = 465 + i / 4 * -120;
			if (n.tag==0)
			{
				n.aa = Sprite::create("xiangrikui.png");			
				n.aa->setPosition(n.x, n.y);
			}

			if (n.tag == 1)
			{
				n.aa = Sprite::create("wandou.png");
				n.aa->setPosition(n.x, n.y);
				n.aa->setScale(1.68);
			}

			if (n.tag == 2)
			{
				n.aa = Sprite::create("jianguo.png");
				n.aa->setPosition(n.x, n.y);
				n.aa->setScale(1.68);
			}

			if (n.tag == 3)
			{
				n.aa = Sprite::create("gaojianguo.png");
				n.aa->setPosition(n.x, n.y);
			}
			zhiwu.push_back(n);
	}

	for (jg1=zhiwu.begin();jg1!=zhiwu.end();jg1++)
	{
		if (jg1->tag==0)
		{
			jg1->aa->setTag(300);
			this->addChild(jg1->aa,20);
			
		}
		if (jg1->tag == 1)
		{
			jg1->aa->setTag(301);
			this->addChild(jg1->aa, 20);
		}
		
		if (jg1->tag==2)
		{
			jg1->aa->setTag(302);
			this->addChild(jg1->aa, 20);
		}

		if (jg1->tag == 3)
		{
			jg1->aa->setTag(303);
			this->addChild(jg1->aa, 20);
		}
	}
// 	if (a==true)
// 	{
// 		zhiwuka z;
// 		z.tag = 0;
// 		z.x = 500;
// 		z.y = 500;
// 		zhiwu1.push_back(z);
// 	}

	for (jg2 = zhiwu1.begin(); jg2 != zhiwu1.end(); jg2++)
	{
		if (jg2->tag == 0)
		{
			jg2->aa1 = Sprite::create("xiangrikui.png");
			jg2->aa1->setPosition(jg2->x, jg2->y);
			this->addChild(jg2->aa1, 20);
		}
	}


// 	
// 	
// 	ArmatureDataManager::getInstance()->addArmatureFileInfo("NewAnimation0.png", "NewAnimation0.plist", "NewAnimation.ExportJson");
// 	auto aa = Armature::create("NewAnimation");
// 	aa->getAnimation()->playByIndex(0);
// 	aa->setScale(0.7f);
// 	aa->setPosition(Vec2(300, 300));
// 	rootNode->addChild(aa, 20);

}


bool MyScence::onTouchBegan(Touch *touch, Event *event)
{
		Vec2 touchLocation = touch->getLocation();
		Vec2 nodeLocation = this->convertToNodeSpace(touchLocation);
		for (int i = 0; i < this->getChildrenCount(); i++)
		{
			auto tempSprite = this->getChildren().at(i);
			if (tempSprite->getBoundingBox().containsPoint(nodeLocation))
			{
				//Director::getInstance()->replaceScene(TransitionFade::create(3, MyScence::createScene()));				
				if (tempSprite->getTag() == 300)
				{
					zhiwuka z;
					zhiwu1.push_back(z);
					int pp = zhiwu1.size();
				}
			}
		}
	return true;
}

void MyScence::onTouchEnded(Touch *touch, Event *event)
{
}
void MyScence::onTouchMoved(Touch *touch, Event *event)
{
}
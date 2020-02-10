#include "Myscene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocostudio;
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
using namespace CocosDenshion;

Myscene::Myscene()
{
}


Myscene::~Myscene()
{
}

bool Myscene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	schedule(schedule_selector(Myscene::sunTime), 15);
	schedule(schedule_selector(Myscene::sun1Time), 1);
	schedule(schedule_selector(Myscene::pao), 1);
	/*schedule(schedule_selector(Myscene::corpseTime), yy);*/
	schedule(schedule_selector(Myscene::corpsev), 0.1);
	schedule(schedule_selector(Myscene::istime), 0.5);
	schedule(schedule_selector(Myscene::iscar), 0.1);
	schedule(schedule_selector(Myscene::endss), 0.1);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bk.mp3", true);
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Myscene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Myscene::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Myscene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	rootnode = Sprite::create("background1.jpg");
	rootnode->setPosition(Vec2(270, 320));
	rootnode->setScaleY(1.1);
	this->addChild(rootnode,20);

	kuang = Sprite::create("2.png");
	kuang->setPosition(Vec2(300, 600));
	kuang->setScaleY(0.9);
	kuang->setScaleX(1.3);
	this->addChild(kuang, 20);

	kuang1 = Sprite::create("1.png");
	kuang1->setPosition(Vec2(650, 600));
	this->addChild(kuang1, 20);

	chanzi = Sprite::create("chanzi.png");
	chanzi->setPosition(Vec2(650, 600));
	chanzi->setScale(0.5);
	chanzi->setTag(200);
	this->addChild(chanzi, 20);

	kuang3 = Sprite::create("3.png");
	kuang3->setPosition(300, 300);
	this->addChild(kuang3, 20);

	queding = Sprite::create("queding.png");
	queding->setPosition(300, 30);
	queding->setTag(201);
	this->addChild(queding, 20);

	suns = StringUtils::format("%d", mf1);
	lb1 = Label::createWithSystemFont(suns, "Arial", 24);
	lb1->setPosition(Vec2(40, 15));
	kuang->addChild(lb1, 20);

	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			map[i][j] = 0;
		}
	}

// 	for (int i=0;i<5;i++)
// 	{
// 		Car c;
// 		c.x = 200;
// 		c.y = 103 * i + 80;
// 		c.caa = Sprite::create("car.png");
// 		c.caa->setPosition(c.x, c.y);
// 		this->addChild(c.caa,20);
// 		car.push_back(c);
// 	}

	for (int i = 0; i < 7; i++)
	{
		jj n;
		n.tag = i;
		n.sta = 0;
		n.x = 120 + i % 4 * 120;
		n.y = 465 + i / 4 * -120;
		if (n.tag == 0)
		{
			n.aa = Sprite::create("xiangrikui.png");
			n.aa->setPosition(n.x, n.y);
			n.aa->setTag(300);
			this->addChild(n.aa, 20);
		}
		if (n.tag == 1)
		{
			n.aa = Sprite::create("jianguo.png");
			n.aa->setPosition(n.x, n.y);
			n.aa->setTag(301);
			n.aa->setScale(1.68);
			this->addChild(n.aa, 20);
		}
		if (n.tag == 2)
		{
			n.aa = Sprite::create("wandou.png");
			n.aa->setPosition(n.x, n.y);
			n.aa->setTag(302);
			n.aa->setScale(1.68);
			this->addChild(n.aa, 20);
		}
		if (n.tag == 3)
		{
			n.aa = Sprite::create("gaojianguo.png");
			n.aa->setPosition(n.x, n.y);
			n.aa->setTag(303);
			this->addChild(n.aa, 20);
		}
		if (n.tag==4)
		{
			n.aa = Sprite::create("yingtao.png");
			n.aa->setPosition(n.x, n.y);
			n.aa->setTag(304);
			this->addChild(n.aa, 20);
		}
		if (n.tag == 5)
		{
			n.aa = Sprite::create("najiao.png");
			n.aa->setPosition(n.x, n.y);
			n.aa->setTag(305);
			this->addChild(n.aa, 20);
		}
		if (n.tag == 6)
		{
			n.aa = Sprite::create("wogua.png");
			n.aa->setPosition(n.x, n.y);
			n.aa->setTag(306);
			this->addChild(n.aa, 20);
		}
		zhiwu.push_back(n);
	}
}

bool Myscene::onTouchBegan(Touch * touch, Event * event)
{	
	Point pp = touch->getLocationInView();
	pp = Director::getInstance()->convertToGL(pp);
	Vec2 touchLocation = touch->getLocation();
	Vec2 nodeLocation = this->convertToNodeSpace(touchLocation);
	for (int i = 0; i < this->getChildrenCount(); i++)
	{
		auto tempSprite = this->getChildren().at(i);
		if (tempSprite->getBoundingBox().containsPoint(nodeLocation))
		{
				zhiwuka z;
				z.x = 130 + 80 * zhiwu1.size();
				z.y = 600;
					if (tempSprite->getTag() == 300)
					{
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							if (zhiwu[i].sta != 1 && zhiwu[i].aa->getTag()==300&& zhiwu1.size()<=5)
							{
								z.aa1 = Sprite::create("xiangrikui.png");
								z.aa1->setPosition(z.x, z.y);
								z.aa1->setScale(0.6);
								z.aa1->setTag(400);
								this->addChild(z.aa1, 20);
								zhiwu[i].sta = 1;
								zhiwu1.push_back(z);
							}
						}
					}
					if (tempSprite->getTag() == 301)
					{
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							if (zhiwu[i].sta != 1 && zhiwu[i].aa->getTag() == 301 && zhiwu1.size() <= 5)
							{
								z.aa1 = Sprite::create("jianguo.png");
								z.aa1->setPosition(z.x, z.y);
								/*z.aa1->setScale(0.8);*/
								z.aa1->setTag(401);
								this->addChild(z.aa1, 20);
								zhiwu[i].sta = 1;
								zhiwu1.push_back(z);
							}
						}
					}
					if (tempSprite->getTag() == 302)
					{
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							if (zhiwu[i].sta != 1 && zhiwu[i].aa->getTag() == 302 && zhiwu1.size() <= 5)
							{
								z.aa1 = Sprite::create("wandou.png");
								z.aa1->setPosition(z.x, z.y);
								/*z.aa1->setScale(0.8);*/
								z.aa1->setTag(402);
								this->addChild(z.aa1, 20);
								zhiwu[i].sta = 1;
								zhiwu1.push_back(z);
							}
						}
					}
					if (tempSprite->getTag() == 303)
					{
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							if (zhiwu[i].sta != 1 && zhiwu[i].aa->getTag() == 303 && zhiwu1.size() <= 5)
							{
								z.aa1 = Sprite::create("gaojianguo.png");
								z.aa1->setPosition(z.x, z.y);
								z.aa1->setScale(0.6);
								z.aa1->setTag(403);
								this->addChild(z.aa1, 20);
								zhiwu[i].sta = 1;
								zhiwu1.push_back(z);
							}
						}
					}

					if (tempSprite->getTag() == 304)
					{
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							if (zhiwu[i].sta != 1 && zhiwu[i].aa->getTag() == 304 && zhiwu1.size() <= 5)
							{
								z.aa1 = Sprite::create("yingtao.png");
								z.aa1->setPosition(z.x, z.y);
								z.aa1->setScale(0.6);
								z.aa1->setTag(404);
								this->addChild(z.aa1, 20);
								zhiwu[i].sta = 1;
								zhiwu1.push_back(z);
							}
						}
					}

					if (tempSprite->getTag() == 305)
					{
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							if (zhiwu[i].sta != 1 && zhiwu[i].aa->getTag() == 305 && zhiwu1.size() <= 5)
							{
								z.aa1 = Sprite::create("najiao.png");
								z.aa1->setPosition(z.x, z.y);
								z.aa1->setScale(0.6);
								z.aa1->setTag(405);
								this->addChild(z.aa1, 20);
								zhiwu[i].sta = 1;
								zhiwu1.push_back(z);
							}
						}
					}

					if (tempSprite->getTag() == 306)
					{
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							if (zhiwu[i].sta != 1 && zhiwu[i].aa->getTag() == 306 && zhiwu1.size() <= 5)
							{
								z.aa1 = Sprite::create("wogua.png");
								z.aa1->setPosition(z.x, z.y);
								z.aa1->setScale(0.6);
								z.aa1->setTag(406);
								this->addChild(z.aa1, 20);
								zhiwu[i].sta = 1;
								zhiwu1.push_back(z);
							}
						}
					}
					if (tempSprite->getTag() == 400&&mf1>=50)
					{
						a = 1;
					}
					if (tempSprite->getTag()==401&&mf1>=50)
					{
						a = 2;
					}
					if (tempSprite->getTag() == 402&&mf1>=100)
					{
						a = 3;
					}
					if (tempSprite->getTag() == 403&&mf1>=125)
					{
						a = 4;
					}
					if (tempSprite->getTag() == 404 && mf1 >= 150)
					{
						a = 6;
					}
					if (tempSprite->getTag() == 405 && mf1 >= 125)
					{
						a = 7;
					}
					if (tempSprite->getTag() == 406 && mf1 >= 50)
					{
						a = 8;
					}
					if (tempSprite->getTag()==200)
					{
						a = 5;
					}

					if (tempSprite->getTag() == 201)
					{
						Size visibleSize = Director::getInstance()->getVisibleSize();
						auto yidong = CCMoveTo::create(3, Vec2(visibleSize.width / 2 + 50, visibleSize.height / 2));
						rootnode->runAction(yidong);
						for (int i = 0; i < 5; i++)
						{
							Car c;
							c.x = -220;
							c.y = 103 * i + 100;
							Vec2 endd = Vec2(30,c.y);
							c.caa = Sprite::create("car.png");
							c.caa->setPosition(c.x, c.y);
							auto mt = CCMoveTo::create(4,endd);
							c.caa->runAction(mt);
							this->addChild(c.caa, 20);
							car.push_back(c);
						}
						for (int i = zhiwu.size() - 1; i >= 0; i--)
						{
							zhiwu[i].aa->removeFromParent();
						}
						kuang3->removeFromParent();
						zhiwu.clear();
						queding->removeFromParent();
						iss = true;
					}
		}
	}	
	myx = pp.x - 80;
	myy = pp.y ;
	row = myx / 80;
	col = myy / 110;
	if (map[row][col] == 0)
	{
		if (row < 9 && col < 5)
		{
			if (a == 1 && pp.y < 520 && pp.x>80 && pp.x < 800)
			{
				map[row][col] = 1;
				lb1->removeFromParentAndCleanup(true);
				mf1 -= 50;
				suns = StringUtils::format("%d", mf1);
				lb1 = Label::createWithSystemFont(suns, "Arial", 24);
				lb1->setPosition(Vec2(40, 15));
				kuang->addChild(lb1, 20);
				if (map[row][col] == 1)
				{
				Plant p;
				ArmatureDataManager::getInstance()->addArmatureFileInfo("NewAnimation0.png", "NewAnimation0.plist", "NewAnimation.ExportJson");
				p.aa = Armature::create("NewAnimation");
				p.aa->getAnimation()->playByIndex(0);
				p.aa->setScale(0.7f);
				p.bh = 1;
				p.ch = 0;
				p.type = 1;
				p.hp = 50;
				p.issun = true;
				p.ispao = true;
				p.aa->setPosition(row * 80 + 120, col * 100 + 100);
				this->addChild(p.aa, 20);
				a = 0;
				plant.push_back(p);
				}
			}

			if (a == 2 && pp.y < 520 && pp.x>80 && pp.x < 800)
			{
				map[row][col] = 2;
				lb1->removeFromParentAndCleanup(true);
				mf1 -= 50;
				suns = StringUtils::format("%d", mf1);
				lb1 = Label::createWithSystemFont(suns, "Arial", 24);
				lb1->setPosition(Vec2(40, 15));
				kuang->addChild(lb1, 20);
				if (map[row][col] == 2)
				{
				Plant p;
				ArmatureDataManager::getInstance()->addArmatureFileInfo("NewAnimation0.png", "NewAnimation0.plist", "NewAnimation.ExportJson");
				p.aa = Armature::create("NewAnimation");
				p.aa->getAnimation()->playByIndex(1);
				p.aa->setScale(0.7f);
				p.hp = 100;
				p.issun = true;
				p.ispao = true;
				p.aa->setPosition(row * 80 + 120, col * 100 + 100);
				this->addChild(p.aa, 20);
				a = 0;
				plant.push_back(p);
				}
			}

			if (a == 3 && pp.y < 520 && pp.x>80 && pp.x < 800)
			{
				map[row][col] = 3;
				lb1->removeFromParentAndCleanup(true);
				mf1 -= 100;
				suns = StringUtils::format("%d", mf1);
				lb1 = Label::createWithSystemFont(suns, "Arial", 24);
				lb1->setPosition(Vec2(40, 15));
				kuang->addChild(lb1, 20);
				if (map[row][col] == 3)
				{
				Plant p;
				ArmatureDataManager::getInstance()->addArmatureFileInfo("NewAnimation0.png", "NewAnimation0.plist", "NewAnimation.ExportJson");
				p.aa = Armature::create("NewAnimation");
				p.aa->getAnimation()->playByIndex(4);
				p.aa->setScale(0.7f);
				p.hp = 50;
				p.bh = 2;
				p.dh = 0;
				p.issun = true;
				p.ispao = true;
				p.aa->setPosition(row * 80 + 120, col * 100 + 100);
				p.pl = sqrt((p.aa->getPositionX() - 1000)*(p.aa->getPositionX() - 1000));
				this->addChild(p.aa, 20);
				a = 0;
				plant.push_back(p);
				}
			}

			if (a == 4 && pp.y < 520 && pp.x>80 && pp.x < 800)
			{
				map[row][col] = 4;
				lb1->removeFromParentAndCleanup(true);
				mf1 -= 125;
				suns = StringUtils::format("%d", mf1);
				lb1 = Label::createWithSystemFont(suns, "Arial", 24);
				lb1->setPosition(Vec2(40, 15));
				kuang->addChild(lb1, 20);
				if (map[row][col] == 4)
				{
				Plant p;
				ArmatureDataManager::getInstance()->addArmatureFileInfo("NewAnimation0.png", "NewAnimation0.plist", "NewAnimation.ExportJson");
				p.aa = Armature::create("NewAnimation");
				p.aa->getAnimation()->playByIndex(5);
				p.aa->setScale(0.7f);
				p.hp = 200;
				p.issun = true;
				p.ispao = true;
				p.aa->setPosition(row * 80 + 120, col * 100 + 100);
				this->addChild(p.aa, 20);
				a = 0;
				plant.push_back(p);
				}
			}

			if (a == 6 && pp.y < 520 && pp.x>80 && pp.x < 800)
			{
				schedule(schedule_selector(Myscene::iszha1), 0.5);
				map[row][col] = 6;
				lb1->removeFromParentAndCleanup(true);
				mf1 -= 150;
				suns = StringUtils::format("%d", mf1);
				lb1 = Label::createWithSystemFont(suns, "Arial", 24);
				lb1->setPosition(Vec2(40, 15));
				kuang->addChild(lb1, 20);
				if (map[row][col] == 6)
				{
					Tao t;
					ArmatureDataManager::getInstance()->addArmatureFileInfo("20.png", "20.plist", "2.ExportJson");
					t.ff = Armature::create("2");
					t.ff->getAnimation()->playByIndex(0);
					t.ff->setScale(0.7f);
					t.type = 1;
					t.ff->setPosition(row * 80 + 120+30, col * 100 + 100);
					this->addChild(t.ff, 20);
					a = 0;
					tao.push_back(t);
				}
			}
			
			if (a == 7 && pp.y < 520 && pp.x>80 && pp.x < 800)
			{
				schedule(schedule_selector(Myscene::iszha), 0.5);
				map[row][col] = 7;
				lb1->removeFromParentAndCleanup(true);
				mf1 -= 125;
				suns = StringUtils::format("%d", mf1);
				lb1 = Label::createWithSystemFont(suns, "Arial", 24);
				lb1->setPosition(Vec2(40, 15));
				kuang->addChild(lb1, 20);
				if (map[row][col] == 7)
				{
					Zha z;
					ArmatureDataManager::getInstance()->addArmatureFileInfo("lajiao0.png", "lajiao0.plist", "lajiao.ExportJson");
					z.bb = Armature::create("lajiao");
					z.bb->getAnimation()->playByIndex(0);
					z.bb->setScale(0.7f);
					z.type = 1;
					z.bb->setPosition(row * 80 + 120, col * 100 + 100);
					this->addChild(z.bb, 20);
					a = 0;
					zha.push_back(z);
				}
			}

			if (a == 8 && pp.y < 520 && pp.x>80 && pp.x < 800)
			{
				schedule(schedule_selector(Myscene::guauu), 0.5);
				map[row][col] = 8;
				lb1->removeFromParentAndCleanup(true);
				mf1 -= 50;
				suns = StringUtils::format("%d", mf1);
				lb1 = Label::createWithSystemFont(suns, "Arial", 24);
				lb1->setPosition(Vec2(40, 15));
				kuang->addChild(lb1, 20);
				if (map[row][col] == 8)
				{
					Wogua w;
					ArmatureDataManager::getInstance()->addArmatureFileInfo("40.png", "40.plist", "4.ExportJson");
					w.hh = Armature::create("4");
					w.hh->getAnimation()->playByIndex(0);
					w.hh->setScale(0.7f);
					w.type = 1;
					w.hh->setPosition(row * 80 + 120, col * 100 + 100);
					this->addChild(w.hh, 20);
					a = 0;
					wogua.push_back(w);
				}
			}
		}
	}

	if (a == 5)
	{
		for(int k=plant.size()-1;k>=0;k--)
		{
			Node *n = plant[k].aa;
			if (n->getBoundingBox().containsPoint(nodeLocation))
			{
				int x = (plant[k].aa->getPositionX()-120)/80;
				int y = (plant[k].aa->getPositionY() - 100) / 100;
				map[x][y] = 0;
				plant[k].issun = false;
				plant[k].ispao = false;
				a = 0;
				n->removeAllChildrenWithCleanup(true);
			}
		}
	}

	for (int j=sun.size()-1;j>=0;j--)
	{
		Node *n = sun.at(j);
		if (n->getBoundingBox().containsPoint(nodeLocation))
		{
			lb1->removeFromParentAndCleanup(true);
			mf1 += 25;
			Vec2 endp = Vec2(80,600);
			auto mt = CCMoveTo::create(0.5, endp);
			auto mycall = CCCallFuncN::create(n, callfuncN_selector(Myscene::df));
			auto sq = CCSequence::create(mt, mycall, NULL);
			n->runAction(sq);
			sun.eraseObject(n);
			suns = StringUtils::format("%d", mf1);
			lb1 = Label::createWithSystemFont(suns, "Arial", 24);
			lb1->setPosition(Vec2(40, 15));
			kuang->addChild(lb1, 20);
		}
	}
	return true;
}

void Myscene::df(Node *n)
{
	n->removeFromParentAndCleanup(true);
}

void Myscene::onTouchEnded(Touch * touch, Event * event)
{
}

void Myscene::onTouchMoved(Touch * touch, Event * event)
{
}

cocos2d::Scene * Myscene::createScene()
{
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Myscene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void Myscene::sunTime(float dt)
{
	Armature *aa1;
	int x = random() % 600+100;
	int y = random() % 650;
	ArmatureDataManager::getInstance()->addArmatureFileInfo("sun10.png", "sun10.plist", "sun1.ExportJson");
	aa1 = Armature::create("sun1");
	aa1->getAnimation()->playByIndex(0);
	Vec2 bg = Vec2(x, 700);
	Vec2 en = Vec2(x, y);
	aa1->setPosition(bg);
	auto mt = CCMoveTo::create(5,en);
	aa1->runAction(mt);
	this->addChild(aa1,20);
	sun.pushBack(aa1);
}

void Myscene::sun1Time(float ddt)
{
	Armature *aa2;
	Vec2 bb;
	int aa4 = 20;
	ArmatureDataManager::getInstance()->addArmatureFileInfo("sun10.png", "sun10.plist", "sun1.ExportJson");
	for (plantt=plant.begin();plantt!=plant.end();plantt++)
	{
		if (plantt->bh==1)
		{
			plantt->ch++;
			if (plantt->ch%8==0&&plantt->issun==true)
			{
				plantt->ch = 0;
				aa2 = Armature::create("sun1");
				aa2->getAnimation()->playByIndex(0);
				bb = plantt->aa->getPosition();
				aa2->setPosition(bb);
				aa2->setScale(0.6);
				this->addChild(aa2, 20);
				aa4 = 0;
				sun.pushBack(aa2);				
			}		
		}
	}
}


void Myscene::pao(float ftt)
{
	Sprite *paod;
	Vec2 cc;
	for (plantt = plant.begin(); plantt != plant.end(); plantt++)
	{
		for (corpses = corpse.begin(); corpses != corpse.end(); corpses++)
		{
			if (plantt->bh == 2)
			{
				plantt->dh++;
				if (corpses->cc->getPositionY() == plantt->aa->getPositionY())
				{
					if (plantt->dh % 1 == 0 && plantt->ispao == true)
					{
						plantt->dh = 0;
						paod = Sprite::create("paodan.png");
						cc = plantt->aa->getPosition();
						paod->setPosition(cc.x + 30, cc.y + 10);
						Vec2 endo = Vec2(1200, cc.y);
						auto mt = CCMoveTo::create(plantt->pl / vx, endo);
						paod->runAction(mt);
						paos.push_back(paod);
						this->addChild(paod, 20);
					}
				}
			}
		}
	}
}

void Myscene::corpseTime(float ct)
{
	if (iss == true&&iaa==true)
	{
		CorPse cp;
		cp.x = 900;
		cp.y = random() % 5 * 100 + 100;
		ArmatureDataManager::getInstance()->addArmatureFileInfo("jiangshi60.png", "jiangshi60.plist", "jiangshi6.ExportJson");
		cp.cc = Armature::create("jiangshi6");
		cp.cc->getAnimation()->playByIndex(0);
		cp.cc->setScale(0.8);
		cp.cps = 0;
		cp.ist = false;
		cp.cc->setPosition(cp.x, cp.y);
		this->addChild(cp.cc, 20);
		corpse.push_back(cp);
	}
}

void Myscene::corpsev(float cct)
{
	for (corpses = corpse.begin(); corpses != corpse.end(); corpses++)
	{
		if (corpses->ist == false)
		{
			corpses->cc->setPositionX(corpses->cc->getPositionX() - 2);
		}
	}

	for (corpses=corpse.begin();corpses!=corpse.end();corpses++)
	{
		for (plantt=plant.begin(); plantt!=plant.end();plantt++)
		{
			if (plant.size() > 0)
			{
				if (corpses->cc->getBoundingBox().intersectsRect(plantt->aa->getBoundingBox()) && corpses->cps == 0)
				{
					corpses->cps = 2;
					corpses->ist = true;
					corpses->cc->getAnimation()->playByIndex(1);
				}
				if (corpses->cc->getBoundingBox().intersectsRect(plantt->aa->getBoundingBox()) && corpses->cps == 2 && corpses->hp <= 1)
				{
					corpses->cps = 3;
					corpses->ist = true;
					corpses->cc->getAnimation()->playByIndex(3);
				}
				if (corpses->cc->getBoundingBox().intersectsRect(plantt->aa->getBoundingBox()) && corpses->cps == 1 && corpses->hp <= 1)
				{
					corpses->cps = 4;
					corpses->ist = true;
					corpses->cc->getAnimation()->playByIndex(3);
				}
				if (corpses->cc->getBoundingBox().intersectsRect(plantt->aa->getBoundingBox()))
				{

					plantt->hp--;
					if (plantt->hp <= 0)
					{
						for (corpsess = corpse.begin(); corpsess != corpse.end(); corpsess++)
						{
							for (planttt = plant.begin(); planttt != plant.end(); planttt++)
							{
								if (corpsess->cc->getBoundingBox().intersectsRect(planttt->aa->getBoundingBox()))
								{
									if (corpsess->cps == 2)
									{
										corpsess->cps = 0;
										corpsess->cc->getAnimation()->playByIndex(0);
										corpsess->ist = false;
									}
									if (corpsess->cps == 4)
									{
										corpsess->cps = 2;
										corpsess->cc->getAnimation()->playByIndex(2);
										corpsess->ist = false;
									}
									if (corpses->cps == 3)
									{
										corpses->cps = 2;
										corpses->cc->getAnimation()->playByIndex(2);
										corpsess->ist = false;
									}
								}
							}
						}
						int x = (plantt->aa->getPositionX() - 120) / 80;
						int y = (plantt->aa->getPositionY() - 100) / 100;
						map[x][y] = 0;
						plantt->issun = false;
						plantt->ispao = false;
						plantt->aa->removeAllChildrenWithCleanup(true);
						plant.erase(plantt);
						plantt = plant.begin();
						corpses->ist = false;

					}
				}
			}
		}
	}

	for (int j = corpse.size() - 1; j >= 0; j--)
	{
		Node *c = corpse[j].cc;
		if (corpse[j].hp <= 0)
		{
			c->removeFromParentAndCleanup(true);
			corpse.erase(corpse.begin() + j);
			j = corpse.size() - 1;
		}
	}

	for (int i = paos.size() - 1; i >= 0; i--)
	{
		Node *p = paos.at(i);
		for (int j = corpse.size() - 1; j >= 0; j--)
		{
			Node *c = corpse[j].cc;
			if (p->getBoundingBox().intersectsRect(c->getBoundingBox()))
			{
				corpse[j].hp--;
				p->stopAllActions();
				paos.erase(paos.begin() + i);
				p->removeFromParentAndCleanup(true);
				i = paos.size() - 1;
			}
			if (corpse[j].hp<=0)
			{
				c->removeFromParentAndCleanup(true);
				corpse.erase(corpse.begin() + j);
				j = corpse.size() - 1;
			}
			if (corpse[j].hp == 1&&corpse[j].cps==0)
			{
				corpse[j].cps = 1;
				corpse[j].cc->getAnimation()->playByIndex(2);
				int xx = corpse[j].cc->getPositionX();
				int yy = corpse[j].cc->getPositionY();
				CorPse cp1;
				Vec2 endd = Vec2(xx, yy - 30);
				ArmatureDataManager::getInstance()->addArmatureFileInfo("tou0.png", "tou0.plist", "tou.ExportJson");
				cp1.tou = Armature::create("tou");
				cp1.tou->getAnimation()->playByIndex(0);
				cp1.tou->setScale(0.7);
				cp1.tou->setPosition(xx,yy+40);
				auto mt1 = CCMoveTo::create(1, endd);
				auto mycall1 = CCCallFuncN::create(cp1.tou, callfuncN_selector(Myscene::dd));
				auto sq1 = CCSequence::create(mt1, mycall1, NULL);
				cp1.tou->runAction(sq1);
				this->addChild(cp1.tou, 20);
			}
		}
	}

// 	for (plantt = plant.begin(); plantt != plant.end(); plantt++)
// 	{
// 		if (plantt->type==1)
// 		{
// 			ArmatureDataManager::getInstance()->addArmatureFileInfo("lajiao0.png", "lajiao0.plist", "lajiao.ExportJson");
// 			plantt->aa = Armature::create("lajiao");
// 			plantt->aa->getAnimation()->playByIndex(1);
// 			auto mycall1 = CCCallFuncN::create(plantt->aa, callfuncN_selector(Myscene::baozhao));
// 			auto sq1 = CCSequence::create(mycall1, NULL);
// 			plantt->aa->runAction(sq1);
// 			plantt->type = 2;
// 		}
// 	}
}

void Myscene::istime(float mmt)
{
	tmm++;
	if (tmm%20==0)
	{
		iaa = true;
	}
}

void Myscene::dd(Node *n)
{
	n->removeFromParentAndCleanup(true);
}

void Myscene::baozhao(Node *n)
{
	n->removeFromParentAndCleanup(true);
}

void Myscene::iszha(float mrt)
{
	ztime += 1;
	ztime1 += 1;
	if (zha.size() > 0)
	{
		for (bzha = zha.begin(); bzha != zha.end(); bzha++)
		{
			if (ztime > 1&&bzha->type==1)
			{
				bzha->bb->getAnimation()->playByIndex(1);
				bzha->bb->setScaleX(1.9);
				ztime = 0;
				bzha->type = 2;
			}
			if (ztime1>2&&bzha->type==2)
			{
				int x = (bzha->bb->getPositionX() - 120) / 80;
				int y = (bzha->bb->getPositionY() - 100) / 100;
				auto mycall12 = CCCallFuncN::create(bzha->bb, callfuncN_selector(Myscene::baozhao));
				auto sq12 = CCSequence::create(mycall12, NULL);
				bzha->bb->runAction(sq12);
				map[x][y] = 0;
				ztime1 = 0;
				bzha->type = 3;
				unschedule(schedule_selector(Myscene::iszha));
				for (corpses = corpse.begin(); corpses != corpse.end(); corpses++)
				{
					if (corpses->cc->getBoundingBox().intersectsRect(bzha->bb->getBoundingBox()))
					{
						corpses->hp = 0;
					}
				}
			}
		}
	}
}

void Myscene::iszha1(float mot)
{
	ttime += 1;
	ttime1 += 1;
	if (tao.size()>0)
	{
		for (taoo = tao.begin(); taoo != tao.end(); taoo++)
		{
			if (ttime > 1 && taoo->type == 1)
			{
				int xx = taoo->ff->getPositionX();
				int yy = taoo->ff->getPositionY();
				/*taoo->ff->removeFromParentAndCleanup(true);*/
				ttime = 0;
				taoo->type = 2;
				tt1 = Sprite::create("Boom1.png");
				tt1->setPosition(xx,yy);
				tt1->setScale(1.2);
				this->addChild(tt1, 20);
			}
			if (ttime1 > 2 && taoo->type == 2)
			{
				int x = (taoo->ff->getPositionX() - 150) / 80;
				int y = (taoo->ff->getPositionY() - 100) / 100;
				map[x][y] = 0;
				taoo->type = 3;
				ttime1 = 0;
 				unschedule(schedule_selector(Myscene::iszha1));
				for (corpses = corpse.begin(); corpses != corpse.end(); corpses++)
				{
					if (corpses->cc->getBoundingBox().intersectsRect(tt1->getBoundingBox()))
					{
						corpses->hp = 0;
					}
				}
				taoo->ff->removeFromParentAndCleanup(true);
				tt1->removeFromParentAndCleanup(true);
			}
		}
	}
}

void Myscene::guauu(float mot)
{
	wtime1 += 1;
	if (wogua.size() > 0)
	{
		for (woguaa = wogua.begin(); woguaa != wogua.end(); woguaa++)
		{
			for (corpses = corpse.begin(); corpses != corpse.end(); corpses++)
			{
				if (woguaa->type == 1)
				{
					if (corpses->cc->getBoundingBox().intersectsRect(woguaa->hh->getBoundingBox()))
					{
						wtime += 1;
						Vec2 enfd = Vec2(corpses->cc->getPositionX(), corpses->cc->getPositionY() + 30);
						Vec2 enfd1 = Vec2(corpses->cc->getPositionX(), corpses->cc->getPositionY() - 40);
						auto mt = CCMoveTo::create(0.2, enfd);
						woguaa->hh->runAction(mt);
						if (wtime > 1)
						{
							int x = (woguaa->hh->getPositionX() - 120) / 80;
							int y = (woguaa->hh->getPositionY() - 100) / 100;
							woguaa->hh->getAnimation()->playByIndex(1);
							auto mt1 = CCMoveTo::create(0.1, enfd1);
							auto mycall12 = CCCallFuncN::create(woguaa->hh, callfuncN_selector(Myscene::bao1));
							auto sq12 = CCSequence::create(mt1, mycall12, NULL);
							woguaa->hh->runAction(sq12);
							woguaa->type = 2;
							wtime = 0;
							corpses->hp = 0;
							map[x][y] = 0;
							unschedule(schedule_selector(Myscene::guauu));
						}
					}
				}
			}
		}
	}
}

void Myscene::bao1(Node * n)
{
	n->removeFromParentAndCleanup(true);
}

void Myscene::iscar(float mot)
{
	for (carr = car.begin(); carr != car.end(); carr++)
	{
		for (corpses = corpse.begin(); corpses != corpse.end(); corpses++)
		{
			if (corpses->cc->getBoundingBox().intersectsRect(carr->caa->getBoundingBox()))
			{
				int x = carr->caa->getPositionX();
				int y = carr->caa->getPositionY();
				Vec2 endp = Vec2(x+1000,y);
				auto mt = CCMoveTo::create(3,endp);
				carr->caa->runAction(mt);
				corpses->hp = 0;
			}
		}
	}

	rr++;
	if (rr%500==0)
	{
		yy -=0.5;
	}
	schedule(schedule_selector(Myscene::corpseTime), yy);
}

void Myscene::endss(float mmt)
{
	for (corpses = corpse.begin(); corpses != corpse.end(); corpses++)
	{
		int ads = 1;
		if (corpses->cc->getPositionX() <(-20))
		{
			ads = 2;
			auto lose = Sprite::create("ZombiesWon.png");
			auto fot = FadeIn::create(3);
			lose->runAction(fot);
			lose->setPosition(480, 300);
			this->addChild(lose, 20);
			unschedule(schedule_selector(Myscene::sunTime));
			unschedule(schedule_selector(Myscene::sun1Time));
			unschedule(schedule_selector(Myscene::pao));
			unschedule(schedule_selector(Myscene::corpseTime));
			unschedule(schedule_selector(Myscene::corpsev));
			unschedule(schedule_selector(Myscene::istime));
			unschedule(schedule_selector(Myscene::iscar));
		}
	}
}
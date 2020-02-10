#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "MyScence.h"
#include "Myscene.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocostudio;
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{

    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }   
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	auto caidan = Sprite::create("Surface.png");
	caidan->setPosition(480,320);
	caidan->setScale(1.1);
	rootNode->addChild(caidan);
	auto aa = caidan->getChildByTag(10007);
	maoxian = Sprite::create("maoxian.png");
	maoxian->setTag(120);
	maoxian->setPosition(Vec2(700, 500));
	this->addChild(maoxian);
    return true;	


// 	auto start = Sprite::create("start.png");
// 	auto startMenuItem = MenuItemSprite::create(start, start,
// 		CC_CALLBACK_0(Start::startGame, this));
// 	startMenuItem->setPosition(visibleSize.width / 2, visibleSize.height / 2);
// 	auto menu = Menu::create(startMenuItem, NULL);
// 	menu->setPosition(Vec2::ZERO);
// 	this->addChild(menu, 1);
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
// 	Point pp = touch->getLocationInView();
// 	pp = Director::getInstance()->convertToGL(pp);
// 	Vec2 bb = maoxian->getPosition();
	Vec2 touchLocation = touch->getLocation();
	Vec2 nodeLocation = this->convertToNodeSpace(touchLocation);
	for (int i = 0; i < this->getChildrenCount(); i++)
	{
		auto tempSprite = this->getChildren().at(i);
		if (tempSprite->getBoundingBox().containsPoint(nodeLocation))
		{
			if (tempSprite->getTag() == 120)
			{
				Director::getInstance()->replaceScene(TransitionFade::create(3, Myscene::createScene()));
			}
		}
	}
	return true;
}

void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
}
void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
}

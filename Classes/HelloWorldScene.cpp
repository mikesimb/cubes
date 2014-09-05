#include "HelloWorldScene.h"


USING_NS_CC;

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
    //////////////////////////////
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
                                origin.y + closeItem->getContentSize().height/2 ));


	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem1 = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCallback, this));

	closeItem1->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2+200));
    
    
    auto closeItem2 = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::CloseItem2CallBack, this));
    
	closeItem2->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2 +100));
    



    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem,closeItem1,closeItem2, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 0);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    this->schedule(schedule_selector(HelloWorld::OnTime), 1.0f);

	

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

	m_CubeGame.CreateCurrentCubeitem();
    return true;
}

void HelloWorld::OnTime(float f)
{
	m_CubeGame.movetoDown();
	
}

void HelloWorld::menuCallback(Ref* pSender)
{
	m_CubeGame.TransformCubitem();
}

void HelloWorld::CloseItem2CallBack(Ref* pSender)
{
	m_CubeGame.CopyItemToMap();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::update(float delta)
{
		
	
}




void HelloWorld::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	CCLayer::draw(renderer, transform, flags);
	//DrawGride();
    DrawMap();
	DrawCubeItem();
	

	
}


void HelloWorld::DrawMap()
{
    for (int i = 0; i < cMapCols; i++)
	{
		for (int j = 0; j < cMapRows ; j++)
		{
			if (m_CubeGame.getMapdata(i,j) == 1)
			{
				glLineWidth(1.0f);//œﬂÃıøÌ∂»
				DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
				int sourcex = 40+i * 40;
				int sourcey = 100+ j * 40 ;
				DrawPrimitives::drawRect(ccp(sourcex, sourcey), ccp(sourcex + 40, sourcey + 40));
			}
            else{
				glLineWidth(1.0f);//œﬂÃıøÌ∂»
				DrawPrimitives::setDrawColor4B(0, 255, 0, 255);//—’…´
				int sourcex =40+ i * 40;
				int sourcey = 100 + j * 40;
				DrawPrimitives::drawRect(ccp(sourcex,sourcey),ccp(sourcex+40,sourcey+40));//ªÊ÷∆◊Û÷–µΩ”“÷–
                
            }
            
            
		}
	}
}

void HelloWorld::DrawCubeItem()
{
	ALS_Cubitem * A  = m_CubeGame.getCurrentCubeItem();
    if (A ==NULL) return;
    for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_CubeGame.getCurrentCubeItem()->c[i][j] )
			{
				glLineWidth(1.0f);
				DrawPrimitives::setDrawColor4B(255,0 , 0, 255);
				int sourcex = 40+ m_CubeGame.getCurrentItemColNum()* 40 + j* 40;
				int sourcey = 100+ m_CubeGame.getCurrentItemyRowNum()* 40 + i * 40 ;
				DrawPrimitives::drawRect(ccp(sourcex,sourcey),ccp(sourcex+40,sourcey+40));		
			}
				

		}
	}
}


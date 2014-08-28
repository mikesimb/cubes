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
                                origin.y + closeItem->getContentSize().height/2 +200 ));


	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem1 = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCallback, this));

	closeItem1->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2 + 500));


    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem,closeItem1, NULL);
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

	

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

	m_Currentitem = CreateAnewcube();
	m_CurrentItem_x = 5;
	m_CurrentItem_y = 5;

	//schedule(schedule_selector(HelloWorld::OnTime), 0.5f);
    
    return true;
}

void HelloWorld::OnTime(float f)
{
	
}

void HelloWorld::menuCallback(Ref* pSender)
{
	TransformCubeitem();
	return;
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

//首先是绘制表格函数
//绘制棋盘的过程
void HelloWorld::DrawGride()
{
	for (int i = 0; i < (800 / 40)-1; i++)
	{
		glLineWidth(1.0f);//线条宽度

		DrawPrimitives::setDrawColor4B(255, 0, 0, 255);//颜色

		DrawPrimitives::drawLine(ccp(40, 100 + (i * 40)), ccp(640 - 40, 100 + (i * 40)));//绘制左中到右中
	}

	for (int j = 1; j < (640 / 40); j++)
	{
		glLineWidth(1.0f);//线条宽度

		DrawPrimitives::setDrawColor4B(255, 0, 0, 255);//颜色

		DrawPrimitives::drawLine(ccp(j * 40, 100), ccp(j * 40, 820));//绘制左中到右中
	}

}



void HelloWorld::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	CCLayer::draw(renderer, transform, flags);
	DrawGride();
	DrawCubeItem();
	

	
}

baseitem HelloWorld::CreateAnewcube()
{
	int num = rand() % 13;
	return Cubeitems[num];
}

void HelloWorld::DrawCubeItem()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_Currentitem.c[i][j] == 1)
			{
				glLineWidth(1.0f);//线条宽度
				DrawPrimitives::setDrawColor4B(255, 255, 0, 255);//颜色
				int sourcex = m_CurrentItem_x * 40 + i * 40;
				int sourcey = m_CurrentItem_y * 40 + j * 40 -20;
				DrawPrimitives::drawRect(ccp(sourcex,sourcey),ccp(sourcex+40,sourcey+40));//绘制左中到右中
			}
				

		}
	}
}

void HelloWorld::TransformCubeitem()
{
	int index = m_Currentitem.transformid;
	m_Currentitem = Cubeitems[index];
}

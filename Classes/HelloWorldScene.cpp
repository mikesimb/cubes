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
    
    this->schedule(schedule_selector(HelloWorld::OnTime), 1.0f);

	

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

	m_Currentitem = CreateAnewcube();
	m_CurrentItem_x = 5;
	m_CurrentItem_y = MapRows;

	//schedule(schedule_selector(HelloWorld::OnTime), 0.5f);
    
    
    for (int i = 0 ;i < MapRows;i++)
        for (int j = 0 ;j < MapCols; j++) {
            Map[i][j] = 0;
        }
    
    return true;
}

void HelloWorld::OnTime(float f)
{
   //判断是否产生碰撞
    
    for(int i = 4 ;i>0 ;i--)
        for (int j= 4 ;j>0 ;j--)
        {
            if(m_Currentitem.c[i][j] == Map[m_CurrentItem_x+i][m_CurrentItem_y+1+j])
            {
                //碰撞了
                Map[m_CurrentItem_x +i][m_CurrentItem_y+1+j] = m_Currentitem.c[i][j];
            }
        }
    
    
    
    //判断当前这个是否到底了
    
    if((m_CurrentItem_y-4)>= 0)
    {
        UpdateCurrentItemPos();
        
    }
    else
    {
        for(int i = 4 ;i>0 ;i--)
            for (int j= 4 ;j>0 ;j--)
            {
                if(m_Currentitem.c[i][j] == Map[m_CurrentItem_x+i][m_CurrentItem_y+1+j])
                {
                    //碰撞了
                    Map[m_CurrentItem_x +i][m_CurrentItem_y+1+j] = m_Currentitem.c[i][j];
                }else
                if(m_CurrentItem_y-4 <=0)
                    Map[m_CurrentItem_y-j][m_CurrentItem_x -i] = m_Currentitem.c[i][j];
            }
        m_Currentitem = {{0,0,0,0,
            0,0,0,0,
            0,0,0,0,
            0,0,0,0},0} ;

        
    };
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

// ◊œ» «ªÊ÷∆±Ì∏Ò∫Ø ˝
//ªÊ÷∆∆Â≈Ãµƒπ˝≥Ã
void HelloWorld::DrawGride()
{
	for (int i = 0; i <= MapCols ; i++)
	{
		glLineWidth(1.0f);//œﬂÃıøÌ∂»

		DrawPrimitives::setDrawColor4B(255, 0, 0, 255);//—’…´

		DrawPrimitives::drawLine(ccp(40, 100 + (i * 40)), ccp((MapRows)*40, 100 + (i * 40)));//ªÊ÷∆◊Û÷–µΩ”“÷–
	}

	for (int j = 1; j <= MapRows; j++)
	{
		glLineWidth(1.0f);//œﬂÃıøÌ∂»

		DrawPrimitives::setDrawColor4B(255, 0, 0, 255);//—’…´

		DrawPrimitives::drawLine(ccp(j * 40, 100), ccp(j * 40, 100+(MapCols)*40));//ªÊ÷∆◊Û÷–µΩ”“÷–
	}

}



void HelloWorld::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	CCLayer::draw(renderer, transform, flags);
	DrawGride();
    DrawMap();
	DrawCubeItem();
	

	
}

baseitem HelloWorld::CreateAnewcube()
{
	int num = rand() % 13;
	return Cubeitems[num];
}

void HelloWorld::DrawMap()
{
    for (int i = 0; i < MapRows-1; i++)
	{
		for (int j = 0; j < MapCols ; j++)
		{
			if (Map[i][j] == 1)
			{
				glLineWidth(1.0f);//œﬂÃıøÌ∂»
				DrawPrimitives::setDrawColor4B(255, 0, 0, 255);//—’…´
				int sourcex = 40+i * 40;
				int sourcey = 100+ j * 40 ;
				DrawPrimitives::drawRect(ccp(sourcex,sourcey),ccp(sourcex+40,sourcey+40));//ªÊ÷∆◊Û÷–µΩ”“÷–
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
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_Currentitem.c[i][j] == 1)
			{
				glLineWidth(1.0f);//œﬂÃıøÌ∂»
				DrawPrimitives::setDrawColor4B(255, 255, 0, 255);//—’…´
				int sourcex = m_CurrentItem_x * 40 + i * 40;
				int sourcey = m_CurrentItem_y * 40 + j * 40 -20;
				DrawPrimitives::drawRect(ccp(sourcex,sourcey),ccp(sourcex+40,sourcey+40));//ªÊ÷∆◊Û÷–µΩ”“÷–
			}
				

		}
	}
}

void HelloWorld::UpdateCurrentItemPos()
{
    
    m_CurrentItem_y--;
    //判断是不是被阻挡了
    
}

void HelloWorld::TransformCubeitem()
{
	int index = m_Currentitem.transformid;
	m_Currentitem = Cubeitems[index];
}

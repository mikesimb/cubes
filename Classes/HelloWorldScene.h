#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "renderer/CCRenderer.h"

using namespace cocos2d;
//首先定义个俄罗斯方块的方块形状
typedef struct baseitem
{
   bool c[4][4];
   //变形以后对应的数据ID,255表示没有变形对应
   byte transformid;
};
//另外还需要预定义一些小方块形状
/*
= {
//基本方块
////凸形 以及四种变形方式
{ { 0, 0, 0, 0,
0, 0, 1, 0,
0, 1, 1, 0,
0, 0, 1, 0 }, 1 },

{ { 0, 0, 0, 0,
0, 0, 1, 0,
0, 1, 1, 1,
0, 0, 0, 0 }, 2 },

{ { 0, 0, 0, 0,
0, 0, 1, 0,
0, 0, 1, 1,
0, 0, 1, 0 }, 3 },

{ { 0, 0, 0, 0,
0, 0, 0, 0,
0, 1, 1, 1,
0, 0, 1, 0 }, 0 },

//方形
{ { 0, 0, 0, 0,
0, 1, 1, 0,
0, 1, 1, 0,
0, 0, 0, 0 }, 255 },
//Z1 形
{ { 0, 0, 1, 0,
0, 1, 1, 0,
0, 1, 0, 0,
0, 0, 0, 0 }, 7 },
{ { 0, 0, 0, 0,
0, 1, 1, 0,
1, 1, 0, 0,
0, 0, 0, 0 }, 6 },
//长条形
{ { 0, 1, 0, 0,
0, 1, 0, 0,
0, 1, 0, 0,
0, 1, 0, 0 }, 9 },
//横条形
{ { 0, 0, 0, 0,
0, 0, 0, 0,
1, 1, 1, 1,
0, 0, 0, 0 }, 8 },
//L形
{ { 0, 0, 0, 0,
0, 0, 1, 0,
0, 0, 1, 0,
0, 1, 1, 0 }, 11 },
//L1 形
{ { 0, 0, 0, 0,
0, 0, 0, 0,
1, 0, 0, 0,
1, 1, 1, 0 }, 12 },
//L2 形
//L1 形
{ { 0, 0, 0, 0,
1, 1, 0, 0,
1, 0, 0, 0,
1, 0, 0, 0 }, 13 },
//L1 形
{ { 0, 0, 0, 0,
1, 1, 1, 0,
0, 0, 1, 0,
0, 0, 0, 0 }, 10 }
};
*/


class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);


	virtual void update(float delta);

    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags) override;
	
	//定义一个基本的方块
	baseitem Cubeitems[13];

protected:
	void DrawGride();
	//virtual void draw() final;
};

#endif // __HELLOWORLD_SCENE_H__

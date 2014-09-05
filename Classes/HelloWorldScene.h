#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "renderer/CCRenderer.h"
#include "CubeGame.h"

using namespace cocos2d;

extern ALS_Cubitem;
extern ALS_Cubitem AItems[15];

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void menuCallback(cocos2d::Ref* pSender);
    void CloseItem2CallBack(cocos2d::Ref* pSender);

	virtual void update(float delta);

    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags) override;
	

protected:
	void DrawGride();
	void DrawCubeItem();
    void DrawMap();

	void OnTime(float f);
  

	//virtual void draw() final;
    
    


private:
	CCubeGame m_CubeGame;
    
    
    
};

#endif // __HELLOWORLD_SCENE_H__

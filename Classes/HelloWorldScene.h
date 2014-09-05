#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "renderer/CCRenderer.h"

using namespace cocos2d;

#define MapRows 15
#define MapCols 19
// ◊œ»∂®“Â∏ˆ∂Ì¬ﬁÀπ∑ΩøÈµƒ∑ΩøÈ–Œ◊¥
 struct baseitem
{
   bool c[4][4];
   //±‰–Œ“‘∫Û∂‘”¶µƒ ˝æ›ID,255±Ì æ√ª”–±‰–Œ∂‘”¶
   short transformid;
};
//¡ÌÕ‚ªπ–Ë“™‘§∂®“Â“ª–©–°∑ΩøÈ–Œ◊¥

//∂®“Â“ª∏ˆª˘±æµƒ∑ΩøÈ
const baseitem Cubeitems[13]= {
//ª˘±æ∑ΩøÈ
////Õπ–Œ “‘º∞Àƒ÷÷±‰–Œ∑Ω Ω 0
{ { 0, 0, 0, 0,
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 0, 1, 0 }, 1 },
//1
{ { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 1, 0,
    0, 1, 1, 1 }, 2 },
//2
{ { 0, 0, 0, 0,
    0, 0, 1, 0,
    0, 0, 1, 1,
    0, 0, 1, 0 }, 3 },
//3
{ { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 1,
    0, 0, 1, 0 }, 0 },

//∑Ω–Œ 4
{ { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    0, 1, 1, 0 }, 255 },
//Z1 –Œ 5
{ { 0, 0, 0, 0,
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 1, 0, 0 }, 7 },
//6
{ { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0 }, 6 },

//≥§Ãı–Œ 7
{ { 0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0 }, 8 },
//∫·Ãı–Œ 8
{ { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 1, 1, 1,}, 7 },
//L–Œ 9
{ { 0, 0, 0, 0,
    0, 0, 1, 0,
    0, 0, 1, 0,
    0, 1, 1, 0 }, 10 },
//L1 –Œ 10
{ { 0, 0, 0, 0,
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 1, 0 }, 11},
//L2 –Œ
//L1 –Œ 11
{ { 0, 0, 0, 0,
    1, 1, 0, 0,
    1, 0, 0, 0,
    1, 0, 0, 0 }, 12 },
//L1 –Œ 12
{ { 0, 0, 0, 0,
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0 }, 9 }
};



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


	virtual void update(float delta);

    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags) override;
	
	//∂®“Â“ª∏ˆª˘±æµƒ∑ΩøÈ
	//baseitem Cubeitems[13];

protected:
	void DrawGride();
	void DrawCubeItem();
    void DrawMap();

	void OnTime(float f);
    void UpdateCurrentItemPos();

	//virtual void draw() final;
    
    


private:
	baseitem CreateAnewcube();
	void TransformCubeitem();
	baseitem m_Currentitem;
	int m_CurrentItem_x;
	int m_CurrentItem_y;
    
    unsigned char  Map[MapRows][MapCols];
    
    
    
};

#endif // __HELLOWORLD_SCENE_H__

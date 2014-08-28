#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "renderer/CCRenderer.h"

using namespace cocos2d;
//���ȶ��������˹����ķ�����״
typedef struct baseitem
{
   bool c[4][4];
   //�����Ժ��Ӧ������ID,255��ʾû�б��ζ�Ӧ
   byte transformid;
};
//���⻹��ҪԤ����һЩС������״
/*
= {
//��������
////͹�� �Լ����ֱ��η�ʽ
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

//����
{ { 0, 0, 0, 0,
0, 1, 1, 0,
0, 1, 1, 0,
0, 0, 0, 0 }, 255 },
//Z1 ��
{ { 0, 0, 1, 0,
0, 1, 1, 0,
0, 1, 0, 0,
0, 0, 0, 0 }, 7 },
{ { 0, 0, 0, 0,
0, 1, 1, 0,
1, 1, 0, 0,
0, 0, 0, 0 }, 6 },
//������
{ { 0, 1, 0, 0,
0, 1, 0, 0,
0, 1, 0, 0,
0, 1, 0, 0 }, 9 },
//������
{ { 0, 0, 0, 0,
0, 0, 0, 0,
1, 1, 1, 1,
0, 0, 0, 0 }, 8 },
//L��
{ { 0, 0, 0, 0,
0, 0, 1, 0,
0, 0, 1, 0,
0, 1, 1, 0 }, 11 },
//L1 ��
{ { 0, 0, 0, 0,
0, 0, 0, 0,
1, 0, 0, 0,
1, 1, 1, 0 }, 12 },
//L2 ��
//L1 ��
{ { 0, 0, 0, 0,
1, 1, 0, 0,
1, 0, 0, 0,
1, 0, 0, 0 }, 13 },
//L1 ��
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
	
	//����һ�������ķ���
	baseitem Cubeitems[13];

protected:
	void DrawGride();
	//virtual void draw() final;
};

#endif // __HELLOWORLD_SCENE_H__

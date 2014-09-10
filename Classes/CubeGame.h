#pragma once


/*
这是一个俄罗斯方块游戏，这个游戏有几个前提
1、需要有一个棋盘，也就是地图 我们姑且定义为一个宽10 * 高15的地图
   __________
   ||||||||||
   ||||||||||
   ||||||||||
   ||||||||||
   ||||||||||
   ||||||||||
   ||||||||||
   ||||||||||
   ||||||||||
   左下角为地图的(0，0)坐标

2、由于俄罗斯方块的游戏是各种形状掉落，那么对于形状会有以下的定义,这里需要注意的是其实我们现在定义的图片是倒过来的

*/
//单个物体，我们认为是一个4*4的点阵来实现各中形状的，
 struct ALS_Cubitem
{
	bool c[4][4];
	short transformid;//代表变形后的形状ID
};
#define cMapRows  15
#define cMapCols  10
static ALS_Cubitem AItems[15] = {
		{ { 1, 1, 1, 0,
		0, 1, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 1 },

		{ { 0, 1, 0, 0,
		0, 1, 1, 0,
		0, 1, 0, 0,
		0, 0, 0, 0 }, 2 },

		{ { 0, 1, 0, 0,
		1, 1, 1, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 3 },

		{ { 0, 1, 0, 0,
		1, 1, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 0 }, 0 },

		{ { 1, 1, 0, 0,
		1, 1, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 255 },

		{ { 1, 0, 0, 0,
		1, 1, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 0 }, 6 },

		{ { 0, 1, 1, 0,
		1, 1, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 5 },

		{ { 0, 1, 0, 0,
		1, 1, 0, 0,
		1, 0, 0, 0,
		0, 0, 0, 0 }, 8 },

		{ { 1, 1, 0, 0,
		0, 1, 1, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 7 },

		{ { 0, 1, 0, 0,
		0, 1, 0, 0,
		0, 1, 0, 0,
		0, 1, 0, 0 }, 10 },

		{ { 1, 1, 1, 1,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 9 },

		{ { 1, 1, 1, 0,
		1, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 12 },

		{ { 1, 0, 0, 0,
		1, 0, 0, 0,
		1, 1, 0, 0,
		0, 0, 0, 0 }, 13 },

		{ { 0, 0, 0, 1,
		1, 1, 1, 1,
		0, 0, 0, 0,
		0, 0, 0, 0 }, 14 },

		{ { 1, 1, 0, 0,
		0, 1, 0, 0,
		0, 1, 0, 0,
		0, 1, 0, 0 }, 11 },

		//{ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
		//{ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
		//{ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
};


class CCubeGame
{
public:
	CCubeGame();
	virtual ~CCubeGame();
	//物品变形
	void TransformCubitem();
	//当前物品左右移动
	void Movetoleft();
	void MovetoRight();

	void movetoDown();

	void CreateCurrentCubeitem();

	ALS_Cubitem *  getCurrentCubeItem();
	int getCurrentItemColNum();
	int getCurrentItemyRowNum();

	bool getMapdata(int Row, int Col);
	
    void CopyItemToMap();
protected:
	void InitMap();
	//碰撞检测
	bool CheckBumpItemAndMap();
	//判断列碰撞
	bool CheckBumpItemandmapforcol(bool isMoveLeft);
  
	bool CheckBumpItemandMapforleft();

	bool CheckBumpItemandMapforRight();

	bool CheckCanClearRow(int RowNum);

	void ClearMap();
	bool CheckGameisOver();
    


private:
	//这个是地图数组 每个数字只用O和1来判断
	bool m_Map[cMapRows][cMapCols];
	ALS_Cubitem * m_Current_Cubeitem;
	int m_Current_Cubeitem_ColNum;
	int m_Current_Cubeitem_RowNum;

};


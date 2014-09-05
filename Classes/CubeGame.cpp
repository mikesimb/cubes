#include "CubeGame.h"
#include <stdlib.h>
//#include <stdio.h>


CCubeGame::CCubeGame() :
m_Current_Cubeitem_x(0),
m_Current_Cubeitem_y(0)
{
	InitMap();
}


CCubeGame::~CCubeGame() 
{
}

void CCubeGame::InitMap()
{

	for (int i = 0; i < cMapRows; i++)
		for (int j = 0; j < cMapCols; j++)
		{
		m_Map[i][j] = false;
		}

}

void CCubeGame::CreateCurrentCubeitem()
{
	int index = rand() % 17;
	m_Current_Cubeitem = &AItems[index];
	m_Current_Cubeitem_x = rand() % 10;
	m_Current_Cubeitem_y = 14;
}

void CCubeGame::TransformCubitem()
{
	int index = m_Current_Cubeitem->transformid;
	if (index != 255)
		m_Current_Cubeitem = &AItems[index];
}

void CCubeGame::Movetoleft()
{
	m_Current_Cubeitem_x--;

}

void CCubeGame::MovetoRight()
{
	m_Current_Cubeitem_x++;
}

ALS_Cubitem * CCubeGame::getCurrentCubeItem()
{
	return m_Current_Cubeitem;
}

bool CCubeGame::CheckBumpItemAndMap()
{
	//这有几种情况种检测
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
		//这个物体是否对于地图有碰撞
		if ((m_Current_Cubeitem_x >= 1) && (m_Current_Cubeitem_y >= 1))
		{
			if ((m_Current_Cubeitem->c[i][j] && m_Map[m_Current_Cubeitem_x  + i][m_Current_Cubeitem_y  + j]) == 1)
			{
				return true;
			}
		}
		else
		{
			if (m_Current_Cubeitem_y < 1)
				if ((m_Current_Cubeitem->c[i][j] || m_Map[m_Current_Cubeitem_x][0]) == 1)
				{
					return true;
				}
		}
		}

	return false;

}

int CCubeGame::getCurrentItemx()
{
	return m_Current_Cubeitem_x;
}

int CCubeGame::getCurrentItemy()
{
	return m_Current_Cubeitem_y;
}

bool CCubeGame::getMapdata(int x, int y)
{
	return m_Map[x][y];
}

void CCubeGame::movetoDown()
{
	if (!CheckBumpItemAndMap())
		m_Current_Cubeitem_y--;
}

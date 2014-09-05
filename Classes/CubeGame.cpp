
#include "CubeGame.h"
#include <stdlib.h>
//#include <stdio.h>


CCubeGame::CCubeGame() :
m_Current_Cubeitem_ColNum(0),
m_Current_Cubeitem_RowNum(0)
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
	int index = arc4random()%17;
    //rand() % 17;
	m_Current_Cubeitem = &AItems[index];
	m_Current_Cubeitem_ColNum = arc4random() % 6;
	m_Current_Cubeitem_RowNum = 14;
}

void CCubeGame::TransformCubitem()
{
	int index = m_Current_Cubeitem->transformid;
	if (index != 255)
		m_Current_Cubeitem = &AItems[index];
}

void CCubeGame::Movetoleft()
{
	m_Current_Cubeitem_ColNum--;

}

void CCubeGame::MovetoRight()
{
	m_Current_Cubeitem_ColNum++;
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
		if ((m_Current_Cubeitem_ColNum >= 1) && (m_Current_Cubeitem_RowNum >= 1))
		{
//			if ((m_Current_Cubeitem->c[i][j] && m_Map[m_Current_Cubeitem_RowNum  + i][m_Current_Cubeitem_ColNum + j]) == 1)
//			{
//				return true;
//			}
		}
		else
		{
			if (m_Current_Cubeitem_RowNum < 1)
				if ((m_Current_Cubeitem->c[i][j] || m_Map[m_Current_Cubeitem_ColNum][0]) == 1)
				{
					return true;
				}
		}
		}

	return false;

}

int CCubeGame::getCurrentItemColNum()
{
	return m_Current_Cubeitem_ColNum;
}

int CCubeGame::getCurrentItemyRowNum()
{
	return m_Current_Cubeitem_RowNum;
}

bool CCubeGame::getMapdata(int Col, int Row )
{
	return m_Map[Row][Col];
}

void CCubeGame::movetoDown()
{
	if (!CheckBumpItemAndMap())
		m_Current_Cubeitem_RowNum--;
    else
    {
        //COPY CURRENTITEM TO MAP
        CopyItemToMap();
    }
}


void CCubeGame::CopyItemToMap()
{
    for(int i = 0 ;i < 4 ;i++)
        for (int j = 0 ;j < 4 ;j++)
        {
            if(m_Current_Cubeitem->c[i][j])
            m_Map[m_Current_Cubeitem_RowNum+i][m_Current_Cubeitem_ColNum+j] = m_Current_Cubeitem->c[i][j];
        }
    CreateCurrentCubeitem();
}

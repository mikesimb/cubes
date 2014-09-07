
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
	//这里是碰撞检测
    //首先是判断是不是到了底边？
    if(m_Current_Cubeitem_RowNum < 1)
    {
        //判断CurrentCubItem是不是能够下移动？
        for (int i = 0 ; i < 4; i++) {
            if ((m_Current_Cubeitem_RowNum+ i) == 0 )
            {
                for (int j = 0 ; j < 4; j++) {
                   //判断Cubeitem是不是有东西的点碰到底边了
                    if(m_Current_Cubeitem->c[i][j] && m_Map[m_Current_Cubeitem_RowNum  + i][m_Current_Cubeitem_ColNum + j])
                       return true;
                }
            }
        }
    }else
    //没有到最低边
    {
        //判断CurrentCubItem是不是能够下移动？
        for (int i = 0 ; i < 4; i++) {
                for (int j = 0 ; j < 4; j++) {
                    //判断Cubeitem是不是有东西的点碰到底边了
                    if(m_Current_Cubeitem->c[i][j] && m_Map[m_Current_Cubeitem_RowNum  + i][m_Current_Cubeitem_ColNum + j])
                        return true;
            }
        }

    }
    //可以
    //不可以
    
    //判断是不是在最左边
    //判断是不是在最上边
    //判断是不是在最下边
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
		//’‚∏ˆŒÔÃÂ «∑Ò∂‘”⁄µÿÕº”–≈ˆ◊≤
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

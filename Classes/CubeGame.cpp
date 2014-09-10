
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
	//int index = arc4random()%17;
     int index = rand() % 17;
	m_Current_Cubeitem = &AItems[index];
	//m_Current_Cubeitem_ColNum = arc4random() % 6;
	m_Current_Cubeitem_ColNum = rand() % 6;
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
	if (!CheckBumpItemandMapforleft())
	   m_Current_Cubeitem_ColNum--;


	//首先判断是不是可以移动到这里?


}

void CCubeGame::MovetoRight()
{
	if (!CheckBumpItemandMapforRight())
	      m_Current_Cubeitem_ColNum++;
}

ALS_Cubitem * CCubeGame::getCurrentCubeItem()
{
	return m_Current_Cubeitem;
}


bool CCubeGame::CheckBumpItemandMapforleft()
{
	//向左移动
	if (m_Current_Cubeitem_ColNum < 0)
	{
		//这里说明到了左边界
		//判断CurrentCubItem是不是能够下移动？
		for (int i = 0; i < 4; i++) {
			if ((m_Current_Cubeitem_ColNum + i) == 0)
			{
				for (int j = 0; j < 4; j++) {
					//判断Cubeitem是不是有东西的点碰到左边了
					if (m_Current_Cubeitem->c[i][j] )
						return true;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; i++) {
				{
					for (int j = 0; j < 4; j++) {
						//判断Cubeitem是不是有东西的点碰到左边了
						if (m_Current_Cubeitem->c[i][j] && (m_Map[m_Current_Cubeitem_RowNum + i][m_Current_Cubeitem_ColNum -1 + j]))
							return true;
					}
				}
		}
	}

	return false;
}


bool CCubeGame::CheckBumpItemandmapforcol(bool isMoveLeft)
{
	if (isMoveLeft)
		return CheckBumpItemandMapforleft();
	else
		return CheckBumpItemandMapforRight();
	
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
					if (m_Current_Cubeitem->c[i][j] && (!m_Map[m_Current_Cubeitem_RowNum +i][m_Current_Cubeitem_ColNum + j]))
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
                    //判断Cubeitem是不是有东西的点碰到东西了？
					if (m_Current_Cubeitem_RowNum + i >= cMapRows) break;
					if (m_Current_Cubeitem_RowNum + i - 1 >= cMapRows) break;
                    if(m_Current_Cubeitem->c[i][j] && (m_Map[m_Current_Cubeitem_RowNum  + i-1][m_Current_Cubeitem_ColNum+j ]))
                        return true;
            }
        }

    }
   

	ClearMap();

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

bool CCubeGame::CheckBumpItemandMapforRight()
{
	
	int col = 0;
		//这里说明到了右边界
		for (int j = 3; j >= 0; j--) {
				for (int i = 3; i >= 0; i--) {
					//判断Cubeitem是不是有东西的点碰到左边了
					if (m_Current_Cubeitem_ColNum + j>= 9)
					{
						if (m_Current_Cubeitem->c[i][j])
							return true;
					}
					else
					{
						if (m_Current_Cubeitem->c[i][j] && m_Map[m_Current_Cubeitem_RowNum + i][m_Current_Cubeitem_ColNum + j + 1])
							return true;

					}
			}
		}
// 	}
// 	else
// 	{
// 		for (int i = 4; i > 0; i--) {
// 			for (int j = 4; j > 0; j--) {
// 						//判断Cubeitem是不是有东西的点碰到右边了
// 						if (m_Current_Cubeitem->c[i][j] && (m_Map[m_Current_Cubeitem_RowNum + i][m_Current_Cubeitem_ColNum+1 + j]))
// 							return true;
// 					}
// 				}
// 		}
// 	}

	return false;

}


void CCubeGame::ClearMap()
{
	bool tempmap[cMapRows][cMapCols] = {false};
	int TempRows = 0;
	bool CanClearRow = false;
	for (int i = 0; i < cMapRows; i++)
	{
		//判断本行是不是可以消除
		CanClearRow = CheckCanClearRow(i);
		if (!CanClearRow)
		{
			//COPY本行数据到TempMap中
			for (int j = 0; j < cMapCols;j++)
			{
				tempmap[TempRows][j] = m_Map[i][j];
			}
			TempRows++;
		}
	}

	for (int row = 0; row < cMapRows;row++)
	{
		for (int col = 0; col < cMapCols; col++)
		{
			m_Map[row][col] = tempmap[row][col];
		}
	}
}
//判断是不是可以消除一行
bool CCubeGame::CheckCanClearRow( int RowNum)
{
	for (int i = 0; i < cMapCols; i++)
	{
		if (!m_Map[RowNum][i])
			return false;
	}
	return true;

}

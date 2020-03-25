#include"global.h"
using namespace ege;

LIFE_BLOOD::LIFE_BLOOD()
{
	value = lifeLimit;///初始值为四滴血

	///生成四格血的贴图对象
	for(int i = 0; i < lifeLimit; i++)
		img[i] = newimage(A_blood,A_blood );

	return;
}

void LIFE_BLOOD::render()
{
	for (int i = 0; i < lifeLimit; i++)
	{/*画四个20*20的方块*/
		setfillcolor((i<value?RED:BLACK), img[i]);///根据血量和血量上限的比较来画红血格子的数量
		bar(0, 0, A_blood, A_blood, img[i]);
	}

	///把画的格子贴到屏幕上
	for (int xi = 0; xi < lifeLimit; xi++)
		putimage(X_blood + xi * (A_blood + 2), Y_blood, img[xi]);
}

LIFE_BLOOD::~LIFE_BLOOD()
{
	///把四个贴图对象全部销毁，在结束游戏时用
	for(int i=0;i<lifeLimit;i++)
	delimage(img[i]);
}


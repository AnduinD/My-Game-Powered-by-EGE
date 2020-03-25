#include"global.h"
using namespace ege;
//跑道直接贴全屏，当作背景图

COURSE::COURSE()
{
	img = newimage(X_SIZE,Y_SIZE);///画上跑道
	setbkcolor(TRANSPARENT, img);
	setfillcolor(BLUE,img);///跑道颜色
	bar(0, Y_blood+A_blood, X_SIZE, Y_blood+A_blood+Course_Width,img);///跑道位置
	bar(0, Y_SIZE-Course_Width, X_SIZE,Y_SIZE,img);///跑道位置
}


COURSE::~COURSE()
{
	delimage(img);
}
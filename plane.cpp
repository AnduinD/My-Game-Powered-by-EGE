#include"global.h"
using namespace ege;
#define A_plane 30///定义飞机边长
#define Y_peak (Y_blood+A_blood+Course_Width)///定义整个飞机最高高度
#define Y_bottom (getheight()-Course_Width-A_plane)

PLANE::PLANE()
{
	life = 4;///初始四滴血
	y = (getheight() + A_blood + Y_blood) / 2;///初始飞机高度，在半高处
	dy = 0;///速度静止

	img = newimage(A_plane,A_plane);///飞机格子长宽
	setfillcolor(LIGHTGRAY, img);///飞机颜色
	//setbkcolor(TRANSPARENT,img);
	bar(0, 0, A_plane, A_plane, img);
}

void PLANE::update(key_msg k)
{
	dy=7;///飞机速度（以后考虑可以根据按键时长来做加速运动？）

	if (y >Y_peak  &&(k.key == 'w' || k.key == key_up)) y=(y-dy<Y_peak)? Y_peak:(y-dy) ;//飞机上飞
	if(y < Y_bottom&&(k.key == 's' || k.key == key_down)) y = (y+dy>Y_bottom)?Y_bottom:(y+dy);//飞机下飞
}

void PLANE::render()
{
	putimage(15, y, img);
}

PLANE::~PLANE()
{
	delimage(img);
}
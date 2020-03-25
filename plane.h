#pragma once
///存放跑者的信息的类
///包括相关接口函数的声明。例如生命值降低、增加；
#include"ege.h"
using namespace ege;

#define lifeLimit  4///上限四滴血

class PLANE
{
public:
	PLANE();///初始化函数，游戏开始时生成一个跑者时调用起来
	~PLANE();///挂掉的时候，用这个清除对象

	void update(key_msg);///更新飞机坐标位置,根据读入按下的键盘按键来更新
	//void brake();///刹车，在松开按键后将飞机速度掷0
	//void clear() { cleardevice(img); }///清空飞机的图面，供下一次画画
	void render();///给更新后的对象进行画图

private:
	PIMAGE img;
	int life;
	int dy;//飞机上下移动的速度，按得越久，动得越快
public:	
	int y;//飞机贴图左上角的纵坐标（要上下移动）
	

	
};
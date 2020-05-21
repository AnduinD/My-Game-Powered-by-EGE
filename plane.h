#pragma once
///存放飞机的信息的类，和相关接口函数的声明。
#include"ege.h"
using namespace ege;
#define A_plane 30///定义飞机边长
#define lifeLimit  4///上限四滴血
class PLANE
{
public:
	PLANE();///初始化函数，游戏开始时生成一个跑者时调用起来
	~PLANE();///挂掉的时候，用这个清除对象

	void update(key_msg);///更新飞机坐标位置,根据读入按下的键盘按键来更新
	void render();///给更新后的对象进行画图

private:
	PIMAGE img;
	int life;
	int dy;//飞机上下移动的速度
	int dx;//飞机水平移动的速度
public:	
	int y;//飞机贴图左上角的纵坐标（要上下移动）
	int x;//飞机贴图的左上角横坐标
};
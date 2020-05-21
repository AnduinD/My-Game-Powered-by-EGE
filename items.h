#pragma once
///声明存放路程中碰到的东西的类
///以及障碍物的函数接口声明
#include"ege.h"
using namespace ege;

class ITEM
{
public:
	PIMAGE img;///物件的贴图
	int type;///物件的属性
	float x;///物件的横坐标
	int y;///物件纵坐标
	float speed;///物件的速度
	ITEM* Next_Ptr;///指向下一个item的指针

	ITEM();///构造函数
	void render();///画出item，读入的参数是item的类型
	void update(bool);///更新item对象的值，读入的值是碰撞检测的结果
};

void item_copy(ITEM* x, ITEM y);///将后面一个ITEM_Y的数值参数复制给到ITEM_X里（主要是重载运算符还没整明白TAT）
ITEM* append(ITEM*);///在尾部再加一个item
void update_all(ITEM*,int ,int,int &);
///全链更新，读入参数是：item链头、plane坐标值（用于判断碰撞）、血量地址（用于根据碰撞结果修改血量）
void render_all(ITEM*);///全链重绘


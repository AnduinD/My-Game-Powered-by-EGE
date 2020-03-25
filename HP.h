#pragma once
///血条类
#include"ege.h"
using namespace ege;

class LIFE_BLOOD///命里面每一个血滴的贴图的类
{
private:
	PIMAGE img[4]; ///血滴的贴图
public:
	int value;///第几滴血，用这个值来标记贴图的位置

public:
	LIFE_BLOOD();///用来初始化出4滴血的函数
	~LIFE_BLOOD();///删除血滴贴图对象
	void render();
};



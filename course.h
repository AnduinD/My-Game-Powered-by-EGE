#pragma once
#include"ege.h"
using namespace ege;

class COURSE
{
public:
	COURSE();
	~COURSE();
	void render() { putimage(0,0,img); }///这样放就可以inline了
private:
	PIMAGE img;
};
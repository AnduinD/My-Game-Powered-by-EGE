#pragma once
#include"ege.h"
using namespace ege;

class COURSE
{
public:
	COURSE();
	~COURSE();
	void render() { putimage(0,0,img); }///�����žͿ���inline��
private:
	PIMAGE img;
};
#pragma once
///Ѫ����
#include"ege.h"
using namespace ege;

class LIFE_BLOOD///������ÿһ��Ѫ�ε���ͼ����
{
private:
	PIMAGE img[4]; ///Ѫ�ε���ͼ
public:
	int value;///�ڼ���Ѫ�������ֵ�������ͼ��λ��

public:
	LIFE_BLOOD();///������ʼ����4��Ѫ�ĺ���
	~LIFE_BLOOD();///ɾ��Ѫ����ͼ����
	void render();
};



#pragma once
///�������·���������Ķ�������
///�Լ��ϰ���ĺ����ӿ�����
#include"ege.h"
using namespace ege;

class ITEM
{
public:
	PIMAGE img;///�������ͼ
	int type;///���������
	float x;///����ĺ�����
	int y;///���������
	float speed;///������ٶ�
	ITEM* Next_Ptr;///ָ����һ��item��ָ��

	ITEM();///���캯��
	void render();///����item������Ĳ�����item������
	void update(bool);///����item�����ֵ�������ֵ����ײ���Ľ��
};

void item_copy(ITEM* x, ITEM y);///������һ��ITEM_Y����ֵ�������Ƹ���ITEM_X���Ҫ�������������û������TAT��
ITEM* append(ITEM*);///��β���ټ�һ��item
void update_all(ITEM*,int ,int,int &);
///ȫ�����£���������ǣ�item��ͷ��plane����ֵ�������ж���ײ����Ѫ����ַ�����ڸ�����ײ����޸�Ѫ����
void render_all(ITEM*);///ȫ���ػ�


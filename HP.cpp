#include"global.h"
using namespace ege;

LIFE_BLOOD::LIFE_BLOOD()
{
	value = lifeLimit;///��ʼֵΪ�ĵ�Ѫ

	///�����ĸ�Ѫ����ͼ����
	for(int i = 0; i < lifeLimit; i++)
		img[i] = newimage(A_blood,A_blood );

	return;
}

void LIFE_BLOOD::render()
{
	for (int i = 0; i < lifeLimit; i++)
	{/*���ĸ�20*20�ķ���*/
		setfillcolor((i<value?RED:BLACK), img[i]);///����Ѫ����Ѫ�����޵ıȽ�������Ѫ���ӵ�����
		bar(0, 0, A_blood, A_blood, img[i]);
	}

	///�ѻ��ĸ���������Ļ��
	for (int xi = 0; xi < lifeLimit; xi++)
		putimage(X_blood + xi * (A_blood + 2), Y_blood, img[xi]);
}

LIFE_BLOOD::~LIFE_BLOOD()
{
	///���ĸ���ͼ����ȫ�����٣��ڽ�����Ϸʱ��
	for(int i=0;i<lifeLimit;i++)
	delimage(img[i]);
}


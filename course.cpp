#include"global.h"
using namespace ege;
//�ܵ�ֱ����ȫ������������ͼ

COURSE::COURSE()
{
	img = newimage(X_SIZE,Y_SIZE);///�����ܵ�
	setbkcolor(TRANSPARENT, img);
	setfillcolor(BLUE,img);///�ܵ���ɫ
	bar(0, Y_blood+A_blood, X_SIZE, Y_blood+A_blood+Course_Width,img);///�ܵ�λ��
	bar(0, Y_SIZE-Course_Width, X_SIZE,Y_SIZE,img);///�ܵ�λ��
}


COURSE::~COURSE()
{
	delimage(img);
}
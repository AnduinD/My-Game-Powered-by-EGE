#include"global.h"
using namespace ege;
#define A_plane 30///����ɻ��߳�
#define Y_peak (Y_blood+A_blood+Course_Width)///���������ɻ���߸߶�
#define Y_bottom (getheight()-Course_Width-A_plane)

PLANE::PLANE()
{
	life = 4;///��ʼ�ĵ�Ѫ
	y = (getheight() + A_blood + Y_blood) / 2;///��ʼ�ɻ��߶ȣ��ڰ�ߴ�
	dy = 0;///�ٶȾ�ֹ

	img = newimage(A_plane,A_plane);///�ɻ����ӳ���
	setfillcolor(LIGHTGRAY, img);///�ɻ���ɫ
	//setbkcolor(TRANSPARENT,img);
	bar(0, 0, A_plane, A_plane, img);
}

void PLANE::update(key_msg k)
{
	dy=7;///�ɻ��ٶȣ��Ժ��ǿ��Ը��ݰ���ʱ�����������˶�����

	if (y >Y_peak  &&(k.key == 'w' || k.key == key_up)) y=(y-dy<Y_peak)? Y_peak:(y-dy) ;//�ɻ��Ϸ�
	if(y < Y_bottom&&(k.key == 's' || k.key == key_down)) y = (y+dy>Y_bottom)?Y_bottom:(y+dy);//�ɻ��·�
}

void PLANE::render()
{
	putimage(15, y, img);
}

PLANE::~PLANE()
{
	delimage(img);
}
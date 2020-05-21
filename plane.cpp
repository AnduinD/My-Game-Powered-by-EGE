#include"global.h"
using namespace ege;
#define Y_peak (Y_blood+A_blood+Course_Width)///���������ɻ���߸߶�
#define Y_bottom (getheight()-Course_Width-A_plane)
#define X_Left 0///����ɻ�����߿��Էɵ���λ��
#define X_Right (getwidth()-A_plane)

PLANE::PLANE()
{
    life = 4;///��ʼ�ĵ�Ѫ
    y = (getheight() + A_blood + Y_blood) / 2;///��ʼ�ɻ��߶ȣ��ڰ�ߴ�
    x = 15;//��ʼˮƽλ��
    dx = dy = 0;///�ٶȾ�ֹ

    img = newimage(A_plane, A_plane);///�ɻ����ӳ���
    setfillcolor(LIGHTGRAY, img);///�ɻ���ɫ
    //setbkcolor(TRANSPARENT,img);
    bar(0, 0, A_plane, A_plane, img);
}

void PLANE::update(key_msg k)
{
    ///�ɻ��ٶȣ��Ժ��ǿ��Ը��ݰ���ʱ�����������˶�����
    dy = 7;
    dx = 7;

    if (y > Y_peak && (k.key == 'w' || k.key == key_up))
        y = (y - dy < Y_peak) ? Y_peak : (y - dy);//�ɻ��Ϸ�
    if (y < Y_bottom && (k.key == 's' || k.key == key_down))
        y = (y + dy > Y_bottom) ? Y_bottom : (y + dy);//�ɻ��·�
    if (x > X_Left && (k.key == 'a' || k.key == key_left))
        x = (x - dx < X_Left) ? X_Left : (x - dx);//�ɻ����
    if (x < X_Right && (k.key == 'd' || k.key == key_right))
        x = (x + dx > X_Right) ? X_Right : (x + dx);//�ɻ��ҷ�
}

void PLANE::render()
{
    putimage(x, y, img);
}

PLANE::~PLANE()
{
    delimage(img);
}
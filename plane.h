#pragma once
///��ŷɻ�����Ϣ���࣬����ؽӿں�����������
#include"ege.h"
using namespace ege;
#define A_plane 30///����ɻ��߳�
#define lifeLimit  4///�����ĵ�Ѫ
class PLANE
{
public:
	PLANE();///��ʼ����������Ϸ��ʼʱ����һ������ʱ��������
	~PLANE();///�ҵ���ʱ��������������

	void update(key_msg);///���·ɻ�����λ��,���ݶ��밴�µļ��̰���������
	void render();///�����º�Ķ�����л�ͼ

private:
	PIMAGE img;
	int life;
	int dy;//�ɻ������ƶ����ٶ�
	int dx;//�ɻ�ˮƽ�ƶ����ٶ�
public:	
	int y;//�ɻ���ͼ���Ͻǵ������꣨Ҫ�����ƶ���
	int x;//�ɻ���ͼ�����ϽǺ�����
};
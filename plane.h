#pragma once
///������ߵ���Ϣ����
///������ؽӿں�������������������ֵ���͡����ӣ�
#include"ege.h"
using namespace ege;

#define lifeLimit  4///�����ĵ�Ѫ

class PLANE
{
public:
	PLANE();///��ʼ����������Ϸ��ʼʱ����һ������ʱ��������
	~PLANE();///�ҵ���ʱ��������������

	void update(key_msg);///���·ɻ�����λ��,���ݶ��밴�µļ��̰���������
	//void brake();///ɲ�������ɿ������󽫷ɻ��ٶ���0
	//void clear() { cleardevice(img); }///��շɻ���ͼ�棬����һ�λ���
	void render();///�����º�Ķ�����л�ͼ

private:
	PIMAGE img;
	int life;
	int dy;//�ɻ������ƶ����ٶȣ�����Խ�ã�����Խ��
public:	
	int y;//�ɻ���ͼ���Ͻǵ������꣨Ҫ�����ƶ���
	

	
};
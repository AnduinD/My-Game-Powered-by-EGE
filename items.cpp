#include"global.h"
using namespace ege;

///����item���е��ٶ�
const float base_speed = 0.5f;
const float rand_speed = 4.5f;

inline float my_rand(float m)
{
    return (float)(randomf() * m);
}

ITEM::ITEM()///�����ܵ���С����ĺ���
{
    Next_Ptr = NULL;///��β��
    speed = my_rand(rand_speed) + base_speed;///�����ʼ��һ���ٶ�
    x = X_SIZE + random(50);///���ƴ���Ļ�������λ��
    type = random(5) < 2 ? 1 : 0;///���Ʒ����Ѫ��ı����������Ѷ�	
     y = random(Y_SIZE-(2*Course_Width+Y_blood+ A_blood +Item_Height))+(Course_Width + Y_blood + A_blood);///���item���ֵĸ߶�
	
     img = newimage(Item_Width,Item_Height);
    if (type == 1)
    {///����ʮ��
        setfillcolor(RED, img);
        bar(0, Item_Height / 3, Item_Width, 2 * Item_Height / 3, img);
        bar(Item_Width / 3, 0, 2 * Item_Width / 3, Item_Height, img);  
    }
    if (type == 0)
    {///������
        setfillcolor(CYAN, img);//������ɫ���ã��Ժ���Կ��Ǹĳ������ɫ��ע�������������ɫ���𿪣�
        bar(0, 0, Item_Width, Item_Height, img);
    }
}

void ITEM::update(bool bumpFlag)
{
    x -= speed;///item����λ�ø���
    if (x <= -Item_Width||bumpFlag)
    {
        x = X_SIZE+random(50);///���ƴ���Ļ�������λ��  
        type = random(5)<2?1:0;///���Ʒ����Ѫ��ı����������Ѷ�	
        speed = my_rand(rand_speed) + base_speed;///��������ٶ�
        y = random(Y_SIZE - (2 * Course_Width + Y_blood + A_blood + Item_Height)) + (Course_Width + Y_blood + A_blood);///���item���ֵĸ߶�
        
        cleardevice(img);
        if (type == 1)
        {///����ʮ��
            setfillcolor(RED, img);
            bar(0, Item_Height / 3, Item_Width, 2 * Item_Height / 3, img);
            bar(Item_Width / 3, 0, 2 * Item_Width / 3, Item_Height, img);
        }
        if (type == 0)
        {///������
            setfillcolor(CYAN, img);//������ɫ���ã��Ժ���Կ��Ǹĳ������ɫ��ע�������������ɫ���𿪣�
            bar(0, 0, Item_Width, Item_Height, img);
        }
    }
}

void ITEM::render()
{
    putimage(x, y, img);
}

void item_copy(ITEM* x, ITEM y)
{
    x->img = y.img;
    x->Next_Ptr = y.Next_Ptr;
    x->speed = y.speed;
    x->type = y.type;
    x->x = y.x;
    x->y = y.y;
    return;
}

ITEM* pop(ITEM * head)///��β���ټ�һ��item
{
    ///�����½��
    ITEM* new_item;
    new_item = (ITEM*)malloc(sizeof(ITEM));//����һ��ITEM���ڴ�
    ITEM itemTemp;    
    item_copy( new_item , itemTemp);//��ֵ����
    new_item->Next_Ptr = NULL;//��סβ��

    ///���������β��
    ITEM* previous, * current=head;

    for (previous = NULL ,current = head;                           ///��ʼ��ѭ��������ǰ�ý��Ϊ�գ���ǰ�ڵ���Ϊ�׽��
        current != NULL;                                                    ///ѭ����ֹ������������β���
        previous = current, current = current->Next_Ptr)    ///�����൱��ѭ�������������һ��
      ;///��ѭ����ֻ������previousָ���ε���β���о�������������Ż�����

    previous->Next_Ptr = new_item;///��ջ��
    return head;
}

void update_all(ITEM * head,int yPlane,int &life)
{
    ITEM* previous, * current;
    for (previous = NULL, current = head;                           ///��ʼ��ѭ��������ǰ�ý��Ϊ�գ���ǰ�ڵ���Ϊ�׽��
        current != NULL;                                                    ///ѭ����ֹ������������β���
        previous = current, current = current->Next_Ptr)    ///�����൱��ѭ�������������һ��
    {
        bool bumpFlag = 0;///�����flag����update()
        if (current->x <= 45&& (yPlane - current->y >= -30 && yPlane - current->y <= 20))
        {///��ײ���
           bumpFlag = true;
           if (current->type == 1&&life < lifeLimit) life++;///��Ѫ
           if (current->type == 0&& life > 0) life--;///��Ѫ  
        }
        current->update(bumpFlag);
    }
}
void render_all(ITEM * head)
{
    ITEM* previous, * current;
    for (previous = NULL, current = head;                           ///��ʼ��ѭ��������ǰ�ý��Ϊ�գ���ǰ�ڵ���Ϊ�׽��
        current != NULL;                                                    ///ѭ����ֹ������������β���
        previous = current, current = current->Next_Ptr)    ///�����൱��ѭ�������������һ��
        current->render();
}
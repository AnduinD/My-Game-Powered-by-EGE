#include"global.h"
using namespace ege;

void mainloop()
{
    /*���ɸ�����ͼ����*/
    COURSE course;//�����ͼ
    PLANE plane;//plane��ͼ
    LIFE_BLOOD lifeBlood;//Ѫ����ͼ

    ///���ɵ�һ��item����Ϊitem����ͷ
    ITEM itemTemp;
    ITEM* itemP = &itemTemp;

    course.render();
    plane.render();
    lifeBlood.render();
    render_all(itemP);

    for (int t = 100 * (rand() % 6 + 1); is_run() && lifeBlood.value > 0; delay_fps(60), --t)
    {
        ///�߼�����
        if (kbhit())
        {
            key_msg k = getkey();///��ȡ������ֵ
            if (k.key == key_esc) break;///ǿ��
            else if (k.key == 'p')
                 append(itemP);//�ֶ���������
            else plane.update(k);
        }
        update_all(itemP,plane.x,plane.y, lifeBlood.value);///����item����ͬʱˢ��Ѫ��


        ///ͼ�θ���
        cleardevice();
        course.render();
        lifeBlood.render();
        plane.render();
        render_all(itemP);///�ػ�item��

        if (t <= 0)
        {
            t = 100 * (rand() % 6 + 1);///�����ʱ����
            append(itemP);///��item��β��һ��item  
        }
    }
    return;
}

int main()
{
    initgraph(X_SIZE, Y_SIZE, INIT_RENDERMANUAL | INIT_ANIMATION);

    ///��������ӳ�ʼ��
    randomize();
    srand(time(NULL));

    mainloop();

    closegraph();
    return 0;
}

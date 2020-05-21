#include"global.h"
using namespace ege;

void mainloop()
{
    /*生成各个贴图对象*/
    COURSE course;//轨道贴图
    PLANE plane;//plane贴图
    LIFE_BLOOD lifeBlood;//血条贴图

    ///生成第一个item，作为item链表头
    ITEM itemTemp;
    ITEM* itemP = &itemTemp;

    course.render();
    plane.render();
    lifeBlood.render();
    render_all(itemP);

    for (int t = 100 * (rand() % 6 + 1); is_run() && lifeBlood.value > 0; delay_fps(60), --t)
    {
        ///逻辑更新
        if (kbhit())
        {
            key_msg k = getkey();///读取按键的值
            if (k.key == key_esc) break;///强退
            else if (k.key == 'p')
                 append(itemP);//手动加物块个数
            else plane.update(k);
        }
        update_all(itemP,plane.x,plane.y, lifeBlood.value);///更新item链，同时刷新血量


        ///图形更新
        cleardevice();
        course.render();
        lifeBlood.render();
        plane.render();
        render_all(itemP);///重绘item链

        if (t <= 0)
        {
            t = 100 * (rand() % 6 + 1);///随机延时控制
            append(itemP);///给item链尾加一个item  
        }
    }
    return;
}

int main()
{
    initgraph(X_SIZE, Y_SIZE, INIT_RENDERMANUAL | INIT_ANIMATION);

    ///随机数种子初始化
    randomize();
    srand(time(NULL));

    mainloop();

    closegraph();
    return 0;
}

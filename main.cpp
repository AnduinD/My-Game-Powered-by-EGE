#include"global.h"
//#pragma comment(lib,"graphics19")///直接在源文件目录下链接库，不晓得可不可行，反正编译是过了
using namespace ege;

void mainloop()
{
    /*生成各个贴图对象*/
    COURSE course;//跑道贴图
    PLANE plane;//Runner贴图
    LIFE_BLOOD lifeBlood;//血条贴图
    
    ///生成第一个item，作为item链表头
    ITEM itemTemp;
    ITEM* itemP= &itemTemp;
    
    course.render();
    plane.render();
    lifeBlood.render();
    render_all(itemP);

    for (int t= 100 * (rand() % 6 + 1); is_run()&&lifeBlood.value>0; delay_fps(60),--t)
    {
        ///逻辑更新
        if (kbhit())
        {
            key_msg k = getkey();///读取按键的值
            if (k.key == key_esc) break;///强退
            plane.update(k);
        }
        update_all(itemP,plane.y,lifeBlood.value);///更新item链，同时刷新血量
       

        ///图形更新
        cleardevice();
        course.render();
        lifeBlood.render();
        plane.render();
        render_all(itemP);///重绘item链
        
        if (t <=0) 
        {
            t = 100 * (rand() % 6 + 1);///随机延时控制
            pop(itemP);///给item链尾加一个item  
        }
    }
    return;
}

int main()
{
    initgraph(X_SIZE, Y_SIZE, INIT_RENDERMANUAL|INIT_ANIMATION);

    ///随机数种子初始化
    randomize();
    srand(time(NULL));

    mainloop();

    closegraph();
    return 0;
}

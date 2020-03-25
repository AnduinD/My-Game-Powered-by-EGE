#include"global.h"
using namespace ege;

///调整item飞行的速度
const float base_speed = 0.5f;
const float rand_speed = 4.5f;

inline float my_rand(float m)
{
    return (float)(randomf() * m);
}

ITEM::ITEM()///生成跑道上小物件的函数
{
    Next_Ptr = NULL;///封尾巴
    speed = my_rand(rand_speed) + base_speed;///随机初始化一个速度
    x = X_SIZE + random(50);///控制从屏幕外出发的位置
    type = random(5) < 2 ? 1 : 0;///控制方块和血块的比例来调整难度	
     y = random(Y_SIZE-(2*Course_Width+Y_blood+ A_blood +Item_Height))+(Course_Width + Y_blood + A_blood);///随机item出现的高度
	
     img = newimage(Item_Width,Item_Height);
    if (type == 1)
    {///画红十字
        setfillcolor(RED, img);
        bar(0, Item_Height / 3, Item_Width, 2 * Item_Height / 3, img);
        bar(Item_Width / 3, 0, 2 * Item_Width / 3, Item_Height, img);  
    }
    if (type == 0)
    {///画方块
        setfillcolor(CYAN, img);//方块颜色设置（以后可以考虑改成随机彩色？注意和其他对象颜色区别开）
        bar(0, 0, Item_Width, Item_Height, img);
    }
}

void ITEM::update(bool bumpFlag)
{
    x -= speed;///item飞行位置更新
    if (x <= -Item_Width||bumpFlag)
    {
        x = X_SIZE+random(50);///控制从屏幕外出发的位置  
        type = random(5)<2?1:0;///控制方块和血块的比例来调整难度	
        speed = my_rand(rand_speed) + base_speed;///随机飞行速度
        y = random(Y_SIZE - (2 * Course_Width + Y_blood + A_blood + Item_Height)) + (Course_Width + Y_blood + A_blood);///随机item出现的高度
        
        cleardevice(img);
        if (type == 1)
        {///画红十字
            setfillcolor(RED, img);
            bar(0, Item_Height / 3, Item_Width, 2 * Item_Height / 3, img);
            bar(Item_Width / 3, 0, 2 * Item_Width / 3, Item_Height, img);
        }
        if (type == 0)
        {///画方块
            setfillcolor(CYAN, img);//方块颜色设置（以后可以考虑改成随机彩色？注意和其他对象颜色区别开）
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

ITEM* pop(ITEM * head)///在尾部再加一个item
{
    ///创建新结点
    ITEM* new_item;
    new_item = (ITEM*)malloc(sizeof(ITEM));//分配一个ITEM的内存
    ITEM itemTemp;    
    item_copy( new_item , itemTemp);//赋值进来
    new_item->Next_Ptr = NULL;//封住尾巴

    ///接在链表的尾部
    ITEM* previous, * current=head;

    for (previous = NULL ,current = head;                           ///初始化循环变量：前置结点为空，当前节点设为首结点
        current != NULL;                                                    ///循环终止条件：检索到尾结点
        previous = current, current = current->Next_Ptr)    ///这里相当于循环变量往后迭代一个
      ;///空循环，只用来把previous指针游到表尾（感觉这个操作可以优化？）

    previous->Next_Ptr = new_item;///入栈！
    return head;
}

void update_all(ITEM * head,int yPlane,int &life)
{
    ITEM* previous, * current;
    for (previous = NULL, current = head;                           ///初始化循环变量：前置结点为空，当前节点设为首结点
        current != NULL;                                                    ///循环终止条件：检索到尾结点
        previous = current, current = current->Next_Ptr)    ///这里相当于循环变量往后迭代一个
    {
        bool bumpFlag = 0;///把这个flag传给update()
        if (current->x <= 45&& (yPlane - current->y >= -30 && yPlane - current->y <= 20))
        {///碰撞检测
           bumpFlag = true;
           if (current->type == 1&&life < lifeLimit) life++;///回血
           if (current->type == 0&& life > 0) life--;///掉血  
        }
        current->update(bumpFlag);
    }
}
void render_all(ITEM * head)
{
    ITEM* previous, * current;
    for (previous = NULL, current = head;                           ///初始化循环变量：前置结点为空，当前节点设为首结点
        current != NULL;                                                    ///循环终止条件：检索到尾结点
        previous = current, current = current->Next_Ptr)    ///这里相当于循环变量往后迭代一个
        current->render();
}
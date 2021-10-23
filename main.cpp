#include "mine.h"

int main()
{
    initial i;
    display d;

    system("color 3f");
    system("mode con cols=36 lines=10");
    i.init();
    i.xy(8, 0);
    cout << "扫雷\n\n清除\\标记：鼠标左键单击\n\n标记：鼠标右键单击\n\n请选择难度 |易|  |中|  |难|";

    do{}while (i.input() == 0 || i.y != 4 || (i.x != 6 && i.x != 9 && i.x != 12));
    i.gamelevel();//游戏难度

    system("cls");
    i.frame();//打印框架
    i.initialize();//初始化状态数组

    while (1)
        d.choose();//鼠标选择
}

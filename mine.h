#ifndef Mine
#define Mine
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdio>
using namespace std;

struct mineT {bool ifmine[32][18]; int sign[32][18]; int num[32][18];};

class initial
{
public:
    int input();//鼠标选择
    void xy(int a, int b);//定义坐标函数
    void gamelevel();//游戏难度
    void frame();//打印框架
    void initialize();//初始化状态数组
    void init();
    static int x;
    static int y;
    static int mineLeft;
    static int col;
    static int line;
    static mineT mine;
};

class display : public initial
{
public:
    void discover(int a, int b);//递归扩展
    void reveal();//显示所有雷
    void choose();//操作
    bool win();//判断是否成功
};

#endif

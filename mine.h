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
    int input();//���ѡ��
    void xy(int a, int b);//�������꺯��
    void gamelevel();//��Ϸ�Ѷ�
    void frame();//��ӡ���
    void initialize();//��ʼ��״̬����
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
    void discover(int a, int b);//�ݹ���չ
    void reveal();//��ʾ������
    void choose();//����
    bool win();//�ж��Ƿ�ɹ�
};

#endif

#include "mine.h"

int main()
{
    initial i;
    display d;

    system("color 3f");
    system("mode con cols=36 lines=10");
    i.init();
    i.xy(8, 0);
    cout << "ɨ��\n\n���\\��ǣ�����������\n\n��ǣ�����Ҽ�����\n\n��ѡ���Ѷ� |��|  |��|  |��|";

    do{}while (i.input() == 0 || i.y != 4 || (i.x != 6 && i.x != 9 && i.x != 12));
    i.gamelevel();//��Ϸ�Ѷ�

    system("cls");
    i.frame();//��ӡ���
    i.initialize();//��ʼ��״̬����

    while (1)
        d.choose();//���ѡ��
}

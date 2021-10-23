#include "mine.h"

void display::discover(int a, int b)
{
    if (!mine.ifmine[a][b] && mine.sign[a][b] == 0)
    {
        if (mine.num[a][b] == 0)
        {
            xy(a, b + 2);
            cout << "  ";
            mine.sign[a][b] = 3;

            if (a > 0)
            {
                discover(a - 1, b);
                if (b > 0)
                    discover(a - 1, b - 1);
            }
            if (a < col - 1)
            {
                discover(a + 1, b);
                if (b < line - 1)
                    discover(a + 1, b + 1);
            }
            if (b > 0)
            {
                discover(a, b - 1);
                if (a < col - 1)
                    discover(a + 1, b - 1);
            }
            if (b < line - 1)
            {
                discover(a, b + 1);
                if (a > 0)
                    discover(a - 1, b + 1);
            }
        }
        else
        {
            xy(a, b + 2);
            cout << mine.num[a][b] << " ";
            mine.sign[a][b] = 3;
        }
    }
}

void display::reveal()
{
    for (int i = 0; i < col; i ++)
        for (int j = 0; j < line; j++)
            if (mine.ifmine[i][j])
            {
                xy(i, j + 2);
                cout << "¡ò";
            }
}

void display::choose()
{
    int choose;
    do{choose = input();}while (choose == 0 || x >= col || y < 0 || y >= line);
    xy(x, y + 2);

    if (choose == 1)
    {
        if (mine.sign[x][y] == 0)
        {
            if (mine.ifmine[x][y])
            {
                reveal();
                xy(2, 1);
                cout << "You lose!";
                xy(0, line + 2);
                system("pause");
                exit(0);
            }
            else
                discover(x, y);
        }
    }
    else if (choose == 2 && mine.sign[x][y] < 3)
    {
        mine.sign[x][y] = (mine.sign[x][y] + 1) % 3;

        if (mine.sign[x][y] == 1)
        {
            if (mineLeft == 0)
            {
                mine.sign[x][y]++;
                cout << "? ";
            }
            else
            {
                cout << "¡ð";
                xy(0, 1);
                cout << --mineLeft << " ";
            }
        }
        else if (mine.sign[x][y] == 2)
        {
            cout << "? ";
            xy(0, 1);
            cout << ++mineLeft;
        }
        else
            cout << "¨€";
    }

    if (win())
    {
        xy(2, 1);
        cout << "Äã³É¹¦ÁË£¡";
        xy(0, line + 2);
        system("pause");
        exit(0);
    }

    Sleep(300);
}

bool display::win()
{
    for (int i = 0; i < col; i ++)
        for (int j = 0; j < line; j++)
            if (mine.sign[i][j] == 0 || mine.sign[i][j] == 2)
                return false;

    if (mineLeft == 0)
        return true;
    else
        return false;
}

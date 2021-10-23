#include "mine.h"

mineT initial::mine = {{{false}}, {{0}}, {{0}}};
int initial::x = 0;
int initial::y = 0;
int initial::mineLeft = 0;
int initial::col = 0;
int initial::line = 0;

int initial::input()
{
    POINT p;
    HWND h;
    h = GetForegroundWindow();
    GetCursorPos(&p);
    ScreenToClient(h, &p);
    x = p.x / 16, y = p.y / 16 - 2;

    int i = 0;
    if (GetAsyncKeyState(VK_RBUTTON))
        i = 2;
    if (GetAsyncKeyState(VK_LBUTTON))
        i = 1;
    Sleep(100);
    return i;
}

void initial::init()
{
    CONSOLE_CURSOR_INFO c = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    SetConsoleMode(hStdin, mode);
}

void initial::xy(int a, int b)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {a * 2, b};
    SetConsoleCursorPosition(hOut, pos);
}

void initial::gamelevel()
{
    if (x == 6)
    {
        system("mode con cols=36 lines=16");
        mineLeft = 20;
        col = 18;
        line = 8;
    }
    else if (x == 9)
    {
        system("mode con cols=50 lines=20");
        mineLeft = 50;
        col = 25;
        line = 12;
    }
    else if (x == 12)
    {
        system("mode con cols=64 lines=25");
        mineLeft = 100;
        col = 32;
        line = 18;
    }
}

void initial::frame()
{
    xy(col / 2 - 1, 0);
    cout << "É¨À×\n" << mineLeft;

    for (int i = 0; i < col; i++)
        for (int j = 2; j < line + 2; j++)
        {
            xy(i, j);
            cout << "¨€";
        }
}

void initial::initialize()
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < mineLeft; i++)
    {
        int a, b;
        do
        {
            a = rand() % col, b = rand() % line;
        }while (mine.ifmine[a][b]);
        mine.ifmine[a][b] = true;
    }

    for (int i = 0; i < col; i++)
        for (int j = 0; j < line; j++)
            for (int m = ((i > 0) ? (i - 1) : 0); m < col && m <= i + 1; m++)
                for (int n = ((j > 0) ? (j - 1) : 0); n < line && n <= j + 1; n++)
                    if (mine.ifmine[m][n])
                        mine.num[i][j]++;
}

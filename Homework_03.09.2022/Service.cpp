#include "Service.h"

void PrintString(string Text, int& ActiveString)
{
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << Text;
}

int GetKey()
{
#ifdef linux
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#else
    return _getch();
#endif
}

bool ArrayIsFilled(const bool ArrayFilled, int& ActiveString)
{
    if (ArrayFilled) return true;
    else
    {
        PrintString("Массив не заполнен! Сначала выполните процедуру его заполнения!", ActiveString);
        return false;
    }
}
#include <iostream>
#include <string>
#include <iomanip>

#ifdef linux
#include <termios.h>
#include <unistd.h>
#define ENTER 10
#define UP_ARROW 65
#define DOWN_ARROW 66
#define HOME 72
#define END 70
#else
#include <conio.h>
#define ENTER 13
#define UP_ARROW 72
#define DOWN_ARROW 80
#define HOME 71
#define END 79
#endif


using namespace std;

#define ESC "\x1b"
#define CSI "\x1b["

enum ArrayTypes { Char = 0, Int, Float, Double };

void ArrayTypeSelectionMenu();
void DisplayMenu(string MenuList[], const int MenuItems, int MenuIndex);
void NavigatingByMenu(string MenuList[], const int MenuItems, int& MenuIndex, int key);
void PrintString(string Text, int& ActiveString);
int GetKey();
bool ArrayIsFilled(const bool ArrayFilled, int& ActiveString);

//Char
void menu(char ArrayType, const int ArraySize);
void menu(char ArrayType, const int ArrayColumns, const int ArrayStrings);
void FillRand(char Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(char**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void Print(char Array[], const int ArraySize, int& ActiveString);
void Print(char** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
void ReversePrint(char Array[], const int ArraySize, int& ActiveString);
void ReversePrint(char** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
int Sum(char Array[], const int ArraySize);
int Sum(char** Array, const int ArrayColumns, const int ArrayStrings);
double Avg(char Array[], const int ArraySize);
double Avg(char** Array, const int ArrayColumns, const int ArrayStrings);
char minValueIn(char Array[], const int ArraySize);
char minValueIn(char** Array, const int ArrayColumns, const int ArrayStrings);
char maxValueIn(char Array[], const int ArraySize);
char maxValueIn(char** Array, const int ArrayColumns, const int ArrayStrings);
void shiftLeft(char Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftLeft(char**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void shiftRight(char Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftRight(char**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void UniqueRand(char Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void UniqueRand(char**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
bool ValueInArray(char Array[], const char ArrayValue, const int ArrayIndex);
bool ValueInArray(char** Array, const char ArrayValue, const int IndexString, const int IndexColumn);
void Sort(char Array[], const int ArraySize, const bool SortByAscending, int& ActiveString);
void Sort(char**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString);
void Search(char Array[], const int ArraySize, int& ActiveString);
void Search(char**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);

//Int
void menu(int ArrayType, const int ArraySize);
void menu(int ArrayType, const int ArrayColumns, const int ArrayStrings);
void FillRand(int Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(int**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void Print(int Array[], const int ArraySize, int& ActiveString);
void Print(int** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
void ReversePrint(int Array[], const int ArraySize, int& ActiveString);
void ReversePrint(int** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
int Sum(int Array[], const int ArraySize);
int Sum(int** Array, const int ArrayColumns, const int ArrayStrings);
double Avg(int Array[], const int ArraySize);
double Avg(int** Array, const int ArrayColumns, const int ArrayStrings);
int minValueIn(int Array[], const int ArraySize);
int minValueIn(int** Array, const int ArrayColumns, const int ArrayStrings);
int maxValueIn(int Array[], const int ArraySize);
int maxValueIn(int** Array, const int ArrayColumns, const int ArrayStrings);
void shiftLeft(int Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftLeft(int**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void shiftRight(int Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftRight(int**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void UniqueRand(int Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void UniqueRand(int**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
bool ValueInArray(int Array[], const int ArrayValue, const int ArrayIndex);
bool ValueInArray(int** Array, const int ArrayValue, const int IndexString, const int IndexColumn);
void Sort(int Array[], const int ArraySize, const bool SortByAscending, int& ActiveString);
void Sort(int**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString);
void Search(int Array[], const int ArraySize, int& ActiveString);
void Search(int**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);

//Float
void menu(float ArrayType, const int ArraySize);
void menu(float ArrayType, const int ArrayColumns, const int ArrayStrings);
void FillRand(float Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(float**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void Print(float Array[], const int ArraySize, int& ActiveString);
void Print(float** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
void ReversePrint(float Array[], const int ArraySize, int& ActiveString);
void ReversePrint(float** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
float Sum(float Array[], const int ArraySize);
float Sum(float** Array, const int ArrayColumns, const int ArrayStrings);
float Avg(float Array[], const int ArraySize);
float Avg(float** Array, const int ArrayColumns, const int ArrayStrings);
float minValueIn(float Array[], const int ArraySize);
float minValueIn(float** Array, const int ArrayColumns, const int ArrayStrings);
float maxValueIn(float Array[], const int ArraySize);
float maxValueIn(float** Array, const int ArrayColumns, const int ArrayStrings);
void shiftLeft(float Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftLeft(float**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void shiftRight(float Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftRight(float**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void UniqueRand(float Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void UniqueRand(float**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
bool ValueInArray(float Array[], const float ArrayValue, const int ArrayIndex);
bool ValueInArray(float** Array, const float ArrayValue, const int IndexString, const int IndexColumn);
void Sort(float Array[], const int ArraySize, const bool SortByAscending, int& ActiveString);
void Sort(float**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString);
void Search(float Array[], const int ArraySize, int& ActiveString);
void Search(float**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);

//Double
void menu(double ArrayType, const int ArraySize);
void menu(double ArrayType, const int ArrayColumns, const int ArrayStrings);
void FillRand(double Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(double**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void Print(double Array[], const int ArraySize, int& ActiveString);
void Print(double** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
void ReversePrint(double Array[], const int ArraySize, int& ActiveString);
void ReversePrint(double** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
double Sum(double Array[], const int ArraySize);
double Sum(double** Array, const int ArrayColumns, const int ArrayStrings);
double Avg(double Array[], const int ArraySize);
double Avg(double** Array, const int ArrayColumns, const int ArrayStrings);
double minValueIn(double Array[], const int ArraySize);
double minValueIn(double** Array, const int ArrayColumns, const int ArrayStrings);
double maxValueIn(double Array[], const int ArraySize);
double maxValueIn(double** Array, const int ArrayColumns, const int ArrayStrings);
void shiftLeft(double Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftLeft(double**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void shiftRight(double Array[], const int ArraySize, int ShiftValue, int& ActiveString);
void shiftRight(double**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
void UniqueRand(double Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void UniqueRand(double**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
bool ValueInArray(double Array[], const double ArrayValue, const int ArrayIndex);
bool ValueInArray(double** Array, const double ArrayValue, const int IndexString, const int IndexColumn);
void Sort(double Array[], const int ArraySize, const bool SortByAscending, int& ActiveString);
void Sort(double**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString);
void Search(double Array[], const int ArraySize, int& ActiveString);
void Search(double**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);

int main()
{
    setlocale(LC_ALL, "Rus");
    //menu();
    ArrayTypeSelectionMenu();
    return 0;
}

void ArrayTypeSelectionMenu()
{
    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int SelectionMenuItems = 5;
    string SelectionMenuList[SelectionMenuItems];
    SelectionMenuList[0] = "Работа с массивами типа \"Char\"";
    SelectionMenuList[1] = "Работа с массивами типа \"Int\"";
    SelectionMenuList[2] = "Работа с массивами типа \"Float\"";
    SelectionMenuList[3] = "Работа с массивами типа \"Double\"";
    SelectionMenuList[4] = "Выход";
    int SelectionMenuIndex = 0;
    DisplayMenu(SelectionMenuList, SelectionMenuItems, SelectionMenuIndex);
    bool quit = false;

    int ActiveString = SelectionMenuItems + 2;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            if (SelectionMenuIndex == 4)
            {
                quit = true;
                break;
            }

            PrintString("Введите количество колонок массива: ", ActiveString);
            int ArrayColumns;
            cin >> ArrayColumns;
            cin.ignore(INT32_MAX, '\n');
            ActiveString++;

            PrintString("Введите количество строк массива: ", ActiveString);
            int ArrayStrings;
            cin >> ArrayStrings;
            cin.ignore(INT32_MAX, '\n');
            ActiveString++;

            if (ArrayColumns + ArrayStrings == 0)
            {
                cout << "Массив не может быть пустым!";
                break;
            }

            bool TwoDimensional = (ArrayStrings > 1);

            switch (SelectionMenuIndex)
            {
            case Char:
                if (TwoDimensional) menu((char)SelectionMenuIndex, ArrayColumns, ArrayStrings);
                else menu((char)SelectionMenuIndex, ArrayColumns);
                DisplayMenu(SelectionMenuList, SelectionMenuItems, SelectionMenuIndex);
                break;
            case Int:
                if (TwoDimensional) menu(SelectionMenuIndex, ArrayColumns, ArrayStrings);
                else menu(SelectionMenuIndex, ArrayColumns);
                DisplayMenu(SelectionMenuList, SelectionMenuItems, SelectionMenuIndex);
                break;
            case Float:
                if (TwoDimensional) menu((float)SelectionMenuIndex, ArrayColumns, ArrayStrings);
                else menu((float)SelectionMenuIndex, ArrayColumns);
                DisplayMenu(SelectionMenuList, SelectionMenuItems, SelectionMenuIndex);
                break;
            case Double:
                if (TwoDimensional) menu((double)SelectionMenuIndex, ArrayColumns, ArrayStrings);
                else menu((double)SelectionMenuIndex, ArrayColumns);
                DisplayMenu(SelectionMenuList, SelectionMenuItems, SelectionMenuIndex);
                break;
            case 4: quit = true; break;
            default: break;
            }
        }
        else NavigatingByMenu(SelectionMenuList, SelectionMenuItems, SelectionMenuIndex, key);
    }

}

void NavigatingByMenu(string MenuList[], const int MenuItems, int& MenuIndex, int key)
{
    cout << CSI << MenuIndex + 1 << ";1H";
    switch (key)
    {
    case DOWN_ARROW:
        if (MenuIndex < MenuItems - 1)
        {
            cout << CSI << "1G";
            cout << CSI << "2K";
            cout << CSI << "0m";
            cout << MenuList[MenuIndex];
            MenuIndex++;
            cout << CSI << "1E";
            cout << CSI << "2K";
            cout << CSI << "42m";
            cout << MenuList[MenuIndex];
            cout << CSI << "0m";
            break;
        }
    case UP_ARROW:
        if (MenuIndex > 0)
        {
            cout << CSI << "1G";
            cout << CSI << "2K";
            cout << CSI << "0m";
            cout << MenuList[MenuIndex];
            MenuIndex--;
            cout << CSI << "1F";
            cout << CSI << "2K";
            cout << CSI << "42m";
            cout << MenuList[MenuIndex];
            cout << CSI << "0m";
            break;
        }
    case HOME:
        cout << CSI << "1G";
        cout << CSI << "2K";
        cout << CSI << "0m";
        cout << MenuList[MenuIndex];
        MenuIndex = 0;
        cout << CSI << "1;1H";
        cout << CSI << "2K";
        cout << CSI << "42m";
        cout << MenuList[MenuIndex];
        cout << CSI << "0m";
        break;
    case END:
        cout << CSI << "1G";
        cout << CSI << "2K";
        cout << CSI << "0m";
        cout << MenuList[MenuIndex];
        MenuIndex = MenuItems - 1;
        cout << CSI << MenuItems << ";1H";
        cout << CSI << "2K";
        cout << CSI << "42m";
        cout << MenuList[MenuIndex];
        cout << CSI << "0m";
        break;
    default: break;
    }
}

void DisplayMenu(string MenuList[], const int MenuItems, int MenuIndex)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";
    for (int i = 0; i < MenuItems; i++)
    {
        if (i == MenuIndex)
        {
            cout << CSI << "42m";
            cout << MenuList[i] << endl;
            cout << CSI << "0m";
        }
        else
        {
            cout << MenuList[i] << endl;
        }
    }
    cout << CSI << MenuIndex + 1 << ";1H";
}

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

//Char
void menu(char ArrayType, const int ArraySize)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    char* Array = new char[ArraySize];

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными символами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << minValueIn(Array, ArraySize) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << maxValueIn(Array, ArraySize) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftLeft(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftRight(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArraySize, ArrayFilled, ActiveString, 0, ArraySize - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14: quit = true; delete[] Array; break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void menu(char ArrayType, const int ArrayColumns, const int ArrayStrings)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    char** Array = new char* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        Array[i] = new char[ArrayColumns];
    }

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными символами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << minValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                setlocale(LC_ALL, "*");
                cout << maxValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                setlocale(LC_ALL, "Rus");
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftLeft(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftRight(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString, 0, ArrayColumns + ArrayStrings - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14:
                quit = true;
                for (int i = 0; i < ArrayStrings; i++)
                {
                    delete Array[i];
                }
                delete[] Array;
                break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void FillRand(char Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        int IntValue = rand() % (MaxRand - MinRand) + MinRand;
        char ArrayValue = IntValue;
        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void FillRand(char**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            int IntValue = rand() % (MaxRand - MinRand) + MinRand;
            char ArrayValue = IntValue;
            Array[i][j] = ArrayValue;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void Print(char Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    setlocale(LC_ALL, "*");
    for (int i = 0; i < ArraySize; i++)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "Rus");
}

void Print(char** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "*");
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            cout << " " << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
    setlocale(LC_ALL, "Rus");
}

void ReversePrint(char Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    setlocale(LC_ALL, "*");
    for (int i = ArraySize - 1; i >= 0; i--)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "Rus");
}

void ReversePrint(char** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    cout << endl;
    ActiveString++;
    setlocale(LC_ALL, "*");
    for (int i = ArrayStrings - 1; i >= 0; i--)
    {
        for (int j = ArrayColumns - 1; j >= 0; j--)
        {
            cout << " " << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
    setlocale(LC_ALL, "Rus");
}

int Sum(char Array[], const int ArraySize)
{
    int ArraySum = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    return ArraySum;
}

int Sum(char** Array, const int ArrayColumns, const int ArrayStrings)
{
    int ArraySum = 0;

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            ArraySum += Array[i][j];
        }
    }
    return ArraySum;
}

double Avg(char Array[], const int ArraySize)
{
    int ArraySum = Sum(Array, ArraySize);

    return (double)ArraySum / ArraySize;
}

double Avg(char** Array, const int ArrayColumns, const int ArrayStrings)
{
    int ArraySum = Sum(Array, ArrayColumns, ArrayStrings);

    return (double)ArraySum / (ArrayColumns + ArrayStrings);
}

char minValueIn(char Array[], const int ArraySize)
{
    char MinValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] < MinValue) MinValue = Array[i];
    }
    return MinValue;
}

char minValueIn(char** Array, const int ArrayColumns, const int ArrayStrings)
{
    char MinValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] < MinValue) MinValue = Array[i][j];
        }
    }
    return MinValue;
}

char maxValueIn(char Array[], const int ArraySize)
{
    char MaxValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    return MaxValue;
}

char maxValueIn(char** Array, const int ArrayColumns, const int ArrayStrings)
{
    char MaxValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] > MaxValue) MaxValue = Array[i][j];
        }
    }
    return MaxValue;
}

void shiftLeft(char Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        char CurrentValue = Array[0];
        for (int j = 0; j < ArraySize; j++)
        {
            Array[j] = Array[j + 1];
        }
        Array[ArraySize - 1] = CurrentValue;
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftLeft(char**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        char FirstValue = Array[0][0];
        for (int j = 0; j < ArrayStrings; j++)
        {
            for (int k = 0; k < ArrayColumns; k++)
            {
                if (k == ArrayColumns - 1)
                {
                    if (j == ArrayStrings - 1) Array[j][k] = FirstValue;
                    else Array[j][k] = Array[j + 1][0];
                }
                else Array[j][k] = Array[j][k + 1];
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftRight(char Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArraySize, ArraySize - ShiftValue, ActiveString);
}

void shiftRight(char**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArrayColumns, ArrayStrings, ArrayColumns + ArrayStrings - ShiftValue, ActiveString);
}

void UniqueRand(char Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        int IntValue = rand() % (MaxRand - MinRand) + MinRand;
        char ArrayValue = IntValue;
        while (ValueInArray(Array, ArrayValue, i))
        {
            IntValue = rand() % (MaxRand - MinRand) + MinRand;
            ArrayValue = IntValue;
        }

        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void UniqueRand(char**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            int IntValue = rand() % (MaxRand - MinRand) + MinRand;
            char ArrayValue = IntValue;
            while (ValueInArray(Array, ArrayValue, i, j))
            {
                IntValue = rand() % (MaxRand - MinRand) + MinRand;
                ArrayValue = IntValue;
            }
            Array[i][j] = ArrayValue;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

bool ValueInArray(char Array[], const char ArrayValue, const int ArrayIndex)
{
    bool ValueInArray = false;
    for (int i = 0; i < ArrayIndex; i++)
    {
        if (Array[i] == ArrayValue)
        {
            ValueInArray = true;
            break;
        }
    }
    return ValueInArray;
}

bool ValueInArray(char** Array, const char ArrayValue, const int IndexString, const int IndexColumn)
{
    bool ValueInArray = false;
    for (int i = 0; i < IndexString; i++)
    {
        for (int j = 0; j < IndexColumn; j++)
        {
            if (Array[i][j] == ArrayValue)
            {
                ValueInArray = true;
                break;
            }
        }
    }
    return ValueInArray;
}

void Sort(char Array[], const int ArraySize, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = i + 1; j < ArraySize; j++)
        {
            bool NeedChange;
            if (SortByAscending) NeedChange = (Array[j] < Array[i]);
            else NeedChange = (Array[j] > Array[i]);

            if (NeedChange)
            {
                char CurrentValue = Array[i];
                Array[i] = Array[j];
                Array[j] = CurrentValue;
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Sort(char**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            for (int k = i + 1; k < ArrayStrings; k++)
            {
                for (int l = j + 1; l < ArrayColumns; l++)
                {
                    bool NeedChange;
                    if (SortByAscending) NeedChange = (Array[k][l] < Array[i][j]);
                    else NeedChange = (Array[k][l] > Array[i][j]);

                    if (NeedChange)
                    {
                        char CurrentValue = Array[i][j];
                        Array[i][j] = Array[k][l];
                        Array[k][l] = CurrentValue;
                    }
                }
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Search(char Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //char ArrayOfDoubles[ArraySize];
    char* ArrayOfDoubles = new char[ArraySize];
    int TotalDoubles = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        int CountOfDouble = 1;
        for (int j = i + 1; j < ArraySize; j++)
        {
            if ((Array[i] == Array[j]) && !(Array[j] == ArrayOfDoubles[j]))
            {
                CountOfDouble++;
                ArrayOfDoubles[j] = Array[j];
            }
        }
        if (CountOfDouble > 1)
        {
            TotalDoubles += CountOfDouble;
            cout << Array[i] << " - " << CountOfDouble << " раз(а)\t";
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

void Search(char**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //char ArrayOfDoubles[ArrayStrings][ArrayColumns];
    char** ArrayOfDoubles = new char* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        ArrayOfDoubles[i] = new char[ArrayColumns];
    }
    int TotalDoubles = 0;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            int CountOfDouble = 0;
            for (int k = i; k < ArrayStrings; k++)
            {
                for (int l = 0; l < ArrayColumns; l++)
                {
                    if ((Array[i][j] == Array[k][l]) && !(Array[k][l] == ArrayOfDoubles[k][l]))
                    {
                        CountOfDouble++;
                        ArrayOfDoubles[k][l] = Array[k][l];
                    }
                }
            }
            if (CountOfDouble > 1)
            {
                TotalDoubles += CountOfDouble;
                cout << Array[i][j] << " - " << CountOfDouble << " раз(а)\t";
            }
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete ArrayOfDoubles[i];
    }
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

//Int
void menu(int ArrayType, const int ArraySize)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    int* Array = new int[ArraySize];

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                cout << minValueIn(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                cout << maxValueIn(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftLeft(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftRight(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArraySize, ArrayFilled, ActiveString, 0, ArraySize - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14: quit = true; delete[] Array; break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void menu(int ArrayType, const int ArrayColumns, const int ArrayStrings)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    int** Array = new int* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        Array[i] = new int[ArrayColumns];
    }

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                cout << minValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                cout << maxValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftLeft(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftRight(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString, 0, ArrayColumns + ArrayStrings - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14:
                quit = true;
                for (int i = 0; i < ArrayStrings; i++)
                {
                    delete Array[i];
                }
                delete[] Array;
                break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void FillRand(int Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = rand() % (MaxRand - MinRand) + MinRand;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void FillRand(int**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            Array[i][j] = rand() % (MaxRand - MinRand) + MinRand;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void Print(int Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    for (int i = 0; i < ArraySize; i++)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void Print(int** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    cout << endl;
    ActiveString++;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            cout << " " << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
}

void ReversePrint(int Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    for (int i = ArraySize - 1; i >= 0; i--)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void ReversePrint(int** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    cout << endl;
    ActiveString++;
    for (int i = ArrayStrings - 1; i >= 0; i--)
    {
        for (int j = ArrayColumns - 1; j >= 0; j--)
        {
            cout << " " << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
}

int Sum(int Array[], const int ArraySize)
{
    int ArraySum = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    return ArraySum;
}

int Sum(int** Array, const int ArrayColumns, const int ArrayStrings)
{
    int ArraySum = 0;

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            ArraySum += Array[i][j];
        }
    }
    return ArraySum;
}

double Avg(int Array[], const int ArraySize)
{
    int ArraySum = Sum(Array, ArraySize);

    return (double)ArraySum / ArraySize;
}

double Avg(int** Array, const int ArrayColumns, const int ArrayStrings)
{
    int ArraySum = Sum(Array, ArrayColumns, ArrayStrings);

    return (double)ArraySum / (ArrayColumns + ArrayStrings);
}

int minValueIn(int Array[], const int ArraySize)
{
    int MinValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] < MinValue) MinValue = Array[i];
    }
    return MinValue;
}

int minValueIn(int** Array, const int ArrayColumns, const int ArrayStrings)
{
    int MinValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] < MinValue) MinValue = Array[i][j];
        }
    }
    return MinValue;
}

int maxValueIn(int Array[], const int ArraySize)
{
    int MaxValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    return MaxValue;
}

int maxValueIn(int** Array, const int ArrayColumns, const int ArrayStrings)
{
    int MaxValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] > MaxValue) MaxValue = Array[i][j];
        }
    }
    return MaxValue;
}

void shiftLeft(int Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        int CurrentValue = Array[0];
        for (int j = 0; j < ArraySize; j++)
        {
            Array[j] = Array[j + 1];
        }
        Array[ArraySize - 1] = CurrentValue;
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftLeft(int**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        int FirstValue = Array[0][0];
        for (int j = 0; j < ArrayStrings; j++)
        {
            for (int k = 0; k < ArrayColumns; k++)
            {
                if (k == ArrayColumns - 1)
                {
                    if (j == ArrayStrings - 1) Array[j][k] = FirstValue;
                    else Array[j][k] = Array[j + 1][0];
                }
                else Array[j][k] = Array[j][k + 1];
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftRight(int Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArraySize, ArraySize - ShiftValue, ActiveString);
}

void shiftRight(int**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArrayColumns, ArrayStrings, ArrayColumns + ArrayStrings - ShiftValue, ActiveString);
}

void UniqueRand(int Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        int ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
        while (ValueInArray(Array, ArrayValue, i))
        {
            ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
        }

        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void UniqueRand(int**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            int ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
            while (ValueInArray(Array, ArrayValue, i, j))
            {
                ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
            }
            Array[i][j] = ArrayValue;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

bool ValueInArray(int Array[], const int ArrayValue, const int ArrayIndex)
{
    bool ValueInArray = false;
    for (int i = 0; i < ArrayIndex; i++)
    {
        if (Array[i] == ArrayValue)
        {
            ValueInArray = true;
            break;
        }
    }
    return ValueInArray;
}

bool ValueInArray(int** Array, const int ArrayValue, const int IndexString, const int IndexColumn)
{
    bool ValueInArray = false;
    for (int i = 0; i < IndexString; i++)
    {
        for (int j = 0; j < IndexColumn; j++)
        {
            if (Array[i][j] == ArrayValue)
            {
                ValueInArray = true;
                break;
            }
        }
    }
    return ValueInArray;
}

void Sort(int Array[], const int ArraySize, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = i + 1; j < ArraySize; j++)
        {
            bool NeedChange;
            if (SortByAscending) NeedChange = (Array[j] < Array[i]);
            else NeedChange = (Array[j] > Array[i]);

            if (NeedChange)
            {
                int CurrentValue = Array[i];
                Array[i] = Array[j];
                Array[j] = CurrentValue;
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Sort(int**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            for (int k = i + 1; k < ArrayStrings; k++)
            {
                for (int l = j + 1; l < ArrayColumns; l++)
                {
                    bool NeedChange;
                    if (SortByAscending) NeedChange = (Array[k][l] < Array[i][j]);
                    else NeedChange = (Array[k][l] > Array[i][j]);

                    if (NeedChange)
                    {
                        int CurrentValue = Array[i][j];
                        Array[i][j] = Array[k][l];
                        Array[k][l] = CurrentValue;
                    }
                }
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Search(int Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //int ArrayOfDoubles[ArraySize];
    int* ArrayOfDoubles = new int[ArraySize];
    int TotalDoubles = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        int CountOfDouble = 1;
        for (int j = i + 1; j < ArraySize; j++)
        {
            if ((Array[i] == Array[j]) && !(Array[j] == ArrayOfDoubles[j]))
            {
                CountOfDouble++;
                ArrayOfDoubles[j] = Array[j];
            }
        }
        if (CountOfDouble > 1)
        {
            TotalDoubles += CountOfDouble;
            cout << Array[i] << " - " << CountOfDouble << " раз(а)\t";
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

void Search(int**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //int ArrayOfDoubles[ArrayStrings][ArrayColumns];
    int** ArrayOfDoubles = new int* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        ArrayOfDoubles[i] = new int[ArrayColumns];
    }
    int TotalDoubles = 0;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            int CountOfDouble = 0;
            for (int k = i; k < ArrayStrings; k++)
            {
                for (int l = 0; l < ArrayColumns; l++)
                {
                    if ((Array[i][j] == Array[k][l]) && !(Array[k][l] == ArrayOfDoubles[k][l]))
                    {
                        CountOfDouble++;
                        ArrayOfDoubles[k][l] = Array[k][l];
                    }
                }
            }
            if (CountOfDouble > 1)
            {
                TotalDoubles += CountOfDouble;
                cout << Array[i][j] << " - " << CountOfDouble << " раз(а)\t";
            }
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete ArrayOfDoubles[i];
    }
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

//Float
void menu(float ArrayType, const int ArraySize)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    float* Array = new float[ArraySize];

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                cout << minValueIn(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                cout << maxValueIn(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftLeft(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftRight(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArraySize, ArrayFilled, ActiveString, 0, ArraySize - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14: quit = true; delete[] Array; break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void menu(float ArrayType, const int ArrayColumns, const int ArrayStrings)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    float** Array = new float* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        Array[i] = new float[ArrayColumns];
    }

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                cout << minValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                cout << maxValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftLeft(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftRight(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString, 0, ArrayColumns + ArrayStrings - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14:
                quit = true;
                for (int i = 0; i < ArrayStrings; i++)
                {
                    delete Array[i];
                }
                delete[] Array;
                break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void FillRand(float Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = (float)(rand() % (MaxRand - MinRand) + MinRand) / 10;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void FillRand(float**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            Array[i][j] = (float)(rand() % (MaxRand - MinRand) + MinRand) / 10;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void Print(float Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    for (int i = 0; i < ArraySize; i++)
    {
        cout << " " << setprecision(10) << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void Print(float** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    cout << endl;
    ActiveString++;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            cout << " " << setprecision(10) << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
}

void ReversePrint(float Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    for (int i = ArraySize - 1; i >= 0; i--)
    {
        cout << " " << setprecision(10) << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void ReversePrint(float** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    cout << endl;
    ActiveString++;
    for (int i = ArrayStrings - 1; i >= 0; i--)
    {
        for (int j = ArrayColumns - 1; j >= 0; j--)
        {
            cout << " " << setprecision(10) << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
}

float Sum(float Array[], const int ArraySize)
{
    float ArraySum = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    return ArraySum;
}

float Sum(float** Array, const int ArrayColumns, const int ArrayStrings)
{
    float ArraySum = 0;

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            ArraySum += Array[i][j];
        }
    }
    return ArraySum;
}

float Avg(float Array[], const int ArraySize)
{
    float ArraySum = Sum(Array, ArraySize);

    return (float)ArraySum / ArraySize;
}

float Avg(float** Array, const int ArrayColumns, const int ArrayStrings)
{
    float ArraySum = Sum(Array, ArrayColumns, ArrayStrings);

    return (float)ArraySum / (ArrayColumns + ArrayStrings);
}

float minValueIn(float Array[], const int ArraySize)
{
    float MinValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] < MinValue) MinValue = Array[i];
    }
    return MinValue;
}

float minValueIn(float** Array, const int ArrayColumns, const int ArrayStrings)
{
    float MinValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] < MinValue) MinValue = Array[i][j];
        }
    }
    return MinValue;
}

float maxValueIn(float Array[], const int ArraySize)
{
    float MaxValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    return MaxValue;
}

float maxValueIn(float** Array, const int ArrayColumns, const int ArrayStrings)
{
    float MaxValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] > MaxValue) MaxValue = Array[i][j];
        }
    }
    return MaxValue;
}

void shiftLeft(float Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        float CurrentValue = Array[0];
        for (int j = 0; j < ArraySize; j++)
        {
            Array[j] = Array[j + 1];
        }
        Array[ArraySize - 1] = CurrentValue;
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftLeft(float**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        float FirstValue = Array[0][0];
        for (int j = 0; j < ArrayStrings; j++)
        {
            for (int k = 0; k < ArrayColumns; k++)
            {
                if (k == ArrayColumns - 1)
                {
                    if (j == ArrayStrings - 1) Array[j][k] = FirstValue;
                    else Array[j][k] = Array[j + 1][0];
                }
                else Array[j][k] = Array[j][k + 1];
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftRight(float Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArraySize, ArraySize - ShiftValue, ActiveString);
}

void shiftRight(float**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArrayColumns, ArrayStrings, ArrayColumns + ArrayStrings - ShiftValue, ActiveString);
}

void UniqueRand(float Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        float ArrayValue = (float)(rand() % (MaxRand - MinRand) + MinRand) / 10;
        while (ValueInArray(Array, ArrayValue, i))
        {
            ArrayValue = (float)(rand() % (MaxRand - MinRand) + MinRand) / 10;
        }

        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void UniqueRand(float**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            float ArrayValue = (float)(rand() % (MaxRand - MinRand) + MinRand) / 10;
            while (ValueInArray(Array, ArrayValue, i, j))
            {
                ArrayValue = (float)(rand() % (MaxRand - MinRand) + MinRand) / 10;
            }
            Array[i][j] = ArrayValue;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

bool ValueInArray(float Array[], const float ArrayValue, const int ArrayIndex)
{
    bool ValueInArray = false;
    for (int i = 0; i < ArrayIndex; i++)
    {
        if (Array[i] == ArrayValue)
        {
            ValueInArray = true;
            break;
        }
    }
    return ValueInArray;
}

bool ValueInArray(float** Array, const float ArrayValue, const int IndexString, const int IndexColumn)
{
    bool ValueInArray = false;
    for (int i = 0; i < IndexString; i++)
    {
        for (int j = 0; j < IndexColumn; j++)
        {
            if (Array[i][j] == ArrayValue)
            {
                ValueInArray = true;
                break;
            }
        }
    }
    return ValueInArray;
}

void Sort(float Array[], const int ArraySize, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = i + 1; j < ArraySize; j++)
        {
            bool NeedChange;
            if (SortByAscending) NeedChange = (Array[j] < Array[i]);
            else NeedChange = (Array[j] > Array[i]);

            if (NeedChange)
            {
                float CurrentValue = Array[i];
                Array[i] = Array[j];
                Array[j] = CurrentValue;
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Sort(float**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            for (int k = i + 1; k < ArrayStrings; k++)
            {
                for (int l = j + 1; l < ArrayColumns; l++)
                {
                    bool NeedChange;
                    if (SortByAscending) NeedChange = (Array[k][l] < Array[i][j]);
                    else NeedChange = (Array[k][l] > Array[i][j]);

                    if (NeedChange)
                    {
                        float CurrentValue = Array[i][j];
                        Array[i][j] = Array[k][l];
                        Array[k][l] = CurrentValue;
                    }
                }
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Search(float Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //float ArrayOfDoubles[ArraySize];
    float* ArrayOfDoubles = new float[ArraySize];
    int TotalDoubles = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        int CountOfDouble = 1;
        for (int j = i + 1; j < ArraySize; j++)
        {
            if ((Array[i] == Array[j]) && !(Array[j] == ArrayOfDoubles[j]))
            {
                CountOfDouble++;
                ArrayOfDoubles[j] = Array[j];
            }
        }
        if (CountOfDouble > 1)
        {
            TotalDoubles += CountOfDouble;
            cout << setprecision(10) << Array[i] << " - " << CountOfDouble << " раз(а)\t";
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

void Search(float**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //float ArrayOfDoubles[ArrayStrings][ArrayColumns];
    float** ArrayOfDoubles = new float* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        ArrayOfDoubles[i] = new float[ArrayColumns];
    }
    int TotalDoubles = 0;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            int CountOfDouble = 0;
            for (int k = i; k < ArrayStrings; k++)
            {
                for (int l = 0; l < ArrayColumns; l++)
                {
                    if ((Array[i][j] == Array[k][l]) && !(Array[k][l] == ArrayOfDoubles[k][l]))
                    {
                        CountOfDouble++;
                        ArrayOfDoubles[k][l] = Array[k][l];
                    }
                }
            }
            if (CountOfDouble > 1)
            {
                TotalDoubles += CountOfDouble;
                cout << setprecision(10) << Array[i][j] << " - " << CountOfDouble << " раз(а)\t";
            }
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete ArrayOfDoubles[i];
    }
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

//Double
void menu(double ArrayType, const int ArraySize)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    double* Array = new double[ArraySize];

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                cout << minValueIn(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                cout << maxValueIn(Array, ArraySize) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftLeft(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArraySize;
                shiftRight(Array, ArraySize, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArraySize, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArraySize, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArraySize, ArrayFilled, ActiveString, 0, ArraySize - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArraySize, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14: quit = true; delete[] Array; break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void menu(double ArrayType, const int ArrayColumns, const int ArrayStrings)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    double** Array = new double* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        Array[i] = new double[ArrayColumns];
    }

    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 15;
    string MenuList[MenuItems];
    MenuList[0] = "Заполнить массив случайными числами";
    MenuList[1] = "Вывести массив на экран";
    MenuList[2] = "Вывести массив на экран в обратном порядке";
    MenuList[3] = "Вывести сумму элементов массива";
    MenuList[4] = "Вывести среднее-арифметическое элементов массива";
    MenuList[5] = "Вывести минимальное значение в массиве";
    MenuList[6] = "Вывести максимальное значение в массиве";
    MenuList[7] = "Сдвинуть массив на заданное число элементов влево";
    MenuList[8] = "Сдвинуть массив на заданное число элементов вправо";
    MenuList[9] = "Заполнить массив уникальными случайными числами";
    MenuList[10] = "Отсортировать массив по возрастанию";
    MenuList[11] = "Отсортировать массив по убыванию";
    MenuList[12] = "Заполнить массив случайными числами с обязательными дублями";
    MenuList[13] = "Найти дублирующиеся элементы массива";
    MenuList[14] = "Выход";

    int ActiveString = MenuItems + 2;

    int MenuIndex = 0;
    DisplayMenu(MenuList, MenuItems, MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Print(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 2: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                ReversePrint(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 3: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Сумма элементов массива: ", ActiveString);
                cout << Sum(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 4: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                cout << Avg(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 5: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Минимальное значение в массиве: ", ActiveString);
                cout << minValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 6: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Максимальное значение в массиве: ", ActiveString);
                cout << maxValueIn(Array, ArrayColumns, ArrayStrings) << endl;
                ActiveString++;
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 7: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftLeft(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 8: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                PrintString("Введите значение сдвига: ", ActiveString);
                int ShiftValue;
                cin >> ShiftValue;
                cin.ignore(INT32_MAX, '\n');
                ActiveString++;
                ShiftValue %= ArrayColumns;
                shiftRight(Array, ArrayColumns, ArrayStrings, ShiftValue, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                  break;
            case 9: UniqueRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, true, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 11: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Sort(Array, ArrayColumns, ArrayStrings, false, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 12: FillRand(Array, ArrayColumns, ArrayStrings, ArrayFilled, ActiveString, 0, ArrayColumns + ArrayStrings - 1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled, ActiveString))
            {
                Search(Array, ArrayColumns, ArrayStrings, ActiveString);
                NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
            }
                   break;
            case 14:
                quit = true;
                for (int i = 0; i < ArrayStrings; i++)
                {
                    delete Array[i];
                }
                delete[] Array;
                break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void FillRand(double Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = (double)(rand() % (MaxRand - MinRand) + MinRand) / 10;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void FillRand(double**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            Array[i][j] = (double)(rand() % (MaxRand - MinRand) + MinRand) / 10;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void Print(double Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    for (int i = 0; i < ArraySize; i++)
    {
        cout << " " << setprecision(10) << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void Print(double** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    cout << endl;
    ActiveString++;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            cout << " " << setprecision(10) << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
}

void ReversePrint(double Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    for (int i = ArraySize - 1; i >= 0; i--)
    {
        cout << " " << setprecision(10) << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void ReversePrint(double** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    cout << endl;
    ActiveString++;
    for (int i = ArrayStrings - 1; i >= 0; i--)
    {
        for (int j = ArrayColumns - 1; j >= 0; j--)
        {
            cout << " " << setprecision(10) << Array[i][j];
        }
        cout << endl;
        ActiveString++;
    }
}

double Sum(double Array[], const int ArraySize)
{
    double ArraySum = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    return ArraySum;
}

double Sum(double** Array, const int ArrayColumns, const int ArrayStrings)
{
    double ArraySum = 0;

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            ArraySum += Array[i][j];
        }
    }
    return ArraySum;
}

double Avg(double Array[], const int ArraySize)
{
    double ArraySum = Sum(Array, ArraySize);

    return (double)ArraySum / ArraySize;
}

double Avg(double** Array, const int ArrayColumns, const int ArrayStrings)
{
    double ArraySum = Sum(Array, ArrayColumns, ArrayStrings);

    return (double)ArraySum / (ArrayColumns + ArrayStrings);
}

double minValueIn(double Array[], const int ArraySize)
{
    double MinValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] < MinValue) MinValue = Array[i];
    }
    return MinValue;
}

double minValueIn(double** Array, const int ArrayColumns, const int ArrayStrings)
{
    double MinValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] < MinValue) MinValue = Array[i][j];
        }
    }
    return MinValue;
}

double maxValueIn(double Array[], const int ArraySize)
{
    double MaxValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    return MaxValue;
}

double maxValueIn(double** Array, const int ArrayColumns, const int ArrayStrings)
{
    double MaxValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] > MaxValue) MaxValue = Array[i][j];
        }
    }
    return MaxValue;
}

void shiftLeft(double Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        double CurrentValue = Array[0];
        for (int j = 0; j < ArraySize; j++)
        {
            Array[j] = Array[j + 1];
        }
        Array[ArraySize - 1] = CurrentValue;
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftLeft(double**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        double FirstValue = Array[0][0];
        for (int j = 0; j < ArrayStrings; j++)
        {
            for (int k = 0; k < ArrayColumns; k++)
            {
                if (k == ArrayColumns - 1)
                {
                    if (j == ArrayStrings - 1) Array[j][k] = FirstValue;
                    else Array[j][k] = Array[j + 1][0];
                }
                else Array[j][k] = Array[j][k + 1];
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftRight(double Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArraySize, ArraySize - ShiftValue, ActiveString);
}

void shiftRight(double**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArrayColumns, ArrayStrings, ArrayColumns + ArrayStrings - ShiftValue, ActiveString);
}

void UniqueRand(double Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        double ArrayValue = (double)(rand() % (MaxRand - MinRand) + MinRand) / 10;
        while (ValueInArray(Array, ArrayValue, i))
        {
            ArrayValue = (double)(rand() % (MaxRand - MinRand) + MinRand) / 10;
        }

        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void UniqueRand(double**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            double ArrayValue = (double)(rand() % (MaxRand - MinRand) + MinRand) / 10;
            while (ValueInArray(Array, ArrayValue, i, j))
            {
                ArrayValue = (double)(rand() % (MaxRand - MinRand) + MinRand) / 10;
            }
            Array[i][j] = ArrayValue;
        }
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

bool ValueInArray(double Array[], const double ArrayValue, const int ArrayIndex)
{
    bool ValueInArray = false;
    for (int i = 0; i < ArrayIndex; i++)
    {
        if (Array[i] == ArrayValue)
        {
            ValueInArray = true;
            break;
        }
    }
    return ValueInArray;
}

bool ValueInArray(double** Array, const double ArrayValue, const int IndexString, const int IndexColumn)
{
    bool ValueInArray = false;
    for (int i = 0; i < IndexString; i++)
    {
        for (int j = 0; j < IndexColumn; j++)
        {
            if (Array[i][j] == ArrayValue)
            {
                ValueInArray = true;
                break;
            }
        }
    }
    return ValueInArray;
}

void Sort(double Array[], const int ArraySize, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = i + 1; j < ArraySize; j++)
        {
            bool NeedChange;
            if (SortByAscending) NeedChange = (Array[j] < Array[i]);
            else NeedChange = (Array[j] > Array[i]);

            if (NeedChange)
            {
                double CurrentValue = Array[i];
                Array[i] = Array[j];
                Array[j] = CurrentValue;
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Sort(double**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            for (int k = i + 1; k < ArrayStrings; k++)
            {
                for (int l = j + 1; l < ArrayColumns; l++)
                {
                    bool NeedChange;
                    if (SortByAscending) NeedChange = (Array[k][l] < Array[i][j]);
                    else NeedChange = (Array[k][l] > Array[i][j]);

                    if (NeedChange)
                    {
                        double CurrentValue = Array[i][j];
                        Array[i][j] = Array[k][l];
                        Array[k][l] = CurrentValue;
                    }
                }
            }
        }
    }
    PrintString("Выполнено!", ActiveString);
}

void Search(double Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //double ArrayOfDoubles[ArraySize];
    double* ArrayOfDoubles = new double[ArraySize];
    int TotalDoubles = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        int CountOfDouble = 1;
        for (int j = i + 1; j < ArraySize; j++)
        {
            if ((Array[i] == Array[j]) && !(Array[j] == ArrayOfDoubles[j]))
            {
                CountOfDouble++;
                ArrayOfDoubles[j] = Array[j];
            }
        }
        if (CountOfDouble > 1)
        {
            TotalDoubles += CountOfDouble;
            cout << setprecision(10) << Array[i] << " - " << CountOfDouble << " раз(а)\t";
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

void Search(double**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //double ArrayOfDoubles[ArrayStrings][ArrayColumns];
    double** ArrayOfDoubles = new double* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        ArrayOfDoubles[i] = new double[ArrayColumns];
    }
    int TotalDoubles = 0;
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            int CountOfDouble = 0;
            for (int k = i; k < ArrayStrings; k++)
            {
                for (int l = 0; l < ArrayColumns; l++)
                {
                    if ((Array[i][j] == Array[k][l]) && !(Array[k][l] == ArrayOfDoubles[k][l]))
                    {
                        CountOfDouble++;
                        ArrayOfDoubles[k][l] = Array[k][l];
                    }
                }
            }
            if (CountOfDouble > 1)
            {
                TotalDoubles += CountOfDouble;
                cout << setprecision(10) << Array[i][j] << " - " << CountOfDouble << " раз(а)\t";
            }
        }
    }
    if (TotalDoubles == 0) cout << "отсутствуют";
    for (int i = 0; i < ArrayStrings; i++)
    {
        delete ArrayOfDoubles[i];
    }
    delete[] ArrayOfDoubles;
    cout << endl;
    ActiveString++;
}

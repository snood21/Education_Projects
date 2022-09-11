#include <iostream>
#include <string>

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

void menu();
void DisplayMenu(string MenuList[],int MenuItems,int MenuIndex);
void NavigatingByMenu(string MenuList[], int MenuItems, int &MenuIndex, int key);
int GetKey();
bool ArrayIsFilled(bool ArrayFilled, int ActiveString);
void FillRand(int Array[], int ArraySize, bool &ArrayFilled);
void Print(int Array[], int ArraySize, int &ActiveString);
void ReversePrint(int Array[], int ArraySize, int &ActiveString);
void ReversePrint(int Array[], int ArraySize, int &ActiveString);
void Sum(int Array[], int ArraySize, int &ActiveString);
void Avg(int Array[], int ArraySize, int &ActiveString);
void minValueIn(int Array[], int ArraySize, int &ActiveString);
void maxValueIn(int Array[], int ArraySize, int &ActiveString);
void shiftLeft(int Array[], int ArraySize, int &ActiveString);
void shiftRight(int Array[], int ArraySize, int &ActiveString);
int ReducedShiftValue(int ShiftValue, int ArraySize);
void UniqueRand(int Array[], int ArraySize, bool &ArrayFilled);
bool ValueInArray (int Array[], int ArrayValue, int ArrayIndex);

int main()
{
    setlocale(LC_ALL, "Rus");
    menu();
    return 0;
}

void menu()
{
    int ArraySize;
    cout << "Введите количество элементов массива: ";
    cin >> ArraySize;
    cin.ignore(INT32_MAX,'\n');

    int *Array = new int[ArraySize];
    bool ArrayFilled = false;

    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int MenuItems = 11;
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
    MenuList[10] = "Выход";

    int ActiveString = MenuItems+1;

    int MenuIndex = 0;
    DisplayMenu(MenuList,MenuItems,MenuIndex);
    bool quit = false;

    while (!quit)
    {
        int key = GetKey();

        if (key == ENTER)
        {
            switch (MenuIndex)
            {
            case 0: FillRand(Array,ArraySize,ArrayFilled); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled,ActiveString)) Print(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 2: if (ArrayIsFilled(ArrayFilled,ActiveString)) ReversePrint(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 3: if (ArrayIsFilled(ArrayFilled,ActiveString)) Sum(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 4: if (ArrayIsFilled(ArrayFilled,ActiveString)) Avg(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 5: if (ArrayIsFilled(ArrayFilled,ActiveString)) minValueIn(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 6: if (ArrayIsFilled(ArrayFilled,ActiveString)) maxValueIn(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 7: if (ArrayIsFilled(ArrayFilled,ActiveString)) shiftLeft(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 8: if (ArrayIsFilled(ArrayFilled,ActiveString)) shiftRight(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 9: UniqueRand(Array,ArraySize,ArrayFilled); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: quit = true; delete [] Array; break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void NavigatingByMenu(string MenuList[], int MenuItems, int &MenuIndex, int key)
{
    cout << CSI << MenuIndex+1 << ";1H";
    switch (key)
        {
        case DOWN_ARROW:
            if (MenuIndex < MenuItems-1)
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
            MenuIndex = MenuItems-1;
            cout << CSI << MenuItems << ";1H";
            cout << CSI << "2K";
            cout << CSI << "42m";
            cout << MenuList[MenuIndex];
            cout << CSI << "0m";
            break;
        default: break;
        }
}

void DisplayMenu(string MenuList[], int MenuItems, int MenuIndex)
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
    cout << CSI << MenuIndex+1 << ";1H";
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

bool ArrayIsFilled(bool ArrayFilled, int ActiveString)
{
    if (ArrayFilled) return true;
    else
    {
        cout << CSI << ActiveString << ";1H";
        cout << CSI << "2K";
        cout << "Массив не заполнен! Сначала выполните процедуру его заполнения!";
        return false;
    }
}

void FillRand(int Array[], int ArraySize, bool &ArrayFilled)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = random()%100;
    }
    ArrayFilled = true;
}

void Print(int Array[], int ArraySize, int &ActiveString)
{
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << "Текущий массив:";
    for (int i = 0; i < ArraySize; i++)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void ReversePrint(int Array[], int ArraySize, int &ActiveString)
{
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << "Текущий массив в обратном порядке:";
    for (int i = ArraySize-1; i >= 0; i--)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void Sum(int Array[], int ArraySize, int &ActiveString)
{
    int ArraySum = Array[0];
    
    for (int i = 1; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << "Сумма элементов массива: " << ArraySum << endl;
    ActiveString++;
}

void Avg(int Array[], int ArraySize, int &ActiveString)
{
    int ArraySum = Array[0];
        
    for (int i = 1; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << "Среднее арифметическое элементов массива: " << (double) ArraySum/ArraySize << endl;
    ActiveString++;
}

void minValueIn(int Array[], int ArraySize, int &ActiveString)
{
    int MinValue = Array[0];
        
    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] < MinValue) MinValue = Array[i];
    }
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << "Минимальное значение в массиве: " << MinValue << endl;
    ActiveString++;
}

void maxValueIn(int Array[], int ArraySize, int &ActiveString)
{
    int MaxValue = Array[0];
        
    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    cout << "Максимальное значение в массиве: " << MaxValue << endl;
    ActiveString++;
}

void shiftLeft(int Array[], int ArraySize, int &ActiveString)
{
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    int ShiftValue;
    cout << "Введите значение сдвига: ";
    cin >> ShiftValue;
    cin.ignore(INT32_MAX,'\n');
    ActiveString++;
    ShiftValue = ReducedShiftValue(ShiftValue, ArraySize);
    
    cout << "Массив, сдвинутый на " << ShiftValue << " влево :";
    for (int i = ArraySize - ShiftValue; i < 2 * ArraySize - ShiftValue; i++)
    {
        int ShiftIndex = i%ArraySize;
        cout << " " << Array[ShiftIndex];
    }
    cout << endl;
    ActiveString++;
}

void shiftRight(int Array[], int ArraySize, int &ActiveString)
{
    cout << CSI << ActiveString << ";1H";
    cout << CSI << "2K";
    int ShiftValue;
    cout << "Введите значение сдвига: ";
    cin >> ShiftValue;
    cin.ignore(INT32_MAX,'\n');
    ActiveString++;
    ShiftValue = ReducedShiftValue(ShiftValue, ArraySize);
    
    cout << "Массив, сдвинутый на " << ShiftValue << " вправо :";
    for (int i = ShiftValue; i < ArraySize+ShiftValue; i++)
    {
        int ShiftIndex = i%ArraySize;
        cout << " " << Array[ShiftIndex];
    }
    cout << endl;
    ActiveString++;
}

int ReducedShiftValue(int ShiftValue, int ArraySize)
{
    if (ShiftValue/ArraySize==0) return ShiftValue;
    else return ReducedShiftValue(ShiftValue%ArraySize, ArraySize);
}

void UniqueRand(int Array[], int ArraySize, bool &ArrayFilled)
{
    for (int i = 0; i < ArraySize; i++)
    {
        int ArrayValue = random()%100;
        while (ValueInArray(Array, ArrayValue, i))
        {
            ArrayValue = random()%100;
        }
        
        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
}

bool ValueInArray (int Array[], int ArrayValue, int ArrayIndex)
{
    bool ValueInArray = false;
    for (int i = 0; i < ArrayIndex; i++)
    {
        if (Array[i] == ArrayValue) ValueInArray = true; break;
    }
    return ValueInArray;
}
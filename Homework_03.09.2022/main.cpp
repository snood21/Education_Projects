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
void DisplayMenu(string MenuList[], const int MenuItems, int MenuIndex);
void NavigatingByMenu(string MenuList[], const int MenuItems, int &MenuIndex, int key);
void PrintString(string Text, int &ActiveString);
int GetKey();
bool ArrayIsFilled(const bool ArrayFilled, int &ActiveString);
void FillRand(int Array[], const int ArraySize, bool &ArrayFilled, int &ActiveString, int MinRand = 0, int MaxRand = 100);
void Print(int Array[], const int ArraySize, int &ActiveString);
void ReversePrint(int Array[], const int ArraySize, int &ActiveString);
int Sum(int Array[], const int ArraySize);
double Avg(int Array[], const int ArraySize);
int minValueIn(int Array[], const int ArraySize);
int maxValueIn(int Array[], const int ArraySize);
void shiftLeft(int Array[], const int ArraySize, int ShiftValue, int &ActiveString);
void shiftRight(int Array[], const int ArraySize, int ShiftValue, int &ActiveString);
void UniqueRand(int Array[], int const ArraySize, bool &ArrayFilled, int &ActiveString);
bool ValueInArray (int Array[], int ArrayValue, int ArrayIndex);
void Sort(int Array[], const int ArraySize, const bool SortByAscending, int &ActiveString);
void Search(int Array[], const int ArraySize, int &ActiveString);

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

    int ActiveString = MenuItems+2;

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
            case 0: FillRand(Array,ArraySize,ArrayFilled,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 1: if (ArrayIsFilled(ArrayFilled,ActiveString)) Print(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 2: if (ArrayIsFilled(ArrayFilled,ActiveString)) ReversePrint(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 3: if (ArrayIsFilled(ArrayFilled,ActiveString))
                    {
                        PrintString("Сумма элементов массива: ", ActiveString);
                        cout << Sum(Array,ArraySize) << endl;
                        ActiveString++;
                        NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                    }
                    break;
            case 4: if (ArrayIsFilled(ArrayFilled,ActiveString))
                    {
                        PrintString("Среднее арифметическое элементов массива: ", ActiveString);
                        cout << Avg(Array,ArraySize) << endl;
                        ActiveString++;
                        NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                    }
                    break;
            case 5: if (ArrayIsFilled(ArrayFilled,ActiveString))
                    {
                        PrintString("Минимальное значение в массиве: ", ActiveString);
                        cout << minValueIn(Array,ArraySize) << endl;
                        ActiveString++;
                        NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                    }
                    break;
            case 6: if (ArrayIsFilled(ArrayFilled,ActiveString))
                    {
                        PrintString("Максимальное значение в массиве: ", ActiveString);
                        cout << maxValueIn(Array,ArraySize) << endl;
                        ActiveString++;
                        NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                    }
                    break;
            case 7: if (ArrayIsFilled(ArrayFilled,ActiveString))
                    {
                        PrintString("Введите значение сдвига: ", ActiveString);
                        int ShiftValue;
                        cin >> ShiftValue;
                        cin.ignore(INT32_MAX,'\n');
                        ActiveString++;
                        ShiftValue %= ArraySize;
                        shiftLeft(Array,ArraySize,ShiftValue,ActiveString);
                        NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                    }
                    break;
            case 8: if (ArrayIsFilled(ArrayFilled,ActiveString))
                    {
                        PrintString("Введите значение сдвига: ", ActiveString);
                        int ShiftValue;
                        cin >> ShiftValue;
                        cin.ignore(INT32_MAX,'\n');
                        ActiveString++;
                        ShiftValue %= ArraySize;
                        shiftRight(Array,ArraySize,ShiftValue,ActiveString);
                        NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
                    }
                    break;
            case 9: UniqueRand(Array,ArraySize,ArrayFilled,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 10: if (ArrayIsFilled(ArrayFilled,ActiveString)) Sort(Array,ArraySize,true,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 11: if (ArrayIsFilled(ArrayFilled,ActiveString)) Sort(Array,ArraySize,false,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 12: FillRand(Array,ArraySize,ArrayFilled,ActiveString,0,ArraySize-1); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 13: if (ArrayIsFilled(ArrayFilled,ActiveString)) Search(Array,ArraySize,ActiveString); NavigatingByMenu(MenuList, MenuItems, MenuIndex, key); break;
            case 14: quit = true; delete [] Array; break;
            default: break;
            }
        }
        else NavigatingByMenu(MenuList, MenuItems, MenuIndex, key);
    }
}

void NavigatingByMenu(string MenuList[], const int MenuItems, int &MenuIndex, int key)
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
    cout << CSI << MenuIndex+1 << ";1H";
}

void PrintString(string Text, int &ActiveString)
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

bool ArrayIsFilled(const bool ArrayFilled, int &ActiveString)
{
    if (ArrayFilled) return true;
    else
    {
        PrintString("Массив не заполнен! Сначала выполните процедуру его заполнения!", ActiveString);
        return false;
    }
}

void FillRand(int Array[], const int ArraySize, bool &ArrayFilled, int &ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        Array[i] = random()%(MaxRand-MinRand)+MinRand;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

void Print(int Array[], const int ArraySize, int &ActiveString)
{
    PrintString("Текущий массив:", ActiveString);
    for (int i = 0; i < ArraySize; i++)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
}

void ReversePrint(int Array[], const int ArraySize, int &ActiveString)
{
    PrintString("Текущий массив в обратном порядке:", ActiveString);
    for (int i = ArraySize-1; i >= 0; i--)
    {
        cout << " " << Array[i];
    }
    cout << endl;
    ActiveString++;
}

int Sum(int Array[], const int ArraySize)
{
    int ArraySum = Array[0];
    
    for (int i = 1; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    return ArraySum;
}

double Avg(int Array[], const int ArraySize)
{
    int ArraySum = Sum(Array, ArraySize);
        
    return (double) ArraySum/ArraySize;
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

int maxValueIn(int Array[], const int ArraySize)
{
    int MaxValue = Array[0];
        
    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    return MaxValue;
}

void shiftLeft(int Array[], const int ArraySize, int ShiftValue, int &ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        int CurrentValue = Array[0];
        for (int j = 0; j < ArraySize; j++)
        {
            Array[j] = Array[j+1];
        }
        Array[ArraySize-1] = CurrentValue;
    }
    PrintString("Выполнено!", ActiveString);
}

void shiftRight(int Array[], const int ArraySize, int ShiftValue, int &ActiveString)
{
    shiftLeft(Array, ArraySize, ArraySize-ShiftValue, ActiveString);
}

void UniqueRand(int Array[], const int ArraySize, bool &ArrayFilled, int &ActiveString)
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
    PrintString("Выполнено!", ActiveString);
}

bool ValueInArray (int Array[], int ArrayValue, int ArrayIndex)
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

void Sort(int Array[], const int ArraySize, const bool SortByAscending, int &ActiveString)
{
    for (int i = 0; i < ArraySize; i++)
    {
        for (int j = i+1; j < ArraySize; j++)
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

void Search(int Array[], const int ArraySize, int &ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    int ArrayOfDoubles[ArraySize];
    int TotalDoubles = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        int CountOfDouble = 1;
        for (int j = i+1; j < ArraySize; j++)
        {
            if ((Array[i] == Array[j])&&!(Array[j]==ArrayOfDoubles[j]))
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
    if (TotalDoubles==0) cout << "отсутствуют";
    
    cout << endl;
    ActiveString++;
}
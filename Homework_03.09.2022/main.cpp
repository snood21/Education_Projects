#include "stdafx.h"
#include "constants.h"
#include "Service.h"
#include "FillRand.h"
#include "WorkingWithMenu.h"

enum ArrayTypes { Char = 0, Int, Float, Double };

void ArrayTypeSelectionMenu();

template <typename T> void Print(T Array[], const int ArraySize, int& ActiveString);
template <typename T> void Print(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
template <typename T> void ReversePrint(T Array[], const int ArraySize, int& ActiveString);
template <typename T> void ReversePrint(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);
template <typename T> T Sum(T Array[], const int ArraySize);
template <typename T> T Sum(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> double Avg(T Array[], const int ArraySize);
template <typename T> double Avg(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> T minValueIn(T Array[], const int ArraySize);
template <typename T> T minValueIn(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> T maxValueIn(T Array[], const int ArraySize);
template <typename T> T maxValueIn(T** Array, const int ArrayColumns, const int ArrayStrings);
template <typename T> void shiftLeft(T Array[], const int ArraySize, int ShiftValue, int& ActiveString);
template <typename T> void shiftLeft(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
template <typename T> void shiftRight(T Array[], const int ArraySize, int ShiftValue, int& ActiveString);
template <typename T> void shiftRight(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString);
template <typename T> void Sort(T Array[], const int ArraySize, const bool SortByAscending, int& ActiveString);
template <typename T> void Sort(T**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString);
template <typename T> void Search(T Array[], const int ArraySize, int& ActiveString);
template <typename T> void Search(T**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString);

//Char
void menu(char ArrayType, const int ArraySize);
void menu(char ArrayType, const int ArrayColumns, const int ArrayStrings);
template <typename T>
void UniqueRand(T Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
template <typename T>
void UniqueRand(T**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
template <typename T>
bool ValueInArray(T Array[], const T ArrayValue, const int ArrayIndex);
template <typename T>
bool ValueInArray(T** Array, const T ArrayValue, const int IndexString, const int IndexColumn);

//Int
void menu(int ArrayType, const int ArraySize);
void menu(int ArrayType, const int ArrayColumns, const int ArrayStrings);

//Float
void menu(float ArrayType, const int ArraySize);
void menu(float ArrayType, const int ArrayColumns, const int ArrayStrings);
void UniqueRand(float Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void UniqueRand(float**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);

//Double
void menu(double ArrayType, const int ArraySize);
void menu(double ArrayType, const int ArrayColumns, const int ArrayStrings);
void UniqueRand(double Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void UniqueRand(double**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);

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
template<typename T>
void Print(T Array[], const int ArraySize, int& ActiveString)
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

template <typename T>
void Print(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
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

template <typename T>
void ReversePrint(T Array[], const int ArraySize, int& ActiveString)
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

template <typename T>
void ReversePrint(T** Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
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

template <typename T>
T Sum(T Array[], const int ArraySize)
{
    T ArraySum = 0;

    for (int i = 0; i < ArraySize; i++)
    {
        ArraySum += Array[i];
    }
    return ArraySum;
}

template <typename T>
T Sum(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T ArraySum = 0;

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            ArraySum += Array[i][j];
        }
    }
    return ArraySum;
}

template <typename T>
double Avg(T Array[], const int ArraySize)
{
    T ArraySum = Sum(Array, ArraySize);

    return (double)ArraySum / ArraySize;
}

template <typename T>
double Avg(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T ArraySum = Sum(Array, ArrayColumns, ArrayStrings);

    return (double)ArraySum / (ArrayColumns + ArrayStrings);
}

template <typename T>
T minValueIn(T Array[], const int ArraySize)
{
    T MinValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] < MinValue) MinValue = Array[i];
    }
    return MinValue;
}

template <typename T>
T minValueIn(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T MinValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] < MinValue) MinValue = Array[i][j];
        }
    }
    return MinValue;
}

template <typename T>
T maxValueIn(T Array[], const int ArraySize)
{
    T MaxValue = Array[0];

    for (int i = 1; i < ArraySize; i++)
    {
        if (Array[i] > MaxValue) MaxValue = Array[i];
    }
    return MaxValue;
}

template <typename T>
T maxValueIn(T** Array, const int ArrayColumns, const int ArrayStrings)
{
    T MaxValue = Array[0][0];

    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            if (Array[i][j] > MaxValue) MaxValue = Array[i][j];
        }
    }
    return MaxValue;
}

template <typename T>
void shiftLeft(T Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        T CurrentValue = Array[0];
        for (int j = 0; j < ArraySize; j++)
        {
            Array[j] = Array[j + 1];
        }
        Array[ArraySize - 1] = CurrentValue;
    }
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void shiftLeft(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    for (int i = 0; i < ShiftValue; i++)
    {
        T FirstValue = Array[0][0];
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

template <typename T>
void shiftRight(T Array[], const int ArraySize, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArraySize, ArraySize - ShiftValue, ActiveString);
}

template <typename T>
void shiftRight(T**& Array, const int ArrayColumns, const int ArrayStrings, int ShiftValue, int& ActiveString)
{
    shiftLeft(Array, ArrayColumns, ArrayStrings, ArrayColumns + ArrayStrings - ShiftValue, ActiveString);
}

template <typename T>
void UniqueRand(T Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArraySize; i++)
    {
        T ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
        while (ValueInArray(Array, ArrayValue, i))
        {
            ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
        }

        Array[i] = ArrayValue;
    }
    ArrayFilled = true;
    PrintString("Выполнено!", ActiveString);
}

template <typename T>
void UniqueRand(T**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand, int MaxRand)
{
    for (int i = 0; i < ArrayStrings; i++)
    {
        for (int j = 0; j < ArrayColumns; j++)
        {
            T ArrayValue = rand() % (MaxRand - MinRand) + MinRand;
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

template <typename T>
bool ValueInArray(T Array[], const T ArrayValue, const int ArrayIndex)
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

template <typename T>
bool ValueInArray(T** Array, const T ArrayValue, const int IndexString, const int IndexColumn)
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

template <typename T>
void Sort(T Array[], const int ArraySize, const bool SortByAscending, int& ActiveString)
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

template <typename T>
void Sort(T**& Array, const int ArrayColumns, const int ArrayStrings, const bool SortByAscending, int& ActiveString)
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

template <typename T>
void Search(T Array[], const int ArraySize, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //T ArrayOfDoubles[ArraySize];
    T* ArrayOfDoubles = new T[ArraySize];
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

template <typename T>
void Search(T**& Array, const int ArrayColumns, const int ArrayStrings, int& ActiveString)
{
    PrintString("Дубли в массиве: ", ActiveString);
    //T ArrayOfDoubles[ArrayStrings][ArrayColumns];
    T** ArrayOfDoubles = new T* [ArrayStrings];
    for (int i = 0; i < ArrayStrings; i++)
    {
        ArrayOfDoubles[i] = new T[ArrayColumns];
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

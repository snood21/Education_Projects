#include "stdafx.h"
#include "constants.h"
#include "Service.h"
#include "WorkingWithMenu.h"
#include "TemplatedFunctions.h"
#include "NonTemplatedFunctions.h"

enum ArrayTypes { Char = 0, Int, Float, Double };

void ArrayTypeSelectionMenu();

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

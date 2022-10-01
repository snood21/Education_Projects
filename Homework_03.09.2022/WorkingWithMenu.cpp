#include "WorkingWithMenu.h"

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

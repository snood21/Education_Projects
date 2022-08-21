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
void main_menu(string menu_list[],int menu_items,int menu_index);
int get_key();
void array_arithmetic();

int main()
{
    setlocale(LC_ALL, "Rus");
    menu();
    return 0;
}

void menu()
{
    cout << CSI << "?25l";
    cout << CSI << "?12l";

    const int menu_items = 5;
    string menu_list[menu_items];
    menu_list[0] = "Массив арифметика";
    menu_list[1] = "Циклический сдвиг массива";
    menu_list[2] = "Перевод в двоичную систему";
    menu_list[3] = "Перевод в шестнадцатеричную систему";
    menu_list[4] = "Выход";

    int menu_index = 0;
    main_menu(menu_list,menu_items,menu_index);
    bool quit = false;

    while (!quit)
    {
        int key = get_key();
        switch (key)
        {
        case ENTER:
            switch (menu_index)
            {
            case 0: array_arithmetic(); main_menu(menu_list,menu_items,menu_index); break;
            /*case 1: triangle1(); main_menu(menu_list,menu_items,menu_index); break;
            case 2: triangle2(); main_menu(menu_list,menu_items,menu_index); break;
            case 3: triangle3(); main_menu(menu_list,menu_items,menu_index); break;*/
            case 4: quit = true; break;
            default: break;
            }
            break;
        case DOWN_ARROW:
            if (menu_index < menu_items-1)
            {
                cout << CSI << "1G";
                cout << CSI << "2K";
                cout << CSI << "0m";
                cout << menu_list[menu_index];
                menu_index++;
                cout << CSI << "1E";
                cout << CSI << "2K";
                cout << CSI << "42m";
                cout << menu_list[menu_index];
                cout << CSI << "0m";
                break;
            }
        case UP_ARROW:
            if (menu_index > 0)
            {
                cout << CSI << "1G";
                cout << CSI << "2K";
                cout << CSI << "0m";
                cout << menu_list[menu_index];
                menu_index--;
                cout << CSI << "1F";
                cout << CSI << "2K";
                cout << CSI << "42m";
                cout << menu_list[menu_index];
                cout << CSI << "0m";
                break;
            }
        case HOME:
            cout << CSI << "1G";
            cout << CSI << "2K";
            cout << CSI << "0m";
            cout << menu_list[menu_index];
            menu_index = 0;
            cout << CSI << "1;1H";
            cout << CSI << "2K";
            cout << CSI << "42m";
            cout << menu_list[menu_index];
            cout << CSI << "0m";
            break;
        case END:
            cout << CSI << "1G";
            cout << CSI << "2K";
            cout << CSI << "0m";
            cout << menu_list[menu_index];
            menu_index = menu_items-1;
            cout << CSI << menu_items << ";1H";
            cout << CSI << "2K";
            cout << CSI << "42m";
            cout << menu_list[menu_index];
            cout << CSI << "0m";
            break;
        default: break;
        }
    }
}

void main_menu(string menu_list[],int menu_items,int menu_index)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";
    for (int i = 0; i < menu_items; i++)
    {
        if (i == menu_index)
        {
            cout << CSI << "42m";
            cout << menu_list[i] << endl;
            cout << CSI << "0m";
        }
        else
        {
            cout << menu_list[i] << endl;
        }
    }
    cout << CSI << menu_index+1 << ";1H";
}

int get_key()
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

void array_arithmetic()
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    const int array_size = 5;
    double array[array_size] = {3,5,8,13,21};
    /*cout "Введите массив из пяти элементов:";

    for (int i = 0; i < array_size; i++)
    {
        cin >> array[i];
    }*/
    
    cout << "Введенный массив: " << array[0] << " ";

    double sum = array[0];
    double min = array[0];
    double max = array[0];


    for (int i = 1; i < array_size; i++)
    {
        cout << array[i] << " ";
        sum += array[i];
        max = array[i]>max ? array[i] : max;
        min = array[i]<min ? array[i] : min;
    }
    cout << endl;
    
    cout << "Введенный массив в обратном порядке: ";
    for (int i = array_size-1; i >= 0; i--)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Сумма элементов массива: " << sum << endl;
    cout << "Среднее арифметическое элементов массива: " << sum/array_size << endl;
    cout << "Максимальный элемент массива: " << max << endl;
    cout << "минимальный элемент массива: " << min << endl;   

    cout << CSI << "42m";
    cout << "Назад";
    cout << CSI << "0m";
    while (get_key() != ENTER);
}
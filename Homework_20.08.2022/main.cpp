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
void display_menu(string menu_list[],int menu_items,int menu_index);
void navigating_by_menu(string menu_list[], int menu_items, int &menu_index, int key);
int get_key();
void array_arithmetic();
void cyclic_shift();
void shift_array(bool shift_to_right);
int reduced_shift_value(int shift_value, int array_size);
void decimal_to_binary();
void decimal_to_hexadecimal();

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
    display_menu(menu_list,menu_items,menu_index);
    bool quit = false;

    while (!quit)
    {
        int key = get_key();

        if (key == ENTER)
        {
            switch (menu_index)
            {
            case 0: array_arithmetic(); display_menu(menu_list,menu_items,menu_index); break;
            case 1: cyclic_shift(); display_menu(menu_list,menu_items,menu_index); break;
            case 2: decimal_to_binary(); display_menu(menu_list,menu_items,menu_index); break;
            case 3: decimal_to_hexadecimal(); display_menu(menu_list,menu_items,menu_index); break;
            case 4: quit = true; break;
            default: break;
            }
        }
        else navigating_by_menu(menu_list, menu_items, menu_index, key);
    }
}

void navigating_by_menu(string menu_list[], int menu_items, int &menu_index, int key)
{
    switch (key)
        {
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

void display_menu(string menu_list[], int menu_items, int menu_index)
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
    double array[array_size] = {};
    cout << "Введите массив из пяти элементов: ";

    for (int i = 0; i < array_size; i++)
    {
        cin >> array[i];
    }
    cin.ignore(INT32_MAX,'\n');
    
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

void cyclic_shift()
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    const int sub_menu_items = 3;
    string sub_menu_list[sub_menu_items];
    sub_menu_list[0] = "Циклически сдвинуть массив вправо";
    sub_menu_list[1] = "Циклически сдвинуть массив влево";
    sub_menu_list[2] = "Назад";

    int sub_menu_index = 0;

    display_menu(sub_menu_list, sub_menu_items, sub_menu_index);
    bool back = false;

    while (!back)
    {
        int key = get_key();

        if (key == ENTER)
        {
            switch (sub_menu_index)
            {
            case 0: shift_array(true); display_menu(sub_menu_list, sub_menu_items, sub_menu_index); break;
            case 1: shift_array(false); display_menu(sub_menu_list, sub_menu_items, sub_menu_index); break;
            case 2: back = true; break;
            default: break;
            }
        }
        else navigating_by_menu(sub_menu_list, sub_menu_items, sub_menu_index, key);
    }
}

void shift_array(bool shift_to_right)
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    const int array_size = 10;
    int current_array[array_size] = {1,2,3,4,5,6,7,8,9,10};
    int shift_array[array_size];
    int shift_value;

    cout << "Введите значение сдвига: ";
    cin >> shift_value;
    cin.ignore(INT32_MAX,'\n');

    shift_value = reduced_shift_value(shift_value, array_size);

    for (int i = 0; i < array_size; i++)
    {
        int shift_index = (shift_to_right ? (i+shift_value) : (i + array_size - shift_value))%array_size;
        shift_array[shift_index] = current_array[i];
    }

    cout << "Начальный массив: ";
    
    for (int i = 0; i < array_size; i++)
    {
        cout << current_array[i] << " ";
    }
    
    cout << endl;

    cout << "Массив после сдвига: ";
    
    for (int i = 0; i < array_size; i++)
    {
        cout << shift_array[i] << " ";
    }
    
    cout << endl;

    cout << CSI << "42m";
    cout << "Назад";
    cout << CSI << "0m";
    while (get_key() != ENTER);
}

int reduced_shift_value(int shift_value, int array_size)
{
    if (shift_value/array_size==0) return shift_value;
    else return reduced_shift_value(shift_value%array_size, array_size);
}

void decimal_to_binary()
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    unsigned short decimal;
    cout << "Введите целое неотрицательное десятичное число: ";
    cin >> decimal;
    cin.ignore(INT32_MAX,'\n');

    const unsigned short array_size = 16;
    unsigned short binary_array[array_size] = {};

    for (unsigned short i = 0; i < array_size; i++)
    {
        binary_array[i] = decimal % 2;
        if (decimal/2==0) break;
        else decimal /= 2;       
    }

    cout << "Двоичное представление введенного числа: ";
    
    for (short i = array_size-1; i >= 0; i--)
    {
        cout << binary_array[i];
        if (i == 8) cout << " ";
    }
    
    cout << endl;

    cout << CSI << "42m";
    cout << "Назад";
    cout << CSI << "0m";
    while (get_key() != ENTER);
}

void decimal_to_hexadecimal()
{
    cout << CSI << "1;1H";
    cout << CSI << "2J";

    unsigned long decimal;
    cout << "Введите целое неотрицательное десятичное число: ";
    cin >> decimal;
    cin.ignore(INT32_MAX,'\n');

    const unsigned short array_size = 8;
    char hexadecimal_array[array_size] = {};

    for (unsigned short i = 0; i < array_size; i++)
    {
        int hexadecimal_digit = decimal % 16;
        char hexadecimal_digit_representation;
        switch (hexadecimal_digit)
        {
        case 0: hexadecimal_digit_representation = '0'; break;
        case 1: hexadecimal_digit_representation = '1'; break;
        case 2: hexadecimal_digit_representation = '2'; break;
        case 3: hexadecimal_digit_representation = '3'; break;
        case 4: hexadecimal_digit_representation = '4'; break;
        case 5: hexadecimal_digit_representation = '5'; break;
        case 6: hexadecimal_digit_representation = '6'; break;
        case 7: hexadecimal_digit_representation = '7'; break;
        case 8: hexadecimal_digit_representation = '8'; break;
        case 9: hexadecimal_digit_representation = '9'; break;
        case 10: hexadecimal_digit_representation = 'A'; break;
        case 11: hexadecimal_digit_representation = 'B'; break;
        case 12: hexadecimal_digit_representation = 'C'; break;
        case 13: hexadecimal_digit_representation = 'D'; break;
        case 14: hexadecimal_digit_representation = 'E'; break;
        case 15: hexadecimal_digit_representation = 'F'; break;
        default: break;
        }
        hexadecimal_array[i] = hexadecimal_digit_representation;
        if (decimal/16==0) break;
        else decimal /= 16;
    }

    cout << "Шестнадцатеричное представление введенного числа: ";
    
    for (short i = array_size-1; i >= 0; i--)
    {
        cout << hexadecimal_array[i];
    }
    
    cout << endl;

    cout << CSI << "42m";
    cout << "Назад";
    cout << CSI << "0m";
    while (get_key() != ENTER);
}
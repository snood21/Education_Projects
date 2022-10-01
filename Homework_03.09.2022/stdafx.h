#pragma once

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

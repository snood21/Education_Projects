#include "NonTemplatedFunctions.h"

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


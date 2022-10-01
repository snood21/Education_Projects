#pragma once

#include "stdafx.h"
#include "Service.h"
//Char
void FillRand(char Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(char**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
//Int
void FillRand(int Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(int**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
//Float
void FillRand(float Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(float**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
//Double
void FillRand(double Array[], const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(double**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);

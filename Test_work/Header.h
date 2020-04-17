#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define DATA "data.txt"

#define ENTER 13
#define ESC 27
#define SHIFT_A 65
#define SHIFT_D 68
#define SHIFT_I 73
//#define SHIFT_F 70
#define SHIFT_S 83
#define SHIFT_Q 81



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>


struct human {
	char name[20];
	char surname[20];
	char faculty[50];
	unsigned course;
	unsigned age;
};

struct human* students{};
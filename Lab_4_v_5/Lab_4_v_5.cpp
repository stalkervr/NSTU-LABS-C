#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Лабораторная работа №4 вариант №5\n\n");

    char searchPattern[4][4] = { "=","==","a+=","a-=" };
    char changePattern[4][4] = {};

    for (int i = 0; i < 3; i++)
    {
        printf("%c", searchPattern[2][i]);

    }


    return 0;
}



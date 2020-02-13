// Practice_10-02-2020.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <locale.h>
#include <string.h>

char digits[] = "0123456789ABCDEF";

int digitValue(char c);
int fromString(char str[], int rad);

void reverse(char str[]);
void toString(char str[], int num, int rad);

void toStringR(char str[], int num, int rad, int* pos);
void toStringRWrapper(char str[], int num, int rad);

int main()
{
    char s[10] = "";
    //printf("%d",fromString("F",16));
    toString(s, 13, 2); //Перевод в другую систему счисления
    printf("test 1 => %s\n", s);
    toStringRWrapper(s, 13, 2); //Перевод в другую систему счисления с рекурсией
    printf("test 2 => %s\n", s);

    return 0;
}

int digitValue(char c)
{
    int i;
    for (i = 0; digits[i] != '\0'; i++)
    {
        if (digits[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int fromString(char str[], int rad)
{
    int i, s;

    for (i = 0, s = 0; str[i] != '\0'; i++)
    {
        s *= rad;
        s += digitValue(str[i]);
    }
    return s;
}

#pragma region Перевод числа из десятичной в другую систему счисления
// переворот строки reverse
void reverse(char str[])
{
    int i, j;
    char tmp;
    for (j = 0; str[j] != '\0'; j++);
    j--;

    for (i = 0; i < j; i++, j--)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
// преобразование
void toString(char str[], int num, int rad)
{
    int i;
    if (num == 0)
    {
        str[0] = '0';
        str[1] = '\0';
    }
    else
    {
        for (i = 0; num != 0; num /= rad)
        {
            str[i++] = digits[num % rad];
        }
        str[i] = '\0';
    }
    reverse(str);
}

#pragma endregion

#pragma region Перевод числа из десятичной в другую систему счисления с использованием рекурсии переворот делать не нужно.

void toStringR(char str[], int num, int rad, int* pos)
{
    int digit;
    int pp;
    if (num == 0)
    {
        *pos = 0;
        return;
    }
    digit = num % rad;
    toStringR(str, num / rad, rad, &pp);
    str[pp] = digits[digit];
    *pos = pp + 1;
}

void toStringRWrapper(char str[], int num, int rad)
{
    int pos;
    if (num == 0)
    {
        str[0] = '0';
        str[1] = '\0';
    }
    else
    {
        toStringR(str, num, rad, &pos);
        str[pos] = '\0';
    }
}

#pragma endregion


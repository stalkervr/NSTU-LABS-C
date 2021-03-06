﻿// Practice_24-01-2020.cpp
//

#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
#include <locale.h>

int digitSearch(char[], int pos);
int digitCount(char S[], int pos);
int myAtoi(char S[], int pos);
int searchPatern(char S[], int pos);
int F(int a);

int main()
{
    setlocale(LC_ALL, "Russian");
    char str[] = "sdf237fdg15rhesth54gfdh67";
    //char str1[] = "dd==fgd=f";

    //F(123456);

    int pos = 0;
    int dcount;
    int res;
   // TODO: Переписать с do while
    while (pos != -1)
    {
        pos = digitSearch(str, pos);
        dcount = digitCount(str, pos);
        res = myAtoi(str, pos);

        printf("Индекс первой цифры найденного числа => %d\n", pos);
        printf("Количество цифр в найденном числе    => %d\n", dcount);
        printf("Найдено число                        => %d\n\n", res);

        pos += dcount;
        pos = digitSearch(str, pos);
    }

    //int pos = 0;
    //pos = searchPatern(str1, pos);
    //printf("%s", str1);
    //printf("Индекс найденного совпадения => %d\n", pos);
    //printf("%s", str1);



    return 0;
}

int digitSearch(char S[], int pos)
{
    int i;
    for ( i = pos; S[i] != '\0'; i++)
    {
        if (S[i] >= '0' && S[i] <= '9') 
        {
            return i;
        }
    }
    return -1;
}

int digitCount(char S[], int pos) 
{
    int count = 0;
    int i;
    for (i = pos; S[i] != '\0'; i++) 
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int myAtoi(char S[], int pos)
{
    int i;
    int sum = 0;
    int digit;
    for (i = pos; S[i] != '\0' && (S[i] >= '0' && S[i] <= '9'); i++)
    {
            sum *= 10;
            digit = S[i] - '0';
            sum += digit;
    }
    return sum;
}

int searchPatern(char S[], int pos)
{
    int i;
    for (i = pos; S[i] != '\0'; i++)
    {
        if (S[i] == '=' && S[i + 1] == '=')
        {
            S[i] = '*';
            S[i + 1] = '*';
            return i;
        }
    }
    return -1;
}

//int F(int a)
//{
//    int n, s,  k;
//    for (n = a, s = 0; n != 0; n = n / 10)
//    {
//        k = n % 10;
//        s = s * 10 + k;
//        printf("k => %d  s => %d \n", k, s);
//    }
//    return 0;
//}

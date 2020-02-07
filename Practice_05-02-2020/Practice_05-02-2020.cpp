// Practice_05-02-2020.cpp : 
//
#define N 20
#include <iostream>
#include <stdio.h>
#include <locale.h>

int searchDigit(char S[], int pos);
int convert(char S[], int pos);
//int numLen(int num);
int numLen(char S[], int pos);
//int toNumber(char S[], int p);
int toNumber(char S[], int n);

void toString(int num, char S[]);
int numLen2(int num);
int sym2digit(char c);

int main()
{
    char str[N] = "a38as676fg";
    printf("%d", toNumber(str, 1));

    return 0;
}

int searchDigit(char S[], int pos)
{
    int i;

    for (i = pos; S[i] != '\0'; i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            return i;
        }
    }
    return -1;
}

int convert(char S[], int pos)
{
    int i;
    int sum = 0;

    for (i = pos; S[i] >= '0' && S[i] <= '9'; i++)
    {
        sum *= 10;
        sum += S[i] - '0';
    }
    return sum;
}
/*
int toNumber(char S[], int p)
{
    int num=0;
    int pos;
    pos=searchDigit(S,p);

    if(pos>=0)
    {
        num=convert(S,pos);
    }

    return num;
}
*/
/*
int numLen(int num)
{
    int cnt;

    for(cnt=1;num/10>0;cnt++,num/=10);

    return cnt;
}
*/
int numLen(char S[], int pos)
{
    int i;
    int cnt;
    for (i = pos, cnt = 0; S[i] >= '0' && S[i] <= '9'; i++, cnt++);

    return cnt;
}

int toNumber(char S[], int n)
{
    int i;
    int pos = 0, pos_start = 0;
    int len;
    int num;

    for (i = 0; i < n; i++)
    {
        pos = searchDigit(S, pos_start);
        if (pos >= 0)
        {
            len = numLen(S, pos);
            pos_start = pos + len;
        }
        else
        {
            return 0;
        }
    }
    num = convert(S, pos);
    return num;
}

void toString(int num, char S[])
{
    int len;
    if (num == 0)
    {
        S[0] = '0';
        S[1] = '\0';
    }
    else
    {
        len = numLen2(num);
        S[len--] = '\0';
        for (; num > 0; num /= 10)
        {
            S[len--] = num % 10 + '0';
        }
    }
}

int numLen2(int num)
{
    int cnt;

    for (cnt = 1; num / 10 > 0; cnt++, num /= 10);

    return cnt;
}

int sym2digit(char c)
{
    int i;
    int digits[N] = {};
    for (i = 0; digits[i] != '\0'; i++)
    {
        if (digits[i] == c)
        {
            return i;
        }
    }
    return -1;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>

void replaceWrapper(char str[], char str1[], char str2[]);

int lengthString(char string[]);
void leftShift(char A[], int pos, int num);
void rightShift(char A[], int pos, int num);
int substringSearch(char A[], char B[], int pos);
void substringInsertion(char A[], char B[], int pos);

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Лабораторная работа №4 вариант №5\n\n");

	char searchPattern[5][5] = { "=","==","!=","a+=","a-=" };
	char changePattern[5][5] = { ":=","=","#","a=a+","a=a-" };
	char str[300] = "dfg*=*gsg*==*grg**klfgj";
	//char str1[] = "==";
	//char str2[] = "*";
	//int pos = 0;
	printf("Строка до замены => %s\n\n", str);

	//rightShift(str, 4, 1);
	replaceWrapper(str, "==", "=");

	printf("Строка после замены => %s\n", str);

    return 0;
}

void replaceWrapper(char str[], char str1[], char str2[])
{
	int pos = 0;
	int shiftPoint;
	int deltaShift = lengthString(str1) - lengthString(str2);
	while (pos != -1)
	{
		pos = substringSearch(str, str1, pos);

		shiftPoint = pos + lengthString(str1);

		if (deltaShift < 0)
		{
			rightShift(str, shiftPoint , deltaShift*(-1));
		}
		if (deltaShift > 0)
		{
			leftShift(str, shiftPoint - deltaShift, deltaShift);
		}

		substringInsertion(str, str2, pos);

		pos += lengthString(str1) + abs(deltaShift);
		pos = substringSearch(str, str1, pos);
	}
}

int lengthString(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

void leftShift(char A[], int pos, int num)
{
	int i;
	for (i = pos + num; A[i] != '\0'; i++)
	{
		A[pos++] = A[i];
	}
	A[pos] = '\0';
}

void rightShift(char A[], int pos, int num)
{
	int i;
	int length;
	length = lengthString(A);

	for (i = length; i >= pos; i--)
	{
		A[i + num] = A[i];
	}
	//A[pos] = ' ';
}

int substringSearch(char A[], char B[], int pos)
{
	int i, j;
	int lengthA, lengthB;
	lengthA = lengthString(A);
	lengthB = lengthString(B);
	// проверка если длинна искомой строки больше строки для поиска её там точно нет
	if (lengthB > lengthA)
	{
		return -1;
	}

	for (i = pos; i <= lengthA - lengthB; i++)
	{
		for (j = 0; j < lengthB; j++)
		{
			if (A[i + j] != B[j])// переход к следующему символу строки В(на след итерацию(j++) только если условие ложно 
			{
				break;
			}
		}
		if (j == lengthB)
		{
			return i;
		}
	}
	return -1;
}

void substringInsertion(char A[], char B[], int pos)
{
	int i;
	for (i = 0; B[i] != '\0'; i++)
	{
		A[pos + i] = B[i];
	}
}


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

void replaceShort(char str[], char str1[], char str2[]);

int searchShort(char A[], char B[], int pos);

void replaceWrapper(char str[], char str1[], char str2[]);

int abs(int number);

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
	char str[300] = "(=, ==, !=, a+=, a-=, =)";

	printf("Строка до замены => %s\n\n", str);

	replaceShort(str, "=", ":=");
	replaceWrapper(str, "==", "=");
	replaceWrapper(str, "!=", "#");
	replaceWrapper(str, "a+=", "a=a+");
	replaceWrapper(str, "a-=", "a=a-");
	//printf("Найден символ = его индекс -> %d", searchShort(str,"=",0));

	printf("Строка после замены => %s\n", str);

    return 0;
}

int abs(int number)
{
	return number < 1 ? number * (-1) : number;
}

int searchShort(char A[], char B[], int pos)
{
	int i, j;
	int lengthA, lengthB;
	lengthA = lengthString(A);
	lengthB = lengthString(B);
	// поиск построки "="

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
			if ( A[i] == '=' &&
				 A[i-1] != '=' && 
				 A[i+1] != '=' && 
				 A[i-1] != '!' && 
				 A[i-1] != '+' &&
				 A[i-1] != '-' &&
				 A[i-1] != 'a')
			{
				return i;
			}
		}
	}
	
	return -1;
}

void replaceShort(char str[], char str1[], char str2[])
{
	int pos = 0;
	int shiftPoint;
	int deltaShift = lengthString(str1) - lengthString(str2);

	while (pos != -1)
	{
		pos = searchShort(str, str1, pos);

		shiftPoint = pos + lengthString(str1);

		if (deltaShift < 0)
		{
			rightShift(str, shiftPoint, abs(deltaShift));
		}
		if (deltaShift > 0)
		{
			leftShift(str, shiftPoint - deltaShift, deltaShift);
		}

		substringInsertion(str, str2, pos);

		pos += lengthString(str1) + abs(deltaShift);
		pos = searchShort(str, str1, pos);
	}
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
			rightShift(str, shiftPoint , abs(deltaShift));
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
}

int substringSearch(char A[], char B[], int pos)
{
	int i, j;
	int lengthA, lengthB;
	lengthA = lengthString(A);
	lengthB = lengthString(B);
	// поиск построки "="

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


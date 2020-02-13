#define _CRT_SECURE_NO_WARNINGS

# define N 5
# define M 5

#include <stdio.h>
#include <locale.h>

int lengthString(char string[]);
void leftShift(char string[], int pos, int num);
void rightShift(char string[], int pos, int num);
void substringInsertion(char string[], char subString[], int pos);
int searchShortString(char string[], char subString[], int pos);
int substringSearch(char string[], char subString[], int pos);
void replaceWrapper(char string[], char subString1[], char subString2[]);
int abs(int number);

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("  Лабораторная работа №4 вариант №5\n\n");

	char searchPattern[N][M] = { "=", "==", "!=", "a+=", "a-=" };
	char changePattern[N][M] = { ":=", "=", "#", "a=a+", "a=a-" };
	char str[100] = "(=, ==, !=, a+=, a-=)";

	printf("  Строка до замены    => %s\n\n", str);

	for (int i = 0; i < N; i++)
	{
		replaceWrapper(str, searchPattern[i], changePattern[i]);
	}

	printf("  Строка после замены => %s\n", str);

    return 0;
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

void leftShift(char string[], int pos, int num)
{
	int i;
	for (i = pos + num; string[i] != '\0'; i++)
	{
		string[pos++] = string[i];
	}
	string[pos] = '\0';
}

void rightShift(char string[], int pos, int num)
{
	int i;
	int length;
	length = lengthString(string);

	for (i = length; i >= pos; i--)
	{
		string[i + num] = string[i];
	}
}

void substringInsertion(char string[], char subString[], int pos)
{
	int i;
	for (i = 0; subString[i] != '\0'; i++)
	{
		string[pos + i] = subString[i];
	}
}

int searchShortString(char string[], char subString[], int pos)
{
	int i, j;
	int lengthA, lengthB;
	lengthA = lengthString(string);
	lengthB = lengthString(subString);
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
			if (string[i + j] != subString[j])// переход к следующему символу строки В(на след итерацию(j++) только если условие ложно 
			{
				break;
			}
		}
		if (j == lengthB)
		{
			if ( string[i] == '=' &&
				 string[i-1] != '=' && 
				 string[i+1] != '=' && 
				 string[i-1] != '!' && 
				 string[i-1] != '+' &&
				 string[i-1] != '-' &&
				 string[i-1] != 'a')
			{
				return i;
			}
		}
	}
	
	return -1;
}

int substringSearch(char string[], char subString[], int pos)
{
	int i, j;
	int lengthA, lengthB;
	lengthA = lengthString(string);
	lengthB = lengthString(subString);
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
			if (string[i + j] != subString[j])// переход к следующему символу строки В(на след итерацию(j++) только если условие ложно 
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

void replaceWrapper(char string[], char subString1[], char subString2[])
{
	int pos = 0;
	int shiftPoint;
	int lengthStr1 = lengthString(subString1);
	int lengthStr2 = lengthString(subString2);
	int deltaShift = abs(lengthStr1 - lengthStr2);

	while (pos != -1)
	{

		if (lengthStr1 == 1)
		{
			pos = searchShortString(string, subString1, pos);
		}
		else
		{
			pos = substringSearch(string, subString1, pos);
		}

		if (pos == -1) break;

		shiftPoint = pos + lengthStr1;

		if (lengthStr1 < lengthStr2)
		{
			rightShift(string, shiftPoint, abs(deltaShift));
		}
		if (lengthStr1 > lengthStr2)
		{
			leftShift(string, shiftPoint - deltaShift, deltaShift);
		}

		substringInsertion(string, subString2, pos);

		pos += lengthStr1 + abs(deltaShift);
		pos = substringSearch(string, subString1, pos);
	}
}

int abs(int number)
{
	return number < 1 ? number * (-1) : number;
}


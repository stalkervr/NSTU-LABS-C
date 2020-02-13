#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int lengthString(char string[]);
void leftShift(char string[], int pos, int num);
void rightShift(char string[], int pos, int num);
void substringInsertion(char string[], char subString[], int pos);


void replaceShort(char str[], char str1[], char str2[]);

int searchShort(char A[], char B[], int pos);

void replaceWrapper(char str[], char str1[], char str2[]);

int substringSearch(char A[], char B[], int pos);

int abs(int number);

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Лабораторная работа №4 вариант №5\n\n");

	char searchPattern[5][5] = { "=","==","!=","a+=","a-=" };
	char changePattern[5][5] = { ":=","=","#","a=a+","a=a-" };
	char str[300] = "(=, ==, !=, a+=, a-=, =)";

	printf("Строка до замены => %s\n\n", str);

	//replaceShort(str, "=", ":=");
	replaceWrapper(str, "=", ":=");
	replaceWrapper(str, "==", "=");
	replaceWrapper(str, "!=", "#");
	replaceWrapper(str, "a+=", "a=a+");
	replaceWrapper(str, "a-=", "a=a-");

	printf("Строка после замены => %s\n", str);

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




void replaceShort(char str[], char str1[], char str2[])
{
	int pos = 0;
	int shiftPoint;
	int deltaShift = lengthString(str1) - lengthString(str2);

	while (pos != -1)
	{
		pos = searchShort(str, str1, pos);

		if (pos == -1) break;

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
	int lengthStr1 = lengthString(str1);
	int lengthStr2 = lengthString(str2);
	int deltaShift = abs(lengthStr1 - lengthStr2);

	while (pos != -1)
	{

		if (lengthStr1 == 1)
		{
			pos = searchShort(str, str1, pos);
		}
		else
		{
			pos = substringSearch(str, str1, pos);
		}

		if (pos == -1) break;

		shiftPoint = pos + lengthStr1;

		if (lengthStr1 < lengthStr2)
		{
			rightShift(str, shiftPoint, abs(deltaShift));
		}
		if (lengthStr1 > lengthStr2)
		{
			leftShift(str, shiftPoint - deltaShift, deltaShift);
		}

		substringInsertion(str, str2, pos);

		pos += lengthStr1 + abs(deltaShift);
		pos = substringSearch(str, str1, pos);
	}
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
int abs(int number)
{
	return number < 1 ? number * (-1) : number;
}
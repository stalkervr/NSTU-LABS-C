// Practice_10-02-2020-Part-2.cpp :
//

#include <stdio.h>

int lengthString(char string[]);
void leftShift(char A[], int pos, int num);
void rightShift(char A[], int pos, int num);
int substringSearch(char A[], char B[]);
void substringInsertion(char A[], char B[], int pos);

int len(char S[]);
void razdvijka(char A[], int pos, int num);
void put(char A[], char B[], int pos);
int search(char A[], char B[]);
void sdvijka(char A[], int pos, int num);




int main()
{
	char str[100] = "abcdef";
	//printf("String length => %d\n", lengthString(str));
	//printf("String length => %d\n", len(str));
	//razdvijka(str,2,2);
	//substringInsertion(str,"52",2);
	//printf("%s",str);
	//sdvijka(str, 2, 2);
	//printf("%s", str);

	//printf("%d", search("abc==def==jj", "=="));
    return 0;
}


int len(char S[])
{
	int i;
	for (i = 0; S[i] != '\0'; i++);
	return i;
}

void razdvijka(char A[], int pos, int num)
{
	int i;
	int length;
	length = len(A);

	for (i = length; i >= pos; i--)
	{
		A[i + num] = A[i];
	}
}

void put(char A[], char B[], int pos)
{
	int i;
	for (i = 0; B[i] != '\0'; i++)
	{
		A[pos + i] = B[i];
	}
}

int search(char A[], char B[])
{
	int i, j;
	int lenA, lenB;
	lenA = len(A);
	lenB = len(B);
	if (lenB > lenA)
	{
		return -1;
	}

	for (i = 0; i <= lenA - lenB; i++)
	{
		for (j = 0; j < lenB; j++)
		{
			if (A[i + j] != B[j])
			{
				break;
			}
		}
		if (j == lenB)
		{
			return i;
		}
	}
	return -1;
}

void sdvijka(char A[], int pos, int num)
{
	int i;
	for (i = pos + num; A[i] != '\0'; i++)
	{
		A[pos++] = A[i];
	}
	A[pos] = '\0';
}

#pragma region Rewrite function

int lengthString(char string[])
{
	int i = 0;
	while (string[i]!='\0')
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

int substringSearch(char A[], char B[])
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

	for (i = 0; i <= lengthA - lengthB; i++)
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

#pragma endregion
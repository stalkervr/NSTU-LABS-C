#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int random(int n);
void fillArrayRandomNumbers(int* mass, int n, int a, int b);
void printOutArray(int* mass, int n);
int* createDynamicArray(int amountOfElementsArray);

void immersionInsertionSorting(int arr[], int n, int startIndex, int step);
void shellSorting(int arr[], int amountOfElements);
void bubbleSubSorting(int arr[], int n, int startIndex, int step);


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int N;
	printf("Enter size of array to create:");
	scanf_s("%d", &N);



	system("pause");

	return 0;
}


void shellSorting(int arr[], int amountOfElements)
{
	int step = amountOfElements / 2;   //инициализируем шаг.
	while (step > 0)       //пока шаг не 0
	{
		for (int i = 0; i < (amountOfElements - step); i++)
		{
			int j = i;
			while (j >= 0 && arr[j] > arr[j + step])
			{
				int temp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = temp;
				j--;
			}
		}
		step = step / 2;
	}
}

//----- Вставка погружением
void immersionInsertionSorting(int arr[], int n, int startIndex, int step) {

	for (int i = startIndex; i < n; i += step)// Пока не достигли " дна" или меньшего себя

		for (int k = i + step; k != 0 && arr[k] < arr[k - 1]; k -= step)
		{
			int temp = arr[k];
			arr[k] = arr[k - 1];
			arr[k - 1] = temp;
		}
}

void bubbleSubSorting(int arr[], int n, int startIndex, int step)
{
	for (int i = startIndex; i < n; i += step)
	{
		int min = i;
		for (int j = i + step; j < n; j += step)
		{
			if (arr[j] < arr[min])
			{
				min = j;
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	}
}

int* createDynamicArray(int amountOfElementsArray) {
	int* Array = (int*)malloc(amountOfElementsArray * sizeof(int));
	if (NULL == Array) {
		printf("OS didn't gave memory. Reload.....\n");
		exit(1);
		//system("cls");
		//main();
	}
	else {
		return Array;
	}
}

int random(int n) {
	return rand() % n;
}

void fillArrayRandomNumbers(int* mass, int n, int a, int b)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = random(b - a + 1) + a;
	}
}

void printOutArray(int* mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%i\t", mass[i]);
	}
	printf("\n\n\n");
}
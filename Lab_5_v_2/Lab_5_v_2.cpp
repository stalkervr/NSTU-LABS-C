#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int random(int number);
void fillArrayRandomNumbers(int* arr, int amountOfElementsArray, int leftEndOfRange, int rightEndOfRange);
void printOutArray(int* arr, int amountOfElementsArray);
int* createDynamicArray(int amountOfElementsArray);

void immersionInsertionSorting(int* arr, int amountOfElementsArray, int startIndex, int step);
void shellSorting(int* arr, int amountOfElements);
void bubbleSorting(int* arr, int amountOfElementsArray, int startIndex, int step);


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	printf("Лабораторная работа №5 вариант 2.\n");
	printf("\n");

	int amountOfElements, leftEndOfRange, rightEndOfRange, step, startIndex;

	do
	{
		printf("Введите количество элементов массива -> ");
		scanf_s("%d", &amountOfElements);
		if (amountOfElements <= 0 || amountOfElements >= 4294967294) {
			printf("Количество элементов массива должно быть больше 0 и меньше 4 294 967 295 !!!\n\n");
		}
	} while (amountOfElements <= 0 || amountOfElements >= 4294967294);
	printf("\n");

	do
	{
		printf("Введите диапазон допустимых значений -> ");
		scanf_s("%d %d", &leftEndOfRange, &rightEndOfRange);
		if (leftEndOfRange <= -2147483647 || rightEndOfRange >= 2147483646) {
			printf("Диапазон допустимых значений должен быть больше −2 147 483 647 и меньше 2 147 483 646 !!!\n\n");
		}
	} while (leftEndOfRange <= -2147483647 || rightEndOfRange >= 2147483646);
	printf("\n");

	do
	{
		printf("Введите стартовый индекс и шаг предварительной сортировки -> ");
		scanf_s("%d %d", &startIndex, &step);
		if (startIndex <= 0) {
			printf("Стартовый индекс должен быть 1 или более !!!\n\n");
		}
	} while (startIndex <= 0);
	printf("\n");

	//------------------------------------------
	
	int* mass = createDynamicArray(amountOfElements);
	fillArrayRandomNumbers(mass, amountOfElements, leftEndOfRange, rightEndOfRange);
	printOutArray(mass, amountOfElements);
	immersionInsertionSorting(mass, amountOfElements, startIndex, step);
	printOutArray(mass, amountOfElements);
	shellSorting(mass, amountOfElements);
	printOutArray(mass, amountOfElements);
	free(mass);
	
	//------------------------------------------


	system("pause");

	return 0;
}

//----- Сортировка Шелла
void shellSorting(int* arr, int amountOfElements)
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
void immersionInsertionSorting(int* arr, int amountOfElementsArray, int startIndex, int step) {

	for (int i = startIndex; i < amountOfElementsArray; i += step)// Пока не достигли " дна" или меньшего себя
	{
		//printf("i => %d\n", i);
		for (int k = i + step; k != 0 && (k - step) > 0 && arr[k] < arr[k - step]; k -= step)
		{
			int temp = arr[k];
			arr[k] = arr[k - step];
			arr[k - step] = temp;
			//printf(" k => %d", k);
			//printf(" k-step => %d\n", k - step);
		}
	}
}

//----- Пузырьковая
void bubbleSorting(int* arr, int amountOfElementsArray, int startIndex, int step)
{
	for (int i = startIndex; i < amountOfElementsArray; i += step)
	{
		int min = i;
		for (int j = i + step; j < amountOfElementsArray; j += step)
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
		printf("OS didn't gave memory. Exiting.....\n");
		exit(1);
		//system("cls");
		//main();
	}
	else {
		return Array; // указатель на начало массива
	}
}

int random(int number) {
	return rand() % number;
}

void fillArrayRandomNumbers(int* arr, int amountOfElementsArray, int a, int b)
{
	for (int i = 0; i < amountOfElementsArray; i++)
	{
		arr[i] = random(b - a + 1) + a;
	}
}

void printOutArray(int* arr, int amountOfElementsArray)
{
	for (int i = 0; i < amountOfElementsArray; i++)
	{
		if (i != 0 && i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d\t", arr[i]);
	}
	printf("\n\n\n");
}
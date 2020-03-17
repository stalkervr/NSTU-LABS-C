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
void sortWrapper(int amountOfElements, int leftEndOfRange, int rightEndOfRange, int step, int startIndex);


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
		if (amountOfElements <= 0 || amountOfElements >= INT_MAX) {
			printf("Количество элементов массива должно быть больше 0 и меньше 2 147 483 646 !!!\n\n");
		}
	} while (amountOfElements <= 0 || amountOfElements >= INT_MAX);
	printf("\n");

	do
	{
		printf("Введите диапазон допустимых значений -> ");
		scanf_s("%d %d", &leftEndOfRange, &rightEndOfRange);
		if (leftEndOfRange <= INT_MIN || rightEndOfRange >= INT_MAX) {
			printf("Диапазон допустимых значений должен быть больше −2 147 483 647 и меньше 2 147 483 646 !!!\n\n");
		}
	} while (leftEndOfRange <= INT_MIN || rightEndOfRange >= INT_MAX);
	printf("\n");

	do
	{
		printf("Введите стартовый индекс и шаг предварительной сортировки -> ");
		scanf_s("%d %d", &startIndex, &step);
		if (startIndex <= 0 || step <= 1) {
			printf("Стартовый индекс должен быть 1 или более !!!\n\n");
		}
	} while (startIndex <= 0 || step <= 1);
	printf("\n");
	
	sortWrapper(amountOfElements, leftEndOfRange, rightEndOfRange, step, startIndex);

	system("pause");

	return 0;
}

void sortWrapper(int amountOfElements, int leftEndOfRange, int rightEndOfRange, int step, int startIndex)
{
	int* arr = createDynamicArray(amountOfElements);
	// заполняем массив случайными числами
	fillArrayRandomNumbers(arr, amountOfElements, leftEndOfRange, rightEndOfRange);
	printOutArray(arr, amountOfElements);
	// выполняем предварительную сортировку
	immersionInsertionSorting(arr, amountOfElements, startIndex, step);
	printOutArray(arr, amountOfElements);
	// сортировка Шелла
	shellSorting(arr, amountOfElements);
	printOutArray(arr, amountOfElements);
	// очистка памяти
	free(arr);
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
		for (int k = i + step; k != 0 && (k - step) > 0 && k < amountOfElementsArray && arr[k] < arr[k - step]; k -= step)
		{
			int temp = arr[k];
			arr[k] = arr[k - step];
			arr[k - step] = temp;
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
		printf("ОС отказала в выделении памяти. Выход из программы.....\n");
		system("pause");
		exit(1);
	}
	else {
		return Array; // указатель на начало массива
	}
}

int random(int number) {
	return rand() % number;
}

void fillArrayRandomNumbers(int* arr, int amountOfElementsArray, int leftEndOfRange, int rightEndOfRange)
{
	for (int i = 0; i < amountOfElementsArray; i++)
	{
		arr[i] = random(rightEndOfRange - leftEndOfRange + 1) + leftEndOfRange;
	}
}

void printOutArray(int* arr, int amountOfElementsArray)
{
	for (int i = 0; i < amountOfElementsArray; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%d\t", arr[i]);
	}
	printf("\n\n\n");
}
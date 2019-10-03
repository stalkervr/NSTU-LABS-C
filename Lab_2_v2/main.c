#include "header.h"

int createDynamicArray(int amountOfElementsArray);
void printOutArray(int* mass, int n);
void fillArrayRandomNumbers(int* mass, int n, int a, int b);
int findNearestElement(int* mass, int* mass_out, int n);
int findIndexOfNearestElement(int* mass, int n);
int random(int n);
int calculateArithmeticMean(int* mass, int n);
int generatedOutputArray(int* mass, int n);

void main() {

	setlocale(LC_ALL, "Russian");

	int n, a, b;

	printf("Лабораторная работа №2 вариант 2.\n");
	printf("\n");
	do
	{
		printf("Введите количество элементов массива -> ");
		scanf_s("%d", &n);
		if (n <= 0) {
			printf("Количество элементов массива должно быть больше 0 и меньше 2147483647 !!!\n\n");
		}
	} while (n <= 0);


	printf("\n");
	printf("Введите диапазон допустимых значений -> ");
	scanf_s("%d %d", &a, &b);
	printf("\n\n");

	int* mass = createDynamicArray(n);
	fillArrayRandomNumbers(mass, n, a, b);
	int* mass_out = generatedOutputArray(mass, n);

	printOutArray(mass, n);
	printf("\n");
	printf("Среднее арифметическое элементов массива равно.... -> %d\n", calculateArithmeticMean(mass, n));
	printf("\n");
	printf("Ближайшим элементом к среднему арифметическому является число.... -> %d\n", findNearestElement(mass, mass_out, n));
	printf("\n");
	printf("Индекс ближайшего элемента к среднему арифметическому.... -> %d\n", findIndexOfNearestElement(mass_out, n));
	printf("\n");

	free(mass);
	free(mass_out);
}



int createDynamicArray(int amountOfElementsArray) {
	int* Array = (int*)malloc(amountOfElementsArray * sizeof(int));
	if (NULL == Array) {
		printf("OS didn't gave memory. Reload.....\n");
		exit(1);
		//system("cls");
		//main();
	} else {
		return Array;
	}
}

int findNearestElement(int* mass, int* mass_out, int n)
{
	int index = 0;
	int minElem = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (mass_out[i] < minElem) {
			minElem = mass_out[i];
			if (mass_out[i] > 0) {
				index = i;
			}
		}
	}
	return mass[index];
}

int findIndexOfNearestElement(int* mass, int n)
{
	int index = 0;
	int minElem = INT_MAX;
	for (int i = 0; i < n; i++) 
	{
		if (mass[i] < minElem) {
			minElem = mass[i];
			if (mass[i] > 0) {
				index = i;
			}
		}
	}
	return index;
}

int calculateArithmeticMean(int* mass, int n)
{
	int summ = 0;
	int average = 0;
	for (int i = 0; i < n; i++)
	{
		summ += mass[i];
	}
	average = summ / n;
	return average;
}

int generatedOutputArray(int* mass, int n)
{
	int* mass_out = createDynamicArray(n);
	for (int i = 0; i < n; i++)
	{
		if (mass[i] < 0) {
			mass_out[i] = -1 * (mass[i] - calculateArithmeticMean(mass, n));
			if (mass_out[i] < 0) {
				mass_out[i] = mass_out[i] * -1;
			}
		} else {
			mass_out[i] = mass[i] - calculateArithmeticMean(mass, n);
			if (mass_out[i] < 0) {
				mass_out[i] = mass_out[i] * -1;
			}
		}
	}
	return mass_out;
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
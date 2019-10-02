#include "header.h"

int createDynamicArray(int amountOfElementsArray);
void printArray(int* mass, int n);
void fillArrayRandomNumbers(int* mass, int n, int a, int b);
int getMinElemArray(int* mass, int n);
int getIndexOfNearestElement(int* mass, int* mass_out, int n);
int random(int n);
int calculateArithmeticMean(int* mass, int n);
int genOutputArray(int* mass, int n);

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "Russian");

	int n, a, b;

	printf("Лабораторная работа №2 вариант 2.\n");
	printf("\n");
	printf("Введите количество элементов массива -> ");
	scanf_s("%d", &n);
	printf("\n");
	printf("Введите диапазон допустимых значений -> ");
	scanf_s("%d %d", &a, &b);
	printf("\n");

	int* mass = createDynamicArray(n);
	fillArrayRandomNumbers(mass, n, a, b);
	int* mass_out = genOutputArray(mass, n);

	printArray(mass, n);
	printf("\n");
	printf("Среднее арифметическое элементов массива равно.... -> %d\n", calculateArithmeticMean(mass, n));
	printf("\n");
	printf("Ближайшим элементом к среднему арифметическому является число.... -> %d\n", getIndexOfNearestElement(mass, mass_out, n));
	printf("\n");
	
	return 0;
}



int createDynamicArray(int amountOfElementsArray) {
	int* Array = (int*)malloc(amountOfElementsArray * sizeof(int));
	if (NULL == Array) {
		printf("OS didn't gave memory. Exiting.....\n");
		exit(1);
	}
	else {
		return Array;
	}
}

int getIndexOfNearestElement(int* mass, int* mass_out, int n)
{
	int index = 0;
	int minElem = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (mass_out[i] < minElem)
		{
			minElem = mass_out[i];
			if (mass_out[i] > 0) {
				index = i;
			}
		}
	}
	return mass[index];
}

int random(int n) {
	return rand() % n;
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
	return 0;
}

int genOutputArray(int* mass, int n)
{
	int* mass_out = createDynamicArray(n);
	for (int i = 0; i < n; i++)
	{
		if (mass[i] < 0) {
			mass_out[i] = -1 * (mass[i] - calculateArithmeticMean(mass, n));
			if (mass_out[i] < 0) {
				mass_out[i] = mass_out[i] * -1;
			}
		}
		else {
			mass_out[i] = mass[i] - calculateArithmeticMean(mass, n);
			if (mass_out[i] < 0) {
				mass_out[i] = mass_out[i] * -1;
			}
		}
	}
	return mass_out;
}

void fillArrayRandomNumbers(int* mass, int n, int a, int b)
{
	for (int i = 0; i < n; i++)
	{
		mass[i] = random(b - a + 1) + a;

	}
}

int getMinElemArray(int* mass, int n)
{
	int minElem = INT_MAX;
	for (int i = 1; i < n; i++)
	{
		if (mass[i] < minElem)
		{
			minElem = mass[i];
		}
	}
	return minElem;
}

void printArray(int* mass, int n)
{

	for (int i = 0; i < n; i++)
	{
		fprintf(stdout, "%i\t", mass[i]);
	}
	fprintf(stdout, "\n\n\n");
}
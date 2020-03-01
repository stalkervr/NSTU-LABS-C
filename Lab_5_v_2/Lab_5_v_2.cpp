#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>


void immersionInsertionSorting(int arr[], int n);
void shellSorting(int arr[], int amountOfElements);


int main()
{
	srand(time(NULL));
	return 0;
}

void immersionInsertionSorting(int arr[], int n) {

	for (int i = 1; i < n; i++)// Пока не достигли " дна" или меньшего себя

		for (int k = i; k != 0 && arr[k] < arr[k - 1]; k--)
		{
			int temp = arr[k];
			arr[k] = arr[k - 1];
			arr[k - 1] = temp;
		}
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
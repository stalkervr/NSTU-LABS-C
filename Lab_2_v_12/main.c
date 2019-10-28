#include "header.h"

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay);
bool checkLeapYear(int currentYear);

int main() {

	setlocale(LC_ALL, "Russian");
	printf("Лабораторная работа №2 вариант 12.\n");

	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int startDay = 0;
	int currentYear = 0;

	printf("Введите каким днём недели является 1 Января \n (1-понедельник, 2-вторник, 3-среда, 4-четверг, 5-пятница, 6-суббота, 7-воскресенье):");
	scanf_s("%d", &startDay);

	printf("Введите год : ");
	scanf_s("%d", &currentYear);

	printf("\nКоличество чёрных вторников и пятниц в этом году составляет : %d \n", findBlackDays(currentYear, arrayOfMonths, startDay));
	return 0;
}

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay)
{
	int countBlackDays = 0;

	if (checkLeapYear(currentYear)) {
		arrayOfMonths[1] = 29;
	}

	for (int i = 0; i < 12; i++)
	{
		for (int days = 1; days <= arrayOfMonths[i]; days++)
		{
			printf("%d|%d ", days, startDay);
			if (days == 13 && ((startDay == 2) || (startDay == 5)))
			{
				countBlackDays++;
			}
			startDay = (startDay % 7) + 1;
		}
		printf("\n\n");
	}
	
	return countBlackDays;
}

bool checkLeapYear(int currentYear)
{
	if ((currentYear % 400 == 0) || ((currentYear % 4 == 0) && (currentYear % 100 != 0))) {
		return true;
	}
	else {
		return false;
	}
}

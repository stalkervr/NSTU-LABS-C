#include "header.h"

int findBlackDays();
bool checkLeapYear(int currentYear);

int main() {

	setlocale(LC_ALL, "Russian");
	printf("Лабораторная работа №2 вариант 12.\n");

	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, start, countBlackDays = 0, currentYear;
	printf("Введите каким днём недели является 1 Января \n (1-понедельник, 2-вторник, 3-среда, 4-четверг, 5-пятница, 6-суббота, 7-воскресенье):");

	scanf_s("%d", &start);

	printf("Введите год : ");

	scanf_s("%d", &currentYear);

	if (checkLeapYear(currentYear)) {
		arrayOfMonths[1] = 29;
	}

	for (int i = 0; i < 12; i++)
	{
		for (int days = 1; days <= arrayOfMonths[i]; days++)
		{
			printf("%d|%d ", days, start);
			if (days == 13 && ((start == 2) || (start == 5)))
			{
				countBlackDays++;
			}
			start = (start % 7) + 1;
		}
		printf("\n\n");
	}
	printf("\nКоличество чёрных вторников и пятниц в этом году составляет : %d \n", countBlackDays);
	return 0;
}

int findBlackDays()
{
	return 0;
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

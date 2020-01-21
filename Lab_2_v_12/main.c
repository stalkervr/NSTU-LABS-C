#include "header.h"

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay);
bool checkLeapYear(int currentYear);

int main() {

	setlocale(LC_ALL, "Russian");
	printf("Лабораторная работа №2 вариант 12.\n");

	// массив месятцев
	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// день недели на который приходится 1 января
	int startDay = 0;
	// год для расчёта
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
	// счетчик чёрных дней
	int countBlackDays = 0;
	// проверяем год на високостность
	// если год високостный изменяем второй элемент массива месятцев
	if (checkLeapYear(currentYear)) {
		arrayOfMonths[1] = 29;
	}
	// перебераем массив месятцев
	for (int i = 0; i < 12; i++)
	{
		// проверяем каждый день текущего месяца
		for (int days = 0; days <= arrayOfMonths[i]; days++)
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
// функция проверки года на високосность
bool checkLeapYear(int currentYear)
{
	if ((currentYear % 400 == 0) || ((currentYear % 4 == 0) && (currentYear % 100 != 0))) {
		return true;
	}
	else {
		return false;
	}
}

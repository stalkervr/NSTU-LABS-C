#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay);
bool checkLeapYear(int currentYear);

int main() {

	setlocale(LC_ALL, "Russian");
	printf("Ћабораторна€ работа є2 вариант 12.\n\n");

	// массив мес€цев
	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// день недели на который приходитс€ 1 €нвар€
	int startDay = 0;
	// год дл€ расчЄта
	int currentYear = 0;

	printf("¬ведите каким днЄм недели €вл€етс€ 1 январ€ \n (1-понедельник, 2-вторник, 3-среда, 4-четверг, 5-п€тница, 6-суббота, 7-воскресенье) : ");
	scanf_s("%d", &startDay);
	printf("\n");

	printf("¬ведите год : ");
	scanf_s("%d", &currentYear);
	printf("\n");

	printf("\n оличество чЄрных вторников и п€тниц в этом году составл€ет : %d \n", findBlackDays(currentYear, arrayOfMonths, startDay));
	printf("\n");
	return 0;
}

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay)
{
	// счетчик чЄрных дней
	int countBlackDays = 0;
	// провер€ем год на високостность
	// если год високостный измен€ем второй элемент массива мес€цев
	if (checkLeapYear(currentYear)) {
		arrayOfMonths[1] = 29;
	}
	// перебераем массив мес€тцев
	for (int i = 0; i < 12; i++)
	{
		// провер€ем каждый день текущего мес€ца
		for (int days = 1; days <= arrayOfMonths[i]; days++)
		{
			if (days == 13 && ((startDay == 2) || (startDay == 5)))
			{
				countBlackDays++;
				printf("ћес€ц %d %d|%d ", i + 1, days, startDay);
				printf("\n");
			}
			startDay = (startDay % 7) + 1;
		}
	}

	return countBlackDays;
}
// функци€ проверки года на високосность
bool checkLeapYear(int currentYear)
{
	if ((currentYear % 400 == 0) || ((currentYear % 4 == 0) && (currentYear % 100 != 0))) {
		return true;
	}
	else {
		return false;
	}
}

//int findBlackDays(int currentYear, int* arrayOfMonths, int startDay);
//bool checkLeapYear(int currentYear);
//
//int main() {
//
//	setlocale(LC_ALL, "Russian");
//	printf("Ћабораторна€ работа є2 вариант 12.\n\n");
//
//	// массив мес€тцев
//	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	// день недели на который приходитс€ 1 €нвар€
//	int startDay = 0;
//	// год дл€ расчЄта
//	int currentYear = 0;
//
//	printf("¬ведите каким днЄм недели €вл€етс€ 1 январ€ \n (1-понедельник, 2-вторник, 3-среда, 4-четверг, 5-п€тница, 6-суббота, 7-воскресенье): ");
//	scanf_s("%d", &startDay);
//	printf("\n\n");
//
//	printf("¬ведите год : ");
//	scanf_s("%d", &currentYear);
//	printf("\n\n");
//
//	printf("\n оличество чЄрных вторников и п€тниц в этом году составл€ет : %d \n", findBlackDays(currentYear, arrayOfMonths, startDay));
//	return 0;
//}
//
//int findBlackDays(int currentYear, int* arrayOfMonths, int startDay)
//{
//	// счетчик чЄрных дней
//	int countBlackDays = 0;
//	// провер€ем год на високостность
//	// если год високостный измен€ем второй элемент массива мес€тцев
//	if (checkLeapYear(currentYear)) {
//		arrayOfMonths[1] = 29;
//	}
//	// перебераем массив мес€тцев
//	for (int i = 0; i < 12; i++)
//	{
//		// провер€ем каждый день текущего мес€ца
//		for (int days = 1; days <= arrayOfMonths[i]; days++)
//		{
//			printf("%d|%d ", days, startDay);
//			if (days == 13 && ((startDay == 2) || (startDay == 5)))
//			{
//				countBlackDays++;
//			}
//			startDay = (startDay % 7) + 1;
//		}
//		printf("\n\n");
//	}
//	
//	return countBlackDays;
//}
//// функци€ проверки года на високосность
//bool checkLeapYear(int currentYear)
//{
//	if ((currentYear % 400 == 0) || ((currentYear % 4 == 0) && (currentYear % 100 != 0))) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}



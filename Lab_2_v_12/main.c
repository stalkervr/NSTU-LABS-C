#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay);
bool checkLeapYear(int currentYear);

int main() {

	setlocale(LC_ALL, "Russian");
	printf("������������ ������ �2 ������� 12.\n\n");

	// ������ �������
	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// ���� ������ �� ������� ���������� 1 ������
	int startDay = 0;
	// ��� ��� �������
	int currentYear = 0;

	printf("������� ����� ��� ������ �������� 1 ������ \n (1-�����������, 2-�������, 3-�����, 4-�������, 5-�������, 6-�������, 7-�����������) : ");
	scanf_s("%d", &startDay);
	printf("\n");

	printf("������� ��� : ");
	scanf_s("%d", &currentYear);
	printf("\n");

	printf("\n���������� ������ ��������� � ������ � ���� ���� ���������� : %d \n", findBlackDays(currentYear, arrayOfMonths, startDay));
	printf("\n");
	return 0;
}

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay)
{
	// ������� ������ ����
	int countBlackDays = 0;
	// ��������� ��� �� �������������
	// ���� ��� ����������� �������� ������ ������� ������� �������
	if (checkLeapYear(currentYear)) {
		arrayOfMonths[1] = 29;
	}
	// ���������� ������ ��������
	for (int i = 0; i < 12; i++)
	{
		// ��������� ������ ���� �������� ������
		for (int days = 1; days <= arrayOfMonths[i]; days++)
		{
			if (days == 13 && ((startDay == 2) || (startDay == 5)))
			{
				countBlackDays++;
				printf("����� %d %d|%d ", i + 1, days, startDay);
				printf("\n");
			}
			startDay = (startDay % 7) + 1;
		}
	}

	return countBlackDays;
}
// ������� �������� ���� �� ������������
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
//	printf("������������ ������ �2 ������� 12.\n\n");
//
//	// ������ ��������
//	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	// ���� ������ �� ������� ���������� 1 ������
//	int startDay = 0;
//	// ��� ��� �������
//	int currentYear = 0;
//
//	printf("������� ����� ��� ������ �������� 1 ������ \n (1-�����������, 2-�������, 3-�����, 4-�������, 5-�������, 6-�������, 7-�����������): ");
//	scanf_s("%d", &startDay);
//	printf("\n\n");
//
//	printf("������� ��� : ");
//	scanf_s("%d", &currentYear);
//	printf("\n\n");
//
//	printf("\n���������� ������ ��������� � ������ � ���� ���� ���������� : %d \n", findBlackDays(currentYear, arrayOfMonths, startDay));
//	return 0;
//}
//
//int findBlackDays(int currentYear, int* arrayOfMonths, int startDay)
//{
//	// ������� ������ ����
//	int countBlackDays = 0;
//	// ��������� ��� �� �������������
//	// ���� ��� ����������� �������� ������ ������� ������� ��������
//	if (checkLeapYear(currentYear)) {
//		arrayOfMonths[1] = 29;
//	}
//	// ���������� ������ ��������
//	for (int i = 0; i < 12; i++)
//	{
//		// ��������� ������ ���� �������� ������
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
//// ������� �������� ���� �� ������������
//bool checkLeapYear(int currentYear)
//{
//	if ((currentYear % 400 == 0) || ((currentYear % 4 == 0) && (currentYear % 100 != 0))) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}



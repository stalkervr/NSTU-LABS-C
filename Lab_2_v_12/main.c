#include "header.h"

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay);
bool checkLeapYear(int currentYear);

int main() {

	setlocale(LC_ALL, "Russian");
	printf("������������ ������ �2 ������� 12.\n");

	// ������ ��������
	int arrayOfMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// ���� ������ �� ������� ���������� 1 ������
	int startDay = 0;
	// ��� ��� �������
	int currentYear = 0;

	printf("������� ����� ��� ������ �������� 1 ������ \n (1-�����������, 2-�������, 3-�����, 4-�������, 5-�������, 6-�������, 7-�����������):");
	scanf_s("%d", &startDay);

	printf("������� ��� : ");
	scanf_s("%d", &currentYear);

	printf("\n���������� ������ ��������� � ������ � ���� ���� ���������� : %d \n", findBlackDays(currentYear, arrayOfMonths, startDay));
	return 0;
}

int findBlackDays(int currentYear, int* arrayOfMonths, int startDay)
{
	// ������� ������ ����
	int countBlackDays = 0;
	// ��������� ��� �� �������������
	// ���� ��� ����������� �������� ������ ������� ������� ��������
	if (checkLeapYear(currentYear)) {
		arrayOfMonths[1] = 29;
	}
	// ���������� ������ ��������
	for (int i = 0; i < 12; i++)
	{
		// ��������� ������ ���� �������� ������
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

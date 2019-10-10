#include "header.h"

int main()

{

	int M[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, days, start, i, black = 0, year;
	printf("Enter the day of the week on January 1 (1-mon, 2-tues, 3-wed, 4-thur, 5-frid, 6-sat, 7-sun):");

	scanf_s("%d", &start);

	printf("Check if the year is weighty(yes - 1, no - 0):");

	scanf_s("%d", &year);
	if (year == 1)

	{

		M[1] = 29;

	}
	for (i = 0; i < 12; i++)

	{

		for (days = 1; days <= M[i]; days++)

		{
			printf("%d|%d ", days, start);

			if (days == 13 && ((start == 2) || (start == 5)))

			{

				black++;

			}
			start = (start % 7) + 1;

		}

		printf("\n\n");

	}
	printf("\nThe number of black tuesdays and fridays of the year : %d \n", black);
	return 0;

}
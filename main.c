#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_YEAR 2021
#define MIN_YEAR 2010
#define LOG_DAYS 3

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;
	int month = 0;
	int year = 0;
	int date = 0;
	int correct = 0;
	int i;
	double morning = 0.0;
	double evening = 0.0;
	double morningTotal = 0.0;
	double eveningTotal = 0.0;
	double totalRating = 0.0;
	double averageMorningRating = 0.0;
	double averageEveningRating = 0.0;
	double overallAverageRating = 0.0;

	printf("General Well-being Log");
	printf("\n======================\n");
	printf("Set the year and month for the well-being log (YYYY MM): ");
	scanf("%d %d", &year, &month);

	while (!correct)
	{
		if (year > MAX_YEAR || year < MIN_YEAR) // year out of range
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			if (month < JAN || month > DEC) // month out of range
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
				printf("Set the year and month for the well-being log (YYYY MM): ");
				correct = 0;
				scanf("%d %d", &year, &month);
			}
			else if (month >= JAN || month <= DEC) // month in range
			{
				printf("Set the year and month for the well-being log (YYYY MM): ");
				correct = 0;
				scanf("%d %d", &year, &month);
			}
		}
		else if (year <= MAX_YEAR || year >= MIN_YEAR) //  year in range
		{
			if (month < JAN || month > DEC) // month out of range
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
				printf("Set the year and month for the well-being log (YYYY MM): ");
				correct = 0;
				scanf("%d %d", &year, &month);
			}
			else // both in range
			{
				correct++;
			}
		}
	}
	printf("\n*** Log date set! ***\n");

	for ( i = 0; i < LOG_DAYS; i++)
	{
		switch (month)
		{
			case 1:
				date++;
				printf("\n%d-JAN-0%d", year, date);
				break;
			case 2:
				date++;
				printf("\n%d-FEB-0%d", year, date);
				break;
			case 3:
				date++;
				printf("\n%d-MAR-0%d", year, date);
				break;
			case 4:
				date++;
				printf("\n%d-APR-0%d", year, date);
				break;
			case 5:
				date++;
				printf("\n%d-MAY-0%d", year, date);
				break;
			case 6:
				date++;
				printf("\n%d-JUN-0%d", year, date);
				break;
			case 7:
				date++;
				printf("\n%d-JUL-0%d", year, date);
				break;
			case 8:
				date++;
				printf("\n%d-AUG-0%d", year, date);
				break;
			case 9:
				date++;
				printf("\n%d-SEP-0%d", year, date);
				break;
			case 10:
				date++;
				printf("\n%d-OCT-0%d", year, date);
				break;
			case 11:
				date++;
				printf("\n%d-NOV-0%d", year, date);
				break;
			case 12:
				date++;
				printf("\n%d-DEC-0%d", year, date);
				break;
			default:
				printf("\nERROR: Month is out of bounds\n");
		}
		printf("\n   Morning rating (0.0-5.0): ");
		scanf("%lf", &morning);
		while (morning < 0.0 || morning > 5.0)
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
			printf("\n   Morning rating (0.0-5.0): ");
			scanf("%lf", &morning);
		}
		printf("   Evening rating (0.0-5.0): ");
		scanf("%lf", &evening);
		morningTotal += morning;
		while (evening < 0.0 || evening > 5.0)
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &evening);
		}
		eveningTotal += evening;
	}

	totalRating = morningTotal + eveningTotal;
	averageMorningRating = morningTotal / LOG_DAYS;
	averageEveningRating = eveningTotal / LOG_DAYS;
	overallAverageRating = (averageEveningRating + averageMorningRating) / 2;
	printf("\nSummary");
	printf("\n=======");
	printf("\nMorning total rating: %.3lf", morningTotal);
	printf("\nEvening total rating: %.3lf", eveningTotal);
	printf("\n----------------------------");
	printf("\nOverall total rating: %.3lf\n", totalRating);
	printf("\nAverage morning rating:  %.1lf", averageMorningRating);
	printf("\nAverage evening rating:  %.1lf", averageEveningRating);
	printf("\n----------------------------");
	printf("\nAverage overall rating:  %.1lf", overallAverageRating);
	return 0;
}

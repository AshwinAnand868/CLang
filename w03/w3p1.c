/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Ashwin Anand
	ID     : 152042206
	Email  : aanand24@myseneca.ca
	Section: IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;

	int chosenYear, chosenMonth, logDate;

	printf("General Well-being Log\n");
	printf("======================\n");

	int keepExecuting = 1;
	int flag = 1;
	while (keepExecuting && flag)
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d", &chosenYear);
		scanf("%d", &chosenMonth);

		if (chosenYear >= MIN_YEAR && chosenYear <= MAX_YEAR)
		{
			if (chosenMonth >= JAN && chosenMonth <= DEC)
			{
				switch (chosenMonth)
				{
				case 1:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-JAN-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 2:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-FEB-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 3:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-MAR-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 4:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-APR-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 5:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-MAY-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 6:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-JUN-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 7:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-JUL-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 8:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-AUG-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 9:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-SEP-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 10:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-OCT-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 11:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-NOV-0%d\n", chosenYear, logDate);
					flag = 0;
					break;
				case 12:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					printf("\n");
					printf("Log starting date: %d-DEC-0%d\n", chosenYear, logDate);
					flag = 0;
					break;

				}
			}
			else
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
			}
		}

		else if ((chosenMonth < JAN || chosenMonth > DEC) && (chosenYear < MIN_YEAR || chosenYear > MAX_YEAR))
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		else
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
	}



	return 0;
}

/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   : Ashwin Anand
	ID     : 152042206
	Email  : aanand24@myseneca.ca
	Section: IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXITEMS 10
#define ARRAYSIZE 10

int main(void)
{

	char financeOptionArray[ARRAYSIZE];
	double userMonthlyIncome, totalAmount, totalMonths, priortizedAmountTotal;
	double itemCostArray[ARRAYSIZE];
	 
	int firstFlag, secondFlag, totalItems, i = 0, itemCounter, thirdFlag, itemPriorityArray[ARRAYSIZE] = { 0 }, fourthFlag, itemCounterArray[ARRAYSIZE] = { 0 }, fifthFlag, sixthFlag, selection, seventhFlag, eighthFlag, extraMonths, intuserMonthlyIncome, importanceRatings, noteChecker = 0, intpriortizedAmountTotal, roundedTotalMonths, intTotalAmount, years, months;
	const double MININCOME = 500.00;
	const double MAXINCOME = 400000.00;
	const double LEASTPRICE = 100.00;
	const int MONTHSINAYEAR = 12;
	priortizedAmountTotal = 0.0;
	firstFlag = 1;
	secondFlag = 1;
	fifthFlag = 1;
	sixthFlag = 1;
	
	itemCounter = 1;
	totalAmount = 0.0;
	fourthFlag = 1;
	

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	printf("\n");
	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &userMonthlyIncome);


		if (userMonthlyIncome >= MININCOME && userMonthlyIncome <= MAXINCOME)
		{
			firstFlag = 0;
		}
		else if (userMonthlyIncome < MININCOME)
		{
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MININCOME);
			printf("\n");
		}
		else
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAXINCOME);
			printf("\n");
		}

	} while (firstFlag);

	do
	{
		printf("\n");

		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &totalItems);

		if (totalItems >= 1 && totalItems <= 10)
		{
			secondFlag = 0;
		}
		else
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");

		}
	} while (secondFlag);

	for (i = 0; i < totalItems; i++)
	{
		printf("\n");
		printf("Item-%d Details:\n", itemCounter);
		fifthFlag = 1;
		while (fifthFlag)
		{
			printf("   Item cost: $");
			scanf("%lf", &itemCostArray[i]);


			if (itemCostArray[i] >= LEASTPRICE)
			{
				thirdFlag = 1;
				while (thirdFlag)
				{


					printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
					scanf("%d", &itemPriorityArray[i]);
					fifthFlag = 0;
					if (itemPriorityArray[i] > 0 && itemPriorityArray[i] < 4)
					{
						itemCounterArray[i] = itemCounter;
						itemCounter++;
						do
						{
							printf("   Does this item have financing options? [y/n]: ");
							scanf(" %c", &financeOptionArray[i]);



							if (financeOptionArray[i] == 'y' || financeOptionArray[i] == 'n')
							{
								fourthFlag = 0;

							}

							else
							{
								printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
								scanf("%*c");
							}

						} while (fourthFlag);
						thirdFlag = 0;

					}
					else
					{
						printf("      ERROR: Value must be between 1 and 3\n");
						scanf("%*c");

					}



				}

				fifthFlag = 0;


			}
			else
			{
				printf("      ERROR: Cost must be at least $%.2lf\n", LEASTPRICE);
				fifthFlag = 1;


			}

		}

	}
	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < totalItems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", itemCounterArray[i], itemPriorityArray[i], financeOptionArray[i], itemCostArray[i]);
		totalAmount += itemCostArray[i];
	}


	printf("---- -------- -------- -----------\n");
	printf("                      $ %.2lf", totalAmount);
	printf("\n");
	printf("\n");
	while (sixthFlag)
	{

		if (noteChecker)
		{
			printf("====================================================\n\n");
		}
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);
		printf("\n");


		if (selection == 1)
		{
			printf("====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", totalAmount);

			intTotalAmount = (int)totalAmount * 100;

			intuserMonthlyIncome = (int)userMonthlyIncome * 100;

			totalMonths = intTotalAmount / intuserMonthlyIncome;


			extraMonths = intTotalAmount % intuserMonthlyIncome;

			roundedTotalMonths = totalMonths + 0.5;

			if (extraMonths > 0)
			{
				roundedTotalMonths += 1;
			}

			years = roundedTotalMonths / MONTHSINAYEAR;

			months = roundedTotalMonths % MONTHSINAYEAR;

			printf("Forecast: %d years, %d months\n", years, months);

			for (i = 0; i < totalItems; i++)
			{
				if (financeOptionArray[i] == 'y')
				{
					seventhFlag = 1;
				}
			}
			if (seventhFlag == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
				printf("====================================================\n\n");

			}

		}

		else if (selection == 2)
		{
			eighthFlag = 1;
			while (eighthFlag)
			{
				importanceRatings = 0;


				printf("What priority do you want to filter by? [1-3]: ");

				scanf("%d", &importanceRatings);
				printf("\n");

				printf("====================================================\n");

				if (importanceRatings >= 1 && importanceRatings <= 3)
				{

					eighthFlag = 0;

				}
				else
				{
					printf("ERROR: Value must be between 1 and 3\n");
				}
			}

			priortizedAmountTotal = 0.0;
			for (i = 0; i < totalItems; i++)
			{

				if (itemPriorityArray[i] == importanceRatings)
				{
					priortizedAmountTotal += itemCostArray[i];
				}
			}



			printf("Filter:   by priority (%d)\n", importanceRatings);
			printf("Amount:   $%.2lf\n", priortizedAmountTotal);

			intpriortizedAmountTotal = (int)priortizedAmountTotal * 100;;
			intuserMonthlyIncome = (int)userMonthlyIncome * 100;

			totalMonths = intpriortizedAmountTotal / intuserMonthlyIncome;


			extraMonths = intpriortizedAmountTotal % intuserMonthlyIncome;

			roundedTotalMonths = totalMonths + 0.5;

			if (extraMonths > 0)
			{
				roundedTotalMonths += 1;
			}

			years = roundedTotalMonths / MONTHSINAYEAR;

			months = roundedTotalMonths % MONTHSINAYEAR;


			printf("Forecast: %d years, %d months\n", years, months);
			
			
			
			noteChecker = 0;
			for (i = 0; i < totalItems; i++)
			{
				if (importanceRatings == itemPriorityArray[i])
				{
					if (financeOptionArray[i] == 'y')
					{
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n");
					   

					}
					else
					{
						noteChecker = 1;
					}

				}
			}
			
		}
		
		else if (selection == 0)
		{
			printf("Best of luck in all your future endeavours!\n");
			sixthFlag = 0;

		}
		else
		{

			printf("ERROR: Invalid menu selection.\n");
			printf("\n");
		}



	}
	return 0;
}

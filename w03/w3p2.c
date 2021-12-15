/*
	==================================================
	Workshop #3 (Part-2):
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
#define LOG_DAYS 3

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;


	double morningDiagnosis, eveningDiagnosis, eveningTotal, morningTotal, total, averageMorningRating, averageEveningRating, overallRating, averageOverallRating;
	int chosenYear, chosenMonth, keepExecuting, logDate, i, flag, secondFlag, thirdFlag;
	morningTotal = 0;
	eveningTotal = 0;
	keepExecuting = 1;
	flag = 1;

	printf("General Well-being Log\n");
	printf("======================\n");


	do
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

					for (i = 0; i < LOG_DAYS; i++)
					{

						printf("%d-JAN-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						do
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;
								secondFlag = 0;
								do
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								} while (thirdFlag);
							}

							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						} while (secondFlag);

						logDate++;

					}


					flag = 0;
					break;


				case 2:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");

					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-FEB-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 3:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-MAR-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 4:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-APR-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 5:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-MAY-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 6:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-JUN-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 7:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-JUL-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 8:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-AUG-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 9:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-SEP-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 10:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-OCT-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 11:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-NOV-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}


						}

						logDate++;

					}
					flag = 0;
					break;
				case 12:
					logDate = 1;
					printf("\n");
					printf("*** Log date set! ***\n");
					for (i = 0; i < LOG_DAYS; i++)
					{
						printf("\n");
						printf("%d-DEC-0%d\n", chosenYear, logDate);
						secondFlag = 1;
						while (secondFlag)
						{
							printf("   Morning rating (0.0-5.0): ");
							scanf("%lf", &morningDiagnosis);



							if (morningDiagnosis >= 0.0 && morningDiagnosis <= 5.0)
							{
								thirdFlag = 1;
								morningTotal += morningDiagnosis;

								while (thirdFlag)
								{
									printf("   Evening rating (0.0-5.0): ");
									scanf("%lf", &eveningDiagnosis);
									if (eveningDiagnosis >= 0.0 && eveningDiagnosis <= 5.0)
									{
										eveningTotal += eveningDiagnosis;

										thirdFlag = 0;
									}
									else
									{
										printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
									}

								}
								secondFlag = 0;
							}
							else
							{
								printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
							}

						}

						logDate++;

					}
					flag = 0;
					break;


				}
				total = morningTotal + eveningTotal;
				printf("\n");
				printf("Summary\n");
				printf("=======\n");
				printf("Morning total rating: %.3lf\n", morningTotal);
				printf("Evening total rating: %.3lf\n", eveningTotal);
				printf("----------------------------\n");
				printf("Overall total rating: %.3lf\n", total);
				printf("\n");
				averageMorningRating = morningTotal / 3;
				printf("Average morning rating:  %.1lf\n", averageMorningRating);

				averageEveningRating = eveningTotal / 3;
				printf("Average evening rating:  %.1lf\n", averageEveningRating);
				printf("----------------------------\n");


				overallRating = morningTotal + eveningTotal;
				averageOverallRating = overallRating / 6;
				printf("Average overall rating:  %.1lf\n", averageOverallRating);

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
	} while (keepExecuting && flag);

	return 0;
}

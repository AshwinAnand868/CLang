/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Ashwin Anand
	ID     : 152042206
	Email  : aanand24@myseneca.ca
	Section: IPC144 NDD
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"
#define SZ 3
// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* categoryAddress)
{
	int flag = 1;
	int value;
	
	scanf("%d", &value);
	while (flag)
	{
		
			if (value > 0)
			{
				if (categoryAddress != NULL)
				{
					*categoryAddress = value;
					flag = 0;
					
				}
				return value;
            }
			else
			{
				
				printf("ERROR: Enter a positive value: ");
				scanf("%d", &value);
			}
		
		
	}

	return value;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* categoryAddress)
{
	int flag = 1;
	double value;

	scanf("%lf", &value);
	while (flag)
	{

		if (value > 0)
		{
			if (categoryAddress != NULL)
			{
				*categoryAddress = value;
				flag = 0;
				
			}
			return value;
		}
		else
		{

			printf("ERROR: Enter a positive value: ");
			scanf("%lf", &value);
		}


	}
	return value;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int nProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", NMAXPRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", GRAMS);


}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNUmber)
{
	
	struct CatFoodInfo catFood;
	int sku, calories;
	double price, weight;
	printf("\n");
	printf("Cat Food Product #%d\n", sequenceNUmber);
	printf("--------------------\n");
	printf("SKU           : ");
	catFood.sku = getIntPositive(&sku);
	
	printf("PRICE         : $");
	catFood.price = getDoublePositive(&price);
	
	printf("WEIGHT (LBS)  : ");
	catFood.weight = getDoublePositive(&weight);

	printf("CALORIES/SERV.: ");
	catFood.calories = getIntPositive(&calories);
	
	return catFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\n");
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo catFoodInfo[NMAXPRODUCTS] = { {0} };
	
	openingMessage(NMAXPRODUCTS);
	for (i = 0; i < NMAXPRODUCTS; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i+1);
	}
	displayCatFoodHeader();

	for (i = 0; i < NMAXPRODUCTS; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].price, &catFoodInfo[i].weight, catFoodInfo[i].calories);
	}
}

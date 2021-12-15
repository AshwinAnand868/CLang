/*
	==================================================
	Workshop #6 (Part-2):
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
#include "w6p2.h"


// ----------------------------------------------------------------------------
// PART-1

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




// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kgs)
{
	double localKg;
	localKg = (*lbs) / POUNDSTOKG;
	
	if (kgs != NULL)
	{
		*kgs = localKg;
	}
	return localKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* grams)
{
	int localGrams;
	double* kgs = 0;
	double kg = convertLbsKg(lbs, kgs);
	localGrams = kg * 1000;

	if (grams != NULL)
	{
		*grams = localGrams;
	}
	return localGrams;
}


// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kgs, int* grams)
{
	int* localGrams = 0;
	double* localKilos = 0;

	*kgs = convertLbsKg(lbs, localKilos);
	*grams = convertLbsG(lbs, localGrams);

}


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalGrams, double* totalServings)
{
	double localServings;

	localServings = (double) totalGrams / servingSize;
	if (totalServings != NULL)
	{
		*totalServings = localServings;
	}
	return localServings;

}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* proPrice, const double* totalServings, double* costPerServing)
{
	double costPServ;
	costPServ = (*proPrice) / (*totalServings);

	if (costPerServing != NULL)
	{
		*costPerServing = costPServ;
	}
	return costPServ;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* proPrice, const double* totalCalories, double* costPerCal)
{
	double costPC;
	costPC = (*proPrice) / (*totalCalories);

	if (costPerCal != NULL)
	{
		*costPerCal = costPC;
	}
	return costPC;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo[], const int sequenceNum)
{
	struct ReportData reportData = { 0 };
	double nCalories = 0;

	reportData.proSku = catFoodInfo[sequenceNum].sku;

	reportData.proPrice = catFoodInfo[sequenceNum].price;

	reportData.calsPerServ = catFoodInfo[sequenceNum].calories;

	reportData.weightInLbs = catFoodInfo[sequenceNum].weight;

	reportData.weightInKgs = convertLbsKg(&reportData.weightInLbs, &reportData.weightInKgs);

	reportData.weightInGrams = convertLbsG(&reportData.weightInLbs, &reportData.weightInGrams);

	reportData.totalServings = calculateServings(GRAMS, reportData.weightInGrams, &reportData.totalServings);

	reportData.costPerServ = calculateCostPerServing(&reportData.proPrice, &reportData.totalServings, &reportData.costPerServ);

	nCalories = reportData.calsPerServ * reportData.totalServings;

	reportData.costPerCals = calculateCostPerCal(&reportData.proPrice, &nCalories, &reportData.costPerCals);

	return reportData;

}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\n");
	printf("Analysis Report (Note: Serving = %dg",GRAMS);
	printf("\n");
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData[], const int cheapestPro)
{
	int i;
	
	for (i = 0; i < NMAXPRODUCTS; i++)
	{
		
			printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportData[i].proSku, reportData[i].proPrice, reportData[i].weightInLbs, reportData[i].weightInKgs, reportData[i].weightInGrams, reportData[i].calsPerServ, reportData[i].totalServings, reportData[i].costPerServ, reportData[i].costPerCals);
			if (i + 1 == cheapestPro)
			{
				printf(" ***");
			}
			printf("\n");

	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo)
{
	printf("\n");
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:00%d Price: $%.2lf\n", catFoodInfo.sku, catFoodInfo.price);
	printf("\n");

	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i;
	int indexPro1, indexPro2, indexPro3, index, cheapestProduct;
	struct CatFoodInfo catFoodInfo[NMAXPRODUCTS] = { {0} };
	struct ReportData reportData[NMAXPRODUCTS] = { {0} };
	
	openingMessage(NMAXPRODUCTS);
	for (i = 0; i < NMAXPRODUCTS; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i + 1);
		reportData[i] = calculateReportData(catFoodInfo, i);
	}
	displayCatFoodHeader();
	
	for (i = 0; i < NMAXPRODUCTS; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].price, &catFoodInfo[i].weight, catFoodInfo[i].calories);
	}

	displayReportHeader();

	indexPro1 = 0;
	indexPro2 = 1;
	indexPro3 = 2;
	if (reportData[indexPro1].costPerServ < reportData[indexPro2].costPerServ && reportData[indexPro1].costPerServ < reportData[indexPro3].costPerServ)
	{
		index = indexPro1;
		cheapestProduct = 1;
	}
	else if (reportData[indexPro2].costPerServ < reportData[indexPro3].costPerServ)
	{
		index = indexPro2;
		cheapestProduct = 2;
	}
	else
	{
		index = indexPro3;
		cheapestProduct = 3;
	}
	
    displayReportData(reportData, cheapestProduct);
	
	displayFinalAnalysis(catFoodInfo[index]);
}



/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Ashwin Anand
	ID     : 152042206
	Email  : aanand24@myseneca.ca
	Section: IPC144 NDD
*/

// ----------------------------------------------------------------------------
// defines/macros
#define NMAXPRODUCTS 3
#define GRAMS 64
#define POUNDSTOKG 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int sku;
	double price;
	int calories;
	double weight;
};

struct ReportData
{

	int proSku;
	double proPrice;
	int calsPerServ;
	double weightInLbs;
	double weightInKgs;
	int weightInGrams;
	double totalServings;
	double costPerServ;
	double costPerCals;
};
// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* categoryAddress);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* categoryAddress);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int nProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kgs);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* grams);


// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kgs, int* grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalGrams, double* totalServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* proPrice, const double* totalServings, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* proPrice, const double* totalCalories, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo[], const int sequenceNum);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData[], const int cheapestPro);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo);
// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);

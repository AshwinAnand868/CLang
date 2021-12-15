/*
	==================================================
	workshop #2 (part-1):
	==================================================
	name   : Ashwin Anand
	id     : 152042206
	email  : aanand24@myseneca.ca
	section: IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    double dollars, dueamount;
    int quantity;
    printf("Change Maker Machine\n");
    printf("====================\n");

    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &dollars);
    printf("\n");

    quantity = dollars / 2.00;

    dueamount = dollars - (2.00 * quantity);

    printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", quantity, dueamount);

    quantity = dueamount / 1.00;

    dueamount = dueamount - quantity;

    printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", quantity, dueamount);

    quantity = dueamount / 0.25;

    dueamount = dueamount - (0.25 * quantity);

    printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quantity, dueamount);
    printf("\n");

    printf("Machine error! Thank you for letting me keep $%.2lf!\n", dueamount);
    

    return 0;

}
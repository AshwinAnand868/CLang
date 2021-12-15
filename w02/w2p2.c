/*
	==================================================
	workshop #2 (part-2):
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
	
	double dollars, serviceFee, roundedUpFee, dispensedBalance, fractionCents, dueDollars;
	int quantity, tooniesInCents, cents, dueCents, looniesInCents, quartersInCents, dimesInCents, nickelsInCents, penniesInCents;
	printf("Change Maker Machine\n");
	printf("====================\n");

	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &dollars);
	

	serviceFee = dollars * 0.05;

	roundedUpFee = (int) serviceFee + 0.5;

	printf("Service fee (5.0 percent): %.2lf\n" , roundedUpFee );

	dispensedBalance = dollars - roundedUpFee;

	printf("Balance to dispense: $%.2lf\n", dispensedBalance);
	printf("\n");

	fractionCents =  dispensedBalance * 100;

	

	cents = fractionCents + 0.5;

	tooniesInCents = 200;
	
	quantity = cents / tooniesInCents;

	dueCents = cents % tooniesInCents;

	dueDollars = (double)dueCents / 100;
	
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", quantity, dueDollars);

	
	
	looniesInCents = 100;

	quantity = dueCents / looniesInCents;

	dueCents = dueCents % looniesInCents;

	dueDollars = (double)dueCents / 100;

	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", quantity, dueDollars);

	quartersInCents = 25;

	quantity = dueCents / quartersInCents;

	dueCents = dueCents % quartersInCents;

	dueDollars = (double)dueCents / 100;

	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quantity, dueDollars);

	dimesInCents = 10;

	quantity = dueCents / dimesInCents;

	dueCents = dueCents % dimesInCents;

	dueDollars = (double)dueCents / 100;

	printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", quantity, dueDollars);

	nickelsInCents = 5;

	quantity = dueCents / nickelsInCents;

	dueCents = dueCents % nickelsInCents;

	dueDollars = (double)dueCents / 100;

	printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", quantity, dueDollars);

	penniesInCents = 1;

	quantity = dueCents / penniesInCents;

	dueCents = dueCents % penniesInCents;

	dueDollars = (double)dueCents / 100;

	printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", quantity, dueDollars);
	printf("\n");
	printf("All coins dispensed!\n");



	return 0;
}
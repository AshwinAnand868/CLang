/* -------------------------------------------
Name: Ashwin Anand
Student number: 152042206
Email: aanand24@myseneca.ca
Section: IPC144NDD
Date: 30-6-2021 
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"



void redundancyEliminator(int selector, struct Contact* contact, char yesNo)
{
    if (yesNo == 'y' || yesNo == 'Y')
    {
         switch (selector)
         {
         case 1:
            printf("Please enter the contact's middle initial(s): ");
            scanf("%6[^\n]%*c", contact->name.middleInitial);
            break;

         case 2:
             do
             {
                 printf("Please enter the contact's apartment number: ");
                 scanf("%d%*c", &contact -> address.apartmentNumber);
             } while (contact->address.apartmentNumber < 1);
             break;
         case 3:
             printf("Please enter the contact's cell phone number: ");
             scanf("%10[^\n]%*c", contact -> numbers.cell);
             break;
         case 4:
             printf("Please enter the contact's home phone number: ");
             scanf("%10[^\n]%*c", contact->numbers.home);
             break;
         case 5:
             printf("Please enter the contact's business phone number: ");
             scanf("%10[^\n]%*c", contact->numbers.business);
             break;
         }

     }
}

void getName(struct Name* name, struct Contact* contact)
{  
    char yesNo;
    int selector = 1;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf("%c%*c", &yesNo);
   
    redundancyEliminator(selector, contact, yesNo);

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
 }

void getAddress(struct Address *address, struct Contact* contact)
{
    char yesNo;
    int selector = 2;
   
    do {
        printf("Please enter the contact's street number: ");
        scanf("%d%*c", &address->streetNumber);
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);
    

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf("%c%*c", &yesNo);

    redundancyEliminator(selector, contact, yesNo);

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);

     printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

void getNumbers(struct Numbers *numbers, struct Contact* contact)
{
    char yesNo;
    int selector = 3;
   

    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf("%c%*c", &yesNo);

    redundancyEliminator(selector, contact, yesNo);
   

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf("%c%*c", &yesNo);
    selector++;

    redundancyEliminator(selector, contact, yesNo);
   
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c%*c", &yesNo);
    selector++;

    redundancyEliminator(selector, contact, yesNo);

}
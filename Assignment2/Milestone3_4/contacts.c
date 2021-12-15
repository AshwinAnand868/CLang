//==============================================
// Name:           Ashwin Anand
// Student Number: 152042206
// Email:          aanand24@myseneca.ca
// Section:        NDD
// Date:           7-23-2021
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contacts.h"
#include"contactHelpers.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+



// getName:
void getName(struct Name* name)
{
    int returnedVal;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    returnedVal = yes();

    if (returnedVal == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else
    {
        name->middleInitial[0] = '\0';
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    int returnedInt;

    printf("Please enter the contact's street number: ");
    returnedInt = getInt();


    while (returnedInt < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        returnedInt = getInt();

    }
    address->streetNumber = returnedInt;

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");

    returnedInt = yes();

    if (returnedInt == 1)
    {
        printf("Please enter the contact's apartment number: ");
        returnedInt = getInt();

        while (returnedInt < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            returnedInt = getInt();
        }
    }
    address->apartmentNumber = returnedInt;


    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);

    clearKeyboard();
 
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int returnedInt;

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    returnedInt = yes();
  


    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    if (returnedInt == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);

    }
    else
    {
        numbers->home[0] = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");

    returnedInt = yes();


    if (returnedInt == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else
    {
        numbers->business[0] = '\0';
    }
}

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{

    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}

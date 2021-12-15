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
#include<string.h>
#include"contactHelpers.h"
#include"contacts.h"
#include<ctype.h>

#define MAXCONTACTS 5
#define CELLNUMSIZE 11
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+



// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}
// pause: Empty function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();

}


// getInt: Empty function definition goes here:
int getInt(void)
{
    char nuLine;
    int anInteger;

    scanf("%d%c", &anInteger, &nuLine);
    while (nuLine != '\n')
    {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &anInteger, &nuLine);
    }

    return anInteger;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
    int anInteger;
    // printf("Enter 'seneca', then '99', then '501', then '250' > ");
    anInteger = getInt();

    while (anInteger < min || anInteger > max)
    {

        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        anInteger = getInt();
    }

    return anInteger;

}


// yes: Empty function definition goes here:
int yes(void)
{
    int flag = 0;
    char enteredCharacter, nuLine;

    scanf("%c%c", &enteredCharacter, &nuLine);
    flag = 1;
    while (flag)
    {
        if (enteredCharacter == 'Y' || enteredCharacter == 'N' || enteredCharacter == 'y' || enteredCharacter == 'n')
        {
            if (nuLine == '\n')
            {
                flag = 0;
            }
            else
            {
                clearKeyboard();

                printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
                scanf("%c%c", &enteredCharacter, &nuLine);
            }
        }
        else
        {
            clearKeyboard();

            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            scanf("%c%c", &enteredCharacter, &nuLine);
        }
    }

    if (enteredCharacter == 'y' || enteredCharacter == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


// menu: Empty function definition goes here:
int menu(void)
{
    int anInteger;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");


    anInteger = getIntInRange(0, 6);

    return anInteger;
}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
    struct Contact contacts[MAXCONTACTS] = {
      {
        { "Rick",{'\0'}, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444" }
      },
      {
        { "Maggie","R.", "Greene" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9051112222", "9052223333", "9053334444" }
      },
      {
        { "Morgan", "A.", "Jones" },
       { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
        { "7051112222", "7052223333", "7053334444" }
      },
      {
        { "Sasha", {'\0'}, "Williams" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        {"9052223333", "9052223333", "9054445555" }
      }
    };

      
    int returnedValue, selection, keepDisplaying;

    keepDisplaying = 1;
    while (keepDisplaying)
    {
        selection = menu();

        switch (selection)
        {
        case 1:
            printf("\n");
            displayContacts(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 2:
            printf("\n");
            addContact(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 3:
            printf("\n");
            updateContact(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 4:
            printf("\n");
            deleteContact(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 5:
            printf("\n");
            searchContacts(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 6:
            printf("\n");
            sortContacts(contacts, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 0:
            printf("\n");
            printf("Exit the program? (Y)es/(N)o: ");
            returnedValue = yes();
            printf("\n");
            if (returnedValue == 1)
            {

                keepDisplaying = 0;
                printf("Contact Management System: terminated\n");

            }
            break;


        }

    }
}




// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1, i, flag;

    while (needInput == 1)
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        flag = 1;
        if (strlen(phoneNum) == 10)
        {

            for (i = 0; phoneNum[i] != '\0' && flag; i++)
            {
                if (isdigit(phoneNum[i]) == 0)
                {
                    flag = 0;
                   
                    printf("Enter a 10-digit phone number: ");
                   
                   
                }
                
            }
            if (phoneNum[i] == '\0')
                needInput = 0;
          
        }
        else
        {
           
            printf("Enter a 10-digit phone number: ");
          
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i, returnVal;
   
    returnVal = -1;
    for (i = 0; i < size; i++)
    {
        if (strcmp(cellNum, contacts[i].numbers.cell)==0)
        {
            returnVal = i;
        }
    }

    return returnVal;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d", count);
    printf("\n");
  
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

    
    if (contact->name.middleInitial[0] == '\0')
    {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    else
    {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    if (contact->numbers.cell > 0)
    {
        printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    }
    if (contact->address.apartmentNumber > 0)
    {
        printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
    }
    else
    {
        printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
    }
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    int i, validContacts;
   
    displayContactHeader();

    validContacts = 0;
    for (i = 0; i < size; i++)
    {
       
        if (contacts[i].numbers.cell[0] > 0)
        {
            
            displayContact(&contacts[i]);
            validContacts++;
        }
    }
    displayContactFooter(validContacts);

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    int index;
    char cellNum[CELLNUMSIZE];
    printf("Enter the cell number for the contact: ");
  getTenDigitPhone(cellNum);

   index = findContactIndex(contacts, size, cellNum);
   if (index != -1)
   {
       printf("\n");
       displayContact(&contacts[index]);
   }
   else
   {
       printf("*** Contact NOT FOUND ***\n");
   }

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
    
   int index =  findContactIndex(contacts, size, "");
   if (index != -1)
   {
       getContact(&contacts[index]);
       printf("--- New contact added! ---\n");
   }
   else
   {
       printf("*** ERROR: The contact list is full! ***\n");
   }

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    char cellNum[CELLNUMSIZE];
    int index, returnedVal;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);
    if (index != -1)
    {
        printf("\n");
        printf("Contact found:");
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
      returnedVal = yes();

       if (returnedVal == 1)
       {
          getName(&contacts[index].name);
       }

      
       printf("Do you want to update the address? (y or n): ");

       
       returnedVal = yes();
       if (returnedVal == 1)
       {
           getAddress(&contacts[index].address);
       }
       
       printf("Do you want to update the numbers? (y or n): ");
       
       returnedVal = yes();
       if (returnedVal == 1)
       {
           getNumbers(&contacts[index].numbers);
       }
      
       printf("--- Contact Updated! ---\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
    char cellNum[CELLNUMSIZE];
    int index, returnedVal;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index != -1)
    {
        printf("\n");
        printf("Contact found:");
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");

        printf("CONFIRM: Delete this contact? (y or n): ");
        returnedVal = yes();

        if (returnedVal == 1)
        {
          contacts[index].numbers.cell[index] = '\0';
          printf("--- Contact deleted! ---\n");
        }

        
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
    int i,j;
    struct Contact temp;
    for(i = size-1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0)
            {
                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
               
            }
        }
    }

    printf("--- Contacts sorted! ---\n");
}
 
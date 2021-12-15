//==============================================
// Name:           Ashwin Anand
// Student Number: 152042206
// Email:          aanand24@myseneca.ca
// Section:        IPC144NDD
// Date:           
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
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
   while(nuLine!= '\n')
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
            if(nuLine == '\n')
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
    int returnedValue, selection, keepDisplaying;
 
    keepDisplaying = 1;
    while (keepDisplaying)
    {
        selection = menu();

        switch (selection)
        {
        case 1:
            printf("\n");
            printf("<<< Feature 1 is unavailable >>>\n");
            printf("\n");
            pause();
             printf("\n");
            break;
        case 2:
            printf("\n");
            printf("<<< Feature 2 is unavailable >>>\n");
            printf("\n");
            pause();
             printf("\n");
            break;
        case 3:
            printf("\n");
            printf("<<< Feature 3 is unavailable >>>\n");
            printf("\n");
            pause();
             printf("\n");
            break;
        case 4:
            printf("\n");
            printf("<<< Feature 4 is unavailable >>>\n");
            printf("\n");
            pause();
            printf("\n");
            break;
        case 5:
            printf("\n");
            printf("<<< Feature 5 is unavailable >>>\n");
            printf("\n");
            pause();
             printf("\n");
            break;
        case 6:
            printf("\n");
            printf("<<< Feature 6 is unavailable >>>\n");
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

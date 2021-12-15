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

// Structure type Name declaration (Milestone 1)
struct Name {
    char firstName[31];
    char middleInitial[6];
    char lastName[36];
};

// Structure type Address declaration (Milestone 1)
// Place your code here...
struct Address {
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration (Milestone 1)
// Place your code here...
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration (Milestone 3)
// Place your code here...
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

//Gets an int, a struct object of type Contact, a character as parameters and do all the common tasks required in every function of contacts.c file
void redundancyEliminator(int selector, struct Contact*, char yesNo);


// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *, struct Contact* );

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *, struct Contact* );

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *, struct Contact* );


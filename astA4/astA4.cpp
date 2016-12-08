/*
FILE : astA4.cpp
PROJECT : Advanced Software Techniques - Assignment 4 
PROGRAMMER : Alex Guerro & Kevin Medeiros
DESCRIPTION : This  program will ask a user to enter in details to input into an address book. It will then check the details against another source file that validates the input.
DATE : March 13, 2014
*/


//include files
#include"astA4.h"



int main(void)
{
	//variables initialized
	addressBook newData[10] = {0};
	char userInput[Size6] = {NULL};
	char correctedFormat[Size5] = {NULL};
	int count = 0;
	int retCode = 0;
	int flow = 1;
	long int phoneNumber = 0;
	int exit = 0;
	int length = 0;
	int entry = 1;

	//group distinguish string
	printf("   FOURTH    \n");
	printf("++++++++++++\n\n");
	//this following section of code instructs the user on the program functionality
	printf("INSTRUCTIONS:\n\n");
	printf("Please enter the required information in the specified format into \nthe ");
	printf("address book as each field appears.\n\n");
	printf("To exit early, press enter in the Name field.\nTo skip to a phone number entry, press enter when the address field appears.\n");
	printf("To skip the subsequent fields, press enter when the field appears.\n");
	
	//while loop to get 10 entries for storage
	while( count < maxEntries )
	{	
		//case statement to control program flow
		switch(flow)
		{
			//This section of code asks the user for a first 
			//and last name entry into the addressbook.
			//flush the stdin and call fgets for user input.
			//if user enters carriage return, exit program,
			//if user enters invalid input, loop around and get new data,
			//otherwise, pass userInput to function for validation
		case 1:	printf("\nFirst and Last Name (Format: Xxxxx Xxxxx): ");
			fflush(stdin);
			fgets( userInput, Size6, stdin );
			if(userInput[0] == '\n')
			{
				//set exit to 'a' flag to exit the program
				exit = 'a';
				break;//quit the loop
			}
			else
			{
				//validate the name
				retCode = validateName( userInput );
				if(retCode == 1)
				{
					//if input is invalid, break out of the loop and return
					//to get new data
					printf("Incorrect format\n");
					flow = 1;
					break;
				}
				else
				{
					//pass validated string to function for formatting
					correctNameFormat( userInput, correctedFormat );
					//copy formatted string to struct array
					strcpy(newData[count].name, correctedFormat);
				}
				printf("\n");
			}
			//This section of code asks the user for an address entry into the addressbook.
			//flush the stdin and call fgets for user input.
			//if user enters carriage return, skip to case 6 for phone number input.
			//if user enters invalid input, loop around and get new data,
			//otherwise, pass userInput to function for validation
		case 2:	printf("Enter an Address (Format: 000 Street Street-type direction \nor AAA-00 Street Street-type direction): ");
			fflush(stdin);
			fgets( userInput, Size5, stdin );
			if( userInput[0] == '\n' )
			{
				//user hit enter, skip entry
				printf("\n");
				flow = 6;
				break;
			}
			else
			{
				//validate the address
				retCode = validateAddress( userInput );
				if(retCode == 1)
				{
					//if input is invalid, flush the keyboard, break out of the loop and return
					//to get new data
					printf("Incorrect format\n");
					fflush(stdin);
					flow = 2;
					break;
				}
				//pass validated string to function for formatting
				correctAddressFormat(userInput, correctedFormat);
				//copy formatted string to struct array
				strcpy(newData[count].address, correctedFormat);
				printf("\n");
			}
			//This section of code asks the user for a city entry into the addressbook.
			//flush the stdin and call fgets for user input.
			//if user enters invalid input, loop around and get new data 
			//otherwise, pass userInput to function for validation
		case 3:	printf("Enter a City (Format: Xxxxxxx): ");
			fflush(stdin);
			fgets( userInput, Size6, stdin );
			//validate the address
			if(userInput[0] == '\n')
			{
				//if input is empty, flush the keyboard, break out of the loop and return
				//to get new data
				fflush(stdin);
				flow = 4;
				printf("\n");
				break;//quit the loop
			}
			retCode = validateCity( userInput );
			if(retCode == 1)
			{
				//if input is invalid, flush the keyboard, break out of the loop and return
				//to get new data
				printf("Incorrect format\n");
				fflush(stdin);
				flow = 3;
				break;
			}
			else
			{
				//pass validated string to function for formatting
				correctCityFormat(userInput, correctedFormat);
				//copy formatted string to struct array
				strcpy(newData[count].city, correctedFormat);
				printf("\n");
			}
			//This section of code asks the user for a province entry into the addressbook.
			//flush the stdin and call fgets for user input.
			//if user enters invalid input, loop around and get new data 
			//otherwise, pass userInput to function for validation
		case 4:	printf("Enter a Province (Format: XX): ");
			//if user enters  carriage return, exit program
			//otherwise, scan input for letters only
			fflush(stdin);
			fgets( userInput, Size2, stdin );
			if(userInput[0] == '\n')
			{
				//if input is empty, flush the keyboard, break out of the loop and return
				//to get new data
				fflush(stdin);
				printf("\n");
				flow = 5;
				break;//quit the loop
			}
			//validate the province
			retCode = validateFormatProvince( userInput, correctedFormat );
			if(retCode == 1)
			{
				//if input is invalid, flush the keyboard, break out of the loop and return
				//to get new data
				printf("Incorrect format\n");
				flow = 4;
				fflush(stdin);
				break;
			}
			else if(retCode == 0)
			{
				//copy formatted string to struct array
				strcpy(newData[count].province, userInput);
				printf("\n");
			}
			//This section of code asks the user for a postal code entry into the addressbook.
			//flush the stdin and call fgets for user input.
			//if user enters invalid input, loop around and get new data 
			//otherwise, pass userInput to function for validation
		case 5:	printf("Enter a Postal Code (Format: A0A 0A0): ");
			//if user enters  carriage return, exit program
			//otherwise, scan input for letters only
			fflush(stdin);
			fgets( userInput, Size2, stdin );
			if(userInput[0] == '\n')
			{
				//if input is empty, flush the keyboard, break out of the loop and return
				//to get new data
				fflush(stdin);
				flow = 6;
				printf("\n");
				break;//quit the loop
			}
			//validate the prostal code
			retCode = validateCorrectFormatPostalCode( userInput );
			if(retCode == 1)
			{
				//if input is invalid, flush the keyboard, break out of the loop and return
				//to get new data
				printf("Incorrect format\n");
				fflush(stdin);
				flow = 5;
				break;
			}
			else
			{
				//copy formatted string to struct array
				strcpy(newData[count].postCode, userInput);
				printf("\n");
			}
			//This section of code asks the user for a phone number entry into the addressbook.
			//flush the stdin and call fgets for user input.
			//if the user presses the enter key, this set is skipped
			//if user enters invalid input, loop around and get new data 
			//otherwise, pass userInput to function for validation
		case 6:	printf("Enter a Phone Number (Format: xxx-xxx-xxxx): ");
			//if user enters  carriage return, exit program
			//otherwise, scan input for letters only
			fflush(stdin);
			fgets( userInput, Size3, stdin );
			if(userInput[0] == '\n')
			{
				exit = 'b';
				break;//user chose to skip
			}
			//validate the phone number
			retCode = validatePhoneNumber( userInput );
			if(retCode == 1)
			{
				//if input is invalid, flush the keyboard, break out of the loop, display an error message and return
				//to get new data
				printf("Incorrect format\n");
				fflush(stdin);
				flow = 6;
				break;
			}
			else
			{
				//copy formatted string to struct array set exit to b
				//to loop around and get the next entry
				strcpy(newData[count].phoneNumber, userInput);
				printf("\n");
				exit = 'b';
				break;
			}
		}
		//if user chose to exit early, break out of loop
		//display entries if any
		if(exit == 'a')
		{
			break;
		}
		//an entry has completed successfully, move to the next element to store the info.
		//return to the first case (Name entry), flush the keyboard and reset exit to 0.
		if(exit == 'b')
		{
			++count;//next entry
			flow = 1;
			fflush(stdin);
			userInput[0] = '\0';
			exit = 0;
			system("cls");
		}
	}
	//clear the screen
	system("cls");
	//display all entries into the addressbook, 3 entries at a time
	displayEntries(newData);

	return 0;
}



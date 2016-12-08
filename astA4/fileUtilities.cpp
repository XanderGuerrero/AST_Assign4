/*
FILE : fileUtilities.cpp
PROJECT : Advanced Software Techniques - Assignment 4 
PROGRAMMER : Alex Guerro & Kevin Medeiros
DESCRIPTION : This  source file contains all of the input validation. It will verify that all of the entered information is formatted and entered in correct. Such as name, address, postal code and province etc.
DATE : March 13, 2014
*/

#include"astA4.h"

// FUNCTION : validateName
// DESCRIPTION :
// This function will take in a name as a char and check to see if it is a valid name.
// PARAMETERS :
// char userInput: This passes in a char that contains a name.
// RETURNS : This function returns a status code depending on whether the input is valid or not.
int validateName( char userInput[] )
{
	//variables initialized
	int retCode = 0;
	char c = NULL;
	int length = 0;
	int count = 0;
	int spaceCount = 0;

	//remove the '\n' character from the string
	for( count = 0; count < (length = strlen( userInput )); ++count )
	{
		if( userInput[count] == '\n' )
		{
			userInput[count] = '\0';
		}
	}

	while( kOne )
	{
		//if first character is a space or punctuation, display error message and get new data
		if(isspace( userInput[0]) > 0 || ispunct(userInput[0]) > 0)
		{
			retCode = 1;
			break;
		}
		//if input data is larger than specified, display error message and get new data
		if((length = strlen(userInput)) >  Size4)
		{
			retCode = 1;
			break;
		}
		else
		{
			//if all is good, break out of the loop
			break;
		}
	}
	//check for punctuation and spaces inside string, if puncutation detected, display error message and get new data
	//if more than one space is detected (ex. firstname_lastname), display error message and get new data
	for( count = 0; count < (length = strlen(userInput)); ++count )
	{
		if((isalpha(userInput[count]) == 0) && ((userInput[count]) != '\'') && ((userInput[count]) != '-') && ((userInput[count]) != '.') && ((userInput[count]) != '`') && ((userInput[count]) != ' '))
		{
			retCode = 1;
			break;
		}
		//increment space count when detected and check if the next element is a letter, if not set retcode to 1
		if(isspace(userInput[count]) > 0)
		{
			++spaceCount;
			if(isalpha(userInput[++count]) == 0)
			{
				retCode = 1;
			}
		}
		//if punctuation is detected, display error message and get new data
		if(ispunct(userInput[count]) > 0)
		{
			retCode = 1;
			break;
		}
	}
	//if space count is 1....
	if(spaceCount == 1)
	{
	
	}
	//if more than once space or less than one space is detected, a proper format name was not entered
	//display error message and get new data
	else if(spaceCount > 1 || spaceCount < 1)
	{
		retCode = 1; //improper data entry
	}
	//retcode determines the program flow, retCode 1 means improper entry and retCode 0 means everything is fine.
	return retCode;
}

// FUNCTION : correctNameFormat
// DESCRIPTION :
// This function will take in a name as a char and check to see if it is written in the correct format.
// PARAMETERS :
// char userInput: This passes in a char that contains a name.
// char correctedFormat : This passes in a char with the corrected name format
// RETURNS : This function returns a status code depending on whether the input is valid or not.

void correctNameFormat(char userInput[], char correctedFormat[])
{
	//variables initialized
	int c = 0;
	char buffer1[30] = {NULL};
	char *ptr = NULL;

	//use strtok to separate the input data into tokens
	if((ptr = strtok(userInput, " ")) != NULL )
	{
		strcpy( correctedFormat, ptr );
		//while there are more tokens to get....
		while(ptr != NULL )
		{
			if((ptr = strtok(NULL, " ")) != NULL )
			{
				//if there are no more tokens, break
				break;
			}
		}
		//place a space at the end of the string, capitalize the first character
		strcat( correctedFormat, " ");
		c = toupper( correctedFormat[0] );
		correctedFormat[0] = c;

		//place the token gotten by ptr and place into buffer1
		//capitalize the first character
		strcpy( buffer1, ptr );
		c = toupper( buffer1[0] );
		buffer1[0] = c;
		
		//append buffer1 to corrected string,
		//coversion complete
		strcat( correctedFormat, buffer1 );
	}
}

// FUNCTION : validateAddress
// DESCRIPTION :
// This function will take in an address as a char and check to see if it is a valid address
// PARAMETERS :
// char userInput: This passes in a char that contains a name.
// RETURNS : This function returns a status code depending on whether the input is valid or not.

int validateAddress( char userInput[] )
{
	//variables initialized
	int retCode = 0;
	char c = NULL;
	int length = 0;
	int count = 0;
	int spaceCount = 0;
	int value = 0;
	char* addressOfLastCharacter = NULL;
	char *p = NULL;

	//remove the '\n' from fgets and replace with NULL
	for( count = 0; count < (length = strlen( userInput )); ++count )
	{
		if( userInput[count] == '\n' )
		{
			userInput[count] = '\0';
		}
	}

	//get the last element of the user input,
	//if it's a period(.), replace with NULL
	c = strlen(userInput);
	p = userInput;
	addressOfLastCharacter = p + (c - 1);
	if(*addressOfLastCharacter == '.')
	{
		userInput[(c-1)] = '\0';
	}

	while( kOne )
	{
		//if a dash is detected in the user input.....
		if(strchr(userInput, '-') != NULL)
		{
			//if the first, second and third characters are not letters, display error msg, get new data
			if((isalpha(userInput[0]) == 0) && (isalpha(userInput[1]) == 0) && (isalpha(userInput[2]) == 0))
			{
				retCode = 1;
				break;
			}
			//if the third, fourth and fifth elements are not a dash and digits respectively, display error message and get new data 
			if((userInput[3] != '-') && (isdigit(userInput[4]) == 0) || (isdigit(userInput[5]) == 0))
			{
				retCode = 1;
				break;
			}
			//if element 4 is not either a digit and a letter, display error message and get new data
			if((isdigit(userInput[4]) == 0) && (isalpha(userInput[4]) == 0))
			{
				retCode = 1;
				break;
			}
			//the first element is a space, display error and get new data
			if(isspace(userInput[0]) > 0 || ispunct(userInput[0]) > 0)
			{
				retCode = 1;
				break;
			}
			break;
		}
		//if a dash is not detected.....
		if(strchr(userInput, '-') == NULL)
		{
			//if the first, second elements are not digits, display error message and get new data 
			if((isdigit(userInput[0]) == 0) || (isdigit(userInput[1]) == 0))
			{
				retCode = 1;
				break;
			}
			//if element 3 is not either a digit or space, display an error message and get new data
			if((isdigit(userInput[2]) == 0) && (isspace(userInput[2]) == 0) && (ispunct(userInput[2])))
			{
				retCode = 1;
				break;
			}
			//if element 3 is not a space, dash, or digit, display error message and get new data (format xxx-aa)
			if((userInput[3] != ' ') && (userInput[3] != '-') && (isdigit(userInput[3]) == 0) && (isalpha(userInput[3]) == 0))
			{
				retCode = 1;
				break;
			}
			//if element 4 is not either a digit or letter, display error message and get new data
			if((isdigit(userInput[4]) == 0) && (isalpha(userInput[4]) == 0))
			{
				retCode = 1;
				break;
			}
			//the first element is a space or punctuation, display error and get new data
			if(isspace(userInput[0]) > 0 || ispunct(userInput[0]) > 0)
			{
				retCode = 1;
				break;
			}
			break;
		}
	}
	while(kOne)
	{
			//the length of the string is larger than the specified size, display an error report and get new data
			if( (length = strlen(userInput)) >  Size5)
			{
				retCode = 1;
				break;
			}
			else
			{
				//count the number of spaces
				for(count = 0; count < Size5; ++count )
				{
					if(isspace(userInput[count]) > 0)
					{
						++spaceCount;
					}
				}
				//if the space count is larger than 3 or less than
				if(spaceCount > 3 || spaceCount < 2)
				{
					retCode = 1; //improper data entry
					break;
				}
				//if the number of spaces is 2 or 3, everything is good
				if(spaceCount == 3 || spaceCount == 2)
				{
					break;//correct number of items
				}
			}
	}
	//reset count to 0
	count = 0;
	//if numbers or punctuation are detected after the 6th element, 
	//display error message and get new data
	for(count = 7; count < (length = strlen(userInput)); ++count)
	{
		//if numbers and punctuation are detected...
		if((isdigit(userInput[count]) != 0) || (ispunct(userInput[count]) > 0))
		{
			retCode = 1;
			break;
		}
	}
	//return retCode, 1 means improper data, get new data
	return retCode;
}

// FUNCTION : correctAddressFormat
// DESCRIPTION :
// This function will take in an address as a char and check to see if it is written in the correct format.
// PARAMETERS :
// char userInput: This passes in a char that contains an address
// char correctedFormat : This passes in a char with the corrected address format
// RETURNS : This function returns a status code depending on whether the input is valid or not.
void correctAddressFormat(char userInput[], char correctedFormat[])
{
	//variables initialized
	int i = 0;
	int c = 0;
	char *ptr = NULL;
	char addressStorage[kThree][Size5] = {""};
	int length = 0;
	int j = 0;

	//use strtok to get tokens from string
	if((ptr = strtok(userInput, " ")) != NULL )
	{
		strcpy( correctedFormat, ptr );
		while(ptr != NULL )
		{
			if((ptr = strtok(NULL, " ")) != NULL )
			{
				//stor each string inside a new multi array element
				strcpy(addressStorage[i], ptr);
				++i;
			}
		}
		//reset i
		i = 0;
		//if a dash is detected.......
		if(strchr(userInput, '-') != NULL)
		{
			while( j < kThree )
			{
				//capitalize the letters in the AAA-XX format
				c = toupper( correctedFormat[j] );
				correctedFormat[j] = c;
				++j;
			}
		}

		while(i < kThree)
		{
			//capitalize the first letters in each string
			//and add them to corrected string 
			strcat( correctedFormat, " ");
			c = toupper( addressStorage[i][0] );
			addressStorage[i][0] = c;
			strcat( correctedFormat, addressStorage[i] );
			++i;
		}
	}
}

// FUNCTION : validateCity
// DESCRIPTION :
// This function will take in a city as a char and check to see if it is a valid city.
// PARAMETERS :
// char userInput: This passes in a char that contains a city.
// RETURNS : This function returns a status code depending on whether the input is valid or not.
int validateCity( char userInput[] )
{
	//variables initialized
	int retCode = 0;
	char c = NULL;
	int length = 0;
	int count = 0;
	int spaceCount = 0;
	int size = 0;

	//remove the newline from fgets and replace with NULL
	for( count = 0; count < (length = strlen( userInput )); ++count )
	{
		if( userInput[count] == '\n' )
		{
			userInput[count] = '\0';
		}
	}
	//reset count to 0
	count = 0;

	while( kOne )
	{
		//if a spce or puncutation are detected as the first characters, display error message and get new data
		if(isspace( userInput[0]) > 0 || ispunct(userInput[0]) > 0)
		{
			retCode = 1;
			break;
		}
		//if the user input is too large, display error message and get new data
		if((length = strlen(userInput)) >  Size5)
		{
			retCode = 1;
			break;
		}
		else
		{
			break;
		}
	}
	//check for punctuation inside string
	for( count = 0; count < length; ++count )
	{
		//if something other than a letter, ', -, . or `
		//display error message and get new data
		if((isalpha(userInput[count]) == 0) && ((userInput[count]) != '\'') && ((userInput[count]) != '-') && ((userInput[count]) != '`') && ((userInput[count]) != ' '))
		{
			retCode = 1;
			break;
		}
		//if first element is punctuation, display error message and get new data
		if( ispunct( userInput[0]) > 0 )
		{
			retCode = 1;
			break;
		}
		//if first element is a space character
		if(isspace(userInput[count]) > 0)
		{
			++spaceCount;
		}
	}
	//if the space count is greater than 1, display error message and get new data
	if(spaceCount > 1)
	{
		retCode = 1; //improper data entry
	}

	return retCode;
}

// FUNCTION : correctCityFormat
// DESCRIPTION :
// This function will take in a city as a char and check to see if it is written in the correct format.
// PARAMETERS :
// char userInput: This passes in a char that contains a city.
// char correctedFormat : This passes in a char with the corrected city format
// RETURNS : This function returns a status code depending on whether the input is valid or not.
void correctCityFormat(char userInput[], char correctedFormat[])
{
	//variables initialized
	int i = 0;
	int length = 0;
	int c = 0;
	char *ptr = NULL;

	//use strtok to break string into tokens, 2 max
	if((ptr = strtok(userInput, " ")) != NULL )
	{
		strcpy( correctedFormat, ptr );
		strcat(correctedFormat, " ");
		while(ptr != NULL )
		{
			if((ptr = strtok(NULL, " ")) != NULL )
			{
				strcat(correctedFormat, ptr);
				++i;
			}
		}
		//reset i to 0
		i = 0;
		//if first character of the strings is lower case, it is converted to upper case
		for(i = 0; i < (length = strlen(correctedFormat)); ++i)
		{
			if((c = islower(correctedFormat[0])) > 0)
			{
				c = toupper(correctedFormat[0]);
				correctedFormat[0] = c;
			}
			if(isspace(correctedFormat[i]) > 0)
			{
				++i;
				c = toupper(correctedFormat[i]);
				correctedFormat[i] = c;
			}
		}

	}
}

// FUNCTION : validateFormatProvince
// DESCRIPTION :
// This function will take in a province as a char and check to see if it is written in the correct format.
// PARAMETERS :
// char userInput: This passes in a char that contains a province.
// char correctedFormat : This passes in a char with the corrected province format
// RETURNS : This function returns a status code depending on whether the input is valid or not.

int validateFormatProvince( char userInput[], char correctedFormat[])
{
	//variables used in function intialized
	int retCode = 0;
	int count = 0;
	int length = 0;
	int c = 0;
	//contains the province abbreviations for comparisons
	char provinces[kloopControl][kNumCharacters] = {"AB", "BC", "MB", "NB", "NL", "NT", "NS", "NU", "ON", "PE", "QC", "SK", "YT"};
	
	//remove the newline from fgets and replace with NULL
	for( count = 0; count < (length = strlen( userInput )); ++count )
	{
		if( userInput[count] == '\n' )
		{
			userInput[count] = '\0';
		}
	}
	//reset count
	count = 0;
	//convert all characters to upper case
	for(count = 0; count < (length = strlen(userInput)); ++count)
	{
		c = toupper(userInput[count]);
		userInput[count] = c;
	}
	while( kOne )
	{
		//if elements 0 and 1 are spaces or punctuation, display error message and get new data
		if(isspace( userInput[0]) > 0 || isspace(userInput[1]) > 0 || ispunct(userInput[0]) > 0 || ispunct(userInput[1]) > 0)
		{
			retCode = 1;
			break;
		}
		//if numbers are detected in elements 0 and 1
		if((isdigit(userInput[0]) != 0) || (isdigit(userInput[1]) != 0))
		{
			retCode = 1;
			break;
		}
		//if userInput is too large, display error message and get new data
		if( (length = strlen(userInput)) >=  Size1)
		{
			retCode = 1;
			break;
		}
		else
		{
			break;
		}
	}
	//compare user input with array containing the province abbreviations
	for( count = 0; count < kloopControl; ++count)
	{
		//only if a match is found, the string is copied over to corrected format string
		//and breaks out of the loop
		if(strcmp(userInput, provinces[count]) == 0)
		{
			strcpy(correctedFormat, userInput);
			break;
		}
	}
	//if loop completed, no match was found
	if(count == kloopControl)
	{
		retCode = 1;
	}
	return retCode;
}

// FUNCTION : validateCorrectFormat               Code
// DESCRIPTION :
// This function will take in a name as a char and check to see if it is a valid postalcode as well as if it is in the correct format.
// PARAMETERS :
// char userInput: This passes in a char that contains a postal code.
// RETURNS : This function returns a status code depending on whether the input is valid or not.
int validateCorrectFormatPostalCode( char userInput[] )
{
	//variables initialized
	int isAlphaCharacter = 0;
	int isNumber = 0;
	int length = 0;
	int count = 0;
	int retCode = 0;
	int c = 0;

	//remove the newline from fgets and replace with NULL
	for( count = 0; count < (length = strlen( userInput )); ++count )
	{
		if( (userInput[count]) == '\n' )
		{
			userInput[count] = '\0';
		}
	}
	//reset count to 0
	count = 0;
	//if spaces are detected after element 3, display error message and get new data
	for(count = 4; count < (length = strlen(userInput)); ++count)
	{
		if(isspace(userInput[count]) != 0)
		{
			retCode = 1;
			break;
		}
	}
	//reset count
	count = 0;

	while(kOne)
	{
		//when you reach null, break out of loop
		if(userInput[count] == '\0')
		{
			break;
		}
		//if the user input order is number, letter, number, it is inccorect format, display error message and get new data
		if((isdigit(userInput[0]) > 0) || (isalpha(userInput[1]) > 0) || (isdigit(userInput[2]) > 0))
		{
			retCode = 1;
			break;
		}
		//if the first characters are w and z, display error message and get new data
		if(userInput[0] == 'W' || userInput[0] == 'Z' )
		{
			retCode = 1;
			break;
		}
		//convert all letters to upper case
		for(count = 0; count < (length = strlen(userInput)); ++count)
		{
			c = toupper(userInput[count]);
			userInput[count] = c;
		}
		//if user entered restricted characters, display error message and get new data
		for(count = 0; count < (length = strlen(userInput)); ++count)
		{
			if(userInput[count] == 'D' || userInput[count] == 'F' || userInput[count] == 'I' || userInput[0] == 'o' || userInput[0] == 'Q' || userInput[0] == 'W' )
			{
				retCode = 1;
				break;
			}
			//count number of letters detected, should be 3
			if(isalpha(userInput[count]) > 0)  
			{
				++isAlphaCharacter;
				++count;
			}
			else
			{
				//else display error, get new data
				retCode = 1;
				break;
			}
			//count number of letters detected, should only be 1
			if(isspace(userInput[count]) > 0)
			{
				++count;
			}
			//count number of digits detected, should be 3
			if((isdigit(userInput[count]) > 0))
			{
				++isNumber;
			}
			else
			{
				//else display error, get new data
				retCode = 1;
				break;
			}
		}
		//if there are 3 letters and 3 numbers, we're all good! Otherwise, display error message and get new data
		if((isAlphaCharacter != kThree) && (isNumber != kThree))
		{
			retCode = 1;
			break;
		}
	}

	return retCode;
}

// FUNCTION : validatePhoneNumber
// DESCRIPTION :
// This function will take in a name as a char and check to see if it is a valid phone number
// PARAMETERS :
// char userInput: This passes in a char that contains a phone number
// RETURNS : This function returns a status code depending on whether the input is valid or not.
int validatePhoneNumber( char userInput[] )
{
	//variables initialized
	int length = 0;
	int count = 0;
	int retCode = 0;
	int spaces = 0;
	int dashes = 0;

	//if the length is too large, display error get new data
	if( length = strlen(userInput) > Size3)
	{
		retCode = 1;
	}
	//remove the newline from fgets and replace with NULL
	for( count = 0; count < (length = strlen( userInput )); ++count )
	{
		if( userInput[count] == '\n' )
		{
			userInput[count] = '\0';
		}
	}
	//if input contains letters or spaces, display error message and get new data
	if(	isspace(userInput[0]) > 0 || isspace(userInput[1]) > 0 || 
		ispunct(userInput[0]) > 0 || ispunct(userInput[1]) > 0 ||
		isspace(userInput[2]) > 0 || isspace(userInput[4]) > 0 || 
		ispunct(userInput[2]) > 0 || ispunct(userInput[4]) > 0 ||
		isspace(userInput[5]) > 0 || isspace(userInput[6]) > 0 || 
		ispunct(userInput[5]) > 0 || ispunct(userInput[6]) > 0 ||
		isspace(userInput[8]) > 0 || isspace(userInput[9]) > 0 || 
		ispunct(userInput[8]) > 0 || ispunct(userInput[9]) > 0 ||
		isspace(userInput[10]) > 0 || isspace(userInput[11]) > 0 || 
		ispunct(userInput[10]) > 0 || ispunct(userInput[11]) > 0)
	{
		retCode = 1;
	}
	//count how many dashes and spaces there are
	for(count = 3; count < Size3; ++count)
	{
		if(( userInput[count] == '-' ))
		{
			++dashes;
		}
		if(( userInput[count] == ' '))
		{
			++spaces;
		}
	}
	// if there are not 2 dashes...
	if(dashes != 2)
	{
		//if there are not 2 spaces
		if(spaces != 2)
		{
			//display error, get new data
			retCode = 1;
		}
		
	}
	
	//if any alpha characters are detected, get new data
	for(count = 0; count < userInput[count]; ++count)
	{
		if((isalpha(userInput[count]) > 0))
		{
			retCode = 1;
			break;
		}
	}
	//check for spaces in all elements except element 3 and 7
	for(count = 0; count < (length = userInput[count]); ++count)
	{
		if( count == 3 || count == 7 )
		{
			++count;
		}
		if((isspace(userInput[count]) > 0))
		{
			retCode = 1;
			break;
		}
	}
	//if the count is not 12, too many digits
	if(count != 12)
	{
		retCode = 1;// must have 12 digits xxx-xxx-xxxx
	}

	return retCode;
}


// FUNCTION : displayEntries
// DESCRIPTION :
// This function will allow the user to display the previously entered address book entries.
// PARAMETERS :
// addressBook newData[] : This passes in a new address book entry
// RETURNS : This function returns the contents of the list.

void displayEntries( addressBook newData[] )
{
	//initialize variables
	int count = 0;
	int i = 0;
	addressBook *ptr = NULL;
	int entry = 1;
	int j = 0;

	//loop through the struct array containing the address book information
	for(count = 0; count < 10; ++count)
	{
		//print one entry at a time
		for( i = 0; i < 1; ++i)
		{
			if(count == 9)
			{
				printf("Entry: %d\n", entry);
				printf("NAME:		%s\nADDRESS:	%s\nCITY:		%s\nPROVINCE:	%s\nPOSTAL CODE:	%s\nPHONE NUMBER:	%s\n", newData[count].name, newData[count].address, newData[count].city, newData[count].province, newData[count].postCode, newData[count].phoneNumber);
				break;
			}
			printf("Entry: %d\n", entry++);
			printf("NAME:		%s\nADDRESS:	%s\nCITY:		%s\nPROVINCE:	%s\nPOSTAL CODE:	%s\nPHONE NUMBER:	%s\n", newData[count].name, newData[count].address, newData[count].city, newData[count].province, newData[count].postCode, newData[count].phoneNumber);
			printf("\n");
			//increment the count and look at the next element in the struct array, if the next element is empty
			//exit the loop, otherwise decrease the count and continue
			if(strcmp(newData[++count].name,"") == 0 )
			{
				break;
			}
			else
			{
				--count;
			}
			//after 3 entries are displayed, wait for user input to move on to the next page of entries
			//flush the stdin and clear the screen
			if(count == 2 || count == 5 || count == 8)
			{
				int j = 0;
				getch();
				fflush(stdin);
				for (j = 0; j < 23; ++j)
				{
					printf(" \n");
				}
			}
		}
		//if next element was empty, break out of the loop, done displaying entries
		if(strcmp(newData[count].name,"") == 0 )
		{
			break;
		}
		//if the 10th entry is about to be displayed, scroll the screen to shift the text to the top
		//of the screen
		if(count == 9)
		{
			for (j = 0; j < 17; ++j)
			{
				printf(" \n");
			}
			break;
		}
	}
}
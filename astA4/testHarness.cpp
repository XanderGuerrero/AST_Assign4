#include"astA4.h"



int main(void)
{
	addressBook newData[10] = {0};
	int count = 0;
	int retCode = 0;
	char userInput[60] = "hja";
	char correctedFormat[60] = "";
	int value = 0;
	//0
	value = strlen(userInput);
		//	++count;//2
	/*retCode = validateName( userInput );
	correctNameFormat(userInput,correctedFormat);
	printf("%s\n", correctedFormat);*/

	//retCode =validateAddress( userInput );
	//correctAddressFormat(userInput, correctedFormat);
	//printf("%s\n", correctedFormat);

	//retCode = validateCity( userInput );
	//correctCityFormat( userInput,  correctedFormat);
	//printf("%s\n", correctedFormat);

	////retCode = validateFormatProvince( userInput, correctedFormat);
	////printf("%s\n", correctedFormat);

	//retCode =validateCorrectFormatPostalCode( userInput );
	//printf("%s\n", correctedFormat);

	//retCode =validatePhoneNumber( userInput );
	//printf("%s\n", correctedFormat);

	//0
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//1
		strcpy(newData[count].name, "Angie L"); 
		strcpy(newData[count].address, "354 vica st s");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-123-1234");
	
		//2

			strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//3
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//4
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//5
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//6
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//7
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//8
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//
		strcpy(newData[count].name, "Alex Guerrero"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");
			++count;//10
		strcpy(newData[count].name, "A G"); 
		strcpy(newData[count].address, "354 victoria street south");
		strcpy(newData[count].city, "Kitchener");
		strcpy(newData[count].province, "On");
		strcpy(newData[count].postCode, "N2M 3A5");
		strcpy(newData[count].phoneNumber, "519-749-0749");

		displayEntries(newData);

    return 0;
}


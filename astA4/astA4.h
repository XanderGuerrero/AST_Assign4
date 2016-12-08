/*
FILE : astA4.h
PROJECT : Advanced Software Techniques - Assignment 4 
PROGRAMMER : Alex Guerro & Kevin Medeiros
DESCRIPTION : This  header file contains all of the libraries, constants, prototypes and structs; necessary to allow the program to run.
DATE : March 13, 2014
*/


//include files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
using namespace std;

//disables a warning to allow the use of depricated functions
#pragma warning(disable: 4996)


//Constants used to avoid the presence of magic numbers.
#define kOne 1
#define kThree 3
#define Size1 3
#define Size2 8
#define Size3 13
#define Size4 30
#define Size5 60
#define Size6 62
#define maxEntries 10
#define kloopControl 13
#define kNumCharacters 40

//Struct definition for the address book entries.
typedef struct addressBook
{
	char name[Size4];
	char address[Size5];
	char city[Size5];
	char province[Size1];
	char postCode[Size2];
	char phoneNumber[Size3];
}addressBook;

// Prototypes
int validateName( char input[] );
void correctNameFormat(char nameInput[], char correctedFormat[]);
int validateAddress( char userInput[] );
void correctAddressFormat(char userInput[], char correctedFormat[]);
int validateCity( char userInput[] );
void correctCityFormat(char userInput[], char correctedFormat[]);
int validateFormatProvince( char userInput[], char correctedFormat[] );
int validateCorrectFormatPostalCode( char userInput[] );
int validatePhoneNumber( char userInput[] );
void displayEntries( addressBook newData[] );
// STL_linked_list_console_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <climits> // INT_MIN, INT_MAX
#include <ctime>
#include <stdlib.h>
#include <list>
#include "STLLinkedListClass.h"

using namespace std;

//struct petRecord {
//	int recordNumber;
//	char* ownerLastName;	// Since the possible length of a string is unknown, a pointer must be used
//	char* ownerFirstName;	// because the size of the pointer is known. Memory is then allocated to
//	char* petName;			// to store the string and a pointer to the string is stored here in the linked
//	char* petType;			// list node.
//	int birthMonth;		// change dates from strings to integers to be use with the date calculator.
//	int birthDay;
//	int birthYear;
//	int apptMonth;
//	int apptDay;
//	int apptYear;
//};

int main()
{
	int recordNumber = 0;
	string ownerLastName;
	string ownerFirstName;
	string petName;
	string petType;
	int birthMonth, birthDay, birthYear;
	int apptMonth, apptDay, apptYear;

	string ownerLastNameSearch;

	ifstream infile;
	string inFileName;

	STLLinkedListClass LL;
	int i;

	/*******************************/
	// Open the pet record data file for reading
	inFileName = "PetDataBase.txt";

	infile.open(inFileName);
	if (infile.is_open()) {
		cout << "Read file:\t" << inFileName << endl;
	}
	else {
		cout << "Read file does NOT exit" << endl;
	}


	/*****************************************/
	// initializing the list from the text file.
	LL.initSTLLinkedList(infile);


	/************************************************/
	// Traverse the list to print out the last names.
	LL.displaySTLLastNames();



	/*******************************************/
	// remove records
	for (i = 0; i < 5; i++) {
		if (i == 0) ownerLastNameSearch = "Ibarra";
		if (i == 1) ownerLastNameSearch = "Mercer";
		if (i == 2) ownerLastNameSearch = "Mejia";
		if (i == 3) ownerLastNameSearch = "Mcintosh";
		if (i == 4) ownerLastNameSearch = "Nunez";

		LL.deleteSTLEntry(ownerLastNameSearch);

	}

	LL.displaySTLLastNames();



	/*******************************************/
	// Add records
	for (i = 0; i < 5; i++) {
		if (i == 0) {
			recordNumber = 50;
			ownerLastName = "LastName_00";
			ownerFirstName = "Firstname_00";
			petName = "PetName_00";
			petType = "PetType_00";
			birthMonth = 01;
			birthDay = 01;
			birthYear = 2000;
			apptMonth = 01;
			apptDay = 01;
			apptYear = 2024;

			LL.addSTLEntry(recordNumber,
				ownerLastName, ownerFirstName,
				petName, petType,
				birthMonth, birthDay, birthYear,
				apptMonth, apptDay, apptYear);
		}
			
		if (i == 1) {
			recordNumber = 51;
			ownerLastName = "LastName_01";
			ownerFirstName = "Firstname_01";
			petName = "PetName_01";
			petType = "PetType_01";
			birthMonth = 02;
			birthDay = 02;
			birthYear = 2002;
			apptMonth = 02;
			apptDay = 02;
			apptYear = 2024;

			LL.addSTLEntry(recordNumber,
				ownerLastName, ownerFirstName,
				petName, petType,
				birthMonth, birthDay, birthYear,
				apptMonth, apptDay, apptYear);
		}

		if (i == 2) {
			recordNumber = 52;
			ownerLastName = "LastName_02";
			ownerFirstName = "Firstname_02";
			petName = "PetName_02";
			petType = "PetType_02";
			birthMonth = 03;
			birthDay = 03;
			birthYear = 2003;
			apptMonth = 03;
			apptDay = 03;
			apptYear = 2024;

			LL.addSTLEntry(recordNumber,
				ownerLastName, ownerFirstName,
				petName, petType,
				birthMonth, birthDay, birthYear,
				apptMonth, apptDay, apptYear);
		}

		if (i == 3) {
			recordNumber = 53;
			ownerLastName = "LastName_03";
			ownerFirstName = "Firstname_03";
			petName = "PetName_03";
			petType = "PetType_03";
			birthMonth = 04;
			birthDay = 04;
			birthYear = 2004;
			apptMonth = 04;
			apptDay = 04;
			apptYear = 2024;

			LL.addSTLEntry(recordNumber,
				ownerLastName, ownerFirstName,
				petName, petType,
				birthMonth, birthDay, birthYear,
				apptMonth, apptDay, apptYear);
		}

		if (i == 4) {
			recordNumber = 54;
			ownerLastName = "LastName_04";
			ownerFirstName = "Firstname_04";
			petName = "PetName_04";
			petType = "PetType_04";
			birthMonth = 05;
			birthDay = 05;
			birthYear = 2005;
			apptMonth = 05;
			apptDay = 05;
			apptYear = 2024;

			LL.addSTLEntry(recordNumber,
				ownerLastName, ownerFirstName,
				petName, petType,
				birthMonth, birthDay, birthYear,
				apptMonth, apptDay, apptYear);
		}

	}

	LL.displaySTLLastNames();




    std::cout << "Hello World!\n";
}


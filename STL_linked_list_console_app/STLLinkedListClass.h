#pragma once

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
using namespace std;

#define DEBUG_initLinkedList 0
#define DEBUG_displayLinkedList 0
#define DEBUG_deleteLinkedList 0
#define DEBUG_findRecordByLastName 0
#define DEBUG_displaySingleNode 0
#define DEBUG_addNewRecord 0
#define DEBUG_deleteRecordByLastName 0


/******************************************************************/
// strings need to be defined as char pointers, as opposed to string pointers, to
// be compatible with the string class functions used to manipulate the strings.

struct petRecord {
	int recordNumber;
	char* ownerLastName;	// Since the possible length of a string is unknown, a pointer must be used
	char* ownerFirstName;	// because the size of the pointer is known. Memory is then allocated to
	char* petName;			// to store the string and a pointer to the string is stored here in the linked
	char* petType;			// list node.
	int birthMonth;		// change dates from strings to integers to be use with the date calculator.
	int birthDay;
	int birthYear;
	int apptMonth;
	int apptDay;
	int apptYear;

	struct petRecord* next;
	struct petRecord* previous;
};





class STLLinkedListClass
{
private:
	int recordNumber;
	string ownerLastName;
	string ownerFirstName;
	string petName;
	string petType;
	int birthMonth, birthDay, birthYear;
	int apptMonth, apptDay, apptYear;

	// marks the first node in the linked list for all functions.
	struct petRecord* headPtr;
	// this is used to point to the present node in the linked list
	// in several functions.
	struct petRecord* currentPtr;
	// This marks the next node in the linked list for some functions.
	struct petRecord* nextPtr;
	struct petRecord* previousPtr;
	// This is used to point to a new node when creating the linked list.
	struct petRecord* newPtr;
	// This is used to point to the record that is to be deleted.
	struct petRecord* deletePtr;

	int maxRecordNumber = 0;
	bool matchFound = false;

	// STL variables
	// STL list class. Set up an object, STLLinkedList for petRecord.
	list<petRecord> STLLinkedList;
	list<petRecord> STLHeadIterator;
	list<petRecord> STLIterator;


	int i;


public:

	/************************************************/
/************************************************/
	void initSTLLinkedList(ifstream& infileC) {

		// infileC is the pointer to the input file created in main (infile).
		// Get first line (e.g., record) from text file.
		// The string variables read strings from the text file.
		infileC >> recordNumber;
		infileC >> ownerLastName;
		infileC >> ownerFirstName;
		infileC >> petName;
		infileC >> petType;
		infileC >> birthMonth;
		infileC >> birthDay;
		infileC >> birthYear;
		infileC >> apptMonth;
		infileC >> apptDay;
		infileC >> apptYear;

#if DEBUG_initLinkedList == 1
		// Verify that the data has been read in from the file correctly.
		cout << "from infile: recordNumber: \t" << recordNumber << endl;
		cout << "from infile: ownerLastName: \t" << ownerLastName << endl;
		cout << "from infile: ownerFirstName: \t" << ownerFirstName << endl;
		cout << "from infile: petName: \t\t" << petName << endl;
		cout << "from infile: petType: \t\t" << petType << endl;
		cout << "from infile: birthMonth: \t" << birthMonth << endl;
		cout << "from infile: birthDay: \t" << birthDay << endl;
		cout << "from infile: birthYear: \t" << birthYear << endl;
		cout << "from infile: apptMonth: \t" << apptMonth << endl << endl;
		cout << "from infile: apptDay: \t" << apptDay << endl << endl;
		cout << "from infile: apptYear: \t" << apptYear << endl << endl;
#endif


		// I do not think that headPtr needs to be created in main. All of the linked list
		// functions may be done in this class, so headPtr can be stored in the class and
		// not in main. I do not think that main needs access to headPtr to provide it to 
		// another function. I'll will see.
		// create first node of linked list to store the first record from the file
		headPtr = (struct petRecord*)malloc(sizeof(struct petRecord));
		headPtr->previous = NULL;
		headPtr->next = NULL;
		currentPtr = headPtr;
		newPtr = headPtr;


		/****************************************************/
		// creat struct record and fill with data from infile
		// There has to be a better way to detect the end of the data file, but
		// I will figure that out later.
		while (recordNumber != 99999) {

			// Put the data into the node of the linked list.
			// Store the recordNumber in the linked list node.
			currentPtr->recordNumber = recordNumber;

			// track the maximum recordNumber for when it is time to add additional records
			if (recordNumber > maxRecordNumber) maxRecordNumber = recordNumber;

			// Store the ownerLastName in the linked list node.
			// The null character is not added to the string when read from the file, so it needs to be added here.
			// the length() was put into i just so I could see that the length of the string was correct.
			// The location of the allocated memory is stored in the char pointer in the node.
			// The string read from the file is then copied into the allocated memory.
			// The printf is used to verify that the char pointer in the node points to the correct string.
			ownerLastName.push_back('\0');
			//i = ownerLastName.length();
			currentPtr->ownerLastName = (char*)malloc(ownerLastName.length() + 1);
			ownerLastName.copy(currentPtr->ownerLastName, ownerLastName.length());

			ownerFirstName.push_back('\0'); // You need to add null character at the end to delimited the string.
			//i = ownerFirstName.length();
			currentPtr->ownerFirstName = (char*)malloc(ownerFirstName.length() + 1);
			ownerFirstName.copy(currentPtr->ownerFirstName, ownerFirstName.length());

			petName.push_back('\0'); // You need to add null character at the end to delimited the string.
			//i = petName.length();
			currentPtr->petName = (char*)malloc(petName.length() + 1);
			petName.copy(currentPtr->petName, petName.length());

			petType.push_back('\0'); // You need to add null character at the end to delimited the string.
			//i = petType.length();
			currentPtr->petType = (char*)malloc(petType.length() + 1);
			petType.copy(currentPtr->petType, petType.length());

			currentPtr->birthMonth = birthMonth;
			currentPtr->birthDay = birthDay;
			currentPtr->birthYear = birthYear;

			currentPtr->apptMonth = apptMonth;
			currentPtr->apptDay = apptDay;
			currentPtr->apptYear = apptYear;

#if DEBUG_initLinkedList == 1
			// Print out data from currentPtr to see that data was properly inserted into the node.
			printf("%s\t%d\n", "currentPtr->recordNumber:", currentPtr->recordNumber);
			printf("%s\t%s\n", "currentPtr->ownerLastName:", currentPtr->ownerLastName);
			printf("%s\t%s\n", "currentPtr->ownerFirstName:", currentPtr->ownerFirstName);
			printf("%s\t\t%s\n", "currentPtr->petName:", currentPtr->petName);
			printf("%s\t\t%s\n", "currentPtr->petType:", currentPtr->petType);
			printf("%s\t\t%s\n", "currentPtr->birthMonth", currentPtr->birthMonth);
			printf("%s\t\t%s\n", "currentPtr->birthDay", currentPtr->birthDay);
			printf("%s\t\t%s\n", "currentPtr->birthDay", currentPtr->birthDay);
			printf("%s\t%s\n", "currentPtr->ApptMonth:", currentPtr->ApptMonth);
			printf("%s\t%s\n", "currentPtr->ApptDay:", currentPtr->ApptDay);
			printf("%s\t%s\n", "currentPtr->ApptYear:", currentPtr->ApptYear);
#endif

			// Get next line from infile
			infileC >> recordNumber;
			infileC >> ownerLastName;
			infileC >> ownerFirstName;
			infileC >> petName;
			infileC >> petType;
			infileC >> birthMonth;
			infileC >> birthDay;
			infileC >> birthYear;
			infileC >> apptMonth;
			infileC >> apptDay;
			infileC >> apptYear;

#if DEBUG_initLinkedList == 1
			// Verify that the data has been read in from the file correctly.
			cout << "from infile: recordNumber: \t" << recordNumber << endl;
			cout << "from infile: ownerLastName: \t" << ownerLastName << endl;
			cout << "from infile: ownerFirstName: \t" << ownerFirstName << endl;
			cout << "from infile: petName: \t\t" << petName << endl;
			cout << "from infile: petType: \t\t" << petType << endl;
			cout << "from infile: birthMonth: \t" << birthMonth << endl;
			cout << "from infile: birthDay: \t" << birthDay << endl;
			cout << "from infile: birthYear: \t" << birthYear << endl;
			cout << "from infile: ApptMonth: \t" << ApptMonth << endl << endl << endl;
			cout << "from infile: ApptDay: \t" << ApptDay << endl << endl << endl;
			cout << "from infile: ApptYear: \t" << ApptYear << endl << endl << endl;
#endif

			// See if the end of the file has been reached.
			if (recordNumber != 99999) {
				// The end of the text file has not been reached, so create a new node
				// in the linked list then go back to the start of the while loop to 
				// populate the new node.

				// create next node struct to store the data from file record
				newPtr = (struct petRecord*)malloc(sizeof(struct petRecord));
				newPtr->next = NULL;
				currentPtr->next = newPtr;
				newPtr->previous = currentPtr;
				currentPtr = newPtr;
			}
			else {
				/* If the end of the test file has been reached, then the next in the current node has
				already been set to NULL, so there is nothing more to do because the end of the linked
				list has already been marked. */
				// This else statement does not need to be here, but it is here so I can catch the end of
				// the file in the debugger.

#if DEBUG_initLinkedList == 1
				printf("%s\t%d\n\n", "recordNumber:", recordNumber);
				printf("%s\t%d\n\n", "maxRecordNumber:", maxRecordNumber);
#endif

			}

		}
	}



};


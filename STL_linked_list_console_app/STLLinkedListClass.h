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

	string ownerLastNameSearch;


	// make a link object
	list<petRecord> STLLinkedList;
	list<petRecord>::iterator STLIterator;

	// make a node for passing data to a container in the list
	struct petRecord node;



	int maxRecordNumber = 0;
	bool matchFound = false;

	int i;


public:

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


		/****************************************************/
		// creat struct record and fill with data from infile
		// There has to be a better way to detect the end of the data file, but
		// I will figure that out later.
		while (recordNumber != 99999) {

			// Put the data into the node structure.
			node.recordNumber = recordNumber;

			// track the maximum recordNumber for when it is time to add additional records
			if (recordNumber > maxRecordNumber) maxRecordNumber = recordNumber;

			// Store the ownerLastName in the node structure.
			// The null character is not added to the string when read from the file, so it needs to be added here.
			// The location of the allocated memory for strings is stored in the char pointer in the node.
			// The string read from the file is then copied into the allocated memory.
			ownerLastName.push_back('\0');
			node.ownerLastName = (char*)malloc(ownerLastName.length() + 1);
			ownerLastName.copy(node.ownerLastName, ownerLastName.length());

			ownerFirstName.push_back('\0');
			node.ownerFirstName = (char*)malloc(ownerFirstName.length() + 1);
			ownerFirstName.copy(node.ownerFirstName, ownerFirstName.length());

			petName.push_back('\0');
			node.petName = (char*)malloc(petName.length() + 1);
			petName.copy(node.petName, petName.length());

			petType.push_back('\0');
			node.petType = (char*)malloc(petType.length() + 1);
			petType.copy(node.petType, petType.length());

			node.birthMonth = birthMonth;
			node.birthDay = birthDay;
			node.birthYear = birthYear;

			node.apptMonth = apptMonth;
			node.apptDay = apptDay;
			node.apptYear = apptYear;

			// Put the information from the node structure into the list
			STLLinkedList.push_back(node);

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
		}
	}

	/*****************************************/
	void displaySTLLastNames() {
		// Traverse the list to print out the last names.
		i = 0;
		STLIterator = STLLinkedList.begin();
		for (STLIterator; STLIterator != STLLinkedList.end(); STLIterator++) {
			ownerLastName = STLIterator->ownerLastName;

			cout << STLIterator->ownerLastName;
			if (ownerLastName.length() > 7) cout << "\t";
			else cout << "\t\t";

			if (i > 5) {
				cout << endl;
				i = 0;
			}
			else {
				i++;
			}
		}

		cout << endl << endl;
	}

	/*****************************************/
	void deleteSTLEntry(string LastName) {
		STLIterator = STLLinkedList.begin();
		while (STLIterator != STLLinkedList.end()) {
			ownerLastName = STLIterator->ownerLastName;
			if (ownerLastName.compare(LastName) == 0) {
				STLLinkedList.erase(STLIterator);
				STLIterator = STLLinkedList.end();
			}
			else
				STLIterator++;
		}

	}

	/*****************************************/
	void addSTLEntry(int rNumber, 
		string oLastName, string oFirstName, 
		string pName, string pType, 
		int bMonth, int bDay, int bYear,
		int aMonth, int aDay, int aYear) 
	{

		node.recordNumber = rNumber;

		oLastName.push_back('\0');
		node.ownerLastName = (char*)malloc(oLastName.length() + 1);
		oLastName.copy(node.ownerLastName, oLastName.length());

		oFirstName.push_back('\0');
		node.ownerFirstName = (char*)malloc(oFirstName.length() + 1);
		oFirstName.copy(node.ownerFirstName, oFirstName.length());

		pName.push_back('\0');
		node.petName = (char*)malloc(pName.length() + 1);
		pName.copy(node.petName, pName.length());

		pType.push_back('\0');
		node.petType = (char*)malloc(pType.length() + 1);
		pType.copy(node.petType, pType.length());

		node.birthMonth = bMonth;
		node.birthDay = bDay;
		node.birthYear = bYear;

		node.apptMonth = aMonth;
		node.apptDay = aDay;
		node.apptYear = aYear;

		STLLinkedList.push_back(node);

	}



};


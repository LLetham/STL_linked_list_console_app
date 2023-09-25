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
//#include "STLLinkedListClass.h"
using namespace std;

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

	//struct petRecord* next;
	//struct petRecord* previous;
};




int main()
{
	int recordNumber = 0;
	string ownerLastName;
	string ownerFirstName;
	string petName;
	string petType;
	int birthMonth, birthDay, birthYear;
	int apptMonth, apptDay, apptYear;

	ifstream infile;
	string inFileName;

	struct petRecord node;

	list<petRecord> STLLinkedList;
	list<petRecord>::iterator STLHeadIterator;
	list<petRecord>::iterator STLIterator;


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


	while (recordNumber != 99999) {

		infile >> recordNumber;
		infile >> ownerLastName;
		infile >> ownerFirstName;
		infile >> petName;
		infile >> petType;
		infile >> birthMonth;
		infile >> birthDay;
		infile >> birthYear;
		infile >> apptMonth;
		infile >> apptDay;
		infile >> apptYear;

		node.recordNumber = recordNumber;

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


		STLLinkedList.push_front(node);

		std::cout << "Hello World!\n";

	}

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

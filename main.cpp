/*
Project: Printer Queue extra credit example.
By: Michael Cooper
started: 3/21
date last modified: 3/22/14
Compiler: Microsoft Visual Studio 2012 v110
File Type: main driver file for the Printer queue
*/
#ifndef main_cpp
#define main_cpp

#include <iostream>
#include <string>
#include "printerQueue.h"

using namespace std;

void testCase1();
void testCase2();

int main()
{
	int choice = -1;

	while(choice != 0)
	{
		cout << "\nWhich test case would you like to try?";
		cout << "\nPlease enter an integer: 1, 2, or 0 for exit" << endl;
		cin >> choice;

		if(choice == 1)
			testCase1();
		else if(choice == 2)
			testCase2();
		else if(choice != 0)
			cout << "invalid choice." << endl;
	}

	cout << "\nThanks!" << endl;

	return 0;
}

void testCase1()
{
	Printer Queue;

	Queue.insertAJob(3, "Hello");
	Queue.insertAJob(30, "Points!");
	Queue.insertAJob(21, "things");
	Queue.insertAJob(6, "world");
	Queue.insertAJob(18, "the");
	Queue.insertAJob(9, "Yay");
	Queue.insertAJob(24, "get");
	Queue.insertAJob(15, "do");
	Queue.insertAJob(27, "the");
	Queue.insertAJob(12, "sports");


	Queue.display();

	Queue.printAJob();

	Queue.display();

	Queue.printAJob();

	Queue.display();

	Queue.insertAJob(33, "!");
	Queue.insertAJob(56, "!");
	Queue.display();
	Queue.displayPrintJobs();
}

void testCase2()
{
	Printer Queue;

	Queue.insertAJob(15, "ludacris");
	Queue.insertAJob(10, "see");
	Queue.insertAJob(4, "hoo");
	Queue.insertAJob(17, "night?");
	Queue.insertAJob(8, "you");
	Queue.insertAJob(12, "display");
	Queue.insertAJob(2, "Boo");
	Queue.insertAJob(16, "that");
	Queue.insertAJob(7, "Did");
	Queue.insertAJob(31, "last?");

	Queue.display();

	Queue.printAJob();

	Queue.display();

	Queue.printAJob();

	Queue.display();

	Queue.insertAJob(32, "\nThe thing with Arsenal is,");
	Queue.insertAJob(64, "they always try to walk it in.");
	Queue.display();
	Queue.displayPrintJobs();
}


#endif

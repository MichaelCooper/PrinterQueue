/*
Project: Printer Queue extra credit example.
By: Michael Cooper
started: 3/21
date last modified: 3/22/14
Compiler: Microsoft Visual Studio 2012 v110
File Type: main driver file for the Printer queue
*/
#ifndef mainZhang_cpp
#define mainZhang_cpp

#include <iostream>
#include <string>
#include "ReadyQueue.cpp"

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
  ReadyQueue q1;

  q1.insertProc(5);
  q1.insertProc(1);
  q1.insertProc(8);
  q1.insertProc(11);

  q1.removeHighestProc();
  q1.displayQueue();

  q1.removeHighestProc();
  q1.displayQueue();

  q1.insertProc(3);
  q1.insertProc(7);
  q1.insertProc(2);
  q1.insertProc(12);
  q1.insertProc(9);

  q1.removeHighestProc();
  q1.displayQueue();

  q1.removeHighestProc();
  q1.displayQueue();

  q1.removeHighestProc();
  q1.displayQueue();

  q1.removeHighestProc();
  q1.displayQueue();

  q1.removeHighestProc();
  q1.displayQueue();

  q1.removeHighestProc();
  q1.displayQueue();

  q1.removeHighestProc();
  q1.displayQueue();
}

void testCase2()
{

}


#endif

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
#include "ReadyQueue.h"
#include <time.h>
#include <sys/time.h>

using namespace std;

void testCase1();
void testCase2();

int main()
{
  srand (time(NULL)); //seed the rand function

  int choice = -1;

	cout << "Michael Cooper and James Erickson" << endl;

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

  q1.insertProc(5,false,true);
  q1.insertProc(1,false,true);
  q1.insertProc(8,false,true);
  q1.insertProc(11,false,true);
  q1.displayQueue();
  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.insertProc(3,false,true);
  q1.displayQueue();
  q1.insertProc(7,false,true);
  q1.displayQueue();
  q1.insertProc(2,false,true);
  q1.displayQueue();
  q1.insertProc(12,false,true);
  q1.displayQueue();
  q1.insertProc(9,false,true);

  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.removeHighestProc(true);
  q1.displayQueue();

  q1.removeHighestProc(true);
  q1.displayQueue();
}

void testCase2()
{
  ReadyQueue q1;
  timeval t1,t2,tr; //creating instances of a struct that can get the result from time of day through pass by reference


  for (int i = 0; i < 10; i++)
    {
      while (!q1.insertProc( (rand() % 21), true, true)) {} //insert a random process Id from 0 to 20 without repetition, select random priorities with repetition
    }

  q1.displayQueue();

  gettimeofday(&t1,NULL);

  for (int i = 0; i < 999999; i++)
    {//turn off messages here
      q1.removeHighestProc(false);
      while (!q1.insertProc( (rand() % 21), true, false)) {} //insert a random process Id from 0 to 20 without repetition, select random priorities with repetition
    }

  gettimeofday(&t2,NULL);
  timersub(&t1,&t2,&tr);


  cout << "\n Test took: "  << tr.tv_usec  << " microseconds." << endl; //timersub dereferences arguments
  q1.displayQueue(); //The final content
}


#endif

/*
Project: Printer Queue extra credit example.
By: Michael Cooper
started: 3/21/14
date last modified: 3/22/14
Compiler: Microsoft Visual Studio 2012 v110
File Type: Implimentation file for the Printer queue
*/
#ifndef printerQueue_cpp
#define printerQueue_cpp

#include <iostream>
#include <string>
#include "printerQueue.h"

using namespace std;


//constructor sets position = 1 and gives Queue it's size
Printer::Printer()
{
	Queue[SIZE];
	slot = 1;//start at 1 in order to avoid the 0th slot. Makes division possible
	Message blank;
	blank.message = "";
	blank.priority = -1;

	for(int i = 0; i < SIZE; i++)//initialize the array
		Queue[i] = blank;

}

//sends in the new message to be added
void Printer::insertAJob(int priorityIn, std::string messageIn)
{
	Message toAdd;
	toAdd.priority = priorityIn;
	toAdd.message = messageIn;

	//add the item
	Queue[slot] = toAdd;
	int location = slot;//starting location for the new item being added

	//while the priority is higher than that of it's parent, swap the two
	while((toAdd.priority < Queue[location / 2].priority) && (location != 1))
	{
//echo		cout << "\nSwapping with the root." << endl;
		Queue[location] = Queue[location / 2];//swap the root
		Queue[location / 2] = toAdd;
		location = (location / 2);
	}
	slot++;//incriment the next empty slot
}


//removes the front job and displays it's priority number
void Printer::printAJob()
{
	cout << "Printing [ " << Queue[1].priority << " ]" << endl;
	reHeapify();
}

//re-Heapiy the array after a job has been printed.
void Printer::reHeapify()
{
	slot--;//decriment slot because tree is shrinking by 1
	Queue[1] = Queue[slot];//move the lowest data member to the top
	Queue[slot].priority = -1;//reset priority for the last slot
	int loc = 1; //current location of the lase element in the array

	while(loc != slot -1)//ensures that at most the item will return to the end
	{
		//insure that we don't fall off the tree
		if(((loc * 2) > slot)||(Queue[loc*2].priority == -1))
			return;
		if((Queue[loc].priority > Queue[loc*2].priority) || 
			(Queue[loc].priority > Queue[loc*2+1].priority))
		{
			Message messageHolder = Queue[loc];//pull the current message
			//See which one has a higher priority and swap
			if(Queue[loc*2].priority < Queue[loc*2+1].priority)
			{
				if(Queue[loc*2].priority == -1)
					return;
				cout << "\nSwapping " << Queue[loc].priority 
					 << " with the left child" << endl;
				Queue[loc] = Queue[loc*2];
				Queue[loc*2] = messageHolder;
				loc = (loc * 2);
				continue;//check the loop again
			}
			else
			{
				if(Queue[(loc*2)+1].priority == -1)
					return;
				cout << "\nSwapping " << Queue[loc].priority 
					 << " with the right child" << endl;
				Queue[loc] = Queue[loc*2+1];
				Queue[loc*2+1] = messageHolder;
				loc = (loc * 2+1);
				continue;//check the loop again
			}

		}
		else
			return;//exit if at correct priority
	}
}

//displays everythign left in the queue.
void Printer::display()
{
	cout << "\nThe queue contains: ";

	for(int i = 0; i < slot; i++)
	{
			cout << Queue[i].priority << " ";
	}
	cout << endl;
}

void Printer::displayPrintJobs()
{
	cout << "\nThe remaining jobs say: ";
	for(int i = 0; i < slot; i++)
	{
			cout << Queue[i].message << " ";
	}
	cout << endl;
}

#endif

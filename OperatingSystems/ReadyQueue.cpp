/*
Project: Printer Queue extra credit example.
By: Michael Cooper
started: 3/21/14
date last modified: 3/22/14
Compiler: Microsoft Visual Studio 2012 v110
File Type: Implimentation file for the Printer queue
*/
#ifndef ReadyQueue_cpp
#define ReadyQueue_cpp

#include "ReadyQueue.h"

using namespace std;


//constructor sets position = 1 and gives Queue it's size
ReadyQueue::ReadyQueue()
{
	currentSize = 0;
	nextSlot = 1;//start at 1 in order to avoid the 0th nextSlot. Makes division possible
	PCB blank;
	blank.state = NEW;
	blank.ID = -1;
	for (int i = 0; i < qSIZE; i++)//initialize the array
	{
		Queue[i] = blank;
	}
	for (int j = 0; j < tableSize; j++)
	{
		blank.ID = j + 1;
		PCBTable[j] = blank;
	}
}

//sends in the new task to be added by its entry number
void ReadyQueue::insertProc(int num)
{
	PCB toAdd = PCBTable[(num-1)]; 

	toAdd.state = READY;

	//add the item
	Queue[nextSlot] = toAdd;
	int location = nextSlot;//starting location for the new item being added
	cout << "inserting " << toAdd.ID << " into " << location << endl;
	//while the ID is higher than that of it's parent, swap the two
	while((toAdd.ID < Queue[location / 2].ID) && (location != 1))
	{
		cout << "\nSwapping with the root." << endl;
		Queue[location] = Queue[location / 2];//swap the root
		Queue[location / 2] = toAdd;
		location = (location / 2);
	}
	nextSlot++;//incriment the next empty nextSlot
	currentSize++;
}


//removes the front job and displays it's ID number
PCB ReadyQueue::removeHighestProc()
{
  PCB top = Queue[1];
  Queue[1].state = RUNNING;
  cout << "Removing " << top.ID << endl;
  reHeapify();
  currentSize--;
  return top;
}

//re-Heapiy the array after a job has been printed.
void ReadyQueue::reHeapify()
{
	nextSlot--;//decriment nextSlot because tree is shrinking by 1
	Queue[1] = Queue[nextSlot];//move the lowest data member to the top
	Queue[nextSlot].ID = -1;//reset ID for the last nextSlot
	Queue[nextSlot].state = TERMINATED;
	int loc = 1; //current location of the lase element in the array

	while(loc != nextSlot -1)//ensures that at most the item will return to the end
	{
		//insure that we don't fall off the tree
		if(((loc * 2) > nextSlot)||(Queue[loc*2].ID == -1))
			return;
		if ((Queue[loc].ID > Queue[loc * 2].ID) ||
			(Queue[loc].ID > Queue[loc * 2 + 1].ID))
		{
			PCB PCBHolder = Queue[loc];//pull the current message
			//See which one has a higher ID and swap
			if (Queue[loc * 2].ID < Queue[(loc * 2) + 1].ID || Queue[(loc * 2)+1].ID == -1)
			{
				if (Queue[loc * 2].ID == -1 || Queue[loc * 2].ID > Queue[loc].ID)
					return;
				
				cout << "\nSwapping " << Queue[loc].ID
					<< " with the left child" << endl;

				Queue[loc] = Queue[loc*2];
				Queue[loc*2] = PCBHolder;
				loc = (loc * 2);
				continue;//check the loop again
			}
			else
			{
				if(Queue[(loc*2)+1].ID == -1)
				  return;

				cout << "\nSwapping " << Queue[loc].ID
					<< " with the right child" << endl;
				
				Queue[loc] = Queue[loc*2+1];
				Queue[loc*2+1] = PCBHolder;
				loc = (loc * 2+1);
				continue;//check the loop again
			}

		}
		else
			return;//exit if at correct ID
	}
}

int ReadyQueue::size()
{
  return currentSize;
}

//displays everythign left in the queue.
void ReadyQueue::displayQueue()
{
	cout << "\nThe queue contains: ";

	for(int i = 1; i < nextSlot; i++)
	{
	  cout << endl << Queue[i].ID << " " << endl;
	}
	cout << endl;
}


#endif

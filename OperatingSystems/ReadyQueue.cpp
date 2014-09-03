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
        totalSize = 0;

        Queue[qSIZE];
	slot = 1;//start at 1 in order to avoid the 0th slot. Makes division possible
	
	blank.state = "New";
	blank.priority = -1;
	blank.ID = 0;

	for(int i = 0; i < qSIZE; i++)//initialize the array
		Queue[i] = blank;

	
	newPCB.state = "New";

	for(int j = 0; j < 19; j++)
	  {
	    newPCB.priority = j+1;
	    newPCB.ID = j+1;
	    PCBTable[j] = newPCB;
	  }

}

//sends in the new task to be added by its entry number
void ReadyQueue::insertProc(int num)
{
  PCB toAdd = PCBTable[(num-1)]; 

        toAdd.state = "Ready";

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
	totalSize++;
}


//removes the front job and displays it's priority number
PCB ReadyQueue::removeHighestProc()
{
  PCB top = Queue[1];
  Queue[1].state = "Running";
  reHeapify();
  totalSize--;
  return top;
}

//re-Heapiy the array after a job has been printed.
void ReadyQueue::reHeapify()
{
	slot--;//decriment slot because tree is shrinking by 1
	Queue[1] = Queue[slot];//move the lowest data member to the top
	Queue[slot].priority = -1;//reset priority for the last slot
	Queue[slot].state = "Terminated";
	int loc = 1; //current location of the lase element in the array

	while(loc != slot -1)//ensures that at most the item will return to the end
	{
		//insure that we don't fall off the tree
		if(((loc * 2) > slot)||(Queue[loc*2].priority == -1))
			return;
		if((Queue[loc].priority > Queue[loc*2].priority) || 
			(Queue[loc].priority > Queue[loc*2+1].priority))
		{
			PCB PCBHolder = Queue[loc];//pull the current message
			//See which one has a higher priority and swap
			if(Queue[loc*2].priority < Queue[loc*2+1].priority)
			{
				if(Queue[loc*2].priority == -1)
					return;
				
				Queue[loc] = Queue[loc*2];
				Queue[loc*2] = PCBHolder;
				loc = (loc * 2);
				continue;//check the loop again
			}
			else
			{
				if(Queue[(loc*2)+1].priority == -1)
				  return;
				
				Queue[loc] = Queue[loc*2+1];
				Queue[loc*2+1] = PCBHolder;
				loc = (loc * 2+1);
				continue;//check the loop again
			}

		}
		else
			return;//exit if at correct priority
	}
}

int ReadyQueue::size()
{
  return totalSize;
}

//displays everythign left in the queue.
void ReadyQueue::displayQueue()
{
	cout << "\nThe queue contains: ";

	for(int i = 1; i < slot; i++)
	{
	  cout << endl << Queue[i].ID << " " << Queue[i].priority << endl;
	}
	cout << endl;
}


#endif

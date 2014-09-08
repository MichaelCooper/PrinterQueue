/*
Project: Printer Queue extra credit example.
By: Michael Cooper
started: 3/21
date last modified: 3/22/14
Compiler: Microsoft Visual Studio 2012 v110
File Type: Header file for the Printer queue
*/

#ifndef ReadyQueue_h
#define ReadyQueue_h

#include <iostream>
#include <string>

enum STATE { NEW, READY, RUNNING, WAITING, TERMINATED };

struct PCB
{
	int ID; // The ID and id of the current task
	STATE state;//State of the task.
};

class ReadyQueue
{
protected:
    static const int qSIZE = 21;//used for max size
	static const int tableSize = 20;
	int currentSize;
	PCB Queue[qSIZE];//array of messages to be displayed
	PCB PCBTable[tableSize];
	int nextSlot;//used to keep track the next empty nextSlot in the array

public:
	ReadyQueue();//constructor sets size = 0 and gives Queue it's size
	~ReadyQueue(){};//destructor - Nothing to do here.
	
	void insertProc(int ID);//sends in the new task to be added by its entry number
	
	PCB removeHighestProc();//removes and returns the front PCB

	void reHeapify();//re-Heapify the array after a job has been printed.
	
	int size();//return the number of elements in queue

	void displayQueue();//displays IDs and  priorities of processes in the queue.

};



#endif

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

struct PCB
{
  int priority;//gives the priority of the current task
  int ID;
  std::string state;//State of the task.
};


class ReadyQueue
{
protected:
        static const int qSIZE = 21;//used for max size
	PCB PCBTable[20];
	int totalSize;
	PCB Queue[qSIZE];//array of messages to be displayed
	PCB blank;
	PCB newPCB;
	
	int slot;//used to keep track the next empty slot in the array
public:
	ReadyQueue();//constructor sets size = 0 and gives Queue it's size
	~ReadyQueue(){};//destructor - Nothing to do here.
	
	void insertProc(int num);//sends in the new task to be added by its entry number
	
	PCB removeHighestProc();//removes and returns the front PCB

	void reHeapify();//re-Heapify the array after a job has been printed.
	
	int size();//return the number of elements in queue

	void displayQueue();//displays IDs and  priorities of processes in the queue.

};



#endif

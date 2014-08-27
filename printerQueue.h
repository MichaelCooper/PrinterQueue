/*
Project: Printer Queue extra credit example.
By: Michael Cooper
started: 3/21
date last modified: 3/22/14
Compiler: Microsoft Visual Studio 2012 v110
File Type: Header file for the Printer queue
*/

#ifndef printerQueue_h
#define printerQueue_h

#include <iostream>

struct  Message
{
	int priority;//gives the priority of the current task
	std::string message;//The message to be displayed
};

class Printer
{
protected:
	static const int SIZE = 11;//used for max size
	Message Queue[SIZE];//array of messages to be displayed
	int slot;//used to keep track the next empty slot in the array
public:
	Printer();//constructor sets size = 0 and gives Queue it's size
	~Printer(){};//destructor - Nothing to do here.
	void insertAJob(int priority, std::string message);//inserts using the priority and message
	void printAJob();//removes the front job and displays it's priority number
	void reHeapify();//re-Heapiy the array after a job has been printed.
	void display();//displays priorities of the jobs left in the queue.
	void displayPrintJobs();//displays the messages left in the queue

};



#endif

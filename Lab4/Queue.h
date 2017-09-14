/**
*	@file : Queue.h
*	@author : Connor Welch
*	@date : 2016.9.27
*	Purpose: Header file of Queue. Contains methods for adding, removing, printing, and searching Nodes in a list.
*/
#ifndef QUEUE_H
#define QUEUE_H
#include "qNode.h"
#include <iostream>
#include <fstream>
class Queue
{
	public:
		/**
		*  @pre none
		*  @post Initializes m_front to nullptr and m_size to 0
		*  @return none
		*/
		Queue();

		/**
		*  @pre none
		*  @post removes values from list when program terminates
		*  @return none
		*/
		~Queue();
		/**
		*  @pre none
		*  @post determines if list is empty
		*  @return returns true if empty false otherwise
		*/
		bool isEmpty() const;
		/**
		*  @pre none
		*  @post none
		*  @return returns m_size
		*/
		int size() const;
		/**
		*  @pre takes in an integer
		*  @post searches for a value in the list and lets user know if list is empty
		*  @return returns true if a value is found false otherwise
		*/
		bool search(int value) const;
		/**
		*  @pre none
		*  @post prints the values in the list
		*  @return none
		*/
		void printList() const;
		/**
		*  @pre takes in an integer
		*  @post Adds a value to the back list determined by the state of the list
		*  @return none
		*/
		void addBack(int value);
		/**
		*  @pre none
		*  @post removes a value from the back list determined by the state of the list
		*  @return none
		*/
		int pop();
                /**
		*  @pre Takes in an integer
		*  @post searches for a value then removes that value from the list if it exists
		*  @return returns front value
		*/
    bool remove(int value);
    bool concatenate(qNode* ptr= nullptr);
    bool reverse(qNode* start= nullptr);
    qNode* getFront();

	private:
		qNode* m_front;
		int m_size;
    int current;
		int popValue;
    qNode* newStart;
    qNode* previous;
    qNode* front = m_front;
};

#endif

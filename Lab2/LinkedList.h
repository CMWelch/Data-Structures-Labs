/**
*	@file : LinkedList.h
*	@author : Connor Welch
*	@date : 2016.08.26
*	Purpose: Header file of LinkedList class. Contains methods for adding, removing, printing, and searching Nodes in a list. 
*/
#ifndef LinkedList_H
#define LinkedList_H
#include "Node.h"
#include <iostream>
#include <fstream>
class LinkedList
{
	public:
		/**
		*  @pre none
		*  @post Initializes m_front to nullptr and m_size to 0
		*  @return none
		*/
		LinkedList();

		/**
		*  @pre none
		*  @post removes values from list when program terminates
		*  @return none
		*/
		~LinkedList();	
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
		bool removeBack();
                /**
		*  @pre Takes in an integer
		*  @post searches for a value then removes that value from the list if it exists
		*  @return none
		*/
                bool remove(int value);
                bool concatenate(Node* ptr= nullptr);
                bool reverse(Node* start= nullptr);
                Node* getFront();
	private:
		Node* m_front;
		int m_size;
                int current;
                Node* newStart;
                Node* previous;
                Node* front = m_front;
};

#endif
		

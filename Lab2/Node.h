/**
*	@file : Node.h
*	@author : Connor Welch
*	@date : 2016.08.26
*	Purpose: Header file of Node class. Contains getters and setters for the Node class. 
*/
#ifndef NODE_H
#define NODE_H
class Node
{
	public:
		/**
		*  @pre none
		*  @post Initializes m_next to nullptr and m_value to 0
		*  @return none
		*/
		Node();
		/**
		*  @pre none
		*  @post none
		*  @return returns m_value
		*/
		int getValue();
		/**
		*  @pre none
		*  @post sets m_value to the value passed in
		*  @return none
		*/
		void setValue(int value);
		/**
		*  @pre none
		*  @post none
		*  @return returns m_next
		*/
		Node* getNext();
		/**
		*  @pre none
		*  @post sets m_next to the value passed in
		*  @return none
		*/
		void setNext(Node* prev);
	private:
		int m_value;
		Node* m_next;
};
#endif		

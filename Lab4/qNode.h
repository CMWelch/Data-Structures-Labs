/**
*	@file : qNode.h
*	@author : Connor Welch
*	@date : 2016.9.27
*	Purpose: Header file of Node class. Contains getters and setters for the Node class.
*/
#ifndef QNODE_H
#define QNODE_H
class qNode
{
	public:
		/**
		*  @pre none
		*  @post Initializes m_next to nullptr and m_value to 0
		*  @return none
		*/
		qNode();
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
		qNode* getNext();
		/**
		*  @pre none
		*  @post sets m_next to the value passed in
		*  @return none
		*/
		void setNext(qNode* prev);
	private:
		int m_value;
		qNode* m_next;
};
#endif

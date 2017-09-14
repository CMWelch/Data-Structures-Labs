/**
*	@file : Node.h
*	@author :  Connor Welch
*	@date : 2016.9.27
*	Purpose: Header file of Node
*/
#ifndef NODE_H
#define NODE_H
class Node
{
	public:
		/**
		*  @pre none
		*  @post sets m_left and m_right to nullptr and m_value to 0
		*  @return none
		*/
		Node();
		/**
		*  @pre none
		*  @post none
		*  @return returns m_value
		*/
		int getValue() const;
		/**
		*  @pre none
		*  @post none
		*  @return returns m_left
		*/
		Node* getLeft() const;
		/**
		*  @pre none
		*  @post none
		*  @return returns m_right
		*/
		Node* getRight() const;
		/**
		*  @pre takes in an integer
		*  @post sets m_value to value
		*  @return none
		*/
		void setValue(int value);
		/**
		*  @pre takes in a node pointer
		*  @post sets m_left to left
		*  @return none
		*/
		void setLeft(Node* left);
		/**
		*  @pre takes in a node pointer
		*  @post sets m_right to right
		*  @return none
		*/
		void setRight(Node* right);
	private:
		Node* m_left;
		Node* m_right;
		int m_value;
};
#endif

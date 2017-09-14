/**
*	@file : qNode.cpp
*	@author : Connor Welch
*	@date : 2016.9.27
*	Purpose: Implementation of Node class
*/
#include "qNode.h"
qNode::qNode() //constructor, initializes m_value and m_next
{
	m_value=0;
	m_next=nullptr;
}
int qNode::getValue() //returns m_value
{
	return(m_value);
}
void qNode::setValue(int value) //sets m_value to value
{
	m_value=value;
}
qNode* qNode::getNext() //returns m_next
{
	return(m_next);
}
void qNode::setNext(qNode* prev) //sets m_next to prev
{
	m_next=prev;
}

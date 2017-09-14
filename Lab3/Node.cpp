/**
*	@file : Node.cpp
*	@author : Connor Welch
*       @date : 2016.08.26
*	Purpose: Implementation of Node class
*/
#include "Node.h"
Node::Node() //constructor, initializes m_value and m_next
{
	m_value=-1;
	m_flag=0;
	m_next=nullptr;
}
int Node::getValue() //returns m_value
{
	return(m_value);
}
void Node::setValue(int value) //sets m_value to value
{
	m_value=value;
}
Node* Node::getNext() //returns m_next
{
	return(m_next);
}
void Node::setNext(Node* prev) //sets m_next to prev
{
	m_next=prev;
}
void Node::setFlag(bool flag)
{
	m_flag = flag;
}
bool Node::getFlag()
{
	return(m_flag);
}

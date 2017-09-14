/**
*	@file : Node.cpp
*	@author :  Connor Welch
*	@date : 2016.9.27
*	Purpose: Implementation of Node
*/
#include "Node.h"

Node::Node()//sets m_left and m_right to nullptr and m_value to 0
{
	m_left = nullptr;
	m_right = nullptr;
	m_value = 0;
	m_rank = 0;
}

int Node::getValue() const//returns m_value
{
	return(m_value);
}

Node* Node::getLeft() const//returns m_left
{
	return(m_left);
}

Node* Node::getRight() const//returns m_right
{
	return(m_right);
}
int Node::getRank() const
{
	return(m_rank);
}
void Node::setValue(int value)//sets m_value to value
{
	m_value=value;
}
void Node::setLeft(Node* left)//sets m_left to left
{
	m_left=left;
}
void Node::setRight(Node* right)//sets m_right to right
{
	m_right=right;
}
void Node::setRank(int rank)
{
	m_rank = rank;
}

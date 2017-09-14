/**
*	@file : Leftist.cpp
*	@author :  Connor Welch
*	@date : 2016.9.27
*	Purpose: Implementation of Leftist
*/

#include "Leftist.h"
Leftist::Leftist()//sets m_root to nullptr
{
	m_root=nullptr;
}

Leftist::~Leftist()//deletes all nodes in the binary tree
{
	deleteTree(m_root);
}
bool Leftist::isEmpty() const//determines if the tree is empty or not
{
	if(m_root==nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

bool Leftist::insert(int value)//adds a value to the tree calling add
{
	return(insert(value, m_root));
}
void Leftist::preorder()
{
	preorder(m_root);
}
void Leftist::inorder()
{
	inorder(m_root);
}
void Leftist::levelorder()
{
	levelorder(m_root);
}
void Leftist::deleteTree()
{
	deleteTree(m_root);
}

bool Leftist::insert(int value, Node* subtree)//adds a value to the tree by recursively calling itelf to put it in the correct position
{
	if(isEmpty())
	{
		Node* temp= new Node();
		temp->setValue(value);
		m_root=temp;
		return(false);
	}
	/*
	if(search(value, m_root))
	{
		std::cout << "The value is already in the tree and was not added\n";
		return(false);
	}
	*/
  else
  {
    Node* temp = new Node();
    temp->setValue(value);
    m_root = merge(subtree, temp);
    //delete temp;
  }
}

void Leftist::deleteTree(Node* subtree)//deletes the values in the tree by calling itself to traverse the tree
{
	while(deleteMin() == true)
	{
		
	}
}

Node* Leftist::search(int value, Node* subtree)//searches the tree for the value that was passed in using recursion
{
	if(subtree == nullptr)
	{
		return(nullptr);
	}
	else
	{
		if(subtree->getValue() == value)
		{
			return(subtree);
		}
		else if(value < subtree->getValue())
		{
			parent = subtree;
			search(value, subtree->getLeft());
		}
		else if(value > subtree->getValue())
		{
			parent = subtree;
			search(value, subtree->getRight());
		}
	}
}
bool Leftist::deleteMin()
{

	//Case 1: Empty
	if(isEmpty())
	{
		std::cout << "The tree is empty!\n";
		return(false);
	}
	//Case 2: Root contains value
	else if((m_root->getRight() == nullptr) && (m_root->getLeft() == nullptr))
	{
		delete m_root;
	 	m_root = nullptr;
		return(true);
	}
	else
	{
    Node* temp = m_root;
    m_root = merge(temp->getLeft(), temp->getRight());
    delete temp;
		return(true);
	}
}
void Leftist::preorder(Node* subtree)
{
	if(isEmpty())
	{
		std::cout << "The tree is empty!\n";
		return;
	}
	if(subtree==nullptr)
	{
		return;
	}
	else if (subtree != nullptr)
	{
		std::cout << subtree->getValue() << "\n";
		preorder(subtree->getLeft());
		preorder(subtree->getRight());
	}
}

void Leftist::inorder(Node* subtree)
{
	if(isEmpty())
	{
		std::cout << "The tree is empty!\n";
		return;
	}
	if(subtree==nullptr)
  {
		return;
	}
	else if(subtree != nullptr)
	{
		inorder(subtree->getLeft());
		std::cout << subtree->getValue() << "\n";
	  inorder(subtree->getRight());
	}
}
void Leftist::levelorder(Node* subtree)
{
	/*
	if(isEmpty())
	{
		std::cout << "The tree is empty!\n";
		return;
	}
	Queue q;
	Node* temp;
	if(subtree == m_root)
	{
		q.addBack(m_root->getValue());
	}
	//std::cout << q.pop() << "\n";
	while(q.isEmpty() == false)
	{

			temp = search(q.pop(), m_root);

				std::cout << temp->getValue() << "\n";


		if(temp->getLeft() != nullptr)
		{

			q.addBack(temp->getLeft()->getValue());
		}
		if(temp->getRight() != nullptr)
		{
			q.addBack(temp->getRight()->getValue());
		}
	}
	*/
	if(isEmpty())
	{
		return;
	}
	Queue q;
	Node* temp;
	q.addBack(m_root->getValue());
	while(!q.isEmpty())
	{
		temp = search(q.pop(), m_root);
		std::cout << temp->getValue() << "\n";
		if(temp->getLeft() != nullptr)
		{
			q.addBack(temp->getLeft()->getValue());
		}
		if(temp->getRight() != nullptr)
		{
			q.addBack(temp->getRight()->getValue());
		}
	}


}
Node* Leftist::merge(Node* subtree1, Node* subtree2)
{
	/*
  if(subtree1 == nullptr)
  {
    return(subtree2);
  }
  else if(subtree2 == nullptr)
  {
    return(subtree1);
  }
  else if(subtree1->getValue() < subtree2->getValue())
  {
      merge(subtree1->getRight(), subtree2);
  }
  if(subtree1->getLeft() == nullptr)
  {
    subtree1->setLeft(subtree1->getRight());
  }
  else
  {
    if(subtree1->getLeft()->getRank() < subtree1->getRight()->getRank())
    {
      Node* temp = subtree1->getLeft();
      subtree1->setLeft(subtree1->getRight());
      subtree1->setRight(temp);
      computeRank(subtree1);
    }
  }
  return(subtree1);
	*/
	if(subtree1 == nullptr)
	{
		return(subtree2);
	}
	else if(subtree2 == nullptr)
	{
		return(subtree1);
	}
	else if(subtree1->getValue() > subtree2->getValue())
	{
			Node* temp = subtree1;
			subtree1 = subtree2;
			subtree2 = temp;

	}
	if(subtree1->getRight() == nullptr)
	{
		subtree1->setRight(subtree2);
	}
	else
	{
		subtree1->setRight(merge(subtree1->getRight(), subtree2));
	}
	if((subtree1->getLeft() == nullptr) || (subtree1->getRight()->getRank() > subtree1->getLeft()->getRank()))
	{
		Node* temp = subtree1->getRight();
		subtree1->setRight(subtree1->getLeft());
		subtree1->setLeft(temp);
	}
	if(subtree1->getRight() == nullptr || subtree1->getLeft() == nullptr)
	{
		subtree1->setRank(1);
	}
	else
	{
		subtree1->setRank(subtree1->getRank()+1);
	}
	return(subtree1);
}
void Leftist::computeRank(Node* subtree)
{
  if((subtree->getLeft() == nullptr) && (subtree->getRight() == nullptr))
  {
    subtree->setRank(1);
  }
  else if((subtree->getLeft() != nullptr) && (subtree->getRight() == nullptr))
  {
    subtree->setRank(subtree->getLeft()->getRank() + 1);
  }
  else if((subtree->getLeft() == nullptr) && (subtree->getRight() != nullptr))
  {
    subtree->setRank(subtree->getRight()->getRank() + 1);
  }
  else
  {
    if((subtree->getLeft()->getRank()) < (subtree->getRight()->getRank()))
    {
      subtree->setRank(subtree->getLeft()->getRank() + 1);
    }
    else
    {
      subtree->setRank(subtree->getRight()->getRank() + 1);
    }
  }
}

/**
*	@file : Skew.cpp
*	@author :  Connor Welch
*	@date : 2016.9.27
*	Purpose: Implementation of Skew
*/

#include "Skew.h"
Skew::Skew()//sets m_root to nullptr
{
	m_root=nullptr;
}

Skew::~Skew()//deletes all nodes in the binary tree
{
	deleteTree(m_root);
}
bool Skew::isEmpty() const//determines if the tree is empty or not
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

bool Skew::insert(int value)//adds a value to the tree calling add
{
	return(insert(value, m_root));
}
void Skew::preorder()
{
	preorder(m_root);
}
void Skew::inorder()
{
	inorder(m_root);
}
void Skew::levelorder()
{
	levelorder(m_root);
}
void Skew::deleteTree()
{
	deleteTree(m_root);
}
bool Skew::insert(int value, Node* subtree)//adds a value to the tree by recursively calling itelf to put it in the correct position
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

void Skew::deleteTree(Node* subtree)//deletes the values in the tree by calling itself to traverse the tree
{
	while(deleteMin() == true)
	{

	}
}

Node* Skew::search(int value, Node* subtree)//searches the tree for the value that was passed in using recursion
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
bool Skew::deleteMin()
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
	}
}
void Skew::preorder(Node* subtree)
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

void Skew::inorder(Node* subtree)
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
void Skew::levelorder(Node* subtree)
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
Node* Skew::merge(Node* subtree1, Node* subtree2)
{

	if(subtree1 == nullptr)
	{
		return(subtree2);
	}
	if(subtree2 == nullptr)
	{
		return(subtree1);
	}
	/*
	if(subtree1->getValue() < subtree2->getValue())
	{
		Node* temp = subtree1->getRight();
		subtree1->setRight(subtree1->getLeft());
		subtree1->setLeft(merge(subtree2, temp));
		return(subtree1);
	}
	*/
	if(subtree1->getValue() < subtree2->getValue())
	{
		Node* temp = subtree1->getLeft();
		subtree1->setLeft(merge(subtree1->getRight(), subtree2));
		subtree1->setRight(temp);
		return(subtree1);
	}
	else
	{
		Node* temp = subtree2->getRight();
		subtree2->setRight(merge(subtree2->getLeft(), subtree1));
		subtree2->setLeft(temp);
		return(subtree2);
	}
	/*
	else
	{
		return(merge(subtree2, subtree1));
	}
	*/
}
void Skew::computeRank(Node* subtree)
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

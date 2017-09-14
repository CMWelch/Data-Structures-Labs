/**
*	@file : BinarySearchTree.cpp
*	@author :  Connor Welch
*	@date : 2016.9.27
*	Purpose: Implementation of BinarySearchTree
*/

#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree()//sets m_root to nullptr
{
	m_root=nullptr;
}

BinarySearchTree::~BinarySearchTree()//deletes all nodes in the binary tree
{
	deleteTree(m_root);
}
bool BinarySearchTree::isEmpty() const//determines if the tree is empty or not
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

bool BinarySearchTree::add(int value)//adds a value to the tree calling add
{
	return(add(value, m_root));
}
void BinarySearchTree::preorder()
{
	preorder(m_root);
}
void BinarySearchTree::inorder()
{
	inorder(m_root);
}
void BinarySearchTree::levelorder()
{
	levelorder(m_root);
}
bool BinarySearchTree::add(int value, Node* subtree)//adds a value to the tree by recursively calling itelf to put it in the correct position
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
	if(value<subtree->getValue() && subtree->getLeft() == nullptr)
	{
		Node* temp= new Node();
		temp->setValue(value);
		subtree->setLeft(temp);
		return(true);
	}
	if(value>subtree->getValue() && subtree->getRight() == nullptr)
	{
		Node* temp= new Node();
		temp->setValue(value);
		subtree->setRight(temp);
		return(true);
	}
	if(value<subtree->getValue())
	{
		return(add(value, subtree->getLeft()));
	}
	if(value>subtree->getValue())
	{
		return(add(value, subtree->getRight()));
	}
	return(false);
}

void BinarySearchTree::deleteTree(Node* subtree)//deletes the values in the tree by calling itself to traverse the tree
{
	if(isEmpty())
	{
		return;
	}
	if(subtree->getLeft() != nullptr)
	{
		deleteTree(subtree->getLeft());
	}
	if(subtree->getRight() != nullptr)
	{
		deleteTree(subtree->getRight());
	}
	delete(subtree);
}

Node* BinarySearchTree::search(int value, Node* subtree)//searches the tree for the value that was passed in using recursion
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
bool BinarySearchTree::remove(int value)
{

	//Case 1: Empty
	if(isEmpty())
	{
		return(false);
	}
	//Case 2: Root contains value
	else if((m_root->getValue() == value) && (m_root->getRight() == nullptr) && (m_root->getLeft() == nullptr))
	{
		std::cout << "The tree is empty!\n";
		delete m_root;
	 	m_root = nullptr;
		return(true);
	}
	else
	{
		return(remove(value, search(value, m_root)));
	}
}
bool BinarySearchTree::deleteMin()
{

	//Case 1: Empty
	if(isEmpty())
	{
		std::cout << "The tree is empty!\n";
		return(false);
	}
	//Case 2: Root contains value
	else if((findMin(m_root) == m_root) && (m_root->getRight() == nullptr) && (m_root->getLeft() == nullptr))
	{
		delete m_root;
	 	m_root = nullptr;
		return(true);
	}
	else
	{
		toDelete = findMin(m_root);
		remove(toDelete->getValue(), toDelete);
	}
}
bool BinarySearchTree::deleteMax()
{

	//Case 1: Empty
	if(isEmpty())
	{
		std::cout << "The tree is empty!\n";
		return(false);
	}
	//Case 2: Root contains value
	else if((findMax(m_root) == m_root) && (m_root->getRight() == nullptr) && (m_root->getLeft() == nullptr))
	{
		delete m_root;
	 	m_root = nullptr;
		return(true);
	}
	else
	{
		toDelete = findMax(m_root);
		remove(toDelete->getValue(), toDelete);
	}

}
void BinarySearchTree::preorder(Node* subtree)
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

void BinarySearchTree::inorder(Node* subtree)
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
void BinarySearchTree::levelorder(Node* subtree)
{
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
}
bool BinarySearchTree::remove(int value, Node* subtree)
{

	if(subtree == nullptr)
	{
		return(false);
	}
	//Case 3: Value to delete has no children
	if(subtree == m_root)
	{
		if((subtree->getRight() == nullptr) && (subtree->getLeft() != nullptr))
		{
			toDelete = subtree;
			m_root = subtree->getLeft();
			delete toDelete;
			return(true);
		}
		else if((subtree->getRight() != nullptr) && (subtree->getLeft() == nullptr))
		{
			toDelete = subtree;
			m_root = subtree->getRight();
			delete toDelete;
			return(true);
		}
	}
	else if((subtree->getValue() == value) && (subtree->getRight() == nullptr) && (subtree->getLeft() == nullptr))
	{
		if(parent->getRight() == subtree)
		{
			toDelete = subtree;
			parent->setRight(nullptr);
			delete toDelete;
			return(true);
		}
		else
		{
			toDelete = subtree;
			parent->setLeft(nullptr);
			delete toDelete;
			return(true);
		}
	}

	//Case 4: Value has only left child
	else if((subtree->getValue() == value) && (subtree->getRight() == nullptr) && (subtree->getLeft() != nullptr))
	{
		if(parent->getRight() == subtree)
		{
			toDelete = subtree;
			parent->setRight(subtree->getLeft());
			delete toDelete;
			return(true);
		}
		else
		{
			toDelete = subtree;
			parent->setLeft(subtree->getLeft());
			delete toDelete;
			return(true);
		}

	}

	//Case 5: Value has only right child
	else if((subtree->getValue() == value) && (subtree->getRight() != nullptr) && (subtree->getLeft() == nullptr))
	{
		if(parent->getRight() == subtree)
		{
			toDelete = subtree;
			parent->setRight(subtree->getRight());
			delete toDelete;
			return(true);
		}
		else
		{
			toDelete = subtree;
			parent->setLeft(subtree->getRight());
			delete toDelete;
			return(true);
		}
	}
	// Case 6: Value has two children
	else if((subtree->getValue() == value) && (subtree->getRight() != nullptr) && (subtree->getLeft() != nullptr))
	{
		//std::cout << "made it4";
		toDelete = findMin(subtree->getRight());
		if(subtree->getRight() == toDelete)
		{
			subtree->setValue(toDelete->getValue());
			subtree->setRight(toDelete->getRight());
			delete toDelete;
			return(true);
		}
		else
		{
			subtree->setValue(toDelete->getValue());
			delete toDelete;
			return(true);
		}

	}

	return(false);
}
Node* BinarySearchTree::findMin(Node* subtree)
{
	if(subtree->getLeft() == nullptr)
	{
		return(subtree);
	}
	else
	{
		parent = subtree;
		return(findMin(subtree->getLeft()));
	}
}
Node* BinarySearchTree::findMax(Node* subtree)
{
	if(subtree->getRight() == nullptr)
	{
		return(subtree);
	}
	else
	{
		parent = subtree;
		return(findMax(subtree->getRight()));
	}
}

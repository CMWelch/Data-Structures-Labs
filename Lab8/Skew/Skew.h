/**
*	@file : Skew.h
*	@author :  Connor Welch
*	@date : 2016.9.27
*	Purpose: Header file of Skew
*/
#ifndef Skew_H
#define Skew_H
#include "Node.h"
#include <iostream>
#include "Queue.h"

class Skew
{
	public:
		/**
		*  @pre none
		*  @post sets m_root to nullptr
		*  @return none
		*/
		Skew();
		/**
		*  @pre none
		*  @post deletes all nodes in the binary tree
		*  @return none
		*/
		~Skew();
		/**
		*  @pre none
		*  @post determines if the tree is empty or not
		*  @return returns true if tree is empty false otherwise
		*/
		bool isEmpty() const;
		/**
		*  @pre takes in an integer
		*  @post adds a value to the tree calling add
		*  @return returns true if a value was added false otherwise
		*/
		bool insert(int value);
		/**
		*  @pre takes in an order in which to determine how the values are added
		*  @post creates a vector then calls treeToVector
		*  @return returns a vector with the contents of the tree in the specified order is returned
		*/
		void preorder();
		void inorder();
		void levelorder();
    bool deleteMin();
		void deleteTree();

	private:
		/**
		*  @pre takes in an integer and root of a subtree
		*  @post adds a value to the tree by recursively calling itelf to put it in the correct position
		*  @return returns true if value was found false otherwise
		*/
		bool insert(int value, Node* subtree);
		/**
		*  @pre takes in the root of a subtree
		*  @post deletes the values in the tree by calling itself to traverse the tree
		*  @return returns true if value was found false otherwise
		*/
		void deleteTree(Node* subtree);
		/**
		*  @pre takes in an integer and root of a subtree
		*  @post searches the tree for the value that was passed in using recursion
		*  @return returns true if value was found false otherwise
		*/
	 	Node* search(int value, Node* subtree);
		/**
		*  @pre takes in a subtree and an order
		*  @post prints the values in the tree specified by the order passed in
		*  @return returns true if value was found false otherwise
		*/
		void preorder(Node* subtree);
		void inorder(Node* subtree);
		void levelorder(Node* subtree);
    Node* merge(Node* subtree1, Node* subtree2);
    void computeRank(Node* subtree);
		int tempPrint;
		Node* m_root;
		Node* searchR;
		Node* parent;
		Node* toDelete;
};
#endif

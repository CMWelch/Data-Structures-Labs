/**
*	@file : main.cpp
*	@author :  Connor Welch
*	@date : 2015.11.10
*	Purpose: Implementation of main
*/

#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Timer.cpp"
void printMenu()
{
	std::cout<< "Input a selection:\n"
	<< "1- Insert\n"
	<< "2- Remove\n"
	<< "3- DeleteMin\n"
	<< "4- DeleteMax\n"
	<< "5- preorder\n"
	<< "6- inorder\n"
	<< "7- levelorder\n"
	<< "8- Exit\n";
}

int main()
{
		bool end = false;
		int choice;
		int entry;
		int store;
		BinarySearchTree BST;
		Timer t;
		std::ifstream fin;

		fin.open("data.txt");
		while(fin >> store)
		{
		//	BST.add(store);
		}
		fin.close();


		while(!end)
		{
			printMenu();
			std::cin >> choice;
			if(choice == 1)
			{
				std::cout << "Choose a value to add to the tree.\n";
				std::cin >> entry;
				BST.add(entry);
			}
			if(choice == 2)
			{
				std::cout << "Choose a value to remove from the tree.\n";
				std::cin >> entry;
				if(BST.remove(entry))
				{
					std::cout << "Value removed.\n";
				}
				else
				{
					std::cout << "Value not removed.\n";
				}
			}
			if(choice == 3)
			{
				BST.deleteMin();
			}
			if(choice == 4)
			{
				BST.deleteMax();
			}
			if(choice == 5)
			{
				BST.preorder();
			}
			if(choice == 6)
			{
				BST.inorder();
			}
			if(choice == 7)
		  {
				BST.levelorder();
			}
			if(choice == 8)
			{
				end = true;
			}
			if(choice == 9)
			{
				int n = 400000;
				int random;
				float x;

				srand (1);
				t.start();
				for(int i = 0; i < n; i++)
				{
					BST.add(rand()% ((4*n)+1));
				}
				 std::cout << "The build time is ";
				 t.printTime(t.stop());

				 t.start();
				for(int i = 0; i < n/10; i++)
				{

					x = (rand());
					x = x/RAND_MAX;
					random = rand();


					if((0 <= x) && (x < 0.25))
					{

						BST.deleteMin();


					}
					if((.25 <= x) && (x < 0.5))
					{

						BST.deleteMax();


					}
					if((0.5 <= x) && (x < 0.75))
					{

							BST.add(random);



					}
					if((0.75 <= x) && (x < 1.0))
					{
						BST.remove(random);

					}
				}
				t.printTime(t.stop());
			}

		}
	return 0;
}

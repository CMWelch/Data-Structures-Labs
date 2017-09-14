/**
*	@file : main.cpp
*	@author :  Connor Welch
*	@date : 2015.11.10
*	Purpose: Implementation of main
*/

#include "Leftist.h"
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
	<< "2- DeleteMin\n"
	<< "3- preorder\n"
	<< "4- inorder\n"
	<< "5- levelorder\n"
	<< "6- Exit\n"
	<< "7- Run time tests\n";
}

int main()
{
		bool end = false;
		int choice;
		int entry;
		int store;
		Leftist left;
		Timer t;
		std::ifstream fin;

		fin.open("data.txt");

		//fin >> store;
		//left.insert(store);
	//	fin >> store;
	//	left.insert(store);
		while(fin >> store)
		{
			left.insert(store);
		}
		fin.close();


		while(!end)
		{
			printMenu();
			std::cin >> choice;
			if(choice == 1)
			{
				std::cout << "Choose a value to insert to the tree.\n";
				std::cin >> entry;
				left.insert(entry);
			}
			if(choice == 2)
			{
				left.deleteMin();
			}
			if(choice == 3)
			{
				left.preorder();
			}
			if(choice == 4)
			{
				left.inorder();
			}
			if(choice == 5)
		  {
				left.levelorder();
			}
			if(choice == 6)
			{
				end = true;
			}
			if(choice == 7)
			{
				int n = 400000;
				int random;
				float buildAve = 0;
				float opAve = 0;
				float x;
				float buildTime;
				float opTime;
				for(int j = 1; j < 6; j++)
				{


				left.deleteTree();
				srand (j);
				t.start();
				for(int i = 0; i < n; i++)
				{
					left.insert(rand()% ((4*n)+1));
				}
				 std::cout << "The build time is ";
				 buildTime = t.stop();
				 t.printTime(buildTime);
				 buildAve += buildTime;


				 t.start();
				for(int i = 0; i < n/10; i++)
				{

					x = (rand());
					x = x/RAND_MAX;
					random = rand();


					if((0 <= x) && (x < 0.5))
					{

						left.deleteMin();

					}
					if((0.5 <= x) && (x < 1.0))
					{
							left.insert(random);
					}

				}
				opTime = t.stop();
				t.printTime(opTime);
				opAve += opTime;
			}
			std::cout << buildAve/5 << "\n";
			std::cout << opAve/5 << "\n";
		}
		}
	return 0;
}

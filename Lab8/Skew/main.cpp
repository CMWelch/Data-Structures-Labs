/**
*	@file : main.cpp
*	@author :  Connor Welch
*	@date : 2015.11.10
*	Purpose: Implementation of main
*/

#include "Skew.h"
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
		Skew skew;
		Timer t;
		std::ifstream fin;

		fin.open("data.txt");

		//fin >> store;
		//skew.insert(store);
	//	fin >> store;
	//	skew.insert(store);
		while(fin >> store)
		{
			skew.insert(store);
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
				skew.insert(entry);
			}
			if(choice == 2)
			{
				skew.deleteMin();
			}
			if(choice == 3)
			{
				skew.preorder();
			}
			if(choice == 4)
			{
				skew.inorder();
			}
			if(choice == 5)
		  {
				skew.levelorder();
			}
			if(choice == 6)
			{
				end = true;
			}
			if(choice == 7)
			{
				int n = 200000;
				int random;
				float buildAve = 0;
				float opAve = 0;
				float x;
				float buildTime;
				float opTime;
				for(int j = 1; j < 6; j++)
				{
				srand (j);
				t.start();
				for(int i = 0; i < n; i++)
				{
					skew.insert(rand()% ((4*n)+1));
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
						skew.deleteMin();
					}
					if((0.5 <= x) && (x < 1.0))
					{
						skew.insert(random);
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

/**
*	@file : main.cpp
*	@author : Connor Welch
*	@date : 2016.08.26
*	Purpose: Implementation of LinkedList class
*/
#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>

void menu()
{
    std::cout << "Please choose one of the following commands: \n";
    std::cout << "1- insert" << "\n" << "2- print" << "\n" << "3- exit" << "\n";
}

int main()
{
    LinkedList list;
    int input=0;
    int entry=0;
    int temp;
    bool exit = false;

    std::ifstream fin;
    fin.open("data.txt");
    while(fin >> temp)
    {
      list.addBack(temp);
    }


      fin.close();

    while(exit==false)
    {
        menu();
        std::cin >> input;

        if(input==1)
        {
            std::cout << "Choose a number to insert";
            std::cin >> entry;
            list.addBack(entry);

        }
        if(input==2)
        {
            list.printList();
        }
        if(input==3)
        {
            exit=true;
        }

     }
 return(0);

}


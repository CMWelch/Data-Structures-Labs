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
    std::cout << "1- insert\n" << "2- delete\n" << "3- reverse\n" << "4- concatenate\n" << "5- print" << "\n" << "6- exit" << "\n";
}

int main()
{
    LinkedList list;
    LinkedList list2;
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

    while(exit==false)
    {
        menu();
        std::cin >> input;

        if(input==1)
        {
            std::cout << "Choose a number to insert\n";
            std::cin >> entry;
            list.addBack(entry);

        }
        else if(input==2)
        {
            std::cout << "Enter a value to delete from the list\n";
            std::cin >> entry;
            list.remove(entry);
        }
        else if(input==3)
        {
            list.reverse(list.getFront());
        }
        else if(input==4)
        {
            list.concatenate();
        }
        else if(input==5)
        {
             list.printList();
        }
        else if(input==6)
        {
            exit=true;
        }
        else
        {
            std::cout << "Please enter a valid input\n";
        }
     }
 return(0);
}

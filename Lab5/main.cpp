#include "Min5Heap.h"
#include <iostream>
#include <fstream>
#include "Timer.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void menu()
{
 std::cout << "Please choose one of the following commands\n"
 << "1- insert\n"
 << "2- deleteMin\n"
 << "3- deleteMax\n"
 << "4- remove\n"
 << "5- levelorder\n"
 << "6- Exit\n"
 << "7- Time test\n";
}
int main()
{
 int choice;
 int entry;
 bool end = false;
 Min5Heap heap;
 Timer t;
 std::fstream fin;
 fin.open("data.txt");
 while(fin >> entry)
 {
   //heap.insert(entry);
 }
 fin.close();
 //heap.heapify();
 while(end == false)
 {
   menu();
   std::cin >> choice;
   if(choice == 1)
   {
     std::cout << "Choose a number to insert\n";
     std::cin >> entry;
     heap.insert(entry);
     heap.heapify();
   }
   if(choice == 2)
   {
     heap.deleteMin();
   }
   if(choice == 3)
   {
     heap.deleteMax();
   }
   if(choice == 4)
   {
      std::cout << "Choose a number to delete\n";
      std::cin >> entry;
      heap.remove(entry);
   }
   if(choice == 5)
   {
     heap.levelorder();
   }
   if(choice == 6)
   {
     end = true;
   }
   if(choice == 7)
   {
     int n = 400000;
     int random;
     float x;

     srand (2);
     t.start();
     for(int i = 0; i < n; i++)
     {
       heap.insert(rand()% ((4*n)+1));
     }
      heap.heapify();
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

         heap.deleteMin();


       }
       if((.25 <= x) && (x < 0.5))
       {

         heap.deleteMax();


       }
       if((0.5 <= x) && (x < 1.0))
       {

           heap.insert(random);

       }
     }
     t.printTime(t.stop());
   }

 }
 return(0);
}

#include "Node.h"
#include "Hash.h"
#include <iostream>
#include <fstream>

void menu()
{
  std::cout << "Please choose one of the following commands\n" << "1- insert\n" << "2- delete\n" << "3- print\n" << "4- end\n";
}
int main()
{
    Hash hash;
    int temp;
    bool end = false;
    int select;
    int entry;
    std::ifstream fin;
    fin.open("data.txt");
    fin >> temp;
    while(fin >> temp)
    {
        hash.insert(temp);
        std::cout << temp << "\n";
    }
    fin.close();

    while(end == false)
    {
      menu();
      std::cin >> select;
      if(select == 1)
      {
        std::cout << "Enter a value to store\n";
        std::cin >> entry;
        hash.insert(entry);
      }
      if(select == 2)
      {
        std::cout << "Enter a value to remove\n";
        std::cin >> entry;
        hash.remove(entry);
      }
      if(select == 3)
      {
        hash.print();
      }
      if(select == 4)
      {
        end = true;
      }


    }

    return(0);
}

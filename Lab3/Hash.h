/**
*	@file : Hash.h
*	@author : Connor Welch
*       @date : 2016.08.26
*	Purpose: Header file of Node class
*/
#ifndef HASH_H
#define HASH_H
#include "Node.h"
#include <iostream>
#include <fstream>
class Hash
{
    public:
            Hash();
            ~Hash();
            bool insert(int value);
            bool remove(int value);
            void print();
            bool hash(int value);
            bool contains(int value);
            bool isFull();

    private:
            int hashNum;
            int m;
            Node** arr;
            Node* temp;
};
#endif

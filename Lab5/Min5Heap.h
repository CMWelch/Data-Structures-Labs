#ifndef MIN5HEAP_H
#define MINE5HEAP_H
#include <iostream>
#include <math.h>
class Min5Heap
{
  public:
    Min5Heap();
    ~Min5Heap();
    void insert(int value);
    void remove(int value);
    void deleteMin();
    void deleteMax();
    void levelorder();
    int findParent(int ind);
    int findChildren(int ind, int inc);
    int computeSmallestChild(int ind);
    int computeSmallestLeaf(int ind);
    void downHeap(int ind);
    bool findValue(int val);
    void heapify();

  private:
    int* heap;
    int n;
    int parent;
    int temp;
    int size;
    int child;
    int smallChild;
    int firstLeaf;
    int max;
    bool swap;

};
#endif

#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H
#include <iostream>
#include <math.h>
class MinMaxHeap
{
  public:
    MinMaxHeap();
    ~MinMaxHeap();
    void insert(int value);
    void initialInsert(int value);
    void bottomUp();
    void deleteMin();
    void deleteMax();
    void levelorder();
    int findParent(int ind);
    int findChild(int ind);
    int findChildren(int ind, int inc);
    int computeSmallestChild(int ind);
    int computeLargestChild(int ind);
    bool hasChildren(int ind);
    bool isGrandChild(int ind, int child);
    int computeSmallestLeaf(int ind);
    int computeLargestLeaf(int ind);
    void trickleDownMin(int ind);
    void trickleDownMax(int ind);
    void trickleDown(int ind);
    void bubbleUpMin(int ind);
    void bubbleUpMax(int ind);
    void bubbleUp(int ind);
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
    int largeChild;
    int firstLeaf;
    int min;
    int max;
    int insertion;
    int swap;

};
#endif

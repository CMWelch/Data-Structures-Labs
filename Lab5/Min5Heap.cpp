#include "Min5Heap.h"

Min5Heap::Min5Heap()
{
  n = 400000;
  n = (n+(n*.03));
  parent = 0;
  size = 0;
  swap = false;
  heap= new int[n];
  for(int i = 0; i < n; i++)
  {
    heap[i] = -1;
  }
}
Min5Heap::~Min5Heap()
{
  delete[] heap;
}
void Min5Heap::insert(int value)
{
  if(size == n)
  {
    std::cout << "The heap is full\n";
    return;
  }
  heap[size] = value;
  size++;
}
void Min5Heap::remove(int value)
{
  bool removed = true;
  if(size == 0)
  {
    std::cout << "The heap is empty\n";
    return;
  }
  if(size == 1)
  {
    deleteMin();
  }
  else
  {
    while(removed == true)
    {
      removed = false;
      for(int i =0; i < size; i++)
      {
        if(heap[i] == value)
        {
          heap[i] = heap[size-1];
          heap[size-1] = -1;
          size--;
          downHeap(size-1);
          removed = true;
        }
      }
    }
  }
}
void Min5Heap::deleteMin()
{
  if(size == 0)
  {
    std::cout << "The heap is empty\n";
    return;
  }
  heap[0] = heap[size-1];
  heap[size-1] = -1;
  size--;
  downHeap(size-1);
}
void Min5Heap::deleteMax()
{
  if(size == 0)
  {
    std::cout << "The heap is empty\n";
    return;
  }
  firstLeaf = floor(((size-2)/5)+1);
  max = firstLeaf;

  while(heap[firstLeaf] != -1)
  {
    if(heap[max] < heap[firstLeaf])
    {
      max = firstLeaf;
    }
    firstLeaf++;
  }
  heap[max] = heap[size-1];
  heap[size-1] = -1;
  size--;
  downHeap(size-1);

}
void Min5Heap::levelorder()
{
  std::cout << heap[0];
  std::cout << "-\n";
  for(int i = 1; i < size; i++)
  {
    std::cout << heap[i] << " ";
    if(i % 5 == 0)
    {
      std::cout << "-\n";
    }
  }
}
int Min5Heap::findParent(int ind)
{
  if(ind == 0)
  {
    return(0);
  }
  return(floor((ind-1)/5));

}
int Min5Heap::findChildren(int ind, int inc)
{
  return(((5*ind)+inc));
}
void Min5Heap::downHeap(int ind)
{


    smallChild = computeSmallestChild(ind);
    if(smallChild > (size -1))
    {
      return;
    }
    else if(heap[smallChild] == -1)
    {
      return;
    }
    else if(heap[smallChild] < heap[ind])
    {
      temp = heap[smallChild];
      heap[smallChild] = heap[ind];
      heap[ind] = temp;
      downHeap(smallChild);
    }
    else
    {
      //  std::cout << "test5 ";
        return;
    }
/*
  if(ind == -1)
  {
    return;
  }
  else
  {
    parent = findParent(ind);
    smallChild = computeSmallestChild(parent);
    if(heap[smallChild] == -1)
    {
      //std::cout << "test2 ";
      downHeap(parent-1);


    }
    else if(smallChild > (size -1))
    {
      //std::cout << "test3 ";
      downHeap(parent-1);
    }
    else if(heap[smallChild] < heap[parent])
    {
      //std::cout << "test4 ";
      temp = heap[smallChild];
      heap[smallChild] = heap[parent];
      heap[parent] = temp;
      downHeap(smallChild);
    }
    else
    {
      //  std::cout << "test5 ";
      downHeap(parent-1);
    }
  }
  */
}
int Min5Heap::computeSmallestChild(int ind)
{
  smallChild = findChildren(ind, 1);
  if(smallChild > size - 1)
  {
    return(smallChild);
  }
  if(heap[smallChild] == -1)
  {
    return(smallChild);
  }
  else
  {
    for(int i = 1; i < 6; i++)
    {
      child = findChildren(ind, i);
      if(child > size -1)
      {
        return(smallChild);
      }
      if(heap[child] == -1)
      {
          return(smallChild);
      }
      else if(heap[child] == heap[smallChild])
      {
        smallChild = smallChild;
      }
      else if(heap[child] < heap[smallChild])
      {
        smallChild = child;
      }
    }
  }
  return(smallChild);
}
bool Min5Heap::findValue(int val)
{
  int s = 0;
  while(heap[s] != -1)
  {
    if(heap[s] == val)
    {
      return(true);
    }
    s++;
  }
  return(false);
}

void Min5Heap::heapify()
{
  int index = findParent(size-1);
//  std::cout << index;

  while(index != -1)
  {
    downHeap(index);
    index--;
  }
}

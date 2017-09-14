#include "MinMaxHeap.h"

MinMaxHeap::MinMaxHeap()
{
  n = 400000;
  n = (n+(n*.1));
  parent = 0;
  size = 0;
//  swap = false;
  insertion = 1;
  heap= new int[n];
  for(int i = 0; i < n; i++)
  {
    heap[i] = -1;
  }
}
MinMaxHeap::~MinMaxHeap()
{
  delete[] heap;
}
void MinMaxHeap::bottomUp()
{
  int index = size;
  while(index != 0)
  {
    trickleDown(index);
    index--;
  }

}
void MinMaxHeap::initialInsert(int value)
{
  heap[insertion] = value;
  insertion++;
  size++;
}
void MinMaxHeap::insert(int value)
{
  heap[insertion] = value;
  insertion++;
  size++;
  bubbleUp(size);
}
void MinMaxHeap::levelorder()
{
  std::cout << heap[1];
  std::cout << "\n";
  for(int i = 2; i < size+1; i++)
  {
    std::cout << heap[i] << " ";
    if(i % 2 == 1)
    {
      std::cout << "-\n";
    }
  }
}
int MinMaxHeap::findParent(int ind)
{
  if(ind == 0)
  {
    return(0);
  }
  parent = floor((ind-1)/2);
  if(heap[parent] == -1)
  {
    return(-1);
  }
  return(parent);

}
int MinMaxHeap::findChild(int ind)
{
   child = (2*ind);
   return(child);
}
void MinMaxHeap::deleteMin()
{
  if(size == 0)
  {
    std::cout << "The heap is empty\n";
    return;
  }
  if(size == 1)
  {
    heap[1] == -1;
    size--;
    return;
  }
  else if(size < 4 && size > 1)
  {
    heap[1] = heap[computeSmallestChild(1)];
    heap[computeSmallestChild(1)] == heap[size];
    heap[size] = -1;
    size--;
    trickleDownMin(computeSmallestChild(1));
  }
  else
  {
    int swap =computeSmallestChild(findChild(1));
    heap[1] = heap[swap];
    heap[swap] = heap[size];
    heap[size] = -1;
    size--;
    trickleDownMin(swap);
  }
}
void MinMaxHeap::deleteMax()
{
  if(size == 0)
  {
    std::cout << "The heap is empty\n";
    return;
  }
  if(size == 1)
  {
    heap[1] == -1;
    size--;
    return;
  }
  if(size < 4)
  {
    heap[computeLargestChild(1)] == -1;
    size--;
    return;
  }
  else if( size < 11)
  {
    swap = computeLargestChild(computeLargestChild(1));
    heap[computeLargestChild(1)] = heap[swap];
    heap[swap] = heap[size];
    heap[size] = -1;
    size--;
    trickleDownMax(swap);
  }
  else
  {
    swap = computeLargestChild(findChild(computeLargestChild(1)));
    heap[computeLargestChild(1)] = heap[swap];
    heap[swap] = heap[size];
    heap[size] = -1;
    size--;
    trickleDownMax(swap);
  }
}
int MinMaxHeap::findChildren(int ind, int inc)
{
  return(((2*ind)+inc));
}
int MinMaxHeap::computeSmallestChild(int ind)
{
  smallChild = findChildren(ind, 0);
  if(smallChild > size)
  {
    return(smallChild);
  }
  if(heap[smallChild] == -1)
  {
    return(smallChild);
  }
  else
  {
    for(int i = 0; i < 2; i++)
    {
      child = findChildren(ind, i);
      if(child > size)
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
int MinMaxHeap::computeLargestChild(int ind)
{
  largeChild = findChildren(ind, 0);
  if(largeChild > size)
  {
    return(largeChild);
  }
  if(heap[largeChild] == -1)
  {
    return(largeChild);
  }
  else
  {
    for(int i = 0; i < 2; i++)
    {
      child = findChildren(ind, i);
      if(child > size)
      {
        return(largeChild);
      }
      if(heap[child] == -1)
      {
          return(largeChild);
      }
      else if(heap[child] == heap[largeChild])
      {
        largeChild = largeChild;
      }
      else if(heap[child] > heap[largeChild])
      {
        largeChild = child;
      }
    }
  }
  return(largeChild);
}
int MinMaxHeap::computeSmallestLeaf(int ind)
{
  firstLeaf = floor(((size-1)/2)+1);
  min = firstLeaf;

  while(heap[firstLeaf] != -1)
  {
    if(heap[min] < heap[firstLeaf])
    {
      min = firstLeaf;
    }
    firstLeaf++;
  }
  return(min);
}
int MinMaxHeap::computeLargestLeaf(int ind)
{
  firstLeaf = floor(((size-1)/2)+1);
  max = firstLeaf;

  while(heap[firstLeaf] != -1)
  {
    if(heap[max] < heap[firstLeaf])
    {
      max = firstLeaf;
    }
    firstLeaf++;
  }
  return(min);
}
bool MinMaxHeap::hasChildren(int ind)
{
  if(findChildren(ind, 0) > n)
  {
    return(false);
  }
  if(heap[findChildren(ind, 0)] == -1)
  {
    return(false);
  }
  else
  {
    return(true);
  }
}
bool MinMaxHeap::isGrandChild(int ind, int child)
{
  if(findChild(computeSmallestChild(ind)) > n)
  {
    return(false);
  }
  if(heap[findChild(computeSmallestChild(ind))] != -1)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}
void MinMaxHeap::trickleDown(int ind)
{
  if((int)(floor((log2(ind))))%2 == 0)
  {
          trickleDownMin(ind);
  }
  else
  {
          trickleDownMax(ind);
  }
}
void MinMaxHeap::trickleDownMin(int ind)
{

  int m;
  int temp;
  if(hasChildren(ind))
  {

      m = computeSmallestChild(ind);

      if(hasChildren(m))
      {
        //std::cout << "m5 ";

        if(heap[m] > heap[computeSmallestChild(m)])
        {
          m = computeSmallestChild(m);
        }
      }


      if(isGrandChild(ind, m))
      {
        if(heap[m] < heap[ind])
        {
        //  std::cout << "m3 ";

          //swap A[i] and A[m]
          temp = heap[ind];
          heap[ind] = heap[m];
          heap[m] = temp;
          if((findParent(m) != -1) && (heap[m] > heap[findParent(m)]))
          {
            //swap A[i] < A[parent(m)]
            temp = heap[ind];
            heap[ind] = heap[findParent(m)];
            heap[findParent(m)] = temp;
          }
            trickleDownMin(m);
        }
      }
    else
    {
      if(heap[m] < heap[ind])
      {
        //std::cout << "m4 ";

        //swap A[i] and A[m]
        temp = heap[ind];
        heap[ind] = heap[m];
        heap[m] = temp;
      }
    }

  }
}
void MinMaxHeap::trickleDownMax(int ind)
{
  int m;
  int temp;
  if(hasChildren(ind))
  {

    m = computeLargestChild(ind);

    if(hasChildren(m))
    {
      //std::cout << "m6 ";
      if(heap[m] > heap[computeLargestChild(m)])
      {
        m = computeLargestChild(m);
      }
    }
      if(isGrandChild(ind, m))
      {
      //  std::cout << "m7 ";
        if(heap[m] > heap[ind])
        {
          //swap A[i] and A[m]
          temp = heap[ind];
          heap[ind] = heap[m];
          heap[m] = temp;
          if((findParent(m) != -1) && (heap[m] < heap[findParent(m)]))
          {
            //swap A[i] < A[parent(m)]
            temp = heap[ind];
            heap[ind] = heap[findParent(m)];
            heap[findParent(m)] = temp;
          }
            trickleDownMax(m);
        }
      }
    else
    {
      if(heap[m] > heap[ind])
      {

        //swap A[i] and A[m]
        temp = heap[ind];
        heap[ind] = heap[m];
        heap[m] = temp;
      }
    }
  }
}
void MinMaxHeap::bubbleUpMin(int ind)
{
  if(findParent(findParent(ind)) != -1)
  {
    if(heap[ind] < heap[findParent(findParent(ind))])
    {
      temp = heap[ind];
      heap[ind] = heap[findParent(findParent(ind))];
      heap[findParent(findParent(ind))] = temp;
      bubbleUpMin(findParent(findParent(ind)));
    }
  }
}
void MinMaxHeap::bubbleUpMax(int ind)
{
  if(findParent(findParent(ind)) != -1)
  {
    if(heap[ind] > heap[findParent(findParent(ind))])
    {
      temp = heap[ind];
      heap[ind] = heap[findParent(findParent(ind))];
      heap[findParent(findParent(ind))] = temp;
      bubbleUpMin(findParent(findParent(ind)));
    }
  }
}
void MinMaxHeap::bubbleUp(int ind)
{
  if(findParent(ind) != -1)
  {
    if((int)(floor(log(ind)))%2 == 0)
    {
      if((findParent(ind) != -1) && (heap[ind] > heap[findParent(ind)]))
      {
        temp = heap[ind];
        heap[ind] = heap[findParent(ind)];
        heap[findParent(ind)] = temp;
        bubbleUpMax(findParent(ind));
      }
      else
      {
        bubbleUpMin(ind);
      }
    }
    else
    {
      if((findParent(ind) != -1) && (heap[ind] < heap[findParent(ind)]))
      {
        temp = heap[ind];
        heap[ind] = heap[findParent(ind)];
        heap[findParent(ind)] = temp;
        bubbleUpMin(findParent(ind));
      }
      else
      {
        bubbleUpMax(ind);
      }
    }
  }
}

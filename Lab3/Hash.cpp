#include "Hash.h"

Hash::Hash()
{
    std::ifstream fin;
    fin.open("data.txt");
    fin >> m;
    arr = new Node*[m];
    for(int i = 0; i < m; i++)
    {
      temp = new Node();
      arr[i] = temp;
    }
}
Hash::~Hash()
{
  for(int i = 0; i < m; i++)
  {
      delete arr[i];
  }
      delete arr;
}
bool Hash::insert(int value)
{
    if(isFull())
    {
        std::cout << "Table is full!\n";
        return(false);
    }
    else
    {
      if(hash(value)==true)
      {
        arr[hashNum]->setValue(value);
        return(true);
      }
      else
      {
        std::cout << "Value could not be added\n";
        return(false);
      }
    }
    return(false);
}
bool Hash::remove(int value)
{
   if(contains(value))
   {
     arr[hashNum]->setFlag(true);
     arr[hashNum]->setValue(-1);
     return(true);
   }
   else
   {
     std::cout << "Value not found!\n";
     return(false);
   }
}
void Hash::print()
{
  for(int i = 0; i < m; i++)
  {
    std::cout << arr[i]->getValue() << "\n";
  }
}
bool Hash::hash(int value)
{
  for(int i = 0; i < m; i++)
  {
    hashNum=((value%m)+i)%m;
    if(arr[hashNum]->getValue() == -1)
    {
      return(true);
    }
  }
  return(false);
}
bool Hash::contains(int value)
{
  for(int i = 0; i < m; i++)
  {
    hashNum=((value%m)+i)%m;
    if((arr[hashNum]->getValue() == -1) && (arr[hashNum]->getFlag() == false))
    {
      return(false);
    }
    if(arr[hashNum]->getValue()== value)
    {
      return(true);
    }
  }

  return(false);

}
bool Hash::isFull()
{

  for(int i =0; i < m; i++)
  {
    if(arr[i]->getValue() == -1)
    {
      return(false);
    }
  }
  return(true);

}

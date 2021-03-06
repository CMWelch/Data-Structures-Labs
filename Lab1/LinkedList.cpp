/**
*	@file : LinkedList.cpp
*	@author : Connor Welch
*	@date : 2016.08.26
*	Purpose: Implementation of LinkedList class
*/
#include "LinkedList.h"
LinkedList::LinkedList() //constructor, initializes m_front and m_size
{
	m_front=nullptr;
	m_size=0;
}
LinkedList::~LinkedList() //deletes values from the list when program is terminated
{
	while(m_size>0)
	{
		removeBack();
	}
}
bool LinkedList::isEmpty() const //determines if the list is empty
{
	if(m_size==0)
	{
		return(true);
	}	
	else
	{
		return(false);
	}
}
int LinkedList::size() const //returns m_size
{
	return(m_size);
}
void LinkedList::printList() const //prints out the values in the list
{
	if(isEmpty())
	{
                std::cout << "The list is empty\n";
	}
	Node* find= m_front;
	while(find != nullptr)
	{
                std::cout << find->getValue() << " ";

		find=find->getNext();
	}
        std::cout << "\n";
}
void LinkedList::addBack(int value) //adds a value to the back of the list
{
	Node* last=nullptr;
	if(isEmpty())
	{
		m_front= new Node();
		m_front->setValue(value);
		m_front->setNext(nullptr);
		m_size++;
		
	}
	else
	{
            if(search(value) == false)
            {
		last=m_front;
		while(last->getNext() != nullptr)
		{
			last=last->getNext();
		}
		Node* temp= new Node();
		temp->setValue(value);
		last->setNext(temp);
		m_size++;
              }
            else
            {
                std::cout << "Duplicate value found. It was not added.\n";
            }
		
			
	}
		
	
}
bool LinkedList::search(int value) const //searches for a specific value in the list
{
        if(isEmpty())
        {
                std::cout << "The list is empty\n";
                return(false);
        }
        Node* find= m_front;
        while(find != nullptr)
        {
                if(find->getValue()==value)
                {

                        return(true);
                }
                if(find->getNext() == nullptr)
                {

                        return(false);
                }
                else
                {
                        find=find->getNext();
                }
        }
        return(false);

}
bool LinkedList::removeBack() //removes a value from the back of the list
{
        if(isEmpty())
        {
                std::cout << "Can't remove from an empty list!\n";
                return(false);
        }
        if(m_size==1)
        {
                Node* temp = m_front;
                m_front=nullptr;
                delete temp;
                m_size--;

                return(true);
        }
        else
        {
                Node* last=m_front;
                Node* temp= nullptr;
                while(last->getNext() != nullptr)
                {
                        temp=last;
                        last=last->getNext();
                }
                temp->setNext(nullptr);
                delete last;
                m_size--;

                return(true);
        }


}

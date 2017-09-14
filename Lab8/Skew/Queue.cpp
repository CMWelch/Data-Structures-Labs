/**
*	@file : Queue.cpp
*	@author : Connor Welch
*	@date : 2016.9.27
*	Purpose: Implementation of Queue class
*/
#include "Queue.h"
Queue::Queue() //constructor, initializes m_front and m_size
{
	m_front=nullptr;
	m_size=0;
}

Queue::~Queue() //deletes values from the list when program is terminated
{
	while(m_size>0)
	{
		pop();
	}
}
bool Queue::isEmpty() const //determines if the list is empty
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
int Queue::size() const //returns m_size
{
	return(m_size);
}
void Queue::printList() const //prints out the values in the list
{
	if(isEmpty())
	{
                std::cout << "The list is empty\n";
	}
	qNode* find= m_front;
	while(find != nullptr)
	{
    std::cout << find->getValue() << " ";
		find=find->getNext();
	}
  std::cout << "\n";
}
void Queue::addBack(int value) //adds a value to the back of the list
{
	qNode* last=nullptr;
	if(isEmpty())
	{
		m_front= new qNode();
		m_front->setValue(value);
		m_front->setNext(nullptr);
		m_size++;

	}
	else
	{

			qNode* last=m_front;
			while(last->getNext() != nullptr)
			{
				last=last->getNext();
			}
			qNode* temp= new qNode();
			temp->setValue(value);
			last->setNext(temp);
			m_size++;

	}


}
bool Queue::search(int value) const //searches for a specific value in the list
{
        if(isEmpty())
        {
                std::cout << "The list is empty\n";
                return(false);
        }
        qNode* find= m_front;
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
int Queue::pop() //removes a value from the back of the list
{
        if(isEmpty())
        {
                std::cout << "Can't remove from an empty list!\n";
                return(0);
        }
        if(m_size==1)
        {
                qNode* temp = m_front;
								popValue = temp->getValue();
                m_front=nullptr;
                delete temp;
                m_size--;
                return(popValue);
        }
        else
        {
                qNode* temp = m_front;
								popValue = temp->getValue();
								m_front=m_front->getNext();
								delete temp;
								m_size--;
								return(popValue);
        }


}
bool Queue::remove(int value)
{
    if(isEmpty())
    {
        std::cout << "Can't remove from an empty list!\n";
        return(false);
    }
    if(m_size==1)
    {
        if(search(value))
        {
            qNode* temp = m_front;
            m_front = nullptr;
            delete temp;
            m_size--;
            return(true);
        }
        else
        {
            std::cout << "The value was not found the list will stay the same\n";
            return(false);
        }
    }
    else
    {
        if(search(value))
        {
            qNode* find= m_front;
                while(find->getNext() != nullptr)
                {
                    if(find->getNext()->getValue()==value)
                    {

                            qNode* temp = find->getNext();
                            find->setNext(find->getNext()->getNext());
                            delete temp;
                            m_size--;
                            return true;
                    }
                    else
                    {
                            find=find->getNext();
                    }
                }
            }

        }
return(false);
}


bool Queue::reverse(qNode* start)
{

    if(start->getNext() == nullptr)
    {
        m_front = start;
        return(true);
    }
    reverse(start->getNext());
    qNode* temp = start->getNext();
    temp->setNext(start);
    start->setNext(nullptr);



}
qNode* Queue::getFront()
{
    return(m_front);
}
bool Queue::concatenate(qNode* ptr)
{


    if(ptr==nullptr)
    {
        Queue queue2;
        int temp;
        std::ifstream fin2;
        fin2.open("data2.txt");
        while(fin2 >> temp)
        {
            queue2.addBack(temp);
        }
            fin2.close();
        newStart= queue2.getFront();
        concatenate(newStart);
    }
    else
    {
        if(newStart->getNext() == nullptr)
        {
           addBack(newStart->getValue());
           return(true);
        }
        else if (newStart->getNext() != nullptr)
        {
            addBack(newStart->getValue());
            newStart= newStart->getNext();
            concatenate(newStart);
        }
    }


}

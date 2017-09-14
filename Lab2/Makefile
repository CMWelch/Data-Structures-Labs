lab2: main.o Node.o LinkedList.o
	g++ -std=c++11 -g -Wall main.o Node.o LinkedList.o -o lab2
main.o: main.cpp Node.h LinkedList.h
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -Wall -c LinkedList.cpp
clean: 
	rm *.o lab2



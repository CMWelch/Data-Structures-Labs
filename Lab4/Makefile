lab4: main.o BinarySearchTree.o Node.o qNode.o Queue.o Timer.o
	g++ -Wall -std=c++11 -g main.o BinarySearchTree.o Node.o qNode.o Queue.o Timer.o -o lab4
main.o:  BinarySearchTree.h BinarySearchTree.cpp Node.h Node.cpp qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -Wall -std=c++11 -g -c Node.cpp
qNode.o: qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c qNode.cpp
Queue.o: qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c Queue.cpp
BinarySearchTree.o: Node.h Node.cpp BinarySearchTree.h BinarySearchTree.cpp Queue.h
	g++ -Wall -std=c++11 -g -c BinarySearchTree.cpp
Timer.o: Timer.cpp
	g++ -Wall -std=c++11 -g -c Timer.cpp
clean:
	rm *.o lab4

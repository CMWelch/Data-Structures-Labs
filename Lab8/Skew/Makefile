lab8: main.o Skew.o Node.o qNode.o Queue.o Timer.o
	g++ -Wall -std=c++11 -g main.o Skew.o Node.o qNode.o Queue.o Timer.o -o lab8
main.o:  Skew.h Skew.cpp Node.h Node.cpp qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -Wall -std=c++11 -g -c Node.cpp
qNode.o: qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c qNode.cpp
Queue.o: qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c Queue.cpp
Skew.o: Node.h Node.cpp Skew.h Skew.cpp Queue.h
	g++ -Wall -std=c++11 -g -c Skew.cpp
Timer.o: Timer.cpp
	g++ -Wall -std=c++11 -g -c Timer.cpp
clean:
	rm *.o lab8

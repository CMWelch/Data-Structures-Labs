lab8: main.o Leftist.o Node.o qNode.o Queue.o Timer.o
	g++ -Wall -std=c++11 -g main.o Leftist.o Node.o qNode.o Queue.o Timer.o -o lab8
main.o:  Leftist.h Leftist.cpp Node.h Node.cpp qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -Wall -std=c++11 -g -c Node.cpp
qNode.o: qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c qNode.cpp
Queue.o: qNode.h qNode.cpp
	g++ -Wall -std=c++11 -g -c Queue.cpp
Leftist.o: Node.h Node.cpp Leftist.h Leftist.cpp Queue.h
	g++ -Wall -std=c++11 -g -c Leftist.cpp
Timer.o: Timer.cpp
	g++ -Wall -std=c++11 -g -c Timer.cpp
clean:
	rm *.o lab8

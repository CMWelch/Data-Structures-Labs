lab7: main.o MinMaxHeap.o Timer.o
	g++ -Wall -std=c++11 -g main.o MinMaxHeap.o Timer.o -o lab7
main.o: MinMaxHeap.cpp MinMaxHeap.h
	g++ -Wall -std=c++11 -g -c main.cpp
MinMaxheap.o: MinMaxHeap.h MinMaxHeap.cpp
	g++ -Wall -std=c++11 -g -c MinMaxHeap.cpp
Timer.o: Timer.cpp
	g++ -Wall -std=c++11 -g -c Timer.cpp
clean:
	rm *.o lab7

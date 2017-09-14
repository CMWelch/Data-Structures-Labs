lab5: main.o Min5Heap.o Timer.o
	g++ -Wall -std=c++11 -g main.o Min5Heap.o Timer.o -o lab5
main.o: Min5Heap.cpp Min5Heap.h
	g++ -Wall -std=c++11 -g -c main.cpp
Min5heap.o: Min5Heap.h Min5Heap.cpp
	g++ -Wall -std=c++11 -g -c min5Heap.cpp
Timer.o: Timer.cpp
	g++ -Wall -std=c++11 -g -c Timer.cpp
clean:
	rm *.o lab5

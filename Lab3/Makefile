lab3: main.o Node.o Hash.o
	g++ -std=c++11 -g -Wall main.o Node.o Hash.o -o lab3
main.o: main.cpp Node.h Hash.h
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
Hash.o: Hash.h Hash.cpp
	g++ -std=c++11 -g -Wall -c Hash.cpp
clean: 
	rm *.o lab3



all: project1 project1.o

project1: project1.o 
		g++ -o project1 project1.o 
project1.o: project1.cpp
		g++ -c project1.cpp
clean:
		rm -f *.o project1
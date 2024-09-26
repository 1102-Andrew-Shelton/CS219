project1: main.o start.o hexopps.o start.h hexopps.h
		g++ main.o start.o start.h hexopps.h hexopps.o -o project1

main.o: main.cpp
	g++ -c main.cpp

start.o: start.cpp start.h
	g++ -c start.cpp start.h

hexopps.o: hexopps.cpp hexopps.h
	g++ -c hexopps.cpp hexopps.h

clean:
		rm *.o project1


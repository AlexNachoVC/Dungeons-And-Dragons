CXXFLAGS = -g -Wall --pedantic

main: main.o
	g++ $(CXXFLAGS) main.o -o main

main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp

clean: 
	rm *.o main

valgrind: main
	valgrind --leak-check=full ./main
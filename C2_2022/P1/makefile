# makefile simple
main: main.o Matriz2x2.o
	g++ -o main main.o Matriz2x2.o

main.o: main.cpp Matriz2x2.h 
	g++ -c main.cpp

Matriz2x2.o: Matriz2x2.cpp Matriz2x2.h
	g++ -c Matriz2x2.cpp

clean: 
	rm -rf *.o main

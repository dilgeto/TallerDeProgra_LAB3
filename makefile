FLAGS= -g -Wall

all: main

main: main.cpp Goloso.o Two_opt.o MatrizCosto.o Heuristica.o Edge.o
	g++ ${FLAGS} Goloso.o Two_opt.o Heuristica.o MatrizCosto.o Edge.o main.cpp -o MAIN
Goloso.o: Goloso.cpp Goloso.h
	g++ ${FLAGS} -c Goloso.cpp
Two-opt.o: Two_opt.cpp Two_opt.h
	g++ ${FLAGS} -c Two_opt.cpp
Heuristica.o: Heuristica.cpp Heuristica.h
	g++ ${FLAGS} -c Heuristica.cpp
MatrizCosto.o: MatrizCosto.cpp MatrizCosto.h
	g++ ${FLAGS} -c MatrizCosto.cpp
Edge.o: Edge.cpp Edge.h
	g++ ${FLAGS} -c Edge.cpp
clean:
	rm -f *.o MAIN

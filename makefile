FLAGS= -g -Wall

all: main

main: main.cpp Goloso.o Two_opt.o ACO.o MatrizCosto.o
	g++ ${FLAGS} Goloso.o Two_opt.o ACO.o MatrizCosto.o main.cpp -o MAIN
Goloso.o: Goloso.cpp Goloso.h
	g++ ${FLAGS} -c Goloso.cpp
Two-opt.o: Two_opt.cpp Two_opt.h
	g++ ${FLAGS} -c Two_opt.cpp
ACO.o: ACO.cpp ACO.h
	g++ ${FLAGS} -c ACO.cpp
MatrizCosto.o: MatrizCosto.cpp MatrizCosto.h
	g++ ${FLAGS} -c MatrizCosto.cpp
clean:
	rm -f *.o MAIN

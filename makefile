FLAGS= -g

all: main

main: main.cpp MatrizCostos.o
	g++ ${FLAGS} MatrizCostos.o main.cpp -o MAIN
MatrizCostos.o: MatrizCostos.cpp MatrizCostos.h
	g++ ${FLAGS} -c MatrizCostos.cpp
clean:
	rm -f *.o MAIN

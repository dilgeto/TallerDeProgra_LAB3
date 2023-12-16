FLAGS= -g -Wall

all: test_Edge test_Goloso test_Two_opt test_MatrizCosto test_Prim test_Annealing main 

main: main.cpp Goloso.o Two_opt.o Annealing.o MatrizCosto.o Comparator.o Edge.o Prim.o
	g++ ${FLAGS} Goloso.o Two_opt.o Annealing.o MatrizCosto.o Comparator.o Edge.o Prim.o main.cpp -o MAIN
test_Edge: Edge.o test_Edge.cpp
	g++ ${FLAGS} Edge.o test_Edge.cpp -o test_Edge
test_Goloso: MatrizCosto.o Goloso.o test_Goloso.cpp
	g++ ${FLAGS} MatrizCosto.o Goloso.o test_Goloso.cpp -o test_Goloso
test_Two_opt: MatrizCosto.o Two_opt.o test_Two_opt.cpp
	g++ ${FLAGS} MatrizCosto.o Two_opt.o test_Two_opt.cpp -o test_Two_opt
test_MatrizCosto: MatrizCosto.o test_MatrizCosto.cpp
	g++ ${FLAGS} MatrizCosto.o test_MatrizCosto.cpp -o test_MatrizCosto
test_Prim: MatrizCosto.o Edge.o Comparator.o Prim.o test_Prim.cpp
	g++ ${FLAGS} MatrizCosto.o Edge.o Comparator.o Prim.o test_Prim.cpp -o test_Prim
test_Annealing: MatrizCosto.o Annealing.o test_Annealing.cpp
	g++ ${FLAGS} MatrizCosto.o Annealing.o test_Annealing.cpp -o test_Annealing
Goloso.o: Goloso.cpp Goloso.h
	g++ ${FLAGS} -c Goloso.cpp
Two-opt.o: Two_opt.cpp Two_opt.h
	g++ ${FLAGS} -c Two_opt.cpp
Annealing.o: Annealing.cpp Annealing.h
	g++ ${FLAGS} -c Annealing.cpp
MatrizCosto.o: MatrizCosto.cpp MatrizCosto.h
	g++ ${FLAGS} -c MatrizCosto.cpp
Edge.o: Edge.cpp Edge.h
	g++ ${FLAGS} -c Edge.cpp
Comparator.o: Comparator.cpp Comparator.h
	g++ ${FLAGS} -c Comparator.cpp
Prim.o: Prim.cpp Prim.h
	g++ ${FLAGS} -c Prim.cpp
Tour.o: Tour.cpp Tour.h
	g++ ${FLAGS} -c Tour.cpp
clean:
	rm -f *.o MAIN test_Edge test_Goloso test_Two_opt test_MatrizCosto test_Prim test_Annealing

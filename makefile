FLAGS= -g

all: main

main: main.cpp
	g++ ${FLAGS} main.cpp -o MAIN
clean:
	rm -f *.o MAIN

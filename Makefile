all : add-nbo

add-nbo: main.o
	g++ -g -o add-nbo main.o

main.o:
	g++ -g -c -o main.o main.cpp

clean:
	rm -f add-nbo
	rm -f *.o

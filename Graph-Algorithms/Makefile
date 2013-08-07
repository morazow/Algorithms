CC= g++
CFLAGS= -Wall -g
LDFLAGS=

all: test

graph.o: graph.h graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp

main.o: graph.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test: graph.o main.o
	$(CC) $(CFLAGS) graph.o main.o $(LDFLAGS) -o test

clean:
	rm -rf *.o test

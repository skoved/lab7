GXX=g++
FLAGS=-std=c++11 -g 

all: test

test: lab7.o BSTree.o
	$(GXX) $(FLAGS) lab7.o BSTree.o -o lab7

test6: lab6.o BSTree.o
	$(GXX) $(FLAGS) lab6.o BSTree.o -o lab6

lab7.o: lab7.cpp
	$(GXX) $(FLAGS) -c lab7.cpp -o lab7.o

lab6.o: lab6.cpp
	$(GXX) $(FLAGS) -c lab6.cpp -o lab6.o

BSTree.o: BSTree.cpp BSTree.h
	$(GXX) $(FLAGS) -c BSTree.cpp -o BSTree.o

clean:
	rm *.o lab7 lab6

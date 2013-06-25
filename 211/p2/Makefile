#Makefile for 211 project 3 "Video Rating System"
#Ledbetter, Randy
#rml

#This rule creates the executable videos
videos: main.o video.o
	g++ -Wall -pedantic -g -o videos main.o video.o

#This rule creates the object file main.o
main.o: main.cpp video.h
	g++ -Wall -pedantic -g -c main.cpp

#This rule creates the object file video.o
video.o: video.h video.cpp
	g++ -Wall -pedantic -g -c video.cpp

#This rule tells make what to delete when the user types "make clean"
clean:
	rm -f main main.o video.o

run:
	make
	./run_tests videos



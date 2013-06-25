MSTapp : MSTapp.o MinPriority.o Graph.o 
	g++ -Wall -pedantic -g -o MSTapp MSTapp.o MinPriority.o Graph.o  -lrt

MSTapp.o : MSTapp.cpp MSTapp.h Graph.h
	g++ -Wall -pedantic -g -c MSTapp.cpp

Graph.o : Graph.cpp Graph.h MinPriority.h
	g++ -Wall -pedantic -g -c Graph.cpp

MinPriority.o : MinPriority.cpp MinPriority.h Graph.h
	g++ -Wall -pedantic -g -c MinPriority.cpp

clean :
	rm MSTapp *.o
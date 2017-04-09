all: server.out client.out 

server.out: Server.o Socket.o Udp.o Tcp.o AbstractNode.o Bfs.o Cab.o Driver.o FactoryCab.o Grid.o LuxuryCab.o MainFlow.o Matrix.o Node.o Passenger.o Point.o Searchable.o StandardCab.o TaxiCenter.o TripInformation.o Job.o InputValid.o ThreadPool.o
	g++ -std=c++0x -D _DISABLE_LOGS -pthread  Server.o Socket.o Udp.o Tcp.o AbstractNode.o Bfs.o Cab.o Driver.o FactoryCab.o Grid.o LuxuryCab.o MainFlow.o Matrix.o Node.o Passenger.o Point.o Searchable.o StandardCab.o TaxiCenter.o TripInformation.o Job.o InputValid.o ThreadPool.o  -lboost_serialization -I. -o server.out

client.out: Client.o  Socket.o Udp.o Tcp.o AbstractNode.o Bfs.o Cab.o Driver.o FactoryCab.o Grid.o LuxuryCab.o MainFlow.o Matrix.o Node.o Passenger.o Point.o Searchable.o StandardCab.o TaxiCenter.o TripInformation.o Job.o InputValid.o ThreadPool.o
	g++ -std=c++0x -D _DISABLE_LOGS -pthread Client.o Socket.o Udp.o Tcp.o AbstractNode.o Bfs.o Cab.o Driver.o FactoryCab.o Grid.o LuxuryCab.o MainFlow.o Matrix.o Node.o Passenger.o Point.o Searchable.o StandardCab.o TaxiCenter.o TripInformation.o Job.o InputValid.o ThreadPool.o -lboost_serialization -I. -o client.out

Client.o: src/Client.cpp src/Client.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Client.cpp

Server.o: src/Server.cpp
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Server.cpp

Socket.o: src/Socket.cpp src/Socket.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Socket.cpp

Udp.o: src/Udp.cpp src/Udp.h src/Socket.h src/Socket.cpp
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Udp.cpp src/Socket.cpp

Tcp.o: src/Tcp.cpp src/Tcp.h src/Socket.h src/Socket.cpp
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Tcp.cpp src/Socket.cpp

AbstractNode.o: src/AbstractNode.cpp src/AbstractNode.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/AbstractNode.cpp

Bfs.o: src/Bfs.cpp src/Bfs.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Bfs.cpp

Cab.o: src/Cab.cpp src/Cab.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Cab.cpp

Driver.o: src/Driver.cpp src/Driver.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Driver.cpp

FactoryCab.o: src/FactoryCab.cpp src/FactoryCab.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/FactoryCab.cpp

Grid.o: src/Grid.cpp src/Grid.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Grid.cpp

LuxuryCab.o: src/LuxuryCab.cpp src/LuxuryCab.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/LuxuryCab.cpp

MainFlow.o: src/MainFlow.cpp src/MainFlow.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/MainFlow.cpp

Matrix.o: src/Matrix.cpp src/Matrix.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Matrix.cpp

Node.o: src/Node.cpp src/Node.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Node.cpp

Passenger.o: src/Passenger.cpp src/Passenger.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Passenger.cpp

Point.o: src/Point.cpp src/Point.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Point.cpp

Searchable.o: src/Searchable.cpp src/Searchable.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Searchable.cpp

StandardCab.o: src/StandardCab.cpp src/StandardCab.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/StandardCab.cpp

TaxiCenter.o: src/TaxiCenter.cpp src/TaxiCenter.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/TaxiCenter.cpp

TripInformation.o: src/TripInformation.cpp src/TripInformation.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/TripInformation.cpp

Job.o: src/Job.cpp src/Job.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/Job.cpp

InputValid.o: src/InputValid.cpp src/InputValid.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/InputValid.cpp

ThreadPool.o: src/ThreadPool.cpp src/ThreadPool.h
	g++ -std=c++0x -c -D _DISABLE_LOGS -pthread src/ThreadPool.cpp

clean:
	rm -f *.o a.out

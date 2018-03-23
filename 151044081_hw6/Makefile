all: exe

exe: _mainTester.o CPU.o CPUPROGRAMDYN.o COMPUTER.o Memory.o
	g++ _mainTester.o CPU.o CPUPROGRAMDYN.o COMPUTER.o Memory.o -o exe

_mainTester.o: _mainTester.cpp
	g++ -c -std=c++11 _mainTester.cpp

CPU.o: CPU.cpp
	g++ -c -std=c++11 CPU.cpp

CPUPROGRAMDYN.o: CPUPROGRAMDYN.cpp
	g++ -c -std=c++11 CPUPROGRAMDYN.cpp

COMPUTER.o: COMPUTER.cpp
	g++ -c -std=c++11 COMPUTER.cpp

Memory.o: Memory.cpp
	g++ -c -std=c++11 Memory.cpp

clean:
	rm *.o exe


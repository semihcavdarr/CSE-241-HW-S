all: exe

exe: main.o CPU.o CPUPROGRAM.o COMPUTER.o Memory.o
	g++ main.o CPU.o CPUPROGRAM.o COMPUTER.o Memory.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

CPU.o: CPU.cpp
	g++ -c -std=c++11 CPU.cpp

CPUPROGRAM.o: CPUPROGRAM.cpp
	g++ -c -std=c++11 CPUPROGRAM.cpp

COMPUTER.o: COMPUTER.cpp
	g++ -c -std=c++11 COMPUTER.cpp

Memory.o: Memory.cpp
	g++ -c -std=c++11 Memory.cpp

clean:
	rm *.o exe

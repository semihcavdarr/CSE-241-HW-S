all: exe

exe: main.o CPU.o CPUPROGRAM.o
	g++ main.o CPU.o CPUPROGRAM.o  -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

CPU.o: CPU.cpp
	g++ -c -std=c++11 CPU.cpp

CPUPROGRAM.o: CPUPROGRAM.cpp
	g++ -c -std=c++11 CPUPROGRAM.cpp

clean:
	rm *.o exe

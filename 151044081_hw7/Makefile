all: exe

exe: _mainTester.o BigramDyn.o BigramMap.o DynamicArray.o
	g++ _mainTester.o BigramDyn.o BigramMap.o DynamicArray.o -o exe

_mainTester.o: _mainTester.cpp
	g++ -c -std=c++11 _mainTester.cpp

BigramDyn.o: BigramDyn.cpp
	g++ -c -std=c++11 BigramDyn.cpp

BigramMap.o: BigramMap.cpp
	g++ -c -std=c++11 BigramMap.cpp

DynamicArray.o: DynamicArray.cpp
	g++ -c -std=c++11 DynamicArray.cpp

clean:
	rm *.o exe


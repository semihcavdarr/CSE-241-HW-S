#ifndef MEMORY_H
#define MEMORY_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Memory{

public:

	Memory();
	Memory(char **);
	int get_memory(int i);//döndürülecek lokasyon
	void set_memory(int i, int j);//i.lokasyona set edilecek j değeri

	void setoption(int);//option setter'ı

	int getoption()const ;//option getter'ı

private:

	unsigned int memory[50];//50'lik unsigned memory dizisi

	int option;

};


#endif

#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "CPU.h"
#include "CPUPROGRAMDYN.h"
#include "Memory.h"
using namespace std;

using namespace SemihC;

class Computer{

public:

	Computer(CPU &, CPUProgramDyn &, Memory &, char **);//cpu obj,cpuprogram obj,memory obj,option


	CPU get_cpu()const;//cpu getterı

	CPUProgramDyn get_cpu_prog()const;//cpuprogram getterı

	Memory get_mem()const;//memory getterı

	int get_opt()const;//option getter'ı

	void setoption(int);//option setter'ı

	void set_c(CPU &);//cpu setterı

	void set_cpu_p(CPUProgramDyn &);//cpuprogram setterı

	void set_m(Memory &);//memory setterı

	void execute();// execute fonksiyonu



private:

	Memory memory;

	CPU myCPU;

	CPUProgramDyn myProg;

	int option;


};



#endif 

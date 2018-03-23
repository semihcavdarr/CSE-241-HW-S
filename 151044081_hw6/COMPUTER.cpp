#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "COMPUTER.h"

using namespace SemihC;

Computer::Computer(CPU &obj_cpu, CPUProgramDyn &obj_cpu_prog, Memory &obj_mem, char ** argv){

	set_c(obj_cpu);

	set_cpu_p(obj_cpu_prog);

	set_m(obj_mem);

	int option = argv[2][0] - 48;//stringi inte çevirdim

	obj_cpu.set_option(option);

}

int Computer::get_opt() const{

	return option;

}


CPU Computer::get_cpu() const{

	return myCPU;

}
CPUProgramDyn Computer::get_cpu_prog() const{

	return myProg;

}

Memory Computer::get_mem() const{

	return memory;

}

void Computer::setoption(int opt){

	int temp = get_opt();

	option = temp;

}

void Computer::set_c(CPU &obj){

	myCPU = obj;

}

void Computer::set_cpu_p(CPUProgramDyn &obj){

	myProg = obj;

}

void Computer::set_m(Memory &obj){

	memory = obj;

}

void Computer::execute(){//programı tekte çalıştırır.

	while (!myCPU.halted()){


		string instruction = myProg.getLine(myCPU.getPC());

		myCPU.execute(instruction, memory);

	}

}

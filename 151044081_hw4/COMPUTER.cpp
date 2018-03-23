#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "COMPUTER.h"

COMPUTER::COMPUTER(CPU &obj_cpu, CPUPROGRAM &obj_cpu_prog, Memory &obj_mem, char ** argv){

	set_c(obj_cpu);

	set_cpu_p(obj_cpu_prog);

	set_m(obj_mem);

	int option = argv[2][0] - 48;//stringi inte çevirdim

	obj_cpu.set_option(option);

}

int COMPUTER::get_opt() const{

	return option;

}


CPU COMPUTER::get_cpu() const{

	return myCPU;

}
CPUPROGRAM COMPUTER::get_cpu_prog() const{

	return myProg;

}

Memory COMPUTER::get_mem() const{

	return memory;

}

void COMPUTER::setoption(int opt){

	int temp = get_opt();

	option = temp;

}

void COMPUTER::set_c(CPU &obj){

	myCPU = obj;

}

void COMPUTER::set_cpu_p(CPUPROGRAM &obj){

	myProg = obj;

}

void COMPUTER::set_m(Memory &obj){

	memory = obj;

}

void COMPUTER::execute(){//programı tekte çalıştırır.

	while (!myCPU.halted()){


		string instruction = myProg.getLine(myCPU.getPC());

		myCPU.execute(instruction, memory);

	}

}

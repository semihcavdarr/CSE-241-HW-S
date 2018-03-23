#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Memory.h"
using namespace std;

Memory::Memory(char **argv){

	int option=argv[2][0]-48;//stringi int'e çevirdim.

	setoption(option);

}

Memory::Memory(){

}

void Memory::setoption(int option){

	option = option;
}
int Memory::getoption()const{
	return option;

}

int Memory::get_memory(int i){



	return memory[i];//memory'nin i.değerini döndürür.

}

void Memory::set_memory(int i, int j){

	memory[i] = j;//j değerini memory'nin i. değerine atar.

}



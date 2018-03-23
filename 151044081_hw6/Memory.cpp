#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Memory.h"
using namespace std;

Memory::Memory(int option){

	setoption(option);

}

Memory::Memory(){

}

void Memory::setoption(int option1){

	option = option1;
}
int Memory::getoption()const{
	return option;

}

int Memory::getMem(int i){



	return memory[i];//memory'nin i.değerini döndürür.

}

void Memory::setMem(int i, int j){

	memory[i] = j;//j değerini memory'nin i. değerine atar.

}

void Memory :: printAll()const
{
	for(int i=0 ; i<50; ++i)
		cout <<"#"<<i<<" = "<<memory[i] << endl;
}

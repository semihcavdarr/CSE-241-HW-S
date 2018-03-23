#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "COMPUTER.h"
#include "CPUPROGRAM.h"
#include "CPU.h"
#include "Memory.h"
using namespace std;
/*
*************************************************************************************************************
Hocam ben 4 parametreli computer objesi oluşturdum onu çalıştırabiliyorum fakat pdfteki gibi
sadece option parametresi ile compile edemedim memory,cpu,cpuprogram classlarımda tek parametre olarak option
alan constructorlarım var fakat bunları computer(option) constructor'ı içinde çağıramadım.
*************************************************************************************************************
*/




int main(int argc, char** argv) {
	
	CPUPROGRAM myProg(argv[1]);//filename parametresi
    
    CPU myCPU(1,argc,argv);//pc ,argc,argv parametresi
    
    Memory memory;

	COMPUTER a(myCPU,myProg,memory,argv);

	a.execute(); 
	return 0;
}


#include "CPU.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "CPUPROGRAM.h"

using namespace std;

int main(int argc, char** argv) {
    
    CPUPROGRAM myProg(argv[1]);//filename parametresi
    
    CPU myCPU(1,argc,argv);//pc ,argc,argv parametresi
    
    while(!myCPU.halted()){//halted false döndürdüğü sürece
        
        string instruction = myProg.getLine(myCPU.getPC());//getPC ile sayı al
        //getline ile bu sayıya denk gelen satırı al instruction'a ata
  
        myCPU.execute(instruction); //instruction'ı execute et.

        
    }

    return 0;
}


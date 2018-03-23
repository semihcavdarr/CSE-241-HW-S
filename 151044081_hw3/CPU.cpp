#include "CPU.h"
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

CPU::CPU(int pc,int argc, char** argv){//constructor dosya ve argüman kontrolü yapar.
    
    int option1 =sToMyInt(argv[2]);//argv[2] bir string int'e çevirip 
    
    set_option(option1);//option'a atadım.

    set_register(arrayOfRegister,0);//ilk register değerleri 0 oldu.

    set_pc(pc);//ilk pc değeri 


//Dosya ve argüman kontrolü
        
    ifstream file;

    if(argc!=3){//eksik yada fazla argüman girişi kontrolü
	
        cerr<<"Argüman hatası.";

        exit(1);

    }
    
    if(!(sToMyInt(argv[2]) == 0 || sToMyInt(argv[2]) == 1)){//option'ın 1 yada 0 olmaması durumu kontrolü
		
        cerr << "argv[2] için yanlış input."<<endl;
        
        exit(1);
		
    }
    
    file.open(argv[1]);//Dosyayı aç
    
    if (file.fail()){// Dosyanın açılıp açılmama kontrolü
        
        cerr << "Dosya açılamadı";
        
        exit(1);
    }
    
    else
        
        file.close();
//Kontroller bitti.
}

const int CPU::get_register(int i)const {//register değerini döndürür.

    return arrayOfRegister[i];

}
const int CPU::getPC ()const{//PC değerini döndürür.
    
    return PC;
}
const int CPU::get_option()const{//option değerini döndürür.

    return option;

}
const void CPU::set_register(int *array ,int first_value_for_register){//register değelerini gelen integer ile doldurur.

    const int numberOfRegister = 5;

    for (int i = 0 ; i < numberOfRegister ;i++){

        array[i]=first_value_for_register;


    }
	
}
const void CPU::set_option(int option1){//option setter'ı
    
    option=option1;
    
}
const void CPU::set_pc(int prog_c){//PC setter'ı

    PC = prog_c;

}
const void CPU::print(int *array,int pc){//register değerlerini ve PC'yi print eder.

    const int numberOfRegister = 5;

    for (int i = 0 ; i <numberOfRegister ; i++){

        cout<<"R"<<i<<"="<< array[i]<<endl;

    }

    cout<<"PC="<<pc<<endl;

}
const bool CPU::halted(){

	
    return temp_halted;

}
const void CPU::execute(string &instruction){//gelen instructionları çalıştırır.
    
    string str1,str2,str3;
    
    int idx1,temp,pr_c;
    
    pr_c=getPC();
    
    int opt1=get_option();

    if(instruction[0] == 'H' && instruction[1] == 'L' && instruction[2] == 'T'){
		//HLT komutundan sonra boşluk varsa program bu komutla haltı görür
		//ve sonlanır
		temp_halted = true;	

				
    }
    if(instruction.find(' ') != std::string::npos){//boşluğa bak 

		
        str1=instruction.substr(0,instruction.find(' '));//boşluktan öncesini al
		//str1' e ata
		

        str2=instruction.substr(instruction.find(' ')+1,instruction.find('\0'));
		//boşluktan bir sonraki karakterden string'in sonuna kadar al str2 ye ata
		
			
    }
    if(instruction.find(',') != std::string::npos){//virgülün indexini bul     

        str2=str2.substr(0,str2.find(','));//virgüle kadar olan kısmı
		//str 2'ye ata
		
    }
    str3=instruction.substr(instruction.find(',')+1,instruction.length()-instruction.find(','));
	//virgülden sonraki karakterden stringin sonuna kadar okur
	//str3' e atar.
	

    if(str1 == "MOV"){//str1 MOV'a eşitse 
						
        moving(str2,str3,arrayOfRegister);
		
				
    }
					
    else if(str1 == "ADD"){//str1 ADD'e eşitse
						
        adding(str2,str3,arrayOfRegister);
							
    }
					
    else if(str1 == "SUB"){//str1 SUB'a eşitse
						
        substraction(str2,str3,arrayOfRegister);
					
    }
			
    else if(str1 == "PRN"){//str1 SUB'a eşitse
						
        if(str2[0] == 'R')//str2[0]. elemanı R ise prn yi çağır
							
        {
            idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdim.

            prn(arrayOfRegister[idx1]);
							
        }
						
        else{//değilse prn2'yi çağır
							
             temp = sToMyInt(str2);//str2'yi int'e çevirdim
							
            prn2(temp);
							
        }
							
						
    }
					
    else if(str1 == "JMP"){//str1 JMP'ye eşitse
						
        jumping(str2,str3,arrayOfRegister,pr_c);
						
    }
    else if(str1 == "HLT"){//str1 HLT'ye eşitse flag true olur döngüden çıkar.

        temp_halted = true;

    }
    else{
						
        cerr<<"Syntax error.";//eğer str1 bunlardan birine eşit değilse hata ver
        
        exit(1);//programdan çık.
				
    }
    if(opt1){//option değerine göre output değişir.
			
        option1(arrayOfRegister,str1,str2,str3);
			
    }
    
    set_pc(getPC()+1);//PC 'yi sonraki instructiona geçmek için 1 arttır.
    

}

const void CPU::moving(string str2,string str3,int* arrayOfRegister){

    int idx1 , idx2 , temp ;

    if(str3[0] == 'R'){//2. parametrenin 1.karakteri R ile başlıyorsa
    //2 register parametreli mov fonksiyonunu çağırır.
                        
	idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdik
                
	idx2 = str3[1]-49; //str3[1]'in değerini int'e çevirdik
                        
	movR(arrayOfRegister[idx1],arrayOfRegister[idx2]);

    }
    
    else{//2. parametrenin 1.karakteri R ile başlamıyorsa 
	//1 register 1 constant parametreli mov fonksiyonunu çağırır.
                        
        idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdik
                        
        temp = sToMyInt(str3);//str3'ün int değerini temp'e atadık.
            
        movC(arrayOfRegister[idx1],temp);
                    
    }
}
const void CPU::substraction(string str2,string str3,int* arrayOfRegister){
    
    int idx1 , idx2 ;

    if(str3[0] == 'R'){//str3'ün 0. karakteri R'ye eşitse
                        
        idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdik
                
        idx2 = str3[1]-49; //str3[1]'in değerini int'e çevirdik
                    
        subR(arrayOfRegister[idx1],arrayOfRegister[idx2]);//subR fonksiyonunu çağır
              
    }

    else{//str3'ün 0. karakteri R'ye eşit değilse
                        
        idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdik
             
        int temp = sToMyInt(str3);//str3'ün integer değerini temp'e atadık.
                        
        subC(arrayOfRegister[idx1],temp);//subC foksiyonunu çağır
                        
    }

}
const void CPU::adding(string str2,string str3,int* arrayOfRegister){
    
    int idx1 , idx2 ;
    
    if(str3[0] == 'R'){//str3[0] R'ye eşitse 2 parametre de register
                        
        idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdik
                
        idx2 = str3[1]-49; //str3[1]'in değerini int'e çevirdik
                    
        add(arrayOfRegister[idx1],arrayOfRegister[idx2]);//add fonksiyonunu çağır
        
    }
                    
    else{//değilse biri register diğeri constant
                        
        idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdik
   
        int temp = sToMyInt(str3);//str3'ün integer değerini temp'e atadık.
                        
        add(arrayOfRegister[idx1],temp);// add fonksiyonunu çağır
                        
    }

}
const void CPU::jumping(string str2,string str3,int* arrayOfRegister,int &i){
    
    int idx1 ,temp ;
    
    if(str2[0] == 'R'){ //str2'nin 0. karakteri R'ye eşitse
        
        idx1 = str2[1]-49; //str2[1]'in değerini int'e çevirdik

        temp = sToMyInt(str3);//str3'ün integer değerini temp'e atadık.
            
        jump(arrayOfRegister[idx1],temp,i);//2 parametreli jump fonksiyonunu çağır

    }
    
    else{ //str2'nin 0. karakteri R'ye eşit değilse
                        
        temp = sToMyInt(str2);
                        
        jump(temp, i);//tek değişkenli jump fonksiyonunu çağır.

    }

}
const int CPU::movR(int &rX, int &rY){
    
    rY=rX ;
   
    return rY;
    
}

const int CPU::movC(int &rX,int &constant){
    
    rX=constant;

    return rX;
    
}

const int CPU::add(int &rX,int &rY){
    
    rX=rX+rY;

    return rX;
    
}

const int CPU::subR(int &rX,int &rY){
    
    rX=rX-rY;

    return rX;

}

const int CPU::subC(int &rX,int &constant){
    
    rX=rX-constant;

    return rX;
    
}

const void CPU::jump(int rX,int lineAdress, int &i){
    
    if( rX == 0){
        
        i = lineAdress - 1 ;//-1 dizi 0. indexten başladığı için
        
        set_pc(i);//i'yi pc'ye set et.
        
    }
    
}

const void CPU::jump(int lineAdress,int &i){
    
    i = lineAdress - 1 ;//-1 dizi 0. indexten başladığı için
    
    set_pc(i);//i'yi pc'ye set et.
    
}
const int CPU::pow(int x, int y)//pow fonksiyonu

{
    int toplam =1;

    for (int z = 0 ; z < y ; z++ ){

        toplam = toplam * x;
        
    }
    
    return toplam;
 
}
const void CPU::option1(int * arrayOfRegister,string str1,string str2,string str3){//option 1 olduğunda 
    //bulunan satırı ve registerları basar.
	
    const int numberOfRegister = 5 ;
	
    cout<<str1<<"  "<< str2 <<"  "<< str3 <<"  "<< endl;

    for(int f = 0 ;  f < numberOfRegister ; f++){

        cout<<"R"<< f <<"="<< arrayOfRegister[f]<<endl;	

    }

}
const int  CPU::sToMyInt(string str){
// stringin uzunluğunu bulup uzunluk sayısı kadar dönderip
    //her bir indexteki sayısı '0' dan çıkartıp int değerini buldum sonrasında 10
    //üzeri uzunluk-1 ile çarpıp sonucu buldum.
    
    int sonuc =0;
    
    int uzunluk=str.length();  
    
    for ( int x= 0 ; x < str.length() ; ++x){
         
        str[x]=(str[x]-'0')*pow(10,uzunluk-1);
                            
        sonuc=sonuc+str[x];

        uzunluk-=1;

    }
    
    return sonuc ;

}

const void CPU::prn(int &rX){//print register
    
    cout << rX << endl ;

}

const void CPU::prn2 (int constant){//print constant
    
    cout << constant << endl;
    
}

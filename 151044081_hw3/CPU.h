#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class CPU{
    
public:

    CPU(int,int ,char**);//option,argc,argv
    
    const int get_option()const;//option getter'ı
    const int get_register(int i) const;//register getter'ı
    const int getPC() const;//PC getter'ı
	
    const void set_option(int);//option setter'ı
    const void set_register(int *,int);//register setter'ı
    const void set_pc(int);//PC setter'ı

    

    const bool halted();//true döndüğünde mainde ki döngüden çıkmaya yarayan fonksiyon.

    const void execute(string &);//işlem fonksiyonu



private:
    const void print(int * ,int);//print eder.
    
    const void moving(string str2,string str3,int* arrayOfRegister);//yardımcı mov fonksiyonu

    const void substraction(string str2,string str3,int* arrayOfRegister);//yardımcı sub fonksiyonu

    const void adding(string str2,string str3,int* arrayOfRegister);//yardımcı add fonksiyonu

    const void jumping(string str2,string str3,int* arrayOfRegister,int &i);//yardımcı jump

    const int pow(int x, int y);//x üzeri y değerini hesaplar.

    const int movR(int &rX, int &rY);//rX'nin değerini rY'e atar

    const int movC(int &rX,int &constant);//Constant değerini rX'e atar

    const int add(int &rX,int &rY);//rX ve rY değerini toplar rX'e atar

    const int subR(int &rX,int &rY);//rY değerinden rX değerini çıkartır

    const int subC(int &rX,int &constant);//rY değerinden constant değerini çıkartır

    const void jump(int rX,int lineAdress, int &i);//rX 0 ise lineAdress'e gider.

    const void jump(int lineAdress, int &i);//direk lineAdress'e atlar

    const void prn(int &rX);//register'ı yazdırır

    const void prn2 (int constant);//constant'ı yazdırır.

    const void option1(int * arrayOfRegister,string str1,string str2,string str3);

    const int  sToMyInt(string str);//kendi stoi fonksiyonum
    
    
    int temp_halted=false;//halted için tuttuğum flag
    
    int arrayOfRegister[5];//array registerım

    int PC;//program counter
    
    int option ;//option seçeneğim.

};



#endif /* CPU_H */



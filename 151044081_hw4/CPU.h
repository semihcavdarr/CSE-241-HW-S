#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Memory.h"
using namespace std;


class CPU{

public:

	CPU(int );//option

	CPU(){}//pc,argc,argv (burda argc ve argv was not declared in this scope hatası veriyor tanımlı görmüyor)

	CPU(int, int, char**);//option,argc,argv

	const int get_option()const;//option getter'ı
	const int get_register(int i) const;//register getter'ı
	const int getPC() const;//PC getter'ı

	const void set_option(int);//option setter'ı
	const void set_register(int *, int);//register setter'ı
	const void set_pc(int);//PC setter'ı



	const bool halted();//true döndüğünde mainde ki döngüden çıkmaya yarayan fonksiyon.

	const void execute(string &, Memory & obj);//işlem fonksiyonu



private:

	const int calculate_idx(string str);//memory adresini bulan fonksiyon

	int movAdressToRegister(Memory & obj, int &rX, int idx);//adresteki değeri registera atar.

	int movRegisterToAdress(int &rX, Memory & obj, int idx);//registerda ki değeri adrese atar.

	int subAdressToRegister(int &rX, Memory & obj, int idx);//registarda ki değerden adresteki değeri çıkartır.

	int addAdressToRegister(Memory & obj, int &rX, int idx);//adresteki değeri registera ekler

	const void prnAdress(Memory & obj, int idx);//adresin değerini yazdırır.

	const void jpn(int &rX, int lineAdress, int &i);//rX 0'a eşit yada küçükse lineAdress'e atlar.

	int movConstantToAdress(Memory & obj, int constant, int idx);//constant değeri adrese atar.

	const void print(int *, int);//print eder.

	void moving(string str2, string str3, int arrayOfRegister[5], Memory & obj);//yardımcı mov fonksiyonu

	void substraction(string str2, string str3, int arrayOfRegister[5], Memory & obj);//yardımcı sub fonksiyonu

	void adding(string str2, string str3, int arrayOfRegister[5], Memory & obj);//yardımcı add fonksiyonu

	const void jumping(string str2, string str3, int arrayOfRegister[5], int &i);//yardımcı jump

	const int pow(int x, int y);//x üzeri y değerini hesaplar.

	const int movR(int &rX, int &rY);//rX'nin değerini rY'e atar

	const int movC(int &rX, int &constant);//Constant değerini rX'e atar

	const int add(int &rX, int &rY);//rX ve rY değerini toplar rX'e atar

	const int subR(int &rX, int &rY);//rY değerinden rX değerini çıkartır

	const int subC(int &rX, int &constant);//rY değerinden constant değerini çıkartır

	const void jump(int rX, int lineAdress, int &i);//rX 0 ise lineAdress'e gider.

	const void jump(int lineAdress, int &i);//direk lineAdress'e atlar

	const void prn(int &rX);//register'ı yazdırır

	const void prn2(int constant);//constant'ı yazdırır.

	const void option1( int arrayOfRegister[5], string str1, string str2, string str3);

	const void option2(int *arrayOfRegister, string str1, string str2, string str3, Memory & obj);
	//option değeri 2 ise hem her adımda register değelerini hemde her adımda memory değerlerini
	//ekrana basar.

	const int  sToMyInt(string str);//kendi stoi fonksiyonum


	int temp_halted = false;//halted için tuttuğum flag

	int arrayOfRegister[5];//array registerım

	int PC;//program counter

	int option;//option seçeneğim.

};
#endif

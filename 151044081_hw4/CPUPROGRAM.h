#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class CPUPROGRAM{

public:

	CPUPROGRAM(){}

	CPUPROGRAM(char ** );//option

	CPUPROGRAM(char * filename);//constructor

	void setter_option(int );//option setter'ı

	int getter_option()const;//option getter'ı

	const void set_txt(string, int);//düzenlediğim satırları attığım diziye set etmeye yarayan setter

	const void readFile(char *);//dosyayı açıp okuduğum fonksiyon

	const string getLine(int);//parametre olarak verilen integer'ın dizide hangi satıra geldiğini hesaplar 
	//o satırı döndürür.


private:
	const int size() const;//dosyada kaç satır olduğunu döndürür.

	const void strEdit(string &);//txt dosyasında ki satırları düzenler.

	int Size;//dosyada ki satır sayısı değişkenim.

	string txt[200];//max 200 satırlık txt olacağı için 200'lük bir string dizisi 

	int option;


};

#endif

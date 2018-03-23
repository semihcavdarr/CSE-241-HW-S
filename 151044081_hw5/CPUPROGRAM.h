#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

class CPUPROGRAM{

public:

	//Operator =,copy constructor,destructor are OK!

	CPUPROGRAM(){}

	CPUPROGRAM(int );//option

	CPUPROGRAM(char *filename);//constructor

	const int size() const;//dosyada kaç satır olduğunu döndürür.

	int increase_size() ;//ekleme yapılırsa size'ı arttırır.

	void setter_option(int );//option setter'ı

	int getter_option()const;//option getter'ı

	const void set_txt(string, int);//düzenlediğim satırları attığım diziye set etmeye yarayan setter

	const void readFile(string);//dosyayı açıp okuduğum fonksiyon

	const string getLine(int);//parametre olarak verilen integer'ın dizide hangi satıra geldiğini hesaplar 
	//o satırı döndürür.

	vector <string> operator + (const string);//+ overload

	vector <string> operator + (CPUPROGRAM &);// + overload

	const string& operator[](int);//index overload

	CPUPROGRAM& operator()(int,int)const ;//function call overload

	void operator+=(string );//+= overload

	void operator--(int);//postfix

	void operator--();//prefix

	friend ostream& operator<<(ostream& ,const CPUPROGRAM& );//ostream overload

	bool operator==(const CPUPROGRAM &rhs)const ;//eşit kontrolü

	bool operator!=(const CPUPROGRAM &rhs)const;//farklı kontrolü

	bool operator<(const CPUPROGRAM &rhs)const;//küçük kontrolü

	bool operator<=(const CPUPROGRAM &rhs)const;//küçük eşit kontrolü

	bool operator>=(const CPUPROGRAM &rhs)const;//büyük eşit kontrolü

	bool operator>(const CPUPROGRAM &rhs)const;//büyük kontrolü

private:
	

	const void strEdit(string &);//txt dosyasında ki satırları düzenler.

	int numberOfLines ;//dosyada ki satır sayısı değişkenim.

	vector <string> txt; //instructionların olduğu vector

	int option;


};

#endif

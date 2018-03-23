#ifndef CPUPROGRAMDYN_H
#define CPUPROGRAMDYN_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

namespace SemihC{

class CPUProgramDyn{

public:

	CPUProgramDyn();//default constructor.

	CPUProgramDyn(int );//option

	CPUProgramDyn(char *filename);//constructor
	
	~CPUProgramDyn();//destructor
	
	CPUProgramDyn(const CPUProgramDyn &);//copy constructor
	
	CPUProgramDyn&  operator =(const CPUProgramDyn &);// = operator overload

	int getCapacity() const {return capacity ;}//capacity getter'i

	int getNumberOfLines() const {return numberOfLines;}//numberOfLines getter'i

	const int size() const;//dosyada kac satir oldugunu dondurur.
	
	int decrease_size();//azaltma yapilirsa size'i azaltir.

	int increase_size() ;//ekleme yapilirsa size'i arttirir.

	void setter_option(int );//option setter'i

	int getter_option()const;//option getter'i

	const void set_txt(string, int);//duzenledigim satilari diziye set etmeye yarayan setter

	const void ReadFile(string);//dosyayi acip okudugum fonksiyon

	const string getLine(int);//parametre olarak verilen integer'in dizide hangi satira geldigini hesaplar 
	//o satiri dondurur.

	CPUProgramDyn& operator + (const string);//+ overload

	CPUProgramDyn& operator + (CPUProgramDyn &);// + overload

	const string& operator[](int);//index overload

	CPUProgramDyn& operator()(int,int)const ;//function call overload

	CPUProgramDyn& operator+=(string );//+= overload

	void operator--(int);//postfix

	void operator--();//prefix

	friend ostream& operator<<(ostream& ,const CPUProgramDyn& );//ostream overload

	bool operator==(const CPUProgramDyn &rhs)const ;//esit kontrolu

	bool operator!=(const CPUProgramDyn &rhs)const;//farklı kontrolu

	bool operator<(const CPUProgramDyn &rhs)const;//kucuk kontrolu

	bool operator<=(const CPUProgramDyn &rhs)const;//kucuk esit kontrolu

	bool operator>=(const CPUProgramDyn &rhs)const;//buyuk esit kontrolu

	bool operator>(const CPUProgramDyn &rhs)const;//buyuk kontrolu

private:

	int numberOfLines = 0;//dosyada ki satir sayisi degiskenim.

	string * txt; //instructionlarin oldugu dizi

	int option;

	int capacity = 25;


};

}
#endif

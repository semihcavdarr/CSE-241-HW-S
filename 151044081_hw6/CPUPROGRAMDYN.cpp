#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstddef>
#include <stdio.h>
#include "CPUPROGRAMDYN.h"
using namespace std;

namespace SemihC{

CPUProgramDyn::CPUProgramDyn(){

	txt = nullptr;


}

CPUProgramDyn::CPUProgramDyn(int option){

	setter_option(option);

	txt = nullptr;

}
CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn & obj){//copy constructor
	
	numberOfLines = obj.numberOfLines;

	capacity = obj.capacity;

	txt = new string[numberOfLines];

	for(int i = 0 ; i < numberOfLines ; i++){

		txt[i] = obj.txt[i];
	}
	
}

CPUProgramDyn& CPUProgramDyn::operator = (const CPUProgramDyn & obj){//= overload

	if(capacity != obj.capacity){

		delete [] txt;

		txt = new string[obj.capacity];

	}
	numberOfLines=obj.numberOfLines;

	for(int i=0; i<numberOfLines; i++)

		txt[i]=obj.txt[i];

	return *this;

}
CPUProgramDyn::~CPUProgramDyn(){//destructor

	if(txt != nullptr){

		delete [] txt ;

	}	
	
}
void CPUProgramDyn::setter_option(int _option){

	option=_option;

}
int CPUProgramDyn::getter_option()const{

	return option;

}
CPUProgramDyn::CPUProgramDyn(char *filename){//constructor readFile fonksiyonunu cagirir.

	ReadFile(filename);

}
const void CPUProgramDyn::ReadFile(string filename){

	ifstream file;

	string line;

	file.open(filename);//dosyayi ac

	txt = new string[capacity];

	while (!file.eof()){//dosya sonuna gelene kadar while donuyor.

		if(numberOfLines >= capacity){

			capacity*= 2 ;//yeni capacity olustur.

			string *temp = new string[capacity];

			for(int j = 0 ; j < numberOfLines ; j++){

				temp[j] = txt[j]; 
			}

			for(int k = 0 ; k < numberOfLines ; k++){

				txt[k] = temp[k] ;


			}


		}

		std::getline(file, line);//satır satır okuma

		txt[numberOfLines]=line;//duzenlenmis satiri diziye at

		numberOfLines++;

	}
	numberOfLines=numberOfLines-1;

}

const string CPUProgramDyn::getLine(int i){//integer'a denk gelen satiri return eder.


	return txt[numberOfLines-1];

}

const int CPUProgramDyn::size()const{//satir sayisi return eder

	return numberOfLines;

}

const void CPUProgramDyn::set_txt(string line, int i){//diziye set etmeyi saglar.

	txt[numberOfLines]=line;

}

int CPUProgramDyn::increase_size(){
	
	numberOfLines++;//1 azalt

	return numberOfLines;
}
int CPUProgramDyn::decrease_size(){
	
	numberOfLines--;//1 azalt
	
	return numberOfLines;
	
	
}

const string& CPUProgramDyn::operator[](int i){

	if(i >= numberOfLines+1 || i < 0 || i == numberOfLines){//index kontrolÃ¼
	
		cerr<<"Girdiginiz index dizi size'indan buyuk veya 0'dan kucuk "<<endl;

		static string empty = "";

		return empty;//bos string dondur
	}

	return txt[i];

}

CPUProgramDyn& CPUProgramDyn:: operator+=(const string line){
	static CPUProgramDyn empty;

	if(line.length() == 0){//string bossa hata ver

		cerr<<"eklemek istenen string bos"<<endl;
		

		return empty;//bos obje dondur
	}
	if(numberOfLines >= capacity){

		cerr<<"kapasite dolu"<<endl;

		return empty;//bos obje dondur
	}
	txt[numberOfLines]=line;//stringi diziye ekle
	increase_size();//size'i arttirir.	


	return *this;//objeyi dondur


}
bool CPUProgramDyn::operator==(const CPUProgramDyn &rhs)const{

	return (numberOfLines==rhs.numberOfLines);


}
bool CPUProgramDyn::operator!=(const CPUProgramDyn &rhs)const{

	return (numberOfLines!=rhs.numberOfLines);

}
bool CPUProgramDyn::operator>(const CPUProgramDyn &rhs)const {

	return (numberOfLines>rhs.numberOfLines);

}

bool CPUProgramDyn::operator<(const CPUProgramDyn &rhs)const {

	return (numberOfLines<rhs.numberOfLines);

}
bool CPUProgramDyn::operator<=(const CPUProgramDyn &rhs)const{

	return (numberOfLines<=rhs.numberOfLines);
}

bool CPUProgramDyn::operator>=(const CPUProgramDyn &rhs)const {

	return (numberOfLines>=rhs.numberOfLines);
}

void CPUProgramDyn::operator--(int){
	
	if(numberOfLines == 0){//size 0 sa hata ver.

		cerr<<"-- operatoru daha fazla eleman cıkartamaz"<<endl;

		return;
	}

	txt[numberOfLines-1]= "/0";//dizinin sonuncu elemanına null atadım

}
void CPUProgramDyn::operator--(){
	
	if(numberOfLines == 0){//size 0 sa hata ver.
		cerr<<"-- operatoru daha fazla eleman cıkartamaz"<<endl;

		return;
	}

	txt[numberOfLines]= "/0";//dizinin sonuncu elemanına null atadım

}

CPUProgramDyn& CPUProgramDyn::operator()(int first,int last)const{

	static CPUProgramDyn ptr;

	int i=first;

	string line;

	if((first < 0) || (last > numberOfLines-1) || (first > last)){//first 0'dan kucukse yada last size'dan buyukse 
		//veya first lasttan buyukse hata ver.
	
		cerr<<"Girdiginiz parametrelerden first yada last degeri hatalı"<<endl;

		return ptr;

	}
	ptr.txt=new string[last-first+1];

	int j=0;
	for(i=first-1; i < last ; i++){//(1,3) için
	//1.,2. ve 3.satiri yazdiriyorum
		

		line = txt[i];//line'a ata
		
		ptr.txt[j]=line;//ptr'nin txtsine yaz

		j++;
	}

	ptr.numberOfLines=last-first+1;

	return ptr;//yeni objeyi dondur
}
ostream& operator<<(ostream& out,const CPUProgramDyn& o){

	for (int i =0;i<o.numberOfLines;i++){


		out<<o.txt[i]<<endl;//pointer elemanlarini yaz

	}


return out;


}

CPUProgramDyn& CPUProgramDyn:: operator+(const string line){

	static CPUProgramDyn empty;

	static CPUProgramDyn ptr;

	ptr.txt = new string[numberOfLines+1];

	if(line.length() == 0){//string bossa hata ver

		cerr<<"eklemek istenen string bos"<<endl;
		

		return empty;//bos obje dondur
	}
	if(numberOfLines >= capacity){

		cerr<<"kapasite dolu"<<endl;

		return empty;//bos obje dondur
	}

	for(int i = 0 ; i < numberOfLines ; i++){

		ptr.txt[i]= txt[i];


	}

	ptr.txt[numberOfLines]=line;//stringi diziye ekle

	ptr.numberOfLines=numberOfLines+1;

	return ptr;//yeni CPUProgramDyn objesi dondur

}
CPUProgramDyn& CPUProgramDyn :: operator+(CPUProgramDyn & rhs){
	
	static CPUProgramDyn empty;

	int j = 0 ;

	if(rhs.numberOfLines == 0){
		
		cerr<<"eklenecek obje bos"<<endl;
		
		return empty;
	}

	static CPUProgramDyn ptr;
	ptr.txt=new string[numberOfLines+rhs.numberOfLines];


	for (j = 0 ; j <numberOfLines ; j++){

		ptr.txt[j] = txt[j];
	}
	
	for(int i = 0 ; i<rhs.numberOfLines ;i++){

		ptr.txt[j] = rhs.txt[i];
		++j;
	}

	ptr.numberOfLines=numberOfLines+rhs.numberOfLines;
	
	return ptr;//yeni CPUProgramDyn objesi dondur
}

}
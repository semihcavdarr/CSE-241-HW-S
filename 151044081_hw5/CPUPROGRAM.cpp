#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "CPUPROGRAM.h"
using namespace std;

CPUPROGRAM::CPUPROGRAM(int option){

	setter_option(option);

}
void CPUPROGRAM::setter_option(int _option){

	option=_option;

}
int CPUPROGRAM::getter_option()const{

return option;

}
CPUPROGRAM::CPUPROGRAM(char *filename){//constructor readFile fonksiyonunu çağırır.

	readFile(filename);

}
const void CPUPROGRAM::readFile(string filename){

	ifstream file;

	string line;

	file.open(filename);//dosyayı açıyorum

	while (!file.eof()){//dosya sonuna gelene kadar while dönüyor.

		std::getline(file, line);//satır satır okuma yapıp line stringine atıyorum

		strEdit(line);//line'ı düzenliyorum

		txt.push_back(line);//düzenlenmiş line'ı diziye atıyorum

	}
	txt.pop_back();//sona konan boşluğu siler

	numberOfLines = txt.size();

}

const string CPUPROGRAM::getLine(int i){//integer'a denk gelen satırı return eder.


	return txt.at(i-1);

}

const int CPUPROGRAM::size()const{//satır sayısını return eder

	return numberOfLines;

}

const void CPUPROGRAM::set_txt(string line, int i){//diziye set etmeyi sağlar.

	txt.push_back(line);

}

int CPUPROGRAM::increase_size(){
	
	numberOfLines++;

	return numberOfLines;
}

const void CPUPROGRAM::strEdit(string &satir){//verilen satırı düzenler.

	for (int j = 0; j < satir.length(); j++){//Satir uzunluğu kadar dön

		if (satir[satir.find(';') - 1] == ' ')//noktalı virgülden önce boşluk varsa o boşluğu siler.

			satir = satir.erase(satir.find(";") - 1, 1);

		else if (satir.find(";") != std::string::npos){//noktalı virgül varsa noktalı virgülden öncesini alır.

			satir = satir.substr(0, satir.find(";"));

		}

		else if (satir[j] >= 'a' && satir[j] <= 'z'){//küçük harfleri büyük harfe çevirir.

			satir[j] -= 32;

		}

		else if (satir[0] == ' '){//baştaki boşlukları siler.

			satir.erase(0, 1);

			j -= 1;

		}

		else if (satir[j] == ' ' && satir[j + 1] == ' '){ // arka arkaya boşluk varsa siler.

			satir.erase(j, 1);

			j--;

		}

		else if (satir[j] == ',' && satir[j + 1] == ' '){//virgülden sonra boşluk varsa siler.

			satir.erase(j + 1, 1);

			j--;

		}

		else if (satir[j] == ' ' && satir[j + 1] == ','){//virgülden önce boşluk varsa siler.

			satir.erase(j, 1);

		}

		else if (satir.find("\t") != std::string::npos){ // tab varsa siler.

			satir.erase(satir.find("\t"), 1);

		}


	}//end of for loop

}

const string& CPUPROGRAM::operator[](int i){

	if(i>txt.size() || i < 0){//index kontrolü
	
		cerr<<"Girdiginiz index vector size'indan buyuk veya 0'dan küçük "<<endl;

		exit(1);
	}

	return txt.at(i);

}

void CPUPROGRAM::operator+=(string line){
	
	txt.push_back(line);//line'ı ekle

	increase_size();	//size'ı arttır.

}
bool CPUPROGRAM::operator==(const CPUPROGRAM &rhs)const{

	return (txt.size()==rhs.txt.size());


}
bool CPUPROGRAM::operator!=(const CPUPROGRAM &rhs)const{

	return (txt.size()!=rhs.txt.size());

}
bool CPUPROGRAM::operator>(const CPUPROGRAM &rhs)const {

	return (txt.size()>rhs.txt.size());

}

bool CPUPROGRAM::operator<(const CPUPROGRAM &rhs)const {

	return (txt.size()<rhs.txt.size());

}
bool CPUPROGRAM::operator<=(const CPUPROGRAM &rhs)const{

	return (txt.size()<=rhs.txt.size());
}

bool CPUPROGRAM::operator>=(const CPUPROGRAM &rhs)const {

	return (txt.size()>=rhs.txt.size());
}

void CPUPROGRAM::operator--(int){
	
	if(txt.size() == 0){//size 0 sa hata ver.

		cerr<<"-- operatörü daha fazla eleman çıkartamaz"<<endl;

		exit(1);
	}

	txt.pop_back();//pop et

}
void CPUPROGRAM::operator--(){
	
	if(txt.size() == 0){//size 0 sa hata ver.
		cerr<<"-- operatörü daha fazla eleman çıkartamaz"<<endl;

		exit(1);
	}

	txt.pop_back();//pop et

}

CPUPROGRAM& CPUPROGRAM::operator()(int first,int last)const{

	CPUPROGRAM *ptr = new CPUPROGRAM;//dynamic CPUPROGRAM objesi

	int i=first;

	string line;

	if((first < 0) || (last > txt.size()-1) || (first > last)){//first 0'dan küçükse yada last size'dan büyükse hata ver.
	
		cerr<<"Girdiğiniz parametrelerden first yada last değeri hatalı"<<endl;

	}

	for(i ; i < last+1 ; i++){//(last+1) yaptım myProg(1,3) olduğunda 
	//1.,2. ve 3.satırı yazdırıyorum
		

		line = txt.at(i);//line'a ata
		
		ptr->txt.push_back(line);//ptr'nin txtsine yaz
		

	}

	return *ptr;//yeni objeyi döndür
}
ostream& operator<<(ostream& out,const CPUPROGRAM& o){

	for (int i =0;i<o.txt.size();i++){


		out<<o.txt.at(i)<<endl;//vector elemanlarını yaz

	}


return out;


}

vector <string> CPUPROGRAM:: operator+(const string line){

	if(line.length() == 0)//string boşsa hata ver

		cerr<<"eklemek istenen string boş"<<endl;

	increase_size();//size'ı arttırır.	

	txt.push_back(line);//stringi vectöre ekle

	return txt;//vectoru döndür


}
vector <string> CPUPROGRAM :: operator+(CPUPROGRAM & rhs){
	
	for(int i = 0 ; i<rhs.txt.size() ;i++){

		string line = rhs.txt.at(i);//vector'ün i'sini line ' a at

		txt.push_back(line);//line'ı vectore push et
	}
	
	return txt;//vectoru döndür
}


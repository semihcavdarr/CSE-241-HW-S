#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "CPUPROGRAM.h"
using namespace std;

CPUPROGRAM::CPUPROGRAM(char **argv){

	int option = argv[2][0]-48;//string'i integer'a çevirdim

	setter_option(option);
}
void CPUPROGRAM::setter_option(int option){
	option=option;
}
int CPUPROGRAM::getter_option()const{
return option;
}
CPUPROGRAM::CPUPROGRAM(char * filename){//constructor readFile fonksiyonunu çağırır.

	readFile(filename);

}
const void CPUPROGRAM::readFile(char * filename){

	ifstream file;

	string line;

	int i = 0;

	file.open(filename);//dosyayı açıyorum

	while (!file.eof()){//dosya sonuna gelene kadar while dönüyor.

		std::getline(file, line);//satır satır okuma yapıp line stringine atıyorum

		strEdit(line);//line'ı düzenliyorum

		txt[i] = line;//düzenlenmiş line'ı diziye atıyorum

		i++;//dizinin bir sonraki elemanına atama yapmak için i'yi arttırıyorum.

	}

	Size = i - 1;//i=0 olduğundan size i-1'e eşit.

}

const string CPUPROGRAM::getLine(int i){//integer'a denk gelen satırı return eder.


	return txt[i - 1];

}

const int CPUPROGRAM::size()const{//satır sayısını return eder

	return Size;

}
const void CPUPROGRAM::set_txt(string line, int i){//diziye set etmeyi sağlar.

	txt[i - 1] = line;

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


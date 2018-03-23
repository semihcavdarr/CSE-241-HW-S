#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std ;

class CPUPROGRAM{
    
public:
	
    CPUPROGRAM(char * filename);//constructor

    const void set_txt(string,int);//düzenlediğim satırları attığım diziye set etmeye yarayan setter

    const void readFile(char *);//dosyayı açıp okuduğum fonksiyon

    const string getLine (int);//parametre olarak verilen integer'ın dizide hangi satıra geldiğini hesaplar 
    //o satırı döndürür.


private:
    const int size() const ;//dosyada kaç satır olduğunu döndürür.
    
    const void strEdit(string &);//txt dosyasında ki satırları düzenler.
    
    int Size;//dosyada ki satır sayısı değişkenim.

    string txt[200];//max 200 satırlık txt olacağı için 200'lük bir string dizisi 



};

#endif /* CPUPROGRAM_H */



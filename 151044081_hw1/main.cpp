#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void option1(int * arrayOfRegister,string str1,string str2,string str3);
//option 1 olduğunda bulunan satırı ve register değerlerini yazdırır.

int pow(int x, int y);//x üzeri y değerini hesaplar.

int movR(int &rX, int &rY);//rX'nin değerini rY'e atar

int movC(int &rX,int &constant);//Constant değerini rX'e atar

int add(int &rX,int &rY);//rX ve rY değerini toplar rX'e atar

int subR(int &rX,int &rY);//rY değerinden rX değerini çıkartır

int subC(int &rX,int &constant);//rY değerinden constant değerini çıkartır

void jump(int rX,int lineAdress, int &i);//rX 0 ise lineAdress'e gider.

void jump(int lineAdress, int &i);//direk lineAdress'e atlar

void prn(int &rX);//register'ı yazdırır

void prn2 (int constant);//constant'ı yazdırır.

void halt();//programı halt eder

bool hataKontrol(int argc, char** argv);//argc,argv ve dosya kontrolü yapar

void strDuzenleme(string &satir);//boşlukları siler tokenları ayırır.

void yerDegistirme(string str2,string str3,int* arrayOfRegister);//yardımcı mov fonksiyonu

void cikarma(string str2,string str3,int* arrayOfRegister);//yardımcı sub fonksiyonu

void ekleme(string str2,string str3,int* arrayOfRegister);//yardımcı add fonksiyonu

int  sToMyInt(string str);//kendi stoi fonksiyonum

void zipla(string str2,string str3,int* arrayOfRegister,int &i);//yardımcı jump 

void doEverything(const string* dizi, int option);

int main(int argc, char *argv[]){

    int a=0 , counter = 0, i = 0 ;
    
    string satir; 
    
    const int numberOfLines = 200 ;//.txt dosyasının maximum 200 satır olacağını düşündüm.
    
    string dizi[numberOfLines];

    int option = sToMyInt(argv[2]);
    
    ifstream file;

    if (!hataKontrol(argc,argv))
        
        exit (1);
    
    
    file.open(argv[1]);
    
    while(!file.eof()){//Dosya bitene kadar devam et
        
        std::getline(file,satir);//Satir satir oku

        strDuzenleme(satir);

        dizi[i]=satir;//işlenmiş satırı dizinin i. elemanına atıyorum
        
        i++;//i yi güncelleme
         
    }
    
	doEverything(dizi, option);
    
    file.close();//Dosyayı kapat
    
    return 0;

}

int movR(int &rX, int &rY){
    
    rY=rX ;
   
    return rY;
    
}

int movC(int &rX,int &constant){
    
    rX=constant;

    return rX;
    
}

int add(int &rX,int &rY){
    
    rX=rX+rY;

    return rX;
    
}

int subR(int &rX,int &rY){
    
    rX=rX-rY;

    return rX;

}

int subC(int &rX,int &constant){
    
    rX=rX-constant;

    return rX;
    
}

void jump(int rX,int lineAdress, int &i){
    
    if( rX == 0){
        
        i = lineAdress - 2 ;//-1 i yi döngüde arttırdığım için -1 dizi 0. indexten 
    //başladığı için
        
    }
    
}

void jump(int lineAdress,int &i){
    
    i = lineAdress - 2 ;//-1 i yi döngüde arttırdığım için -1 dizi 0. indexten 
    //başladığı için
    
}

void halt(){

    exit(1);
    
}

int pow(int x, int y)//pow fonksiyonu

{
    int toplam =1;

    for (int z = 0 ; z < y ; z++ ){

        toplam = toplam * x;
        
    }
    
    return toplam;
 
}

bool hataKontrol(int argc, char** argv)

{
    
    bool kontrol=true;
        
    ifstream file;

    if(argc!=3){//eksik yada fazla argüman girişi kontrolü
	
	cerr<<"Argüman hatası.";
	
	kontrol=false;
		
    }
    
    if(!(sToMyInt(argv[2]) == 0 || sToMyInt(argv[2]) == 1)){//option'ın 1 yada 0 olmaması durumu kontrolü
		
	cerr << "argv[2] için yanlış input."<<endl;
        
	kontrol=false;
		
    }
    
    file.open(argv[1]);//Dosyayı aç
    
    if (file.fail()){// Dosyanın açılıp açılmama kontrolü
        
        cerr << "Dosya açılamadı";
        
        kontrol=false;
    }
    
    else
        
        file.close();

    return kontrol;
    
}

void strDuzenleme(string &satir){
    
    for(int j = 0 ; j < satir.length() ; j++){//Satir uzunluğu kadar dön
        
        if(satir[satir.find(';')-1] == ' ')
				
			satir=satir.erase(satir.find(";")-1,1);

        else if(satir.find(';') != std::string::npos){//noktalı virgül varsa noktalı virgülden öncesini al

            satir=satir.substr(0,satir.find(';'));


        }
	
		

		
        
        else if (satir[j] >= 'a' && satir[j] <= 'z'){//küçük harfleri büyük harfe çevirme
            
            satir[j]-=32;
            
        }

        else if (satir[0] == ' '){//baştaki boşlukları sil

            satir.erase(0,1);

            j-=1;
            
        }

        else if (satir[j] == ' ' && satir[j+1] == ' '){ // arka arkaya boşluk varsa sil

            satir.erase(j,1);

            j--;

        }

        else if(satir[j] == ',' && satir[j+1] == ' '){//virgülden sonra boşluk varsa sil

            satir.erase(j+1,1);
            
            j--;

        }

        else if(satir[j] == ' ' && satir[j+1] == ','){//virgülden önce boşluk varsa sil

            satir.erase(j,1);

        }

        else if (satir.find("\t") != std::string::npos){ // tab varsa sil

            satir.erase(satir.find("\t"),1);

        }

        /*if(satir[j] == ','){
				            
            counter++;

            if(counter > j+1){

                cerr<<"1 den fazla virgül var";

                exit(1);
            }
         
        }*/
        
    }//end of for loop
    
}
void yerDegistirme(string str2,string str3,int* arrayOfRegister){

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

void cikarma(string str2,string str3,int* arrayOfRegister){
    
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
void ekleme(string str2,string str3,int* arrayOfRegister){
    
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

int sToMyInt(string str){// stringin uzunluğunu bulup uzunluk sayısı kadar dönderip
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

void zipla(string str2,string str3,int* arrayOfRegister,int &i){
    
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

void prn(int &rX){//print register
    
    cout << rX << endl ;

}

void prn2 (int constant){//print constant
    
    cout << constant << endl;
    
}
void option1(int * arrayOfRegister,string str1,string str2,string str3){
	
    const int numberOfRegister = 5 ;
	
    cout<<str1<<"  "<< str2 <<"  "<< str3 <<"  "<< endl;

    for(int f = 0 ;  f < numberOfRegister ; f++){

        cout<<"R"<< f <<"="<< arrayOfRegister[f]<<endl;	

    }

}

void doEverything(const string* dizi, int option){
			
	int i = 0 ;//dizinin indexini tutacağım değer
        
    int idx1 , idx2 ;//arrayin parametre olarak göndereceğim indexleri
    
    int temp = 0 ;  
	
    const int numberOfRegister = 5 ;//register sayısı
    
    int arrayOfRegister[numberOfRegister]={0,0,0,0,0};
	
	string str1 , str2 , str3;
	
	while(true){//Sonsuz döner halt olana kadar

			if(dizi[i][0] == 'H' && dizi[i][1] == 'L' && dizi[i][2] == 'T'){
				//HLT komutundan sonra boşluk varsa program bu komutla haltı görür
				//ve sonlanır
				
				halt();
				
			}
			
			if(dizi[i].find(' ') != std::string::npos){//boşluğa bak 
				
				str1=dizi[i].substr(0,dizi[i].find(' '));//boşluktan öncesini al
				//str1' e ata
				

				
				str2=dizi[i].substr(dizi[i].find(' ')+1,dizi[i].find('\0'));
				//boşluktan bir sonraki karakterden string'in sonuna kadar al str2 ye ata
				
				
			}      
			
			if(dizi[i].find(',') != std::string::npos){//virgülün indexini bul     

				str2=str2.substr(0,str2.find(','));//virgüle kadar olan kısmı
				//str 2'ye ata

			}
					
			str3=dizi[i].substr(dizi[i].find(',')+1,dizi[i].length()-dizi[i].find(','));
				//virgülden sonraki karakterden stringin sonuna kadar okur
				//str3' e atar.
			
			if(str1 == "MOV"){//str1 MOV'a eşitse 
						
				yerDegistirme(str2,str3,arrayOfRegister);
					
			}
					
			else if(str1 == "ADD"){//str1 ADD'e eşitse
						
				ekleme(str2,str3,arrayOfRegister);
							
			}
					
			else if(str1 == "SUB"){//str1 SUB'a eşitse
						
				cikarma(str2,str3,arrayOfRegister);
					
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
						
				zipla(str2,str3,arrayOfRegister,i);
						
			}
						
					
			else if(str1 == "HLT"){//str1 HALT'a eşitse
						
				halt();//Halt fonksiyonunu çağır
				
			}

			
					
			else{
						
				cerr<<"Syntax error.";//eğer str1 bunlardan birine eşit değilse hata ver
				
			}  

			if(option){
			
				option1(arrayOfRegister,str1,str2,str3);
			
			}
			
			i++;//i sayısını güncelle
			
    }//end of while
}

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <sstream>
#include "BigramDyn.h"
#include "Bigram.h"
#include "DynamicArray.h"

using namespace std;

template<class T>
BigramDyn<T>::BigramDyn(int _dataType){

	dataType =_dataType;

	dyn = nullptr;

}

template<class T>
void BigramDyn<T>::readFile(const string filename) throw (myException){

	ifstream file,file2 ;

	string line ;

	string temp;

	int count = 0 ;

	file.open(filename);

	file2.open(filename);

	ifstream file3;

	file3.open(filename);

	string line4;

	T p;

	getline(file3,line4);

	istringstream a(line4);

	vector = new T[capacity];

	string n;

	getline(file, n);

	istringstream s(n);

	s >> n;

	if(s.eof()){

		throw myException("EMPTY FILE!");
	}

	if(file.fail()){

		throw myException("File could not opened");


	}
	file.seekg(0);

	getline(file2,line);

	if(line.length() == 0){

		throw myException("Empty File");

	}

	while(file>>temp){

		
		if(numberOfLines >= capacity){

			capacity*= 2 ;

			T *a = new T[capacity];

			for(int j = 0 ; j < numberOfLines ; j++){

				a[j] = vector[j]; 
			}

			for(int k = 0 ; k < numberOfLines ; k++){

				vector[k] = a[k] ;


			}


		}

		if(dataType == 1){

			if(badDataForint(temp)){

				vector[count]=(stoi(temp));

				count++;

			}

			else{

				throw myException("bad data for int file");

			}

			
		}//end if
		else if(dataType == 3){

			if(badDataFordouble(temp)){

				vector[count]=(stod(temp));

				count++;

			}

			else{

				throw myException("bad data for double file");
			}

		}//end else-if

		else if(dataType == 2){
			

			while(!a.eof()){


				a >> p;
			
				vector[count] = p;

				count++;
			}
		}


		numberOfLines++;//numgram sayısı



	
	}//end while

	dyn = new DynamicArray<T>[numberOfLines];

	int k = 0;

	for(int i = 0 ; i < numberOfLines-1 ; i++){

		bool flag = true;

		for(int j = 0 ; j < i ; j++){

			if((vector[i] == dyn[j].geta()) && vector[i+1] == dyn[j].getb()){

				dyn[j].setvalue(dyn[j].getvalue()+1);

				flag = false;
			}
		}

		if(flag == true){

			dyn[k].seta(vector[i]);

			dyn[k].setb(vector[i+1]);

			dyn[k].setvalue(1);

			k++;

		}

	}


}//end function

template<class T>
int BigramDyn<T>::numGrams() const{

	return numberOfLines-1;
}

template<class T>
BigramDyn<T>::BigramDyn(const BigramDyn<T>& rhs){


	dataType = rhs.dataType;

	capacity = rhs.capacity;

	numberOfLines = rhs.numberOfLines;

	for(int i = 0 ; i < numberOfLines ; i++){

		dyn[i].seta(rhs.dyn[i].geta());

		dyn[i].setb(rhs.dyn[i].getb());

		dyn[i].setvalue(rhs.dyn[i].getvalue());


	}

	for(int j = 0 ; j < numberOfLines ; j++){

		vector[j] = rhs.vector[j];

	}
}

template<class T>
BigramDyn<T> & BigramDyn<T>::operator =(const BigramDyn<T>& other){

	if(this == other){

		return *this;
	}

	dataType = other.dataType;

	capacity = other.capacity;

	numberOfLines = other.numberOfLines;

	delete [] vector;

	delete [] dyn;

	vector=new T[capacity];

	dyn = new DynamicArray<T>[capacity];

	for(int i = 0 ; i < numberOfLines ; i++)

		vector[i] = other.vector[i];

	for(int j = 0 ; j < numberOfLines ; j++){

		dyn[j].seta(other.dyn[j].geta());

		dyn[j].setb(other.dyn[j].getb());

		dyn[j].setvalue(other.dyn[j].getvalue());
	}

	return *this;

}

template<class T>
int BigramDyn<T>::numOfGrams(const T var1,const T var2){

	for(int i = 0 ; i < numberOfLines ; i++){

		if(dyn[i].geta() == var1 && dyn[i].getb() == var2)

			return dyn[i].getvalue();

	}

	return 0;
}

template<class T>
pair<T,T> BigramDyn<T>::maxGrams(){

	int max = dyn[0].getvalue();

	auto str1 = dyn[0].geta();

	auto str2 = dyn[0].getb();

	for(int i = 0 ; i < numberOfLines ; i++){

		if(dyn[i].getvalue() > max){

			max = dyn[i].getvalue();

			str1 = dyn[i].geta();

			str2 = dyn[i].getb();
		}

	}

	pair<T,T> peyir(str1,str2);


	return peyir;

}



template<class T>
bool BigramDyn<T>::badDataForint(string line){

	int i = 0;

	for(int j = 0 ; j < line.length(); j++){

		int a = line[i] - '0';

		if(a >= 0 && a <10){

			return true;
		}
		
		else{
			return false;
						
		}

		i++;
	}

}
template<class T>
bool BigramDyn<T>::badDataFordouble(string line){
	int count = 0 ;
	int i = 0 ;

	for(int k = 0 ; k < line.length() ; k++){

		if(line[k] == '.'){

			count ++;
		}
	}

	for(int j = 0; j < line.length() ; j++){

		int a = line[i] - '0';

		if((a >= 0 && a <10) && count == 1)

			return true;

		else{

			return false ;
		}
						
		i++;
	}	

}

template<class T>
void BigramDyn<T>::print(ostream & out){

	int max = dyn[0].getvalue();

	auto str1 = dyn[0].geta();

	auto str2 = dyn[0].getb();



	for(int i = 0 ; i < numberOfLines ; i++){

		if(dyn[i].getvalue() > max){

			max = dyn[i].getvalue();

			str1 = dyn[i].geta();

			str2 = dyn[i].getb();
		}

	}

	pair<T,T> peyir(str1,str2);

	for(max ; max >0 ; max--){

		for(int i = 0 ; i < numberOfLines-1 ; i++){

			if(max == dyn[i].getvalue())

				out<<"first.first :"<<dyn[i].geta()<<" first.second: "<<dyn[i].getb()<<" second: "<<dyn[i].getvalue()<<endl;

		}
	}

	
}
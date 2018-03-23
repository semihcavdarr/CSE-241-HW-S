#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <exception>
#include "Bigram.h"
#include "BigramMap.h"
#include "Exception.h"
#include <sstream>


using namespace std;


template <class T>
void  BigramMap<T>::readFile(const string filename) throw (myException){

	ifstream file,file2;

	string line ;

	string temp;

	int a = 0 ;

	file.open(filename);

	file2.open(filename);

	string n;

	getline(file, n);

	istringstream k(n);

	k >> n;

	if(k.eof()){

		throw myException("EMPTY FILE!");
	}

	if(file.fail()){

		throw myException("File could not opened");


	}
	file.seekg(0);
	
	while(file>>temp){

		if(dataType == 1)

			if(badDataForint(temp)){

			}

			else{

				throw myException("Bad data for int file");
			}

		else if(dataType == 2){

			if(badDataFordouble(temp)){

			}
			else
				throw myException("Bad data for double file");
		}
	}

	getline(file2,line);

	if(line.length() == 0)

		throw myException("Empty file");

	T var ;

	istringstream iss(line);

	while(!iss.eof()){

		if(iss.fail())

			throw myException("Bad data");

		iss >> var;

		v.push_back(var);

		countForNumGrams++;

	}

	int s = 0 ;

	int b = 0 ;

	pair<T,T> peyir[countForNumGrams];

	for(b,s ; b < countForNumGrams-1, s < countForNumGrams-1; b++,s++){//pair olustur

		peyir[s].first = (v[b]);

		peyir[s].second = (v[b+1]);


	}
	for(int c = 0 ; c < countForNumGrams-1 ; c++ ){

		auto found = mymap.find(pair <T,T>(v[c],v[c+1]));



		if(found == mymap.end()){

			mymap.insert(make_pair(pair<T,T>(v[c],v[c+1]),1));//map'te yoksa map'e ekle
		}

		else{//map'te varsa value'yu 1 arttır

			auto f2 = found->first;

			found->second = ((found->second) +1);

			
		}
	}//end for


}//end function

template<class T>
int BigramMap<T>::numOfGrams(const T var1,const T var2){

	auto find = mymap.find(pair<T,T>(var1,var2));

	if(find != mymap.end()){

		auto f1 = find->first;

		auto f2 = find->second;

		return f2;

	}
	else{

		return 0;


	}


}

template<class T>
pair<T,T> BigramMap<T>::maxGrams(){

	auto it = mymap.begin();

	auto end = mymap.end();

	int max_value = it->second;

	auto str = it->first;

	for( ; it != end; ++it) {

    	if(it->second > max_value) {

        	max_value = it->second;

        	str = it->first;
    	}
    
	}

	return str;

}

template<class T>
int BigramMap<T>::numGrams() const {

	return countForNumGrams-1;
}

template<class T>
bool BigramMap<T>::badDataForint(string line){

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
bool BigramMap<T>::badDataFordouble(string line){
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
void BigramMap<T>::print(ostream& out){

	auto x = maxGrams();

	auto find = mymap.find(x);

	int value = find->second;

	for(value ; value >0 ; value--){

		for(auto y : mymap){

			if(y.second == value)

				out<<"first.first :"<<y.first.first<<" first.second :"<<y.first.second<<" second :"<<y.second<<endl;
		}
	}

}
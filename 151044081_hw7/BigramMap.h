#ifndef BIGRAMMAP_H
#define BIGRAMMAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include "Bigram.h"
#include "Exception.h"
#include <exception>


using namespace std;


template<class T>
class BigramMap : public Bigram<T>
{

public:

	BigramMap(){}

	BigramMap(int _dataType){

		dataType = _dataType;
	}

	virtual void readFile(const string filename) throw (myException);

	virtual int numGrams() const override;

	virtual int numOfGrams(const T,const T) override;

	virtual pair<T,T> maxGrams() override;

	virtual void print(ostream& out);

	friend ostream&  operator <<(ostream& out,BigramMap<T> & obj1){

		obj1.print(out);

		return out;
	}

	bool badDataForint(string line);

	bool badDataFordouble(string line);

private:
	int dataType;

	map<pair<T, T>,int> mymap;

	int countForNumGrams = 0 ;

	std::vector<T> v;


};
#endif
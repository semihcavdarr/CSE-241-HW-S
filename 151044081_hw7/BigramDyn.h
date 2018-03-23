#ifndef BIGRAMDYN_H
#define BIGRAMDYN_H


#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "Bigram.h"
#include "DynamicArray.h"
#include "Exception.h"
#include <exception>

using namespace std;

template <class T>
class BigramDyn : public Bigram<T> {

public:

	BigramDyn(){}

	BigramDyn(int _dataType);

	BigramDyn(const BigramDyn<T> & );

	BigramDyn<T>& operator =(const BigramDyn<T>& );

	virtual void readFile(const string filename) throw (myException);

	virtual int numGrams() const override;

	virtual int numOfGrams(const T,const T) override;

	virtual pair<T, T> maxGrams() override;

	virtual void print(ostream& out);

	friend ostream&  operator <<(ostream& out,BigramDyn<T> & obj1){

		obj1.print(out,obj1);

		return out;
	}



	bool badDataForint(string line);

	bool badDataFordouble(string line);

	~BigramDyn(){

		if(vector != nullptr){

			delete [] vector;
		delete [] dyn;
		}
	}
	
private:

	int dataType;

	DynamicArray<T> *dyn;

	T *vector;

	int capacity = 50;

	int numberOfLines = 0 ;

};

#endif
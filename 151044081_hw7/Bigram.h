#ifndef BIGRAM_H
#define BIGRAM_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <exception>

using namespace std;

template<class T>
class Bigram{

public:

	Bigram(){}

	virtual void readFile(const string filename) = 0;

	virtual int numGrams() const = 0;

	virtual int numOfGrams(const T,const T) = 0;

	virtual pair<T, T> maxGrams() = 0;

	virtual void print(ostream& out) = 0;

	friend ostream& operator <<(ostream& out,Bigram<T> & obj1){

		obj1.print(out);

		return out;
	}
};

#endif
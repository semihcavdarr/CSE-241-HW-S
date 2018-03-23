#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <iostream>
#include <string>
#include <exception>

using namespace std;

class myException : public exception{

public:

	myException(const char * _mystring){

		mystring = _mystring;

	}

	virtual const char* what() const throw() {

		return mystring;
	}
private:
	const char * mystring;
};

#endif
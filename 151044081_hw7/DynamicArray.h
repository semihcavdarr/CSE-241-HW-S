#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <string>
#include <utility>


using namespace std;

template<class T>
class DynamicArray{

public:

	void seta(T );

	void setb(T );

	void setvalue(int );

	T geta() const;

	T getb() const;

	int getvalue() const;


private:

	T a;

	T b;

	int value = 0 ;


};



#endif

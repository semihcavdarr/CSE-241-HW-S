#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <utility>

using namespace std;


template<class T>
void DynamicArray<T>::seta(T var){

	a = var ;
}

template<class T>
void DynamicArray<T>::setb(T var){

	b = var ;
}

template<class T>
void DynamicArray<T>::setvalue(int var){

	value = var;
}
template<class T>
T DynamicArray<T>::geta() const{

	return a;
}
template<class T>
T DynamicArray<T>::getb() const {

	return b;
}
template<class T>
int DynamicArray<T>::getvalue() const {

	return value; 
}


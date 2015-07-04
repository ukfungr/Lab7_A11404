#pragma once
#include "Nodo.h"

using namespace std;

template<class T>
class Iterador
{
private:
	Nodo<T> * actual;

public:
	Iterador(Nodo<T> * actual) {
		this->actual = actual;
	}


	~Iterador() {

	}


	//Preincremento
	Iterador<T>& operator++() {
		bool continuar = true;
		while (continuar && actual != 0) {
			continuar = false;
			if (actual != NULL){
				if (actual->getNext() != NULL){
					actual = actual->getNext();
				}
				else {
					actual = actual->getNext();
					continuar = true;
				}
			}
		}
		return *this;
	}


	//Posincremento
	Iterador<T> operator++(int) {
		Iterador<T> tmp(this->actual);
		++(*this);
		return tmp;
	}


	T operator*(){
		return actual->getActual();
	}


	bool operator!=(Iterador<T> & otro){
		return this->actual != otro.actual;
	}


	bool operator==(Iterador<T> & otro) {
		return this->actual == otro.actual;
	}
};


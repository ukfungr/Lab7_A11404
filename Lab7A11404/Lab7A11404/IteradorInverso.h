#pragma once
#include "Nodo.h"


using namespace std;

template<class T>
class IteradorInverso
{
private:
	Nodo<T> * anterior;
	Nodo<T> * actual;

public:


	IteradorInverso(Nodo<T> * actual) {
		this->anterior = actual;
		this->actual = actual;
	}


	~IteradorInverso() {

	}


	//Preincremento
	IteradorInverso<T>& operator--() {
		bool continuar = true;
		while (continuar && actual != 0) {
			continuar = false;
			Nodo<T> * temp = actual;
			if (actual != NULL){
				if (actual->getPrevious() != NULL){
					actual = actual->getPrevious();
				}
				else {
					//actual = actual;
					actual = actual->getPrevious();
					continuar = true;
				}
			}
			//anterior = temp;
		}
		return *this;
	}


	//Posincremento
	IteradorInverso<T> operator--(int) {
		IteradorInverso<T> tmp(this->actual);
		--(*this);
		return tmp;
	}


	T operator*(){
		return actual->getActual();
	}


	bool operator!=(IteradorInverso<T> & otro){
		return this->actual != otro.actual;
	}


	bool operator==(IteradorInverso<T> & otro) {
		return this->actual == otro.actual;
	}
};


#pragma once
#include "DoublyLinkedList.h"
//#include "Gato.h"
//#include "Iterador.h"
//#include "IteradorInverso.h"

using namespace std;

template<class T>
class Nodo
{
	template<class T>
	friend ostream & operator<<(ostream &, Nodo<T> &);

private:
	T actual;
	Nodo<T> * previous;
	Nodo<T> * next;

public:
	Nodo::Nodo(T elemento) {
		actual = elemento;
		previous = NULL;
		next = NULL;
	}


	Nodo::~Nodo() {
	}


	T Nodo::getActual() {
		return this->actual;
	}


	Nodo<T> * Nodo::getPrevious() {
		return previous;
	}


	void Nodo::setPrevious(Nodo<T> * e) {
		this->previous = e;
	}


	Nodo<T> * Nodo::getNext() {
		return next;
	}


	void Nodo::setNext(Nodo<T> * e) {
		this->next = e;
	}
};

template<class T>
ostream & operator<<(ostream & out, Nodo<T> & e)
{
	return out << e.actual;
}
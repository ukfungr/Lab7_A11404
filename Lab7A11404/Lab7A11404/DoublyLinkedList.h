#pragma once
#include "Nodo.h"
#include "Iterador.h"
#include "IteradorInverso.h"
#include "Gato.h"
#include <iostream>
using namespace std;

template<class T>
class DoublyLinkedList
{
	template<class T>
	friend ostream & operator<<(ostream &, DoublyLinkedList<T> &);

private:
	Nodo<T> * head;
	Nodo<T> * tail;
	int n;

public:
	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
		n = 0;
	}


	~DoublyLinkedList() {
		if (head != NULL){
			destruirRec(head);
		}
	}


	void destruirRec(Nodo<T> * nodo) {
		if (nodo->getNext() != NULL) {
			destruirRec(nodo->getNext());
		}
		delete nodo;
	}


	void insertarElemento(T elemento) {
		Nodo<T> * nodo = new Nodo<T>(elemento);
		if (head == NULL){
			head = nodo;
			tail = nodo;
			n++;
		}
		else {
			insertarElementoFinal(nodo);
		}
	}


	/// Iterador
	Iterador<T> begin() {
		return Iterador<T>(head);
	}


	Iterador<T>end() {
		return Iterador<T>(NULL);
	}


	/// Iterador Inverso
	IteradorInverso<T> rBegin() {
		return IteradorInverso<T>(NULL);
	}


	IteradorInverso<T> rEnd() {
		return IteradorInverso<T>(tail);
	}


private:
	void insertarElementoInicio(Nodo<T> * elemento) {
		Nodo<T> * temp = elemento;
		temp->setNext(head);
		head = temp;
		if (head != NULL){
			temp->getNext()->setPrevious(head);
		}
		n++;
	}


	void insertarElementoCualquiera(Nodo<T> * nodoActual, int k) {
		Nodo<T> * temp = head;
		Nodo<T> * anterior = NULL;
		int cont = 0;
		while (cont != k - 1){
			anterior = temp;
			temp = temp->getNext();
			cont++;
		}
		anterior->setNext(nodoActual);//Define puntero del elemento en la posición anterior hacia el elemnto a ser insertado
		anterior->setPrevious(anterior);//Define el puntero al elemnto anterior al insertado
		n++;
		anterior->getNext()->setNext(temp);//Define puntero del elemento insertado al siguiente
		anterior->getNext()->setPrevious(anterior->getNext());//Define puntero del elemento movido hacia el anterior, o sea, apunta hacia el elemento insertado
	}


	void insertarElementoFinal(Nodo<T> * nodoActual) {
		Nodo<T> * temp = head;
		Nodo<T> * anterior = NULL;
		while (temp->getNext() != NULL){
			anterior = temp;
			temp = temp->getNext();
		}
		temp->setNext(nodoActual);//Define puntero al último elemento de la lista
		temp->getNext()->setPrevious(temp);//Define puntero al elemento anterior al último de la lista
		tail = temp->getNext();
		n++;
	}


	void eliminarElementoInicio(){
		Nodo<T> * temp = head;
		head = head->getNext();
		delete temp;
		if (head != NULL){
			head->setPrevious(NULL);
		}
		n--;
	}


	void eliminarElementoFinal(){
		Nodo<T> * temp = head;
		Nodo<T> * previous = NULL;
		while (temp->getNext() != NULL){
			previous = temp;
			temp = temp->getNext();
		}
		previous->setNext(NULL);
		temp->setPrevious(NULL);///Define como nulo el puntero al elemento anterior, del elemento recién eliminado
		tail = previous;
		delete temp;
		n--;
	}


	void eliminarPosicionCualquiera(int k){
		Nodo<T> * temp = head;
		Nodo<T> * previous = NULL;
		int i = 1;
		while (i < k){
			previous = temp;
			temp = temp->getNext();
			i++;
		}
		previous->setNext(previous->getNext()->getNext());//Define el puntero del elemento anterior al borrado hacia el elemento siguiente al elemento borrado 
		temp->setPrevious(NULL); //Define como NULL el  puntero al elemento anterior del elemento recién eliminado
		delete temp;
		n--;
	}


	void eliminarElementoCualquiera(Nodo<T> * nodoActual){
		Nodo<T> * temp = head;
		Nodo<T> * previous = NULL;
		int i = 1;
		while (*temp != *nodoActual){
			previous = temp;
			temp = temp->getNext();
			i++;
		}
		previous->setNext(previous->getNext()->getNext());
		temp->setPrevious(NULL); //Define como NULL el  puntero al elemento anterior del elemento recién eliminado
		delete temp;
		n--;
	}


	void imprimir(Nodo<T> * nodo, ostream& out) {
		if (nodo->getNext() != NULL){
			out << *nodo << " <-> ";
		}
		else {
			out << *nodo;
		}
		if (nodo->getNext() != NULL){
			imprimir(nodo->getNext(), out);
		}
		cout << "\t";
	}
};

template<class T>
ostream & operator<<(ostream & out, DoublyLinkedList<T> & l) {
	l.imprimir(l.head, out);
	return out;
}
// Lab7A11404.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "Gato.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(NULL));

	cout << "Lista de integers" << endl;
	DoublyLinkedList<int> l;
	for (int i = 0; i < 10; ++i){
		l.insertarElemento(rand() % 100);
	}

	cout << l << endl;
	cout << endl;

	//Iterador preincremento
	cout << "Iterador preincremento" << endl;
	Iterador<int> it = l.begin();
	while (it != l.end()) {
		cout << *it << endl;
		++it;
	}
	cout << endl;

	//Iterador posincremento
	cout << "Iterador posincremento" << endl;
	Iterador<int> itPos = l.begin();
	while (itPos != l.end()) {
		cout << *(itPos++) << endl;
	}
	cout << endl;

	//Iterador inverso preincremento
	cout << "Iterador inverso preincremento" << endl;
	IteradorInverso<int> k = l.rEnd();
	while (k != l.rBegin()) {
		cout << *k << endl;
		--k;
	}
	cout << endl;

	//Iterador inverso posincremento
	cout << "Iterador inverso posincremento" << endl;
	IteradorInverso<int> kPos = l.rEnd();
	while (kPos != l.rBegin()) {
		cout << *(kPos--) << endl;
	}
	cout << endl;

	/// Lista de chars
	cout << "Lista de chars" << endl;
	DoublyLinkedList<char> c;
	for (int i = 0; i < 10; ++i){
		c.insertarElemento((char)rand() % (157 - 97) + 97);
	}

	cout << c << endl;

	//Iterador preincremento
	cout << "Iterador preincremento" << endl;
	Iterador<char> itPreChar = c.begin();
	while (itPreChar != c.end()) {
		cout << *itPreChar << endl;
		++itPreChar;
	}
	cout << endl;

	//Iterador posincremento
	cout << "Iterador posincremento" << endl;
	Iterador<char> itPosChar = c.begin();
	while (itPosChar != c.end()) {
		cout << *(itPosChar++) << endl;
	}
	cout << endl;

	//Iterador inverso preincremento
	cout << "Iterador inverso preincremento" << endl;
	IteradorInverso<char> kPreChar = c.rEnd();
	while (kPreChar != c.rBegin()) {
		cout << *kPreChar << endl;
		--kPreChar;
	}
	cout << endl;

	//Iterador inverso posincremento
	cout << "Iterador inverso posincremento" << endl;
	IteradorInverso<char> kPosChar = c.rEnd();
	while (kPosChar != c.rBegin()) {
		cout << *(kPosChar--) << endl;
	}
	cout << endl;


	/// Lista de doubles
	cout << "Lista de doubles" << endl;
	DoublyLinkedList<double> d;
	for (int i = 0; i < 10; ++i){
		d.insertarElemento(((double)rand()*(100.00 - 0.00)) / (double)RAND_MAX);
	}

	cout << d << endl;

	cout << endl;

	//Iterador preincremento
	cout << "Iterador preincremento" << endl;
	Iterador<double> itPreD = d.begin();
	while (itPreD != d.end()) {
		cout << *itPreD << endl;
		++itPreD;
	}
	cout << endl;

	//Iterador posincremento
	cout << "Iterador posincremento" << endl;
	Iterador<double> itPosD = d.begin();
	while (itPosD != d.end()) {
		cout << *(itPosD++) << endl;
	}
	cout << endl;

	//Iterador inverso preincremento
	cout << "Iterador inverso preincremento" << endl;
	IteradorInverso<double> kPreD = d.rEnd();
	while (kPreD != d.rBegin()) {
		cout << *kPreD << endl;
		--kPreD;
	}
	cout << endl;

	//Iterador inverso posincremento
	cout << "Iterador inverso posincremento" << endl;
	IteradorInverso<double> kPosD = d.rEnd();
	while (kPosD != d.rBegin()) {
		cout << *(kPosD--) << endl;
	}
	cout << endl;



	/// Lista de gatos
	cout << "Lista de gatos" << endl;
	DoublyLinkedList<Gato> g;
	string pandilla[] = { "Don Gato", "Benito", "Cucho", "Demostenes", "Panza", "Espanto" };

	for (int i = 0; i < 6; ++i){
		g.insertarElemento(Gato(pandilla[i], rand() % 100));
	}

	cout << g << endl;
	
	cout << endl;
	
	//Iterador preincremento
	cout << "Iterador preincremento" << endl;
	Iterador<Gato> itPreG = g.begin();
	while (itPreG != g.end()) {
		cout << *itPreG << endl;
		++itPreG;
	}
	cout << endl;

	//Iterador posincremento
	cout << "Iterador posincremento" << endl;
	Iterador<Gato> itPosG = g.begin();
	while (itPosG != g.end()) {
		cout << *(itPosG++) << endl;
	}
	cout << endl;

	//Iterador inverso preincremento
	cout << "Iterador inverso preincremento" << endl;
	IteradorInverso<Gato> kPreG = g.rEnd();
	while (kPreG != g.rBegin()) {
		cout << *kPreG << endl;
		--kPreG;
	}
	cout << endl;

	//Iterador inverso posincremento
	cout << "Iterador inverso posincremento" << endl;
	IteradorInverso<Gato> kPosG = g.rEnd();
	while (kPosG != g.rBegin()) {
		cout << *(kPosG--) << endl;
	}
	cout << endl;

	system("pause");

	return 0;
}


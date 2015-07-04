#pragma once
//#include "Nodo.h"

using namespace std;

class Gato
{
	friend ostream & operator<<(ostream &, Gato &);

	template<class T>
	friend class Nodo;

private:
	string gato;
	int edad;
	Gato();

public:
	Gato(string, int);
	virtual ~Gato();
	void setGato(string g);
	void setEdad(int e);
	string getGato();
	int getEdad();
};

ostream & operator<<(ostream &, Gato &);
#include "stdafx.h"
#include "Gato.h"

Gato::Gato()
{
}


Gato::Gato(string gato, int edad)
{
	this->gato = gato;
	this->edad = edad;
	setGato(gato);
	setEdad(edad);
}


Gato::~Gato()
{
}


void Gato::setGato(string g)
{
	gato = g;
}


void Gato::setEdad(int e)
{
	edad = e;
}


string Gato::getGato()
{
	return gato;
}


int Gato::getEdad()
{
	return edad;
}


ostream & operator<<(ostream & out, Gato & g)
{
	out << g.edad << "::" << g.gato;
	return out;
}
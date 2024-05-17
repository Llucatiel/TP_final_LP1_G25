#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <list>
#include "cAtaque.h"


using namespace std;

class cDatos
{
protected:
	string nombre;
	string color;
	string peso;
	string tamano;
	time_t fecha;
	int* estadisticas;
	bool vivo = true;
	list<cAtaque*> ataques;
	int cantAtaques;

	virtual void generarStats();
	void baja() { this->vivo = false; }
public:

	string getNombre() const { return this->nombre; }
	string getTamano() const { return this->tamano; }
	virtual void mostrarStats();
	virtual void mostrarAtaques();
	int getAnios();
	virtual void descripcion()const = 0;
	virtual ~fisico();

};


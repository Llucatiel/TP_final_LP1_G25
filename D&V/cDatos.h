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
	list<cAtaque*> ataques;
	cAtaque* puntero;
	int* estadisticas;
	bool vivo = true;


	virtual void generarStats();
	void baja() { this->vivo = false; }

public:
	static void espera(float i);

	virtual void mostrarStats();
	virtual void mostrarAtaques();
	virtual void descripcion()const = 0;
	virtual ~cDatos();

	int getCantAtk() { return (int)this->ataques.size(); }
	int getAnios();
	bool getVivo()const { return this->vivo; }
	string getNombre() const { return this->nombre; }
	string getTamano() const { return this->tamano; }
};


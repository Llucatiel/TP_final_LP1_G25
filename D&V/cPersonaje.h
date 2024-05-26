#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <list>
#include <sstream>
#include <Windows.h>
#include <cstdlib>

#include "cAtaque.h"

using namespace std;

class cPersonaje
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
	cPersonaje();
	cPersonaje(string nombre, string color, string peso, string tamano, int d, int m, int a);
	virtual void mostrarStats();
	virtual void mostrarAtaques();
	virtual void descripcion()const = 0;
	virtual void operator+(cAtaque* atk);
	virtual string To_string();
	virtual ~cPersonaje();

	int getCantAtk() { return (int)this->ataques.size(); }
	int getAnios();
	void imprimirDatos();
	float atacar(int i);
	float getStat(int i) { return this->estadisticas[i]; }
	bool getVivo()const { return this->vivo; }
	string getNombre() const { return this->nombre; }
	string getTamano() const { return this->tamano; }
	cAtaque* getAtk(int i);
	void mostrarDanos();
	list<cAtaque*> getListAtaques()const { return this->ataques; }
	void operator-(cAtaque* atk);
};


#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <list>
#include <sstream>
#include "cAtaque.h"
#include <Windows.h>

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
	static void espera(float i);
	//	CREAR CONSTRUCTOR OARA QUE ANDA
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

	void mostrarDanos();
	void operator-(cAtaque* atk);
};


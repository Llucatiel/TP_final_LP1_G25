#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>
#include "cPersonaje.h"
using namespace std;

class cVikingo : public cPersonaje
{
	static int comida;
	static int cantVikingos;
	string trabajo;

protected:
	int dragones_terminados;
	string apellido;

public:
	cVikingo() {}
	cVikingo(string nombre, string apellido, int d, int m, int a, string altura, string peso, string trabajo, int dragones_terminados);
	~cVikingo();

	static int getComida() { return comida; }
	static int getCantVikingos() { return cantVikingos; }
	static void cambioComida(int suma) { comida += suma; };

	//bool trabajar();
	bool dragonesMatados() { return dragones_terminados>0?true:false;}
	string getApellido() const { return apellido; }
	string getTrabajo() { return trabajo; }

	void setTrabajo(string nuevo) { this->trabajo = nuevo; }
	void setDragonesTerminados(int suma) { this->dragones_terminados += suma; }
	void descripcion()const;
};
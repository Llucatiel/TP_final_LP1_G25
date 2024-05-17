#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>
#include "cDatos.h"
using namespace std;

class cVikingo : public cDatos
{
	string apellido;
	static int comida;
	static int cantVikingos;
protected:
	string trabajo;
	int dragones_terminados;
	

public:
	cVikingo(string nombre, string apellido, int d, int m, int a, string altura, string peso, string trabajo, int dragones_terminados);
	//bool trabajar();
	friend void atacarDragones(list<cVikingo> vikingos);
	//bool dragonesMatados();
	string getApellido() const { return apellido; }
	string getTrabajo() { return trabajo; }
	void setTrabajo(string nuevo) { this->trabajo = nuevo; }
	void setDragonesTerminados(int suma) { this->dragones_terminados += suma; }

	static int getComida() { return comida; }
	static int getCantVikingos() { return cantVikingos; }
	static void cambioComida(int suma);
	void descripcion()const;

	~cVikingo();
};
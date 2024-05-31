#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>
#include "cPersonaje.h"
#include "cDragon.h"
using namespace std;

class cVikingo : public cPersonaje
{
	static int comida;
	static int cantVikingos;


protected:
	string trabajo;
	int dragones_terminados;
	string apellido;

	virtual void impresion() const;
public:
	cVikingo(string nombre, string color, string apellido, int d, int m, int a, string altura, string peso, string trabajo, int dragones_terminados);
	virtual ~cVikingo();

	static int getComida();
	static int getCantVikingos();
	static void cambioComida(int suma);

	//bool trabajar();
	bool dragonesMatados();
	bool domar(cDragon* dragon);
	string getApellido() const;
	string getTrabajo();
	int getDragonesTerminados() const;

	void setTrabajo(string nuevo);
	void setDragonesTerminados(int suma);
	void descripcion()const;
};
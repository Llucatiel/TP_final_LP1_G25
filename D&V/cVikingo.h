#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>
#include "cPersonaje.h"
#include "cDragon.h"

using namespace std;


enum trabajos {
	herrero, carpintero, cantinero, pastor, entrenadordedragones
};

class cVikingo : public cPersonaje
{
	static int cantVikingos;
	//friend void cBocon::encuentrePaz(cVikingo* perdida);
protected:
	trabajos trabajo;
	int dragones_terminados;
	string apellido;

	virtual void impresion() const;
public:
	cVikingo(string nombre, string color, string apellido, int d, int m, int a, string altura, string peso, trabajos trabajo, int dragones_terminados);
	virtual ~cVikingo();

	static int getCantVikingos();

	int trabajar();
	bool dragonesMatados();
	//bool domar(cDragon* dragon); No implentado :(
	
	string getApellido() const;
	string getTrabajo();
	int getDragonesTerminados() const;

	void setTrabajo(trabajos nuevo);
	void setDragonesTerminados(int suma);
	
};
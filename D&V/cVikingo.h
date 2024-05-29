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
	string trabajo;

protected:
	int dragones_terminados;
	string apellido;

	virtual void impresion() const {
		cout << apellido << "uno de nuestros grandes "<<trabajo<<"en berk. ";
		cout<< "Lleva vagando por estas tierras desde hace "<<fecha<<" años con su melena "<<color<<".";
	}
public:
	cVikingo(string nombre, string color, string apellido, int d, int m, int a, string altura, string peso, string trabajo, int dragones_terminados);
	~cVikingo();

	static int getComida() { return comida; }
	static int getCantVikingos() { return cantVikingos; }
	static void cambioComida(int suma) { comida += suma; };

	//bool trabajar();
	bool dragonesMatados() { return dragones_terminados>0?true:false;}
	bool domar(cDragon* dragon);
	string getApellido() const { return apellido; }
	string getTrabajo() { return trabajo; }
	int getDragonesTerminados() const { return this->dragones_terminados; }

	void setTrabajo(string nuevo) { this->trabajo = nuevo; }
	void setDragonesTerminados(int suma) { this->dragones_terminados += suma; }
	void descripcion()const;
};
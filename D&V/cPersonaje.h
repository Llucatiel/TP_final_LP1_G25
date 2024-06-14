#pragma once
#include <ctime>
#include <list>
#include <sstream>
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
	tipo tipo_ataque;
	list<cAtaque*> ataques;
	int* estadisticas = NULL;
	int edad;
	bool vivo;


	virtual void generarStats();
	void baja();
	virtual void impresion() const=0;

public:
	cPersonaje(string nombre, string color, string peso, string tamano, int d, int m, int a);

	virtual void mostrarStats();
	virtual void mostrarAtaques();
	virtual void descripcion() = 0;
	virtual void operator+(cAtaque* atk);
	virtual string To_string();
	friend ostream& operator<<(ostream& os,const cPersonaje& cPe);
	virtual ~cPersonaje();

	int getCantAtk();
	int getAnios();
	void imprimirDatos();
	float atacar(int i);
	bool getVivo()const;
	float getStat(int i);
	string getNombre()const;
	string getTamano() const;
	string getColor() const;
	string getPeso() const;
	cAtaque* getAtk(int i);
	list<cAtaque*> getListAtaques()const;
	time_t getTimer();

	void mostrarDanos();
	void operator-(cAtaque* atk);
};


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
	list<cAtaque*> ataques;
	cAtaque* puntero = NULL;
	int* estadisticas = NULL;
	bool vivo;


	virtual void generarStats();
	void baja() { this->vivo = false; }
	virtual void impresion() const{ cout << "Edad: " << fecha << endl; }

public:
	cPersonaje(string nombre, string color, string peso, string tamano, int d, int m, int a);

	virtual void mostrarStats();
	virtual void mostrarAtaques();
	virtual void descripcion()const = 0;
	virtual void operator+(cAtaque* atk);
	virtual string To_string();
	friend ostream& operator<<(ostream& os, const cPersonaje& cPe);
	virtual ~cPersonaje();

	int getCantAtk() { return (int)this->ataques.size(); }
	int getAnios();
	void imprimirDatos();
	float atacar(int i);
	float getStat(int i) { return this->estadisticas[i]; }
	bool getVivo()const { return this->vivo; }
	string getNombre() const { return this->nombre; }
	string getTamano() const { return this->tamano; }
	string getColor() const { return this->color; }
	string getTam() const { return this->tamano; }
	string getPeso() const { return this->peso; }
	cAtaque* getAtk(int i);
	list<cAtaque*> getListAtaques()const { return this->ataques; }

	void mostrarDanos();
	void operator-(cAtaque* atk);
};


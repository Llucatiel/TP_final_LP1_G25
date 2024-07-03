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
	int buff = 0;
	bool vivo;
	bool borrado = false;


	virtual void generarStats();
	void baja();
	virtual void impresion() const=0;

public:
	cPersonaje(string nombre, string color, string peso, string tamano, int d, int m, int a);

	virtual void mostrarStats();
	virtual void mostrarAtaques();
	virtual void operator+(cAtaque* atk);
	virtual string To_string();
	friend ostream& operator<<(ostream& os,const cPersonaje& cPe);
	virtual ~cPersonaje();

	int getCantAtk();
	int getAnios();
	int getBuff();
	void imprimirDatos();
	int atacar(int i);
	float ataque(int i, int critico);
	bool getVivo()const;
	bool getBorrado()const;
	float getStat(int i);
	string getNombre()const;
	string getTamano() const;
	string getColor() const;
	string getPeso() const;
	cAtaque* getAtk(int i);
	list<cAtaque*> getListAtaques()const;
	time_t getTimer();

	void mostrarDanos();
	void convertido();
	void operator-(cAtaque* atk);
};


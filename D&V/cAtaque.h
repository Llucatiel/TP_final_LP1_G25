#pragma once
#include <string>
#include <iostream>
using namespace std;

enum TIPO { vacio = -1, fuego, aire, veneno, fisico };
typedef TIPO tipo;

class cAtaque
{
private:
	string nombre;
	tipo type;
	int estadisticaUsada;
	float dano;
	float probabilidad;

	float danoTotal(int stat);


public:
	cAtaque();
	cAtaque(tipo type);
	cAtaque(string nombre, tipo type, int stat, float dano, float prob);
	~cAtaque();

	int getStat() { return this->estadisticaUsada; }
	float probTotal(int stat);
	string getNombre() { return this->nombre; }
	tipo getTipo() { return this->type; }
	float getDano() { return this->dano; }
	float getProb() { return this->probabilidad; }
};

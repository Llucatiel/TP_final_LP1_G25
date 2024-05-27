#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

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

	float probTotal(int stat);
	float getDano() { return this->dano; }
	float getProb() { return this->probabilidad; }
	int getStat() { return this->estadisticaUsada; }
	string getNombre() { return this->nombre; }
	tipo getTipo() { return this->type; }
};

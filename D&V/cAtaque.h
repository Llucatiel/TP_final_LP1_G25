#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

enum tipo { vacio = -1, fuego, aire, veneno, fisico };


class cAtaque
{
private:
	string nombre;
	tipo type;
	int estadisticaUsada;
	float dano;
	float probabilidad;



public:
	cAtaque();
	cAtaque(tipo type);
	cAtaque(string nombre, tipo type, int stat, float dano, float prob);
	~cAtaque();

	float danoTotal(int stat);
	float probTotal(int stat);
	float getDano();
	float getProb();
	int getStat();
	string getNombre();
	tipo getTipo();
};

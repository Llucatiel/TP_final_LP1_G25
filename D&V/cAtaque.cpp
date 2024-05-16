#include "cAtaque.h"


cAtaque::cAtaque(string nombre, tipo type, int stat, float dano, float prob)
{
	this->nombre = nombre;
	this->type = type;
	this->estadisticaUsada = stat;
	this->dano = dano;
	this->probabilidad = prob;
}



cAtaque::~cAtaque()
{
}


//Calcula si el ataque pega y el daño producido
float cAtaque::probTotal(int stat)
{


	float prob = this->probabilidad * (float)stat / 10;

	if (prob >= 94)
		prob = 94;

	int hit = rand() % 100;
	cout << hit << endl;
	if (hit == 0) {
		return danoTotal(stat) * 2;
	}
	else if (hit <= prob)
		return danoTotal(stat);

	cout << "Fallo" << endl;

	return 0;
}


//Calcula el daño producido
float cAtaque::danoTotal(int stat)
{
	float total = this->dano * (float)stat / 10;
	string elemento[4] = { "fuego", "aire", "veneno", "fisico" };
	cout << total << " de dano de " << elemento[this->type] << endl;

	return total;
}



#include "cAtaque.h"


cAtaque::cAtaque(tipo type)
{
	this->type = type;
	string melee[4] = { "Fuerza bruta", "Carga", "Cabezaso", "Corte horizontal" };
	nombre = melee[rand() % 4];
	if(this->type == fisico)
		estadisticaUsada = 0;
	this->dano = 12 + rand() % 27;
	this->probabilidad = 12 + rand() % 27;

}

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
	if (hit == 0) {
		cout << "HA SACADO UN CRITICO" << endl;
		return danoTotal(stat) * 2;
	}
	else if (hit <= prob) {
		cout << "Ha acertado al objetivo" << endl;
		return danoTotal(stat);
	}
	cout << "El ataque fallo lastimosamente..." << endl;

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



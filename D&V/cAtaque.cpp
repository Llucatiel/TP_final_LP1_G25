#include "cAtaque.h"

string Fisico[] = { "Fuerza bruta", "Carga", "Cabezaso", "Corte horizontal" };
string Fuego[] = { "Bola de fuego", "Llamarada", "Lluvia de meteoros", "Cabezaso volcanico" };
string Aire[] = { "Tornado", "Corte aereo", "Aliento de tormenta", "Nube de algodon" };
string Veneno[] = { "Escupitajo sombrio", "Rociada de acido", "Derretir escamas", "Vision alterada" };

string elemento[4] = { "fuego", "aire", "veneno", "fisico" };

//Crea ataque completamente al azar
cAtaque::cAtaque()
{
	this->type = (tipo)(rand() % 4);
	int elegir = rand() % 4;

	switch (this->type)
	{
	case 0:
		this->nombre = Fuego[elegir];
		this->estadisticaUsada = 3;
		this->dano = 25 + rand() % 26;
		this->probabilidad = 32 + rand() % 26;
		break;

	case 1:
		this->nombre = Aire[elegir];
		this->estadisticaUsada = 1;
		this->dano = 12 + rand() % 26;
		this->probabilidad = 45 + rand() % 26;
		break;

	case 2:
		this->nombre = Veneno[elegir];
		this->estadisticaUsada = 3;
		this->dano = 19 + rand() % 26;
		this->probabilidad = 40 + rand() % 26;
		break;

	case 3:
		this->nombre = Fisico[elegir];
		this->estadisticaUsada = 0;
		this->dano = 27 + rand() % 26;
		this->probabilidad = 30 + rand() % 26;
		break;

	default:
		break;
	}
	if (this->probabilidad > 99.0)
		this->probabilidad = 95.0;
}

//Crea ataque por su tipo
cAtaque::cAtaque(tipo type)
{
	int elegir = rand() % 4;
	this->type = type;

	switch (this->type)
	{
	case 0:
		this->nombre = Fuego[elegir];
		this->estadisticaUsada = 3;
		this->dano = 25 + rand() % 26;
		this->probabilidad = 32 + rand() % 26;
		break;

	case 1:
		this->nombre = Aire[elegir];
		this->estadisticaUsada = 1;
		this->dano = 12 + rand() % 26;
		this->probabilidad = 45 + rand() % 26;
		break;

	case 2:
		this->nombre = Veneno[elegir];
		this->estadisticaUsada = 3;
		this->dano = 19 + rand() % 26;
		this->probabilidad = 40 + rand() % 26;
		break;

	case 3:
		this->nombre = Fisico[elegir];
		this->estadisticaUsada = 0;
		this->dano = 27 + rand() % 26;
		this->probabilidad = 30 + rand() % 26;
		break;

	default:
		break;
	}
	if (this->probabilidad > 99.0)
		this->probabilidad = 95.0;
}

//Crea ataque por todos sus atributos
cAtaque::cAtaque(string nombre, tipo type, int stat, float dano, float prob)
{
	this->nombre = nombre;
	this->type = type;
	this->estadisticaUsada = stat;
	this->dano = dano;
	this->probabilidad = prob;
}


//Calcula si el ataque pega y el da�o producido
float cAtaque::probTotal(int stat)
{
	float prob = this->probabilidad * (float)stat / 10; //stat = 20 -> prob*2

	if (prob > 95.0)
		prob = 95.0;

	int hit = rand() % 100;
	if (hit <= 10.0) {
		return 2;
	}
	else if (hit <= prob) {
		return 1;
	}
	return 0;
}

float cAtaque::getDano()
{
	return this->dano;
}

float cAtaque::getProb()
{
	return this->probabilidad;
}

int cAtaque::getStat()
{
	return this->estadisticaUsada;
}

string cAtaque::getNombre()
{
	return this->nombre;
}

tipo cAtaque::getTipo()
{
	return this->type;
}


//Calcula el da�o producido
float cAtaque::danoTotal(int stat)
{
	float total = (this->dano * (float)stat / 10) + (rand() % 16);
	return total;
}


cAtaque::~cAtaque()
{
}
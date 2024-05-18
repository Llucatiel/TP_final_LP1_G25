#include "cAtaque.h"


cAtaque::cAtaque()
{
	this->type = (tipo)(rand() % 4);
	string fisico[4] = { "Fuerza bruta", "Carga", "Cabezaso", "Corte horizontal" };
	string fuego[4] = { "Bola de fuego", "Llamarada", "Lluvia de meteoros", "Cabezaso volcanico" };
	string aire[4] = { "Tornado", "Corte aereo", "Aliento de tormenta", "Nube de algodon" };
	string veneno[4] = { "Escupitajo sombrio", "Rociada de acido", "Derretir escamas", "Vision alterada" };


	this->nombre = "404";
	this->estadisticaUsada = 0;
	this->dano = 0;
	this->probabilidad = 0;

	int elegir = rand() % 4;
	switch (this->type)
	{
	case 0:
		this->nombre = fuego[elegir];
		this->estadisticaUsada = 3;
		this->dano = 25 + rand() % 26;
		this->probabilidad = 12 + rand() % 26;
		break;

	case 1:
		this->nombre = aire[elegir];
		this->estadisticaUsada = 1;
		this->dano = 12 + rand() % 26;
		this->probabilidad = 25 + rand() % 26;
		break;

	case 2:
		this->nombre = veneno[elegir];
		this->estadisticaUsada = 3;
		this->dano = 19 + rand() % 26;
		this->probabilidad = 20 + rand() % 26;
		break;

	case 3:
		this->nombre = fisico[elegir];
		this->estadisticaUsada = 0;
		this->dano = 27 + rand() % 26;
		this->probabilidad = 10 + rand() % 26;
		break;

	default:
		break;
	}
}

cAtaque::cAtaque(tipo type)
{//TIPO { vacio = -1, fuego, aire, veneno, fisico}
	this->type = type;
	string fisico[4] = { "Fuerza bruta", "Carga", "Cabezaso", "Corte horizontal" };
	string fuego[4] = { "Bola de fuego", "Llamarada", "Lluvia de meteoros", "Cabezaso volcanico" };
	string aire[4] = { "Tornado", "Corte aereo", "Aliento de tormenta", "Nube de algodon" };
	string veneno[4] = { "Escupitajo sombrio", "Rociada de acido", "Derretir escamas", "Vision alterada" };

	int elegir = rand() % 4;
	switch (this->type)
	{
	case 0:
		this->nombre = fuego[elegir];
		this->estadisticaUsada = 3;
		this->dano = 25 + rand() % 26;
		this->probabilidad = 12 + rand() % 26;
		break;

	case 1:
		this->nombre = aire[elegir];
		this->estadisticaUsada = 1;
		this->dano = 12 + rand() % 26;
		this->probabilidad = 25 + rand() % 26;
		break;

	case 2:
		this->nombre = veneno[elegir];
		this->estadisticaUsada = 3;
		this->dano = 19 + rand() % 26;
		this->probabilidad = 20 + rand() % 26;
		break;

	case 3:
		this->nombre = fisico[elegir];
		this->estadisticaUsada = 0;
		this->dano = 27 + rand() % 26;
		this->probabilidad = 10 + rand() % 26;
		break;

	default:
		break;
	}
}

cAtaque::cAtaque(string nombre, tipo type, int stat, float dano, float prob)
{
	this->nombre = nombre;
	this->type = type;
	this->estadisticaUsada = stat;
	this->dano = dano;
	this->probabilidad = prob;
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


cAtaque::~cAtaque()
{
}

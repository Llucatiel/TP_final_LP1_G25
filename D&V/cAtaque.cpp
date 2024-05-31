#include "cAtaque.h"

string Fisico[] = { "Fuerza bruta", "Carga", "Cabezaso", "Corte horizontal" };
string Fuego[] = { "Bola de fuego", "Llamarada", "Lluvia de meteoros", "Cabezaso volcanico" };
string Aire[] = { "Tornado", "Corte aereo", "Aliento de tormenta", "Nube de algodon" };
string Veneno[] = { "Escupitajo sombrio", "Rociada de acido", "Derretir escamas", "Vision alterada" };

//Crea ataque completamente al azar
cAtaque::cAtaque()
{
	this->type = (tipo)(rand() % 4);

	this->nombre = "404";
	this->estadisticaUsada = 0;
	this->dano = 0;
	this->probabilidad = 0;

	int elegir = rand() % 4;
	switch (this->type)
	{
	case 0:
		this->nombre = Fuego[elegir];
		this->estadisticaUsada = 3;
		this->dano = 25 + rand() % 26;
		this->probabilidad = 12 + rand() % 26;
		break;

	case 1:
		this->nombre = Aire[elegir];
		this->estadisticaUsada = 1;
		this->dano = 12 + rand() % 26;
		this->probabilidad = 25 + rand() % 26;
		break;

	case 2:
		this->nombre = Veneno[elegir];
		this->estadisticaUsada = 3;
		this->dano = 19 + rand() % 26;
		this->probabilidad = 20 + rand() % 26;
		break;

	case 3:
		this->nombre = Fisico[elegir];
		this->estadisticaUsada = 0;
		this->dano = 27 + rand() % 26;
		this->probabilidad = 10 + rand() % 26;
		break;

	default:
		break;
	}
}

//Crea ataque por su tipo
cAtaque::cAtaque(tipo type)
{
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
		this->dano = 35 + rand() % 26;
		this->probabilidad = 83 + rand() % 26;
		break;

	case 1:
		this->nombre = aire[elegir];
		this->estadisticaUsada = 1;
		this->dano = 22 + rand() % 26;
		this->probabilidad = 89 + rand() % 26;
		break;

	case 2:
		this->nombre = veneno[elegir];
		this->estadisticaUsada = 3;
		this->dano = 29 + rand() % 26;
		this->probabilidad = 85 + rand() % 26;
		break;

	case 3:
		this->nombre = fisico[elegir];
		this->estadisticaUsada = 0;
		this->dano = 37 + rand() % 26;
		this->probabilidad = 80 + rand() % 26;
		break;

	default:
		break;
	}
	if (this->probabilidad > 99)
		this->probabilidad = 95;
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

	if (prob > 95)
		prob = 95;

	int hit = rand() % 100;
	if (hit <= 10) {
		cout << "HA SACADO UN CRITICO" << endl;
		for (int i = 0; i < 3; i++) {
			system("color 47");
			Sleep(100);
			system("color 67");
			Sleep(100);
		}
		system("color 07");
		return danoTotal(stat) * 2;
	}
	else if (hit <= prob) {
		cout << "Ha acertado al objetivo" << endl;
		for (int i = 0; i < 3; i++) {
			system("color 87");
			Sleep(100);
			system("color 07");
			Sleep(100);
		}
		return danoTotal(stat);
	}
	cout << "El ataque fallo lastimosamente..." << endl;
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
	if (total <= 0)
		total = 5;

	string elemento[4] = { "fuego", "aire", "veneno", "fisico" };
	cout << total << " de dano de " << elemento[this->type] << endl;
	return total;
}


cAtaque::~cAtaque()
{
}

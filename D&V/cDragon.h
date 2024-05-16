#pragma once
#include <ctime>
#include <cstdlib>
#include "cAtaque.h"
#include <list>


class cDragon
{
private:
	string nombre;
	float vidaMax;
	float vidaActual;
	string tamano;
	string color;
	bool domado;
	string peso;
	unsigned short int cantJinetes;
	tipo aliento;
	tipo segundo;
	list<cAtaque*> ataques;
	int* estadisticas; //Potencia, Fuerza, Destreza, Constitucion
	int cantCabezas;
	int cantAtaques;
	time_t fechaAdopcion;
	bool vivo;


	void generarStats();//Genera por primera vez las estadisticas del dragon. Solo al llamar al constructor
	void altaNombre();

public:
	bool getDomado() const { return this->domado; }
	cDragon(cAtaque* atk);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas, int d, int m, int a);
	~cDragon();
	string getNombre() const { return this->nombre; }
	string getTamano() const { return this->tamano; }
	int getTiempoAdoptado();

	float atacar(int i);

	void aprenderAtk(cAtaque* atk);
	void olvidarAtk(cAtaque* atk);
	void mostrarStats();
	void mostrarAtaques();
	void perderVida(float dano);
	float getVida() const { return this->vidaActual; }
	void curarse() { this->vidaActual = this->vidaMax; }
};
#pragma once
#include <cstdlib>
#include "cPersonaje.h"

class cDragon : public cPersonaje
{
	static int cantDragones;

	int identificador;
	int* estadisticas; //Potencia, Fuerza, Destreza, Constitucion
	unsigned short int cantJinetes;
	float vidaMax;
	float vidaActual;
	int cantCabezas;
	bool domado;
	bool vivo;
	tipo aliento;
	tipo segundo;


	void generarStats();
	void altaNombre();

public:
	cDragon();
	cDragon(cAtaque* atk);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas, int d, int m, int a);

	float getVidaActual() const { return this->vidaActual; }
	float getVidaTotal() const { return this->vidaMax; }
	bool getDomado() const { return this->domado; }
	int getIdentificador() const { return this->identificador; }
	tipo getAliento() const { return aliento; }
	tipo getSegundo() const { return segundo; }

	void mostrarStats();
	void operator+(cAtaque* atk);
	void perderVida(float dano);
	void curarse() { this->vidaActual = this->vidaMax; }
	void descripcion()const;
	//void domar() {};
};


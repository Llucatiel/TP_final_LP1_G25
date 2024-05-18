#pragma once
#include <cstdlib>
#include "cDatos.h"

class cDragon : public cDatos
{
private:

	float vidaMax;
	float vidaActual;
	bool domado;
	unsigned short int cantJinetes;
	tipo aliento;
	tipo segundo;
	int* estadisticas; //Potencia, Fuerza, Destreza, Constitucion
	int cantCabezas;
	bool vivo;

	void generarStats();
	void altaNombre();

public:
	cDragon();
	cDragon(cAtaque* atk);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas, int d, int m, int a);

	void mostrarStats();
	bool getDomado() const { return this->domado; }
	float atacar(int i);
	void aprenderAtk(cAtaque* atk);
	void olvidarAtk(cAtaque* atk);
	void perderVida(float dano);
	float getVidaActual() const { return this->vidaActual; }
	void curarse() { this->vidaActual = this->vidaMax; }
	void descripcion()const;
	void mostrarDanos();
};
#pragma once
#include "cPersonaje.h"

class cDragon : public cPersonaje
{
private:
	static int cantDragonesDomados;

	unsigned short int cantJinetes;
	int identificador;
	float vidaMax;
	float vidaActual;
	int cantCabezas;
	bool domado;
	tipo secundario;


	void generarStats();
	void altaNombre();
	void impresion() const;

	static int sumaVuelta();

public:
	cDragon();
	cDragon(cAtaque* atk);
	cDragon(cAtaque* atk, tipo secundario, string tamano, string color, string peso, int cabezas);
	cDragon(cAtaque* atk, tipo secundario, string tamano, string color, string peso, int cabezas, int d, int m, int a);
	~cDragon();

	float getVidaActual() const;
	float getVidaTotal() const;
	bool getDomado() const;
	unsigned int getCantCabezas() const;
	int getIdentificador() const;
	void setBuff(int buffo);
	tipo getAliento() const;
	tipo getsecundario() const;

	void domar();
	void mostrarStats();
	void operator+(cAtaque* atk);
	void perderVida(float dano);
	void curarse();
};
#pragma once
#include "cPersonaje.h"



class cDragon : public cPersonaje
{
private:
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
	void impresion() const;

	static int sumaVuelta();

public:
	cDragon();
	cDragon(cAtaque* atk);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas);
	cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas, int d, int m, int a);

	float getVidaActual() const;
	float getVidaTotal() const;
	bool getDomado() const;
	int getIdentificador() const;
	tipo getAliento() const;
	tipo getSegundo() const;

	void domar();
	void mostrarStats();
	void operator+(cAtaque* atk);
	void perderVida(float dano);
	void curarse();
	void descripcion()const;
};
#pragma once
#include "cJinete.h"
//Estos dos son para llevar un string de minusculas a mayusculas
#include <algorithm>
#include <cctype>

class cDragon;

class cBocon
{
	static int comida;
	list<cDragon*> dragones;
	list<cDragon*> dragonesNoDomados;
	list<cVikingo*> vikingos;
	list<cJinete*> jinetes;
	list<cPersonaje*> valhalla;

public:
	cBocon();
	~cBocon();

	static int getComida();
	static void cambioComida(int suma);

	int getCantDrag();
	int getCantVik();
	int getCantJin();


	void operator+(cDragon* dragon);
	void operator+(cVikingo* vik);
	void operator+(cJinete* jin);
	void encuentrePaz(cDragon* perdida);
	void encuentrePaz(cVikingo* perdida);
	void encuentrePaz(cJinete* perdida);
	void enlistarVikingo();
	void enlistarDragon();
	void conversion(cDragon* dragon, list<cVikingo*> vikingo);


	void elegirVikingo(int* elegidos, int n);
	void elegirDragon(int elegido);

	void atacarDragones(list<cVikingo*> vikingos);
	void pelea(list<cJinete*> jin);
};


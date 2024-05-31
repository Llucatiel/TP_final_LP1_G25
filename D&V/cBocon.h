#pragma once
#include "cJinete.h"
//Estos dos son para llevar un string de minusculas a mayusculas
#include <algorithm>
#include <cctype>

class cBocon
{
	list<cDragon*> dragones;
	list<cDragon*> dragonesNoDomados;
	list<cVikingo*> vikingos;
	list<cJinete*> jinetes;
	list<cPersonaje*> valhalla;

public:
	cBocon();
	~cBocon();

	void operator+(cDragon* dragon);
	void operator+(cVikingo* vik);
	void operator+(cJinete* jin);
	void operator+(cPersonaje* perdida);
	void enlistarVikingo();
	void enlistarDragon();
	void conversion(cDragon* dragon, cVikingo* vikingo);

	void elegirVikingo(int* elegidos, int n);
	void elegirDragon(int elegido);

	void atacarDragones(list<cVikingo*> vikingos);
	void pelea(list<cJinete*> jin);
};


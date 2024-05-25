#pragma once
#include "cJinete.h"
//Estos dos son para llevar un string de minusculas a mayusculas ->
#include <algorithm>
#include <cctype>

class cVikingo;

class cBocon
{
	list<cDragon*> dragones;
	list<cVikingo*> vikingos;
	list<cJinete*> jinetes;


public:
	cBocon() {};
	~cBocon() {
		vikingos.clear();
		dragones.clear();
	}

	void operator+(cDragon* dragon) { dragones.push_back(dragon); }
	void operator+(cVikingo* vik) { vikingos.push_back(vik); }
	void operator+(cJinete* jin) { jinetes.push_back(jin); }
	void enlistarVikingo();
	void enlistarDragon();

	void elegirVikingo(int* elegidos, int n);
	void elegirDragon(int elegido);

	void atacarDragones(list<cVikingo*> vikingos);
	void pelea(list<cJinete*> jin);

	void transformacion(cVikingo& vikingos);
};


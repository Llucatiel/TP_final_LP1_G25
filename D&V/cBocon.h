#pragma once
#include "cDragon.h"
#include "cJinete.h"
#include <cstdlib>
#include <iostream>
//Estos dos son para llevar un string de minusculas a mayusculas
#include <algorithm>
#include <cctype>

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

	void agregarDragon(cDragon* dragon) { dragones.push_back(dragon); }
	void agregarVikingo(cVikingo* vik) { vikingos.push_back(vik); }
	void agregarJinete(cJinete* jin) { jinetes.push_back(jin); }
	void enlistarVikingo();
	void enlistarDragon();

	void elegirVikingo(int* elegidos, int n);
	void elegirDragon(int elegido);

	void atacarDragones(list<cVikingo*> vikingos);
	void pelea(cDragon* dragon);
};

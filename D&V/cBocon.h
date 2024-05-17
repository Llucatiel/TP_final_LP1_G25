#pragma once
#include "cDragon.h"
#include "cJinete.h"
#include <cstdlib>
#include <iostream>

class cBocon
{
	list<cDragon*> dragones;
	list<cVikingo*> vikingos;
	list<cJinete*> jinetes;

public:
	cBocon();

	void agregarDragon(cDragon* dragon) { dragones.push_back(dragon); }
	void agregarVikingo(cVikingo* vik) { vikingos.push_back(vik); }
	void agregarJinete(cJinete* jin) { jinetes.push_back(jin); }

	void atacarDragones(list<cVikingo*> vikingos);
	void elegir(int* elegidos, int n);

	void enlistarVikingo();
	void enlistarDragon();
	void pelea(cDragon* dragon);

	~cBocon() {
		vikingos.clear();
		dragones.clear();
	}
};


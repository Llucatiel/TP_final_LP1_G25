#pragma once
#include "cDragon.h"
#include "cVikingo.h"
#include <cstdlib>
#include <iostream>

class cBocon
{
	list<cDragon*> dragones;
	list<cVikingo*> vikingos;

public:
	cBocon();

	void agregarDragon(cDragon* dragon) { dragones.push_back(dragon); }
	void agregarVikingo(cVikingo* vik) { vikingos.push_back(vik); }

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


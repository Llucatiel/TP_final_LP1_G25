#pragma once
#include "cVikingo.h"
#include "cDragon.h"

enum eRelacion {
	pobre = 0, mala, mediana, buena, superbuena
};
typedef eRelacion relacion;


class cJinete :public cVikingo
{
	string apodo;
	string colordepelo;
	cDragon* dragon;
	int notaEntrenar = 5;
	int buffeo = 0;
	relacion relacionDragon = pobre;

public:
	void asignarDragon(cDragon* dragon);
	string getApodo() { return apodo; }
	string setApodo(string apodito) {
		this->apodo = apodito;
	}
	void entrenar();

};


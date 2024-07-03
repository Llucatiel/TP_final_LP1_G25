#pragma once
#include "cVikingo.h"
#include "cDragon.h"

class cJinete :public cVikingo
{
	string apodo;
	cDragon* dragon;
	int notaEntrenar;

	void impresion() const;

public:
	cJinete(string nombre, string apellido, string pelo,string altura, string peso, int d, int m, int a,string apodo,cDragon*dragon);
	cJinete(cVikingo* viki, cDragon* dragon);
	void asignarDragon(cDragon* dragon);
	string getApodo()const;
	void setApodo(string apodito);
	cDragon* getDragon();
	void entrenar();
	~cJinete();

	int getNota();
};


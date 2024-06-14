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
	cDragon* dragon;
	int notaEntrenar;
	relacion relacionDragon = pobre;

	void impresion() const;

public:
	cJinete(string nombre, string apellido, string pelo,string altura, string peso, int d, int m, int a,string apodo,cDragon*dragon);
	cJinete(cVikingo& viki, cDragon* dragon);
	void asignarDragon(cDragon* dragon);
	string getApodo()const;
	void setApodo(string apodito);
	cDragon* getDragon();
	void entrenar();

};


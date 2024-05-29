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
	int notaEntrenar = 5;
	int buffeo = 0;
	relacion relacionDragon = pobre;

	void impresion() const {
		cout<< apellido;
		cout << "y su empedernido dragon es el poderoso: " << dragon->getNombre() << ". Lleva vagando por estas tierras desde hace "<<fecha<<" años con su melena "<<color<<".";
	}

public:
	cJinete(string nombre, string apellido, string pelo,string altura, string peso, int d, int m, int a,string apodo,cDragon*dragon);
	cJinete(cVikingo& viki, cDragon* dragon);
	void asignarDragon(cDragon* dragon);
	string getApodo() { return apodo; }
	string setApodo(string apodito) {
		this->apodo = apodito;
	}
	cDragon *getDragon() { return dragon; }
	void entrenar();

};


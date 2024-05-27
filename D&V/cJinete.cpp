#include "cJinete.h"

cJinete::cJinete(string nombre, string apellido, string pelo,string altura, string peso, int d, int m, int a, string apodo, cDragon* dragon):
	cVikingo(nombre, pelo, apellido, d, m, a, altura, peso, "Jinete", dragones_terminados)
{
	this->apodo = apodo;
	this->dragon = dragon;
}

cJinete::cJinete(cVikingo& viki, cDragon *dragon):cVikingo(viki.getNombre(),viki.getColor(), viki.getApellido(), 1, 1, 1000, viki.getTam(),viki.getPeso(), "Jinete", NULL)
{
	this->dragon = dragon;
	this->ataques = viki.getListAtaques();

}

void cJinete::asignarDragon(cDragon* dragon)
{
	this->dragon = dragon;
}

void cJinete::entrenar()
{
	int buffeo;
	notaEntrenar = rand() % 11;

	buffeo = (notaEntrenar - 5) / 2;
}

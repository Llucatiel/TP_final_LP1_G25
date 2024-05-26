#include "cJinete.h"

cJinete::cJinete(string nombre, string pelo, int d, int m, int a, string apodo, cDragon* dragon): cVikingo()
{
	this->nombre = nombre;
	this->color = pelo;
	struct tm date = { 0 };
	date.tm_year = a - 1900;
	date.tm_mon = m - 1;
	date.tm_mday = d;
	this->fecha = mktime(&date);
	this->apodo = apodo;
	this->dragon = dragon;
}

cJinete::cJinete(cVikingo& viki):cVikingo()
{
	this->nombre = viki.getNombre();
	this->apellido = viki.getApellido();
	this->dragon = getDragon();
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

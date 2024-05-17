#include "cJinete.h"

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

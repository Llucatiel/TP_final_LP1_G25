#include "cJinete.h"

void cJinete::impresion() const
{
	cout << "Apellido: " << apellido << endl;
	cout << "Apodo: " << apodo << endl;
	cout << "Dragon: " << dragon->getNombre() << endl;
	cout << "Edad: " << edad << endl;
	cout << "Color de pelo: " << color << endl;
}

cJinete::cJinete(string nombre, string apellido, string pelo,string altura, string peso, int d, int m, int a, string apodo, cDragon* dragon):
	cVikingo(nombre, pelo, apellido, d, m, a, altura, peso, "Jinete", dragones_terminados)
{
	this->apodo = apodo;
	this->dragon = dragon;
	this->buffeo = 0;
	this->notaEntrenar = 5;
}

cJinete::cJinete(cVikingo& viki, cDragon *dragon):cVikingo(viki.getNombre(),viki.getColor(), viki.getApellido(), 0, 0, 0, viki.getTamano(),viki.getPeso(), "Jinete", NULL)
{
	try {
		dragon->domar();
		this->dragon = dragon;
		*this - getAtk(0);
	}
	catch (const exception* e) {
		cout << e->what();
		this->dragon = NULL;
		delete e;
	}
	this->ataques = viki.getListAtaques();
	for (int i = 0; i < 3; i++)
		this->estadisticas[i] = viki.getStat(i);
	this->fecha = viki.getTimer();
	this->edad = getAnios();
}

void cJinete::asignarDragon(cDragon* dragon)
{
	this->dragon = dragon;
}

void cJinete::setApodo(string apodito)
{
	this->apodo = apodito;
}

void cJinete::entrenar()
{
	int buffeo;
	notaEntrenar = rand() % 11;

	buffeo = (notaEntrenar - 5) / 2;
}

string cJinete::getApodo() const {
	return apodo;
}

cDragon* cJinete::getDragon() {
	return dragon;
}
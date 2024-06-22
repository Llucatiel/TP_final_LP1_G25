#include "cJinete.h"

void cJinete::impresion() const
{
	cout << " " << apellido << " nuestro gran jinete de " <<dragon->getNombre() << " que lleva rondando por estas tierras desde hace " << edad << " primaveras." << endl;
	cout << "Su brillante cabellera " << color << " resplandece ante el atardecer de este peso pesado de " << peso << " kg ademas de su estatura de " << tamano << " metros" << endl;
	if (dragones_terminados > 0)
		cout << "Lleva " << dragones_terminados << " cadaveres de dragones en su espalda" << endl;
}

cJinete::~cJinete()
{
}

cJinete::cJinete(string nombre, string apellido, string pelo,string altura, string peso, int d, int m, int a, string apodo, cDragon* dragon):
	cVikingo(nombre, pelo, apellido, d, m, a, altura, peso, entrenadordedragones, dragones_terminados)
{
	this->apodo = apodo;
	this->dragon = dragon;
	this->notaEntrenar = 5;
}

cJinete::cJinete(cVikingo* viki, cDragon *dragon):cVikingo(viki->getNombre(),viki->getColor(), viki->getApellido(), 0, 0, 0, viki->getTamano(),viki->getPeso(), entrenadordedragones, NULL)
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
	this->ataques.clear();

	this->ataques = viki->getListAtaques();

	for (int i = 0; i < 3; i++)
		this->estadisticas[i] = viki->getStat(i);
	this->fecha = viki->getTimer();
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
	notaEntrenar = 1 + rand() % 10;
	int buff = (notaEntrenar - 5) / 2;
	getDragon()->setBuff(buff);
	cout << "El entrenamiento de hoy ";
	if (notaEntrenar < 4) {
		cout << "fue un fracaso\n";
	}
	else if (notaEntrenar < 6)
		cout << "podrias haberlo hecho mejor\n";
	else if (notaEntrenar < 10)
		cout << "estuviste muy bien, con espacio a mejora\n";
	else cout << "es un bellisimo 10\n";
	
		cout << getDragon()->getNombre() << " tendra un modificador de " << buff << " a sus estadisticas durante su siguiente pelea\n";
}

string cJinete::getApodo() const {
	return apodo;
}

cDragon* cJinete::getDragon() {
	return dragon;
}
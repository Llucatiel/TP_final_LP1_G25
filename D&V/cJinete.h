#pragma once
#include "cVikingo.h"
#include "cDragon.h"

enum eResultado {
	noAsistio = 0, reprobo, aprobo, primero, ultimo
};
typedef eResultado resultado;

class cJinete :public cVikingo
{
	string apodo;
	string colordepelo;
	cDragon* dragon;

	

};


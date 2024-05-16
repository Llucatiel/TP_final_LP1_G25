#include "cVikingo.h"

int cVikingo::comida = 30;
int cVikingo::cantVikingos = 0;
cVikingo::cVikingo(string nombre, string apellido, int d, int m, int a, string altura, string peso, string trabajo, int dragones_terminados)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->fechadeNacimiento.tm_mday = d;
    this->fechadeNacimiento.tm_mon = m - 1;
    this->fechadeNacimiento.tm_year = a - 1900;
    this->altura = altura;
    this->peso = peso;
    this->trabajo = trabajo;
    this->dragones_terminados = dragones_terminados;

    cantVikingos++;
}


int cVikingo::getEdad()
{
    time_t now;
    time(&now);
    time_t nacimiento = mktime(&fechadeNacimiento);
    int age = ((difftime(now, nacimiento) + 864000L / 2) / 86400L) / 365;
    return age;
}

void cVikingo::cambioComida(int suma)
{
    comida += suma;
}
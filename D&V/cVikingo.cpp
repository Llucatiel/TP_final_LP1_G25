#include "cVikingo.h"

int cVikingo::comida = 30;
int cVikingo::cantVikingos = 0;

cVikingo::cVikingo(string nombre, string apellido, int d, int m, int a, string tamano, string peso, string trabajo, int dragones_terminados)
{

    this->estadisticas = new int[3];
    this->nombre = nombre;
    this->apellido = apellido;
    struct tm date = { 0 };
    date.tm_year = a - 1900;
    date.tm_mon = m - 1;
    date.tm_mday = d;

    this->fecha = mktime(&date);

    this->tamano = tamano;
    this->peso = peso;
    this->trabajo = trabajo;
    this->dragones_terminados = dragones_terminados;

    generarStats();
    cantVikingos++;
}


void cVikingo::cambioComida(int suma)
{
    comida += suma;
}

void cVikingo::descripcion() const
{
    cout << " " << endl;
}

cVikingo:: ~cVikingo() {
    cantVikingos--;
}
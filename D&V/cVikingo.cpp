#include "cVikingo.h"

//Inicializa sus atributos estaticos
int cVikingo::comida = 30;
int cVikingo::cantVikingos = 0;

//Creacion por parametro de un vikingo
cVikingo::cVikingo(string nombre, string apellido, int d, int m, int a, string tamano, string peso, string trabajo, int dragones_terminados):cPersonaje(nombre,ap)
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

//Imprime por pantalla la descripcion del vikingo
void cVikingo::descripcion() const
{
    cout << " " << endl;
}

//Libera memoria
cVikingo:: ~cVikingo() {
    cantVikingos--;
}
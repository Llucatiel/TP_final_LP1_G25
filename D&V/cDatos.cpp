#include "cDatos.h"

void cDatos::generarStats()
{

    int min = 0;
    int dice = 0;
    //Para generar las estadisticas, se tiran 4 dados y se resta el numero más bajo

    for (int i = 0; i < 3; i++) {
        this->estadisticas[i] = 0;
        min = 0;

        for (int j = 0; j < 4; j++) {
            dice = 1 + rand() % 6;
            this->estadisticas[i] += dice;
            if (min > dice)
                min = dice;
        }
        this->estadisticas[i] -= min;
    }
}

void cDatos::mostrarStats()
{
    if (!this->vivo)
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");

    cout << "Fuerza: " << this->estadisticas[0] << endl;
    cout << "Destreza: " << this->estadisticas[1] << endl;
    cout << "Constitucion: " << this->estadisticas[2] << endl;
}

void cDatos::mostrarAtaques()
{

    if (!this->vivo)
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");


    if (this->cantAtaques < 1) {
        cout << getNombre() << " no conoce ningun ataque. " << endl;
        return;
    }

    int cont = 0;
    list<cAtaque*>::iterator it = this->ataques.begin();

    while (it != this->ataques.end()) {
        cont++;
        cout << cont << ". " << (*it)->getNombre() << endl;
        it++;
    }
}

cDatos::~cDatos()
{
    this->ataques.clear();
    delete[]estadisticas;
}

int cDatos::getAnios()
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    time_t now;
    time(&now); //Tiempo actual
    int edad = (int)difftime(now, this->fecha) / 86400;
    //Calcula la diferencia entre ahora y fecha de adopcion
    if (edad < 365)
        return edad;
    return edad / 365;
    //La divide por la cantidad de dias en un anio
}

#include "cDragon.h"

//Genera las estadisticas del dragon al crearse el mismo
void cDragon::generarStats()
{
    int min = 0;
    int dice = 0;
    //Para generar las estadisticas, se tiran 4 dados y se resta el numero más bajo

    for (int i = 0; i < 4; i++) {
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


//Se le asigna al azar un nombre pre generado segun su tipo principal
void cDragon::altaNombre()
{
    //TIPO { vacio = -1, fuego, aire, veneno, fisico}
    int elegir = rand() % 4;
    string fuego[4] = { "Fogon", "Chispas", "Fogata", "Llamaleon" };
    string aire[4] = { "Nomada", "Tornado", "Cizalla", "Piloto" };
    string veneno[4] = { "Toxina", "Patogeno", "Ponzona", "Ala letal" };
    string fisico[4] = { "Patada", "Fuerza bruta", "Mr. Musculo", "Pinzas" };
    switch (this->aliento)
    {
    case 0:
        this->nombre = fuego[elegir];
        break;

    case 1:
        this->nombre = aire[elegir];
        break;

    case 2:
        this->nombre = veneno[elegir];
        break;

    case 3:
        this->nombre = fisico[elegir];
        break;

    default:
        break;
    }
}



cDragon::cDragon(cAtaque* atk)
{
    this->vivo = true;
    this->aliento = atk->getTipo();
    this->segundo = (tipo)(-1 + (rand() % 5));
    this->ataques.push_back(atk);

    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[3] * 5;
    this->vidaActual = this->vidaMax;

    this->tamano = to_string(50 + rand() % 250) + " cm";
    string color[5] = { "Verde", "Rojo", "Azul", "Marron", "Negro" };
    this->color = color[rand() % 5];
    this->domado = false;
    this->peso = to_string(40 + rand() % 460) + " kg";
    this->cantJinetes = 0;
    this->cantCabezas = 1 + rand() % 1;
    this->cantAtaques = 1;
}



cDragon::cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas)
{
    this->vivo = true;
    this->aliento = atk->getTipo();
    this->segundo = segundo;
    ataques.push_back(atk);

    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[3] * 5;
    this->vidaActual = this->vidaMax;

    this->tamano = tamano;
    this->color = color;
    this->domado = false;
    this->peso = peso;
    this->cantJinetes = 0;
    this->cantCabezas = cabezas;
    this->cantAtaques = 1;
}

cDragon::cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas, int d, int m, int a)
{
    this->vivo = true;
    this->aliento = atk->getTipo();
    this->segundo = segundo;
    ataques.push_back(atk);

    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[3] * 5;
    this->vidaActual = this->vidaMax;

    this->tamano = tamano;
    this->color = color;
    this->domado = false;
    this->peso = peso;
    this->cantJinetes = 0;
    this->cantCabezas = cabezas;
    this->cantAtaques = 1;

    struct tm date = { 0 };
    date.tm_year = a - 1900;
    date.tm_mon = m - 1;
    date.tm_mday = d;

    this->fechaAdopcion = mktime(&date);
    this->domado = true;
}


//Devuelve la cantidad de dias que lleva adoptado el dragon
int cDragon::getTiempoAdoptado()
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    time_t now;
    time(&now); //Tiempo actual
    int edad = (int)difftime(now, this->fechaAdopcion) / 86400;
    //Calcula la diferencia entre ahora y fecha de adopcion
    if (edad < 365)
        return edad;
    return edad / 365;
    //La divide por la cantidad de dias en un anio
}


//Busca en la lista de ataques el ataque a utilizar
float cDragon::atacar(int i)
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    if (this->cantAtaques <= i)
        throw new exception("No se conocen tantos ataques");

    list<cAtaque*>::iterator it = this->ataques.begin();

    int j = 0;
    while (j < i) {
        it++;
        j++;
    }

    return (*it)->probTotal(estadisticas[(*it)->getStat()]);
}


//Aprende un nuevo ataque en caso de no poseerlo
void cDragon::aprenderAtk(cAtaque* atk)
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    if (this->cantAtaques >= 4)
        throw new exception("El dragon ya conoce 4 ataques");

    if (atk->getTipo() != this->aliento && atk->getTipo() != this->segundo)
        throw new exception("El tipo de ataque no corresponde con el del Dragon");

    list<cAtaque*>::iterator it = this->ataques.begin();

    while (it != this->ataques.end()) {
        if ((*it)->getNombre() == atk->getNombre()) {
            throw new exception("El Dragon ya conoce el ataque");
        }
    }

    this->ataques.push_back(atk);
    this->cantAtaques++;
}


//Olvida un ataque ya aprendido
void cDragon::olvidarAtk(cAtaque* atk)
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    list<cAtaque*>::iterator it = this->ataques.begin();
    bool borrador = false;

    while (it != this->ataques.end()) {
        if ((*it)->getNombre() == atk->getNombre()) {
            this->ataques.erase(it);
            this->cantAtaques--;
            borrador = true;

            cout << this->nombre << " ha olvidado como usar " << atk->getNombre() << endl;
            return;
        }
    }

    if (!borrador)
        throw new exception("El Dragon no conoce el ataque");
}


//Muestras las estadisticas del dragon
void cDragon::mostrarStats()//Potencia, Fuerza, Destreza, Constitucion
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    cout << "Potencia: " << this->estadisticas[0] << endl;
    cout << "Fuerza: " << this->estadisticas[1] << endl;
    cout << "Destreza: " << this->estadisticas[2] << endl;
    cout << "Constitucion: " << this->estadisticas[3] << endl;
}


//Al recibir daño, pierde vida el mismo, en caso de llegar a 0 inutiliza las funciones del dragon
void cDragon::perderVida(float dano)
{
    this->vidaActual -= dano;

    if (this->vidaActual <= 0)
        this->vivo = false;
}


//Muestras los ataques que el dragon conoce
void cDragon::mostrarAtaques()
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");


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



cDragon::~cDragon()
{
    delete[] estadisticas;
    this->ataques.clear();
}





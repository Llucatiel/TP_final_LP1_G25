#include "cDragon.h"

void cDragon::generarStats()
{

    int min = 0;
    int dice = 0;
    //Para generar las estadisticas, se tiran 4 dados y se resta el numero m�s bajo

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
        this->estadisticas[i] *= 1,5;
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



cDragon::cDragon()
{
    this->vivo = true;
    this->aliento = (tipo)(rand() % 4);

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
    this->cantCabezas = 1 + (rand() % 10)/10;
    if (cantCabezas > 0) {
        puntero = new cAtaque[2];
        do {
            this->segundo = (tipo)(rand() % 4);
        } while (segundo == aliento);
        puntero[1] =  cAtaque(this->segundo);

        ataques.push_back(&puntero[1]);
    }
    else {
        puntero = new cAtaque[1];
        this->segundo = vacio;
    }
    puntero[0] = cAtaque(this->aliento);
    ataques.push_front(&puntero[0]);

}

cDragon::cDragon(cAtaque* atk)
{
    this->vivo = true;
    this->aliento = atk->getTipo();
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
    if (cantCabezas > 0) {
        do {
            this->segundo = (tipo)(-1 + (rand() % 5));
        } while (segundo == aliento);
    }
}



cDragon::cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas)
{
    this->vivo = true;
    this->aliento = atk->getTipo();
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
    if (cantCabezas > 0) {
        this->segundo = segundo;
    }
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

    struct tm date = { 0 };
    date.tm_year = a - 1900;
    date.tm_mon = m - 1;
    date.tm_mday = d;

    this->fecha = mktime(&date);
    this->domado = true;
}

//Busca en la lista de ataques el ataque a utilizar
float cDragon::atacar(int i)
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    if (this->ataques.size() < i)
        throw new exception("No se conocen tantos ataques");

    list<cAtaque*>::iterator it = this->ataques.begin();
    i--;

    for (int j = 0; j < i; j++) 
        it++;
    
    cout << nombre << " a usado " << (*it)->getNombre() << endl;

    return (*it)->probTotal(estadisticas[(*it)->getStat()]);
}


//Aprende un nuevo ataque en caso de no poseerlo
void cDragon::aprenderAtk(cAtaque* atk)
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    if (this->ataques.size() >= 4)
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
            borrador = true;
            cout << this->nombre << " ha olvidado como usar " << atk->getNombre() << endl;
            return;
        }
    }

    if (!borrador)
        throw new exception("El Dragon no conoce el ataque");
}

//Al recibir da�o, pierde vida el mismo, en caso de llegar a 0 inutiliza las funciones del dragon
void cDragon::perderVida(float dano)
{
    this->vidaActual -= dano;
    
    if (this->vidaActual <= 0) {
        cout << getNombre() << " a perecido en batalla" << endl;
        baja();
    }
    else if (dano > 0)
        cout << "Dejandolo a " << nombre << " a " << vidaActual << " puntos de vida" << endl << endl;
    else
        cout << endl;
}

void cDragon::descripcion()const
{
    cout << " " << endl;
}

void cDragon::mostrarDanos()
{

    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    list<cAtaque*>::iterator it = this->ataques.begin();

    while (it != this->ataques.end()) {
        cout << (*it)->getNombre() << ":\n";
        cout << "Dano: " << (*it)->getDano() << endl << "Probabilidad: " << (*it)->getProb() << endl;
        it++;
    }
}


void cDragon::mostrarStats()
{

    if (!this->vivo)
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");

    cout << "Fuerza: " << this->estadisticas[0] << endl;
    cout << "Destreza: " << this->estadisticas[1] << endl;
    cout << "Constitucion: " << this->estadisticas[2] << endl;
    cout << "Potencia: " << this->estadisticas[3] << endl;
}





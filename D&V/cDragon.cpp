#include "cDragon.h"

int cDragon::cantDragones = 0;

//Genera estadisticas al azar para un dragon
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
        if (this->estadisticas[i] < 6)
            this->estadisticas[i] = 8;
        this->estadisticas[i] *= 1,5;
    }
}

//Se le asigna al azar un nombre pre generado segun su tipo principal
void cDragon::altaNombre()
{
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



//Dragon completamente al azar
cDragon::cDragon() :cPersonaje("sinNombre", "sinColor", to_string(40 + rand() % 460), to_string(50 + rand() % 250), 1, 1, 1000)
{
    this->aliento = (tipo)(rand() % 4);
    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[2] * 10;
    this->vidaActual = this->vidaMax;

    string col[5] = { "Verde", "Rojo", "Azul", "Marron", "Negro" };
    this->color = col[rand() % 5];
    this->domado = false;
    this->fecha = NULL;

    this->cantJinetes = 0;
    this->cantCabezas = 1 + (1 + rand() % 12)/10;
    if (cantCabezas > 1) {
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

//Dragon creado a partir de 1 ataque
cDragon::cDragon(cAtaque* atk) :cPersonaje("sinNombre", "sinColor", to_string(40 + rand() % 460), to_string(50 + rand() % 250), 1, 1, 1)
{
    this->aliento = atk->getTipo();
    this->ataques.push_back(atk);
    string col[5] = { "Verde", "Rojo", "Azul", "Marron", "Negro" };
    this->color = col[rand() % 5];

    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[2] * 10;
    this->vidaActual = this->vidaMax;

    this->domado = false;
    this->fecha = NULL;

    this->cantJinetes = 0;
    this->cantCabezas = 1 + (1 + rand() % 12) / 10;
    if (cantCabezas > 1) {
        do {
            this->segundo = (tipo)(rand() % 4);
        } while (segundo == aliento);
        puntero = new cAtaque[1];
        puntero[0] = cAtaque(this->segundo);
        ataques.push_front(&puntero[0]);
    }
}

//Dragon creado por sus atributos
cDragon::cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas): cPersonaje("sinNombre", color, peso, tamano, 1, 1, 1)
{
    this->aliento = atk->getTipo();
    ataques.push_back(atk);

    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[2] * 10;
    this->vidaActual = this->vidaMax;

    this->fecha = NULL;
    this->domado = false;

    this->cantJinetes = 0;
    this->cantCabezas = cabezas;
    if (cantCabezas > 1) {
        this->segundo = segundo;
        puntero = new cAtaque[1];
        puntero[0] = cAtaque(this->segundo);
        ataques.push_front(&puntero[0]);
    }
}

//Dragon domado creado por sus atributos
cDragon::cDragon(cAtaque* atk, tipo segundo, string tamano, string color, string peso, int cabezas, int d, int m, int a) : cPersonaje("sinNombre", color, peso, tamano, d, m, a)
{
    this->aliento = atk->getTipo();
    this->segundo = segundo;
    ataques.push_back(atk);

    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[2] * 10;
    this->vidaActual = this->vidaMax;

    this->domado = true;

    this->cantJinetes = 1;
    this->cantCabezas = cabezas;
    if (cantCabezas > 1) {
        this->segundo = segundo;
        puntero = new cAtaque[1];
        puntero[0] = cAtaque(this->segundo);
        ataques.push_front(&puntero[0]);
    }
}

void cDragon::domar()
{
    this->domado = true;
    time(&fecha);
    this->cantJinetes = 1;
    this->identificador = sumaVuelta();
}

//Imprime por pantalla las estadisticas del dragon
void cDragon::mostrarStats()
{

    if (!this->vivo)
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");

    cout << "Fuerza: " << this->estadisticas[0] << endl;
    cout << "Destreza: " << this->estadisticas[1] << endl;
    cout << "Constitucion: " << this->estadisticas[2] << endl;
    cout << "Potencia: " << this->estadisticas[3] << endl;
}

//Aprende un nuevo ataque en caso de no poseerlo
void cDragon::operator+(cAtaque* atk)
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
        it++;
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
        it++;
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

    //ANIADIR COLOSITOS TODOS VIOLENTOS BIEN BONITOS, system("color...");
}

//Imprime por pantalla la descripcion del dragon
void cDragon::descripcion()const
{
    cout << " " << endl;
}
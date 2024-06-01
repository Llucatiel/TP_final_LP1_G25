#include "cDragon.h"

int cDragon::cantDragones = 0;

string col[5] = { "Verde", "Rojo", "Azul", "Marron", "Negro" };

string FUEGO[] = { "Fogon", "Chispas", "Fogata", "Llamaleon" };
string AIRE[] = { "Nomada", "Tornado", "Cizalla", "Piloto" };
string VENENO[] = { "Toxina", "Patogeno", "Ponzona", "Ala letal" };
string FISICO[] = { "Patada", "Fuerza bruta", "Mr. Musculo", "Pinzas" };

//Genera estadisticas al azar para un dragon
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
        if (this->estadisticas[i] < 6)
            this->estadisticas[i] = 8;
        this->estadisticas[i] *= 1,5;
    }
}

//Se le asigna al azar un nombre pre generado segun su tipo principal
void cDragon::altaNombre()
{
    int elegir = rand() % 4;
    switch (this->tipo_ataque)
    {
    case 0:
        this->nombre = FUEGO[elegir];
        break;

    case 1:
        this->nombre = AIRE[elegir];
        break;

    case 2:
        this->nombre = VENENO[elegir];
        break;

    case 3:
        this->nombre = FISICO[elegir];
        break;

    default:
        break;
    }
}

void cDragon::impresion() const
{
    if (getDomado())
        cout << "Edad: " << fecha << endl;
    cout << "Color de escamas: " << color << endl;
}

int cDragon::sumaVuelta()
{
    return ++cantDragones;
}



//Dragon completamente al azar
cDragon::cDragon() :cPersonaje("sinNombre", col[rand() % 5], to_string(40 + rand() % 460), to_string(50 + rand() % 250), 1, 1, 1000)
{
    this->tipo_ataque = (tipo)(rand() % 4);
    this->estadisticas = new int[4];
    altaNombre();
    generarStats();
    this->vidaMax = this->estadisticas[2] * 10;
    this->vidaActual = this->vidaMax;

    this->domado = false;
    this->fecha = NULL;

    this->cantJinetes = 0;
    this->cantCabezas = 1 + (1 + rand() % 12)/10;
    if (cantCabezas > 1) {
        do {
            this->secundario = (tipo)(rand() % 4);
        } while (secundario == tipo_ataque);
        ataques.push_back(new cAtaque(secundario));
    }

    ataques.push_front(new cAtaque(tipo_ataque));
}

//Dragon creado a partir de 1 ataque
cDragon::cDragon(cAtaque* atk) :cPersonaje("sinNombre", col[rand() % 5], to_string(40 + rand() % 460), to_string(50 + rand() % 250), 1, 1, 1)
{
    this->tipo_ataque = atk->getTipo();
    this->ataques.push_back(atk);

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
            this->secundario = (tipo)(rand() % 4);
        } while (secundario == tipo_ataque);
        ataques.push_front(new cAtaque(secundario));
    }
}

//Dragon creado por sus atributos
cDragon::cDragon(cAtaque* atk, tipo secundario, string tamano, string color, string peso, int cabezas): cPersonaje("sinNombre", color, peso, tamano, 1, 1, 1)
{
    this->tipo_ataque = atk->getTipo();
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
        this->secundario = secundario;
        ataques.push_front(new cAtaque(secundario));
    }
}

//Dragon domado creado por sus atributos
cDragon::cDragon(cAtaque* atk, tipo secundario, string tamano, string color, string peso, int cabezas, int d, int m, int a) : cPersonaje("sinNombre", color, peso, tamano, d, m, a)
{
    this->tipo_ataque = atk->getTipo();
    this->secundario = secundario;
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
        this->secundario = secundario;
        ataques.push_front(new cAtaque(secundario));
    }
}

cDragon::~cDragon()
{
}

float cDragon::getVidaActual() const
{
    return this->vidaActual;
}

float cDragon::getVidaTotal() const
{
    return this->vidaMax;
}

bool cDragon::getDomado() const
{
    return this->domado;
}

int cDragon::getIdentificador() const
{
    return this->identificador;
}

tipo cDragon::getAliento() const
{
    return tipo_ataque;
}

tipo cDragon::getsecundario() const
{
    return secundario;
}

void cDragon::domar()
{
    if (domado)
        throw new exception("Lamentablemente, este dragon ya esta domado");
    this->domado = true;
    time(&fecha);
    this->cantJinetes++;
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
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");

    if (this->ataques.size() >= 4)
        throw new exception("El dragon ya conoce 4 ataques");

    if (atk->getTipo() != this->tipo_ataque && atk->getTipo() != this->secundario)
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

//Al recibir daño, pierde vida el mismo, en caso de llegar a 0 inutiliza las funciones del dragon
void cDragon::perderVida(float dano)
{
    this->vidaActual -= dano;
    
    if (this->vidaActual <= 0) {
        cout << getNombre() << " a perecido en batalla" << endl;
        this->vivo = false;
    }
    else if (dano > 0)
        cout << "Dejandolo a " << nombre << " a " << vidaActual << " puntos de vida" << endl << endl;
    else
        cout << endl;

    //ANIADIR COLOSITOS TODOS VIOLENTOS BIEN BONITOS, system("color...");
}

void cDragon::curarse()
{
    this->vidaActual = this->vidaMax;
}

//Imprime por pantalla la descripcion del dragon
void cDragon::descripcion()const
{
    cout << "el es el poderoso "<<nombre<<", un magnifico dragon de "<<peso<<" kg y de escamas "<<color<<" que lleva "<<" 3 " << "volando por estas tierras." << endl;
    cout << "tiene un temible tipo_ataque de " << tipo_ataque << endl;
}
#include "cPersonaje.h"

//Generacion al azar de las estadisticas de cada clase
void cPersonaje::generarStats()
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

cPersonaje::cPersonaje(string nombre, string color, string peso, string tamano, int d, int m, int a)
{
    ataques.clear();
    this->nombre = nombre;
    this->color = color;
    this->peso = peso;
    this->tamano = tamano;
    this->vivo = true;

    if (d == 0) 
        this->fecha = NULL;
    else{
        struct tm date = { 0 };
        date.tm_year = a - 1900;
        date.tm_mon = m - 1;
        date.tm_mday = d;
        this->fecha = mktime(&date);
        this->edad = getAnios();
    }
}

//Imprime por pantalla las estadisticas
void cPersonaje::mostrarStats()
{
    if (!this->vivo)
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");

    cout << "Fuerza: " << this->estadisticas[0] << endl;
    cout << "Destreza: " << this->estadisticas[1] << endl;
    cout << "Constitucion: " << this->estadisticas[2] << endl;
}

//Imprime por pantalla los ataques conocidos
void cPersonaje::mostrarAtaques()
{

    if (!this->vivo)
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");


    if (this->ataques.size() < 1) {
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


string cPersonaje::To_string()
{
     stringstream ss;

    ss << "Nombre: " << nombre << endl;
    ss << "Color de pelo: " << color << endl;
    ss << "Peso: " << peso << endl;
    ss << "Tamano: " << tamano << endl;
    ss << "Edad: " << getAnios() << endl;

    return ss.str();
}

//Calcula la fecha creada en años, o dias en caso a ser menor de 1 año
int cPersonaje::getAnios()
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    time_t now;
    time(&now); //Tiempo actual
    int edad = difftime(now, this->fecha) / 86400;
    //Calcula la diferencia entre ahora y fecha 
    if (edad < 365)
        return edad;
    return edad / 365;
    //La divide por la cantidad de dias en un anio
}

void cPersonaje::imprimirDatos()
{
    cout << *this << endl;
}

float cPersonaje::atacar(int i)
{

    if (!this->vivo)
        throw new exception("Ya no se encunetra con nosotros");

    if (this->ataques.size() < i)
        throw new exception("No se conocen tantos ataques");

    list<cAtaque*>::iterator it = this->ataques.begin();
    i--;

    for (int j = 0; j < i; j++)
        it++;

    cout << nombre << " a usado " << (*it)->getNombre() << endl;

    return (*it)->probTotal(this->getStat((*it)->getStat())+buff);
}

int cPersonaje::getCantAtk()
{
    return (int)this->ataques.size();
}

float cPersonaje::getStat(int i)
{
    return this->estadisticas[i];
}

bool cPersonaje::getBorrado() const
{
    return borrado;
}

bool cPersonaje::getVivo() const
{
    return this->vivo;
}

string cPersonaje::getNombre() const
{
    return this->nombre;
}

string cPersonaje::getTamano() const
{
    return this->tamano;
}
string cPersonaje::getPeso() const
{
    return this->peso;
}
string cPersonaje::getColor() const {
    return this->color;
}

cAtaque* cPersonaje::getAtk(int i)
{

    if (!this->vivo)
        throw new exception("Lamentablemente, ya no se encuentra vivo/a.");


    if (this->ataques.size() < 1) 
        throw new exception("No se conoce ningun ataque. ");
    

    list<cAtaque*>::iterator it = this->ataques.begin();

    for (int j = 0; j < i && it != this->ataques.end(); j++) {
        it++;
    }

    return (*it);
}

void cPersonaje::mostrarDanos()
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

//Aprende un nuevo ataque
void cPersonaje::operator+(cAtaque* atk)
{
        if (!this->vivo)
            throw new exception("Lo lamento, pero ya no es utilizable");

        if (this->ataques.size() >= 4)
            throw new exception("Ya se conocen 4 ataques");

        if (atk->getTipo() != fisico)
            throw new exception("No es capaz de aprender a usar el ataque");

        list<cAtaque*>::iterator it = this->ataques.begin();

        while (it != this->ataques.end()) {
            if ((*it)->getNombre() == atk->getNombre()) {
                throw new exception("Ya se conocia el ataque.");
            }
            it++;
        }

        this->ataques.push_back(atk);
}

//Olvida un ataque ya aprendido
void cPersonaje::operator-(cAtaque* atk)
{

    if (!this->vivo)
        throw new exception("Lo lamentamos, ya no puede ser utilizado");

    list<cAtaque*>::iterator it = this->ataques.begin();
    bool borrador = false;

    while (it != this->ataques.end()) {
        if ((*it)->getNombre() == atk->getNombre()) {
            delete (*it);
            this->ataques.erase(it);
            return;
        }
        it++;
    }

    if (!borrador)
        throw new exception("Ataque no conocido");
}

void cPersonaje::convertido()
{
    this->borrado = true;
}

time_t cPersonaje::getTimer()
{
    return fecha;
}

//Libera memoria
cPersonaje::~cPersonaje()
{   
    baja();
    if(estadisticas != nullptr)
    delete[]estadisticas;
}

ostream& operator<<(ostream& os, const cPersonaje& cPe)
{
    os << "El es el poderoso " << cPe.nombre;
    cPe.impresion();
    return os;
}

void cPersonaje::baja() {
    this->vivo = false;
    if (!borrado) {
        list<cAtaque*>::iterator it = ataques.begin();

        if (!ataques.empty()) {
            while (it != ataques.end()) {
                if (*it != nullptr)
                    delete (*it);
                *it = nullptr;
                it++;
            }
        }
    }
    ataques.clear();
}

list<cAtaque*> cPersonaje::getListAtaques() const{
    return this->ataques;
}
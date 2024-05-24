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

cPersonaje::cPersonaje(string nombre, string color, string peso, string tamano)
{
    this->nombre = nombre;
    this->color = color;
    this->peso = peso;
    this->tamano = tamano;
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

//Calcula la fecha creada en años, o dias en caso a ser menor de 1 año
int cPersonaje::getAnios()
{
    if (!this->vivo)
        throw new exception("El dragon ya no puede ser utilizado");

    time_t now;
    time(&now); //Tiempo actual
    int edad = (int)difftime(now, this->fecha) / 86400;
    //Calcula la diferencia entre ahora y fecha 
    if (edad < 365)
        return edad;
    return edad / 365;
    //La divide por la cantidad de dias en un anio
}

string cPersonaje::To_string()
{
    stringstream ss;

    ss << "nombre: " << nombre << endl;
    ss << "color de pelo: " << color << endl;
    ss << "peso: " << peso << endl;
    ss << "tamaño: " << tamano << endl;
    ss << "nacimiento: " << fecha << endl;

    return ss.str();
}

void cPersonaje::imprimirDatos()
{
    string info = To_string();
    cout << info;
}

float cPersonaje::atacar(int i)
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

    return (*it)->probTotal((*it)->getStat());
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
            this->ataques.erase(it);
            borrador = true;
            cout << this->nombre << " ha olvidado como usar " << atk->getNombre() << endl;
            return;
        }
        it++;
    }

    if (!borrador)
        throw new exception("Ataque no conocido");
}

//Libera memoria
cPersonaje::~cPersonaje()
{   
    this->ataques.clear();
    delete[]estadisticas;
    delete []puntero;
}


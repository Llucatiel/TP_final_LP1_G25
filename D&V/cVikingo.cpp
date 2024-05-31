#include "cVikingo.h"

//Inicializa sus atributos estaticos
int cVikingo::comida = 30;
int cVikingo::cantVikingos = 0;

void cVikingo::impresion() const
{
    cout << "Apellido: " << apellido << endl;
    cout << "Trabajo: " << trabajo << endl;
    cout << "Edad: " << fecha << endl;
    cout << "Color de pelo: " << color << endl;
}

//Creacion por parametro de un vikingo
cVikingo::cVikingo(string nombre, string color, string apellido, int d, int m, int a, string altura, string peso, string trabajo, int dragones_terminados)
 : cPersonaje(nombre, color, peso, altura, d, m, a) 
{

    this->estadisticas = new int[3];
    this->apellido = apellido;
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

bool cVikingo::dragonesMatados()
{
    return dragones_terminados > 0 ? true : false;
}

bool cVikingo::domar(cDragon* dragon)
{
    if (dragon->getVidaActual() > dragon->getVidaTotal() * 0.75)
        throw new exception("El dragon a domar no se encuentra lo suficientemente bajo de vida.");

    time_t now;
    time_t diff;
    int dice = 0;
    string escrito;
    float complejo = dragon->getVidaActual();
    float fuerza = getStat(0) > getStat(1) ? getStat(0) : getStat(1); //Decide si el vikingo es mejor con su fuerza o su destreza

    cout << "DEBES DE MANTENER AL DRAGON ATADO, ESCRIBE EN PANTALLA LAS PALABRAS QUE MANDAREMOS A CONTINUACION: " << endl;
    cout << "Cuidado!! Todas las palabras estaran en mayusculas." << endl;
    system("pause");

    while (complejo > 0 && complejo < dragon->getVidaTotal() * 0.65) {
        dice = rand() % 5;
        switch (dice) {
        case 0:
            cout << "APRETAR" << endl;
            time(&now);
            while (escrito != "APRETAR")
                cin >> escrito;
            break;
        case 1:
            cout << "TIRONEAR" << endl;
            time(&now);
            while (escrito != "TIRONEAR")
                cin >> escrito;
            break;
        case 2:
            cout << "GOLPEAR" << endl;
            time(&now);
            while (escrito != "GOLPEAR")
                cin >> escrito;
            break;
        case 3:
            cout << "PATEAR" << endl;
            time(&now);
            while (escrito != "PATEAR")
                cin >> escrito;
            break;
        default:
            continue;
        }
        time(&diff);
        float hecho = fuerza - difftime(now, diff) * 4;
        if (hecho < 0)
            cout << "El dragon se esta liberando! MAS RAPIDO Y CON MAS FUERZA" << endl;
        else
            cout << "BIEN HECHO, SIGUE ASI, CON VELOCIDAD." << endl;
        complejo -= hecho;
        Sleep(500 + rand() % 1000);
        system("cls");
    }
    if (complejo <= 0) {
        cout << dragon->getNombre() << " ha sido domado con exito. Felicidades!" << endl;
        return true;
    }
    else
        cout << dragon->getNombre() << " ha logrado escapar, que lastima." << endl;
    return false;

}

string cVikingo::getApellido() const
{
    return apellido;
}

string cVikingo::getTrabajo()
{
    return trabajo;
}

int cVikingo::getDragonesTerminados() const
{
    return this->dragones_terminados;
}

void cVikingo::setTrabajo(string nuevo)
{
    this->trabajo = nuevo;
}

void cVikingo::setDragonesTerminados(int suma)
{
    this->dragones_terminados += suma;
}

//Libera memoria
cVikingo:: ~cVikingo() {
    cantVikingos--;
}

int cVikingo::getComida()
{
    return comida;
}

int cVikingo::getCantVikingos()
{
    return cantVikingos;
}

void cVikingo::cambioComida(int suma)
{
    comida += suma;
}

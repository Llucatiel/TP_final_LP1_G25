#include "cVikingo.h"

string TRABAJOS[] = { "herrero", "carpintero","cantinero", "pastor"};
//Inicializa sus atributos estaticos
int cVikingo::cantVikingos = 0;

void cVikingo::impresion() const
{
    cout << " " << apellido << " nuestro gran vikingo y " << TRABAJOS[trabajo] << " que lleva rondando por estas tierras desde hace " << edad << " primaveras." << endl;
    cout << "su brillante cabellera " << color << " resplandece ante el atardecer de este peso pesado de " << peso << " kg ademas de su estatura de " << tamano << " metros" << endl;
    if (dragones_terminados>0)
        cout << "lleva " << dragones_terminados << " cadaveres de dragones en su espalda" << endl;
}

//Creacion por parametro de un vikingo
cVikingo::cVikingo(string nombre, string color, string apellido, int d, int m, int a, string altura, string peso, trabajos trabajo, int dragones_terminados)
 : cPersonaje(nombre, color, peso, altura, d, m, a) 
{

    this->estadisticas = new int[3];
    this->apellido = apellido;
    this->peso = peso;
    this->trabajo = trabajo;
    this->dragones_terminados = dragones_terminados;
    ataques.push_back(new cAtaque(fisico));
    generarStats();
    cantVikingos++;
}

int cVikingo::trabajar()
{
    int premio = -5 + rand() % +10;

    switch (trabajo) {
    case 0:
        if (premio > 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "Creaste una increible espada y la vendiste a un muy buen precio, con ese dinero optuviste " << premio << " de comida" << endl;
                return premio;
            case 1:
                cout << " Tu arsenal entero se vendio, y con todo ese dinero obtuviste " << premio * 2 << " de comida" << endl;
                return premio * 2;
            }
        }
        else if (premio < 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "Se te rompio una espada y tuviste que usar dinero extra para repararla, se consume " << -premio << " de comida" << endl;
                return premio;
            case 1:
                cout << "Tu arsenal entero se cayo y rompio, tanto esfuerzo en reparar todo consumio " << -premio * 2 << " de comida" << endl;
                return premio * 2;
            }
        }
    case 1:
        if (premio > 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "Reparaste esa mesa que te pidieron y te pagaron muy bien, con eso puedes comprar " << premio << " de comida" << endl;
                return premio;
            case 1:
                cout << "Reparaste toda la casa, muy buen trabajo, te pagan " << premio * 2 << " de comida" << endl;
                return premio * 2;
            }
        }
        else if (premio < 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "Se te rompio tu martillo y tuviste que usar dinero extra para repararla, se consume " << -premio << " de comida" << endl;
                return premio;
            case 1:
                cout << "Se te rompio la casa que segun la dejaste en perfectas condiciones, te demandan y te quitan " << -premio * 2 << " de comida " << endl;
                return premio * 2;
            }
        }
        break;
    case 2:
        if (premio > 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "El tomador del pueblo te compro su botella energizante usual, te paga con " << premio << " de comida" << endl;
                return premio;
            case 1:
                cout << "El tomador del pueblo trajo a sus amigos de otras tierras, te pagan una gran ronda de bebidas con " << premio * 2 << " de comida" << endl;
                return premio * 2;
            }
        }
        else if (premio < 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "Sin que te des cuenta, el tomador se lleva una botella sin pagar y tuviste que reponerla, eso te consumio " << -premio << " de comida" << endl;
                return premio;
            case 1:
                cout << "Hubo una pelea en el bar por culpa del tomador del pueblo, tuviste que reponer todos los daños y eso te costo " << -premio * 2 << " de comida" << endl;
                return premio * 2;
            }
        }
        break;
    case 3:
        if (premio > 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "Te compran una oveja a un muy buen precio, te pagan con " << premio << " de comida" << endl;
                return premio;
            case 1:
                cout << "Te compran todo un rebaño, te pagan muy bien con " << premio * 2 << " de comida" << endl;
                return premio * 2;
            }
        }
        else if (premio < 0) {
            int i = rand() % +2;
            switch (i) {
            case 0:
                cout << "Se te enferma una oveja y tienes que pagarle al medico del pueblo para que sane, esto te costara " << -premio << " de comida" << endl;
                return premio;
            case 1:
                cout << "Un dragon salvaje arrazo con tu rebaño, reponer todo te costara " << -premio * 2 << " de comida" << endl;
                return premio * 2;
            }
        }
        break;
    }
        cout << "Jornada laboral comun, no obtuviste ganancia";
        return 0;
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
    return TRABAJOS[trabajo];
}

int cVikingo::getDragonesTerminados() const
{
    return this->dragones_terminados;
}

void cVikingo::setTrabajo(trabajos nuevo)
{
    this->trabajo = nuevo;
}

void cVikingo::setDragonesTerminados(int suma)
{
    this->dragones_terminados += suma;
}

cVikingo:: ~cVikingo() {
    cantVikingos--;
    if(this )
}


int cVikingo::getCantVikingos()
{
    return cantVikingos;
}

#include "cBocon.h"

cBocon::cBocon()
{
    vikingos.clear();
    jinetes.clear();
    dragones.clear();
    valhalla.clear();
    dragonesNoDomados.clear();

    for (int i = 0; i < 8; i++) 
        dragonesNoDomados.push_back(new cDragon());
}

cBocon::~cBocon()
{
    if (!vikingos.empty()) {
        list<cVikingo*>::iterator v = vikingos.begin();
        while (v != vikingos.end()) {
            delete (*v);
            v++;
        }
    }
    if (!jinetes.empty()) {
        list<cJinete*>::iterator j = jinetes.begin();
        while (j != jinetes.end()) {
            delete (*j);
            j++;
        }
    }
    if (!dragones.empty()) {
        list<cDragon*>::iterator d = dragones.begin();
        while (d != dragones.end()) {
            delete (*d);
            d++;
        }
    }
    if (!dragonesNoDomados.empty()) {
        list<cDragon*>::iterator d = dragonesNoDomados.begin();
        while (d != dragonesNoDomados.end()) {
            delete (*d);
            d++;
        }
    }
    if (!valhalla.empty()) {
        list<cPersonaje*>::iterator p = valhalla.begin();
        while (p != valhalla.end()) {
            delete (*p);
            p++;
        }
    }
    jinetes.clear();
    vikingos.clear();
    dragones.clear();
    dragonesNoDomados.clear();
    valhalla.clear();
}

void cBocon::operator+(cDragon* dragon)
{
    dragones.push_back(dragon);
}

void cBocon::operator+(cVikingo* vik)
{
    vikingos.push_back(vik);
}

void cBocon::operator+(cJinete* jin)
{
    jinetes.push_back(jin);
}

void cBocon::encuentrePaz(cDragon* perdida)
{
    list<cDragon*>::iterator it;
    for (it = dragones.begin(); it != dragones.end(); it++) {
        if ((*it)->getIdentificador() == perdida->getIdentificador()) {
            dragones.erase(it);
            break;
        }
    }

    perdida->baja();
    valhalla.push_back(perdida);
}

void cBocon::encuentrePaz(cVikingo* perdida)
{
    list<cVikingo*>::iterator it;
    for (it = vikingos.begin(); it != vikingos.end(); it++) {
        if ((*it)->getNombre() == perdida->getNombre()) {
            vikingos.erase(it);
            break;
        }
    }
    valhalla.push_back(perdida);
}

void cBocon::encuentrePaz(cJinete* perdida)
{
    list<cJinete*>::iterator it;
    for (it = jinetes.begin(); it != jinetes.end(); it++) {
        if ((*it)->getNombre() == perdida->getNombre()) {
            jinetes.erase(it);
            break;
        }
    }
    valhalla.push_back(perdida);
}

//Muestra la lista de vikingos
void cBocon::enlistarVikingo()
{
    list<cVikingo*>::iterator it = vikingos.begin();

    int i = 0;
    while (it != vikingos.end()) {
        cout << i << ". " << (*it)->getNombre() << endl;
        i++;
        it++;
    }
}

//Muestra la lista de Dragones
void cBocon::enlistarDragon()
{
    list<cDragon*>::iterator it = dragones.begin();

    int i = 0;
    while (it != dragones.end()) {
        cout << i << ". " << (*it)->getNombre() << endl;
        i++;
        it++;
    }
}

void cBocon::conversion(cDragon* dragon, list<cVikingo*> vikingo)
{
    list<cVikingo*>::iterator it = vikingo.begin();
    list<cVikingo*>::iterator its = vikingos.begin();
    int cant = vikingo.size();
    for (int i = 0; i < cant; i++) {
        (*this) + (new cJinete(*(*it), dragon));
        while (its != vikingos.end()) {
            if ((*its)->getNombre() == (*it)->getNombre()) {
                vikingos.erase(its);
                break;
            }
            its++;
        }
        it++;
    }
}

//Busca en la lista de vikingos a aquellos elegidos para usarlos al llamar atacarDragones
void cBocon::elegirVikingo(int* elegidos, int n)
{
    list<cVikingo*>::iterator it = vikingos.begin();
    list<cVikingo*> v;
    bool c = false;
    int j = 0;
    while (it != vikingos.end()) {
        for (int i = 0; i < n; i++) {
            if (j == elegidos[i]) {
                v.push_back((*it));
                c = true;
            }
        }
        j++;
        it++;
    }
    if (!c)
        return;

    atacarDragones(v);

}

//Busca en la lista de dragones que tiene (En el futuro deberia de ser de jinetes) y al final llama a pelear
void cBocon::elegirDragon(int elegido)
{

    list<cDragon*>::iterator it = dragones.begin();
    bool encontrado = false;
    int j = 0;
    while (it != dragones.end()) {
        if (j == elegido) {
            encontrado = true;
            break;
        }
        j++;
        it++;
    }
    if (!encontrado)
        return;

    list<cJinete*>::iterator ij = jinetes.begin();
    list<cJinete*> jin;
    while (ij != jinetes.end()) {
        if ((*ij)->getDragon()->getIdentificador() == (*it)->getIdentificador())
            jin.push_back((*ij));
        ij++;
    }

    pelea(jin);
}

//Pelea entre los vikingos y los dragones
void cBocon:: atacarDragones(list<cVikingo*> vikingos)//en el main especificamos que no se puede enviar mas de 6
{
    int cantidadeVikingos = vikingos.size();

    if (cVikingo::getCantVikingos() < cantidadeVikingos || cantidadeVikingos > 6)
        return; // Exception??
    unsigned int dado;

    cVikingo::cambioComida(-cantidadeVikingos);

    cout << "los vikingos que enviaras consumiran: " << cantidadeVikingos << " de comida." << endl;

    dado = cantidadeVikingos + rand() % (12 - cantidadeVikingos);

    int premio = 0;

    cout << "tu dado saco " << dado << endl;

    if (dado < 3) {
        cout << "encruzijada fallida" << endl;
    }
    else if (dado < 6) {
        premio = cantidadeVikingos * 0.5;
        cout << "exito de la encruzijada de un 50%, obtienes comida: " << cantidadeVikingos * 0.5 << endl;
    }
    else if (dado < 9) {
        premio = cantidadeVikingos;
        cout << "exito de la encruzijada de un 100%, obtienes comida: " << cantidadeVikingos << endl;
    }
    else {
        premio = cantidadeVikingos * 2;
        cout << "exito de la encruzijada de un 200%, obtienes comida: " << cantidadeVikingos * 2 << endl;
    }

    if (dado > 2) {
        list<cVikingo*>::iterator it = vikingos.begin();

        while (it != vikingos.end()) {
            (*it)->setDragonesTerminados(1);
            it++;
        }
    }

    cVikingo::cambioComida(premio);
}

//Pelea pokemon de dragones
void cBocon::pelea(list<cJinete*> jin)
{
    int lim = 1 + rand() % 4;
    cDragon* enemigo = new cDragon(new cAtaque());
    //Crea a un ataque y dragon genericos para combatir
    list<cJinete*>::iterator it = jin.begin();
    cDragon* dragon = (*it)->getDragon();

    for (int i = enemigo->getCantAtk(); i < lim; i++) {
        try {
            cAtaque* atk = new cAtaque(enemigo->getAliento());
            (*enemigo) + atk;
        }
        catch (const exception* e) {
            i--;
            delete e;
        }
    }

    float life = 0;
    life = (*it)->getStat(2) * 5;
    if (jin.size() == 2) {
        it++;
        life += (*it)->getStat(2) * 5;
        it = jin.begin();
    }
    float max = life;

    bool ambos = true;
    bool perdida = false;
    lim = enemigo->getCantAtk();
    system("cls");

    cout << dragon->getNombre() << " se enfrenta a " << enemigo->getNombre() << endl << "PREPARENCE PARA LA BATALLA!" << endl << endl;

    while (ambos) { //El combate seguira hasta que uno de los dos caiga
        bool atacado = false;
        do {
            cout << enemigo->getNombre() << ": " << enemigo->getVidaActual() << " / " << enemigo->getVidaTotal() << " hp" << endl;
            cout << "\t\t\t\t\t";
            if (dragon->getVivo()) {
                cout << dragon->getNombre() << ": " << dragon->getVidaActual() << " / " << dragon->getVidaTotal() << " hp" << endl;

                cout << "Elija el ataque a usar: " << endl;
                dragon->mostrarAtaques();
                cout << "5. mostrar danos" << endl;

                int i;
                cin >> i;

                try {
                    if (i == 5) {
                        dragon->mostrarDanos();
                        system("pause");
                        system("cls");
                        continue;
                    }
                    enemigo->perderVida(dragon->atacar(i)); //Perder vida llama dentro de si a atacar, calcula si pego o no, y cuanto danio hizo
                    atacado = true;
                }
                catch (const exception* e) {
                    cout << e->what() << endl;
                    delete e;
                    atacado = false;
                    system("puase");
                    system("cls");
                }
            }
            else {
                cout << "Jinetes: " << life << " / " << max << " hp" << endl;
                while (it != jin.end()) {
                    cout << "Elija el ataque a usar: " << endl;
                    (*it)->mostrarAtaques();
                    cout << "5. mostrar danos" << endl;

                    int i;
                    cin >> i;

                    float dano = 0;
                    try {
                        if (i == 5) {
                            (*it)->mostrarDanos();
                            system("pause");
                            system("cls");
                            continue;
                        }
                        enemigo->perderVida((*it)->atacar(i)); //Perder vida llama dentro de si a atacar, calcula si pego o no, y cuanto danio hizo
                        atacado = true;
                    }
                    catch (const exception* e) {
                        cout << e->what() << endl;
                        delete e;
                        atacado = false;
                        system("puase");
                        system("cls");
                    }
                    it++;
                }
                it = jin.begin();
            }

        } while (!atacado);

        //Espera 1.5 segundos y sigue con el programa
        Sleep(1500);
        system("cls");
        ambos = enemigo->getVivo();
        if (!ambos)
            break;

        cout << enemigo->getNombre() << ": " << enemigo->getVidaActual() << " / " << enemigo->getVidaTotal() << " hp" << endl;
        cout << "\t\t\t\t\t";
        if (dragon->getVivo()) {
            cout << dragon->getNombre() << ": " << dragon->getVidaActual() << " / " << dragon->getVidaTotal() << " hp" << endl;
            try {
                dragon->perderVida(enemigo->atacar(rand() % lim));
            }
            catch (const exception* e) {
                cout << e->what() << endl;
                delete e;
            }
            if (!dragon->getVivo()) {
                Sleep(3000);
                cout << dragon->getNombre() << " ha perecido en batalla, pero aun no es el fin!" << endl;
            }
            Sleep(1000);
            system("CLS");
        }
        else {
            cout << "Jinetes: " << life << " / " << max << " hp" << endl;
            try {
                life -= enemigo->atacar(rand() % lim);
            }
            catch (const exception* e) {
                cout << e->what() << endl;
                delete e;
            }
            if (life <= 0) {
                ambos = false;
                perdida = true;
            }
            Sleep(1000);
            system("CLS");
        }
    }
    if (!dragon->getVivo()) {
        cout << "Lamentamos fuertemente la perdida de " << dragon->getNombre() << endl << "peleo bien." << endl;
        encuentrePaz(dragon);
        if (!perdida) {
            cout << "Nuestros fuertes jinetes volveran a casa, con pena y tristeza, pero victorios." << endl;
            for (list<cJinete*>::iterator it = jin.begin(); it != jin.end(); it++)
                encuentrePaz((*it));
        }
        else
            cout << "Que el Valhalla les guarde un lugar a nuestros grandes guerreros." << endl;
    }
    else {
        string mayus = dragon->getNombre();
        transform(mayus.begin(), mayus.end(), mayus.begin(), ::toupper); //Recorre el string completo, haciendo mayuscula todos sus caracteres
        cout << "INCREIBLE BATALLA DADA POR " << mayus << "!!!" << endl << "Hoy vuelve victorioso a casa." << endl;
    }
    delete enemigo;
}

void encuentrePaz(cDragon* perdida)
{
}

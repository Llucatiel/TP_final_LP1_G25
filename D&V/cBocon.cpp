#include "cBocon.h"

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
    int at = 1 + rand() % 4;
    cAtaque* atk = new cAtaque[at];
    atk[0] = cAtaque();
    cDragon* enemigo = new cDragon(&atk[0]);
    //Crea a un ataque y dragon genericos para combatir
    list<cJinete*>::iterator it = jin.begin();
    cDragon* dragon = (*it)->getDragon();

    for (int i = enemigo->getCantAtk(); i < at; i++) {
        try {
            atk[i] = cAtaque(enemigo->getAliento());
            (*enemigo) + (&atk[i]);
        }
        catch (const exception* e) {
            i--;
            delete e;
        }
    }

    bool ambos = true;
    int lim = enemigo->getCantAtk();
    system("cls");

    cout << dragon->getNombre() << " se enfrenta a " << enemigo->getNombre() << endl << "PREPARENCE PARA LA BATALLA!" << endl << endl;

    while (ambos){ //El combate seguira hasta que uno de los dos caiga
        bool atacado = false;
        do {
            cout << enemigo->getNombre() << ": " << enemigo->getVidaActual() << " / " << enemigo->getVidaTotal() << " hp" << endl;
            cout << "\t\t\t\t\t";
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
        } while (!atacado);

        //Espera 3 segundos y sigue con el programa
        Sleep(1500);
        system("cls");
        ambos = enemigo->getVivo();
        if (!ambos)
            break;

        cout << enemigo->getNombre() << ": " << enemigo->getVidaActual() << " / " << enemigo->getVidaTotal() << " hp" << endl;
        cout << "\t\t\t\t\t";
        cout << dragon->getNombre() << ": " << dragon->getVidaActual() << " / " << dragon->getVidaTotal() << " hp" << endl;
        try {
            dragon->perderVida(enemigo->atacar(rand() % lim));
        }
        catch (const exception* e) {
            cout << e->what() << endl;
            delete e;
        }
        ambos = dragon->getVivo();

        Sleep(1800);
        system("CLS");
    }

    if (!dragon->getVivo())
        cout << "Lamentamos fuertemente la perdida de " << dragon->getNombre() << endl << "peleo bien." << endl;
    else {
        string mayus = dragon->getNombre();
        transform(mayus.begin(), mayus.end(), mayus.begin(), ::toupper); //Recorre el string completo, haciendo mayuscula todos sus caracteres
        cout << "INCREIBLE BATALLA DADA POR " << mayus << "!!!" << endl << "Hoy vuelve victorioso a casa." << endl;
    }
       
    
    delete enemigo;
    delete []atk;
}



#include "cBocon.h"

cBocon::cBocon()
{
}


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


void cBocon::elegir(int* elegidos, int n)
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

void cBocon::pelea(cDragon* dragon)
{
    cAtaque* atk = new cAtaque(fisico);
    cDragon* enemigo = new cDragon(atk);
    bool ambos = true;
    int lim = enemigo->getCantAtk();

    while (ambos){
        cout << "Elija el ataque a usar: " << endl;
        dragon->mostrarAtaques();

        bool atacado;
        do {
            try {
                int i;
                cin >> i;
                enemigo->perderVida(dragon->atacar(i));
                atacado = true;
           }
            catch (const exception* e) {
                cout << e->what() << endl;
                delete e;
                atacado = false;
            }
        } while (!atacado);

        ambos = enemigo->getVivo();
        if (!ambos)
            break;
        try {
            dragon->perderVida(enemigo->atacar(rand() % lim));
        }
        catch (const exception* e) {
            cout << e->what() << endl;
            delete e;
        }
        ambos = dragon->getVivo();

        char a;
        cin >> a;
        system("CLS");
    }

    if (!dragon->getVivo())
        cout << "Lamentamos fuertemente la perdida de " << dragon->getNombre() << endl << "peleo bien." << endl;
    else
        cout << "INCREIBLE LA BATALLA DADA POR " << dragon->getNombre() << endl << "Hoy vuelve victorioso a casa." << endl;
    
    delete enemigo;
    delete atk;
}



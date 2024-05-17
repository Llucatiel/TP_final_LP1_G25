#include <iostream>
#include "cDragon.h"
#include "cVikingo.h"

using namespace std;

void atacarDragones(list<cVikingo*> vikingos)//en el main especificamos que no se puede enviar mas de 6
{
    int cantidadeVikingos = vikingos.size();
    cout<< cantidadeVikingos;
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

int main()
{
    srand(time(0));

    cAtaque* bola = new cAtaque("Bola de fuego", fuego, 0, 25, 40);
    cDragon* draco = new cDragon(bola, vacio, "100", "Rojo", "100 kg", 1);


    cout << draco->getNombre() << endl;
    draco->mostrarStats();

    cVikingo* hipo = new cVikingo("hipo", "campo", 02, 12, 2003, "1.70", "55", "inutil", 0);

    list<cVikingo*> vikingos;
    vikingos.push_back(hipo);

    atacarDragones(vikingos);

    cout << cVikingo::getComida();

    hipo->mostrarStats();
    vikingos.clear();

    delete hipo;
    delete draco;
    /*
    cAtaque *bola = new cAtaque("Bola de fuego", fuego, 0, 25, 40);
    cDragon* draco = new cDragon(bola, vacio, "100", "Rojo", "100 kg", 1);
    cout << draco->getNombre() << endl;

    cDragon* draco2 = new cDragon(bola, vacio, "100", "Rojo", "100 kg", 1);

    draco->mostrarStats();
    cout << endl << draco2->getNombre() << endl;
    draco2->mostrarStats();
    cout << draco2->getVida() << endl;

    try {
        draco->aprenderAtk(bola);
        draco2->aprenderAtk(bola);
    }
    catch(const exception *e){
        cout << e->what() << endl;
        delete e;
    }
    try {
        float hp1 = draco->atacar(1);
        draco2->perderVida(hp1);

        cout << draco2->getVida();


    }
    catch (const exception* e) {
        cout << e->what() << endl;
        delete e;
    }



    delete bola;
    delete draco;
    */

    /*
     cAtaque* bola = new cAtaque("Bola de fuego", fuego, 0, 25, 40);
     cDragon* draco = new cDragon(bola, vacio, "100", "Rojo", "100 kg", 1, 02, 12, 2003);

     cout << draco->getTiempoAdoptado() << endl;
     try {
         draco->mostrarAtaques();
         draco->olvidarAtk(bola);
         draco->mostrarAtaques();
     }
     catch (const exception* e) {
         cout << e->what() << endl;
         delete e;
     }

     delete draco;
     delete bola;
     */
    return 0;
}

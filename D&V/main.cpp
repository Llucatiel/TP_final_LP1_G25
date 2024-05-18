#include <iostream>
#include "cBocon.h"

using namespace std;


int main()
{
    srand(time(0));

    cDragon* draco = new cDragon();
    cBocon* bocon = new cBocon();

    bocon->agregarDragon(draco);

    bocon->enlistarDragon();

    /*
    int cant;
    cout << "Cantidad de vikingos a enviar: "; cin >> cant;
    int* vikingosElegidos = new int[cant];
    cout << "Elija los vikingos a enviar: " << endl;
    for (int i = 0; i < cant; i++)
        cin >> vikingosElegidos[i];
        bocon->elegirVikingo(vikingosElegidos, cant);
        delete []elegidos;
        */

    int dragonElegido;
    cout << "Elija el dragon a enviar: " << endl;
        cin >> dragonElegido;
    bocon->elegirDragon(dragonElegido);

    delete bocon;
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

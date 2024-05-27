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

    int dragonElegido;
    cout << "Elija el dragon a enviar: " << endl;
        cin >> dragonElegido;
    bocon->elegirDragon(dragonElegido);

    delete bocon;
    delete draco;

    return 0;
}

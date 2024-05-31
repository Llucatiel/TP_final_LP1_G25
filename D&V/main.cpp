#include <iostream>
#include "cBocon.h"

using namespace std;

int main() 
{
    srand(time(0));

    cDragon* draco = new cDragon();
    cDragon* ocard = new cDragon();
    cBocon* bocon = new cBocon();
    cVikingo* bodoque = new cVikingo("Juan Carlos", "Rojo", "Bodoque", 2, 12, 2003, "0.50", "3", "Notero", 0);

    bodoque->descripcion();

    (*bocon)+(draco);
    (*bocon) + (ocard);
    (*bocon) + (bodoque);
    list<cVikingo*> lv;
    lv.push_back(bodoque);
    bocon->conversion(draco, lv);

    /*
    int dragonElegido;
    cout << "Elija el dragon a enviar: " << endl;
        cin >> dragonElegido;
    bocon->elegirDragon(dragonElegido);
    */
    delete bocon;
    return 0;
}

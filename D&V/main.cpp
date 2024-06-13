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
    cVikingo* mario = new cVikingo("Mario", "Gris", "Hugo", 2, 12, 2003, "0.50", "3", "Notero", 0);
    cVikingo* hipo = new cVikingo("Hipo", "Negro", "Hipo", 3, 9, 1999, "1.80", "75", "Herrero", 3);

    (*bocon)+(draco);
    (*bocon) + (bodoque);
    (*bocon) + (mario);
    (*bocon) + (hipo);
    (*bocon) + (ocard);
    
    list<cVikingo*> lv;
    lv.push_back(bodoque);

    bocon->conversion(draco, lv);
    lv.pop_back();

    lv.push_back(mario);
    bocon->conversion(ocard, lv);
    lv.clear();

    bocon->enlistarDragon();
    cout << "Elija el dragon a enviar: " << endl;
    Sleep(5000);
    bocon->elegirDragon(rand() % bocon->getCantDrag());
    cout << cBocon::getComida() << endl;
    delete bocon;
    return 0;
}

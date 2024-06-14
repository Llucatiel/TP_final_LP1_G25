#include <iostream>
#include "cBocon.h"

using namespace std;

int main() 
{
    srand(time(0));

    cDragon* draco = new cDragon();
    cDragon* ocard = new cDragon();
    cBocon* bocon = new cBocon();
    cVikingo* bodoque = new cVikingo("Juan Carlos", "Rojo", "Bodoque", 2, 12, 2003, "0.50", "3", cantinero, 0);
    cVikingo* mario = new cVikingo("Mario", "Gris", "Hugo", 2, 12, 2003, "0.50", "3", pastor, 0);
    cVikingo* hipo = new cVikingo("Hipo", "Negro", "Hipo", 3, 9, 1999, "1.80", "75", herrero, 3);

    (*bocon)+(draco);
    (*bocon) + (bodoque);
    (*bocon) + (mario);
    (*bocon) + (hipo);
    (*bocon) + (ocard);
    int i[1] = { 0 };
    list<cVikingo*> lv;
    list<cJinete*> jineteada;

    lv.push_back(mario);
    jineteada = bocon->conversion(ocard, lv);
    lv.clear();
    cJinete* marito = jineteada.front();

    cout << *marito << endl;
    
    bocon->elegirVikingo(i, 1);

    bocon->enlistarDragon();
    Sleep(5000);
    bocon->trabajar();
    //bocon->elegirDragon(rand() % bocon->getCantDrag());
    cout << cBocon::getComida() << endl;
    delete bocon;
    return 0;
}
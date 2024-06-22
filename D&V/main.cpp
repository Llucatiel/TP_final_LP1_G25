#include <iostream>
#include "cBocon.h"

#pragma comment(lib, "winmm.lib")
using namespace std;

int main() 
{
    srand(time(0));
    
    cDragon* draco = new cDragon();
    cBocon* bocon = new cBocon();
    cVikingo* bodoque = new cVikingo("Juan Carlos", "Rojo", "Bodoque", 2, 12, 2003, "0.50", "3", cantinero, 0);
    cVikingo* mario = new cVikingo("Mario", "Gris", "Hugo", 2, 12, 2003, "0.50", "3", pastor, 0);
    cVikingo* hipo = new cVikingo("Hipo", "Negro", "Hipo", 3, 9, 1999, "1.80", "75", herrero, 3);
    cVikingo* lauti = new cVikingo("Lautaro", "rubio", "canale", 2, 12, 2003, "1.74", "60", pastor, 0);
    cVikingo* oscar = new cVikingo("Oscar", "negro", "Perdomo", 30, 6, 2005, "1,77", "60", pastor, 0);
    cVikingo* messi = new cVikingo("Lionel", "negro", "messi", 24, 6, 1987, "0.45", "50", herrero, 0);

    (*bocon) + (bodoque);
    (*bocon) + (mario);
    (*bocon) + (hipo);
    (*bocon) + (lauti);
    (*bocon) + (oscar);
    (*bocon) + (messi);

    int i[1] = { 0 };
    list<cVikingo*> lv;
    for (int i = 0; i < 2; i++) {
        try {
            (*mario) + (new cAtaque(fisico));
        }
        catch (const exception* e) {
            i--;
        }
    }
    lv.push_back(mario);
    bocon->conversion(draco, lv);
    bocon->getJin(0)->setApodo("Charlatan");
    lv.clear();
    
    cout << "cargando";Sleep(500);cout << "."; Sleep(500);cout << ".";Sleep(500);cout << ".";Sleep(500);cout << endl;
    cout << "BIENVENIDO A D&V BOCON" << endl;
    cout << "                 ___====-_  _-====___\n";
    cout << "           _--^^^.....//      \\\\.....^^^--_\n";
    cout << "        _-^..........// (    ) \\\\..........^-_\n";
    cout << "       -............//  |\\^^/|  \\\\............-\n";
    cout << "     _/............//   (@::@)   \\\\............\\_\n";
    cout << "    /.............((     \\\\//     )).............\\\n";
    cout << "   -...............\\\\    (oo)    //...............-\n";
    cout << "  -.................\\\\  / \"\" \\  //.................-\n";
    cout << " -...................\\\\/      \\\\//...................-\n";
    cout << "_#/|........./\\......(   ()   )...... /\\.........|\\#_\n";
    cout << "|/ |.|/\\|/\\  \\/|.|/\\  \\    /  \\|.|/\\/  \\/|/\\|/|.\\| \\\n";
    cout << "  |/  V  |  |    |  |    \\  |  |  |    |  |  V  \\\n";
    PlaySound(TEXT("DIVINE EMANATION BUNDLE DRAGONS VOLUME 2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    system("pause");
    system("cls");

    bocon->enlistarVikingo();
    cout << endl;
    bocon->enlistarDragon();
    Sleep(4000);
    system("cls");

    int pr = rand() % bocon->getCantVik();
    int se;
    do {
        se = rand() % bocon->getCantVik();
    } while (se == pr);
    int v[3];
    for (int i = 0; i < 3; i++) {
        v[i] = rand() % bocon->getCantVik();
    }
    bocon->getVik(pr)->imprimirDatos();
    bocon->getVik(se)->imprimirDatos();
    Sleep(10000);
    system("cls");
    cout << bocon->getDrag(rand() % bocon->getCantDrag())->To_string() << endl;

    Sleep(5000);
    system("cls");
    
    bocon->trabajar();
    Sleep(10000);
    system("cls");

    bocon->elegirVikingo(v, 3);
    Sleep(5000);
    pr = rand() % bocon->getCantJin();
    bocon->getJin(pr)->entrenar();
    
    Sleep(5000);
    se = bocon->getJin(pr)->getDragon()->getIdentificador() - 1;
    bocon->getDrag(se)->mostrarDanos();
    bocon->getDrag(se)->mostrarStats();
    Sleep(10000);
    bocon->elegirDragon(se);
    cout <<"cantidad actual de comida: "<< cBocon::getComida() << endl;
    delete bocon;
    return 0;
}
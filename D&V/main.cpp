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
    cVikingo* lauti = new cVikingo("Lautaro", "rubio", "canale", 2, 12, 2003, "1.74", "60", pastor, 0);
    cVikingo* oscar = new cVikingo("Oscar", "negro", "Perdomo", 30, 6, 2005, "1,77", "60", pastor, 0);
    cVikingo* messi = new cVikingo("Lionel", "negro", "messi", 24, 6, 1987, "0.45", "50", herrero, 0);

    (*bocon)+(draco);
    (*bocon) + (bodoque);
    (*bocon) + (mario);
    (*bocon) + (hipo);
    //(*bocon) + (ocard);
    (*bocon) + (lauti);
    (*bocon) + (oscar);
    (*bocon) + (messi);

    int i[1] = { 0 };
    list<cVikingo*> lv;
    (*mario)+(new cAtaque(fisico));
    lv.push_back(mario);
    bocon->conversion(draco, lv);
    
    cout << "cargando";Sleep(1000);cout << "."; Sleep(1000);cout << ".";Sleep(1000);cout << ".";Sleep(1000);cout << endl;
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
    Sleep(2000);
    system("cls");

    bocon->enlistarVikingo();
    cout << endl;
    bocon->enlistarDragon();
    Sleep(4000);
    system("cls");

    bocon->vikRandom()->imprimirDatos();
    bocon->vikRandom()->imprimirDatos();
    Sleep(10000);
    system("cls");

    bocon->trabajar();
    bocon->elegirDragon(rand() % bocon->getCantDrag());
    cout <<"cantidad actual de comida: "<< cBocon::getComida() << endl;
    delete bocon;
    return 0;
}
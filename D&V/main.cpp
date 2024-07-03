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
    PlaySound(TEXT("../DIVINE EMANATION BUNDLE DRAGONS VOLUME 2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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

    cout<<"DRAGON DEL DIA: "<<endl;
    cout << bocon->getDrag(rand() % bocon->getCantDrag())->To_string() << endl;

    Sleep(5000);
    system("cls");
    
    cout << "A LABURAR" << endl << endl;
    bocon->trabajar();
    cout << "Un dia laboral comun en berk, tu cantidad de comida actual es de: " << cBocon::getComida() << endl;
    Sleep(3000);
    system("cls");

    cout << "HORA DE CAZAR DRAGONES" << endl << endl;
    int cantDragones = bocon->getCantDrag();
    int comida = cBocon::getComida();
    bocon->elegirVikingo(v, 3);
    Sleep(5000);
    if (comida > cBocon::getComida() && cantDragones == bocon->getCantDrag())
        cout << "Encruzijada fallida.\n";
    else if (cantDragones < bocon->getCantDrag())
        cout << "Bienvenido " << bocon->getDrag(bocon->getCantDrag() - 1)->getNombre() << " a la familia\n";
    else if (comida < cBocon::getComida())
        cout << "Encruzijada exitosa.\n";
    else
        cout << "Encruzijada sin ganancias ni perdidas\n";


    cout << "HORA DE EJERCITAR ESOS MUSCULOS" << endl << endl;
    cout << "levantando una roca de 100 kg"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << endl;
    cout << "sobrevolando por una montania de 6000 metros a 150km/h"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << endl;
    pr = rand() % bocon->getCantJin();
    bocon->getJin(pr)->entrenar();
    cout << "La nota del entrenamiento es " << bocon->getJin(pr)->getNota();
    cout << "Su dragon tendra una mejora de " << bocon->getJin(pr)->getDragon()->getBuff() << " a sus estaditicas\n";
    
    Sleep(5000);
    system("cls");
    se = bocon->getJin(pr)->getDragon()->getIdentificador() - 1;
    
    cout << "El dragon con el que iras para la batalla hoy es " << bocon->getDrag(se)->getNombre() << endl;
    cout << "MOVIMIENTO DESTACADO: " << endl;
    bocon->getDrag(se)->mostrarDanos();
    cout <<endl<< "ESTADISTICAS:" << endl;
    bocon->getDrag(se)->mostrarStats();
    Sleep(10000);
    list<cJinete*> jin = bocon->elegirDragon(se);

    //PELEA DE DRAGONES!!!!!!!!!!!!!!!!!!!!!!!!

    cBocon::cambioComida((jin.size() * -5));
    int lim = 1 + rand() % 4;
    cDragon* enemigo = new cDragon(new cAtaque());
    //Crea a un ataque y dragon genericos para combatir
    list<cJinete*>::iterator it = jin.begin();
    cDragon* dragon = (*it)->getDragon();

    for (int i = enemigo->getCantAtk(); i < lim; i++) {
        try {
            cAtaque* atk = new cAtaque(enemigo->getAliento());
            (*enemigo) + atk;
        }
        catch (const exception* e) {
            i--;
            delete e;
        }
    }

    float life = 0;
    life = (*it)->getStat(2) * 5;
    if (jin.size() == 2) {
        it++;
        life += (*it)->getStat(2) * 5;
        it = jin.begin();
    }
    float max = life;

    bool ambos = true;
    bool perdida = false;
    lim = enemigo->getCantAtk();
    system("cls");
    int a, b;
    float dano;
    cout << dragon->getNombre() << " se enfrenta a " << enemigo->getNombre() << endl << "PREPARENCE PARA LA BATALLA!" << endl << endl;
    Sleep(2000);
    while (ambos) { //El combate seguira hasta que uno de los dos caiga
        bool atacado = false;
        do {
            cout << enemigo->getNombre() << ": " << enemigo->getVidaActual() << " / " << enemigo->getVidaTotal() << " hp" << endl;
            cout << "\t\t\t\t\t";
            if (dragon->getVivo()) {
                cout << dragon->getNombre() << ": " << dragon->getVidaActual() << " / " << dragon->getVidaTotal() << " hp" << endl;
                Sleep(2000);
                try {
                    a = rand() % dragon->getCantAtk();
                    b = dragon->atacar(a);
                    cout << dragon->getNombre() << " a usado " << dragon->getAtk(a-1)->getNombre() << endl;
                    if (b == 2) {
                        cout << "HA SACADO UN CRITICO" << endl;
                        for (int i = 0; i < 3; i++) {
                            system("color 47");
                            Sleep(100);
                            system("color 67");
                            Sleep(100);
                        }
                        system("color 07");
                    }
                    else if (b == 1) {
                        cout << "Ha acertado al objetivo" << endl;
                        for (int i = 0; i < 3; i++) {
                            system("color 87");
                            Sleep(100);
                            system("color 07");
                            Sleep(100);
                        }
                    }
                    else
                        cout << "El ataque fallo lastimosamente\n";

                    dano = dragon->ataque(a, b);
                    enemigo->perderVida(dano); //Perder vida llama dentro de si a atacar, calcula si pego o no, y cuanto danio hizO
                    atacado = true;
                    cout << "Haciendo " << dano << " puntos de dano\n";
                }
                catch (const exception* e) {
                    cout << e->what() << endl;
                    delete e;
                    atacado = false;
                    Sleep(1000);
                    system("cls");
                }
            }
            else {
                cout << "Jinetes: " << life << " / " << max << " hp" << endl;
                while (it != jin.end()) {
                    try {
                        a = rand() % (*it)->getCantAtk();
                        b = (*it)->atacar(a);
                        cout << (*it)->getNombre() << " a usado " << (*it)->getAtk(a - 1)->getNombre() << endl;
                        if (b == 2) {
                            cout << "HA SACADO UN CRITICO" << endl;
                            for (int i = 0; i < 3; i++) {
                                system("color 47");
                                Sleep(100);
                                system("color 67");
                                Sleep(100);
                            }
                            system("color 07");
                        }
                        else if (b == 1) {
                            cout << "Ha acertado al objetivo" << endl;
                            for (int i = 0; i < 3; i++) {
                                system("color 87");
                                Sleep(100);
                                system("color 07");
                                Sleep(100);
                            }
                        }
                        else
                            cout << "El ataque fallo lastimosamente\n";

                        dano = (*it)->ataque(a, b);
                        enemigo->perderVida(dano); //Perder vida llama dentro de si a atacar, calcula si pego o no, y cuanto danio hizO
                        atacado = true;
                        cout << "Haciendo " << dano << " puntos de dano\n";
                    }
                    catch (const exception* e) {
                        cout << e->what() << endl;
                        delete e;
                        atacado = false;
                        Sleep(1000);
                        system("cls");
                    }
                    it++;
                }
                it = jin.begin();
            }

        } while (!atacado);

        //Espera 1.5 segundos y sigue con el programa
        Sleep(1500);
        system("cls");
        ambos = enemigo->getVivo();
        if (!ambos)
            break;

        cout << enemigo->getNombre() << ": " << enemigo->getVidaActual() << " / " << enemigo->getVidaTotal() << " hp" << endl;
        cout << "\t\t\t\t\t";
        if (dragon->getVivo()) {
            cout << dragon->getNombre() << ": " << dragon->getVidaActual() << " / " << dragon->getVidaTotal() << " hp" << endl;
            Sleep(2000);
            try {
                a = rand() % enemigo->getCantAtk();
                b = enemigo->atacar(a);
                cout << enemigo->getNombre() << " a usado " << enemigo->getAtk(a - 1)->getNombre() << endl;
                if (b == 2) {
                    cout << "HA SACADO UN CRITICO" << endl;
                    for (int i = 0; i < 3; i++) {
                        system("color 47");
                        Sleep(100);
                        system("color 67");
                        Sleep(100);
                    }
                    system("color 07");
                }
                else if (b == 1) {
                    cout << "Ha acertado al objetivo" << endl;
                    for (int i = 0; i < 3; i++) {
                        system("color 87");
                        Sleep(100);
                        system("color 07");
                        Sleep(100);
                    }
                }
                else
                    cout << "El ataque fallo lastimosamente\n";

                dano = enemigo->ataque(a, b);
                dragon->perderVida(dano); //Perder vida llama dentro de si a atacar, calcula si pego o no, y cuanto danio hizO
                atacado = true;
                cout << "Haciendo " << dano << " puntos de dano\n";
            }
            catch (const exception* e) {
                cout << e->what() << endl;
                delete e;
            }
            if (!dragon->getVivo()) {
                Sleep(2000);
                cout << dragon->getNombre() << " ha perecido en batalla, pero aun no es el fin!" << endl;
            }
            Sleep(1000);
            system("CLS");
        }
        else {
            cout << "Jinetes: " << life << " / " << max << " hp" << endl;
            try {
                a = rand() % enemigo->getCantAtk();
                b = enemigo->atacar(a);
                cout << enemigo->getNombre() << " a usado " << enemigo->getAtk(a - 1)->getNombre() << endl;
                if (b == 2) {
                    cout << "HA SACADO UN CRITICO" << endl;
                    for (int i = 0; i < 3; i++) {
                        system("color 47");
                        Sleep(100);
                        system("color 67");
                        Sleep(100);
                    }
                    system("color 07");
                }
                else if (b == 1) {
                    cout << "Ha acertado al objetivo" << endl;
                    for (int i = 0; i < 3; i++) {
                        system("color 87");
                        Sleep(100);
                        system("color 07");
                        Sleep(100);
                    }
                }
                else
                    cout << "El ataque fallo lastimosamente\n";

                dano = enemigo->ataque(a, b);
                life -= dano; 
                atacado = true;
                cout << "Haciendo " << dano << " puntos de dano\n";
            }
            catch (const exception* e) {
                cout << e->what() << endl;
                delete e;
            }
            if (life <= 0) {
                ambos = false;
                perdida = true;
            }
            Sleep(1000);
            system("CLS");
        }
    }
    if (!dragon->getVivo()) {
        cout << "Lamentamos fuertemente la perdida de " << dragon->getNombre() << endl << "peleo bien." << endl;
        bocon->encuentrePaz(dragon);
        if (!perdida) {
            cout << "Nuestros fuertes jinetes volveran a casa, con pena y tristeza, pero victorios." << endl;
        }
        else {
            cout << "Que el Valhalla les guarde un lugar a nuestros grandes guerreros." << endl;
            for (list<cJinete*>::iterator it = jin.begin(); it != jin.end(); it++)
                bocon->encuentrePaz((*it));
        }
    }
    else {
        string mayus = dragon->getNombre();
        transform(mayus.begin(), mayus.end(), mayus.begin(), ::toupper); //Recorre el string completo, haciendo mayuscula todos sus caracteres
        cout << "INCREIBLE BATALLA DADA POR " << mayus << "!!!" << endl << "Hoy vuelve victorioso a casa." << endl;
        dragon->curarse();
    }

    if (!perdida) {
        cBocon::cambioComida(stoi(enemigo->getPeso()) / 10);
        for (list<cJinete*>::iterator it = jin.begin(); it != jin.end(); it++)
            (*it)->setDragonesTerminados(1);
    }
    delete enemigo;
    cout <<"cantidad actual de comida: "<< cBocon::getComida() << endl;
    delete bocon;
    return 0;
}
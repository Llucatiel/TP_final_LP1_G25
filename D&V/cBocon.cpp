#include "cBocon.h"

int cBocon::comida = 30;


int cBocon::getComida()
{
    return comida;
}

void cBocon::cambioComida(int suma)
{
    comida += suma;
}

int cBocon::getCantDrag()
{
    return dragones.size();
}

int cBocon::getCantVik()
{
    return vikingos.size();
}

int cBocon::getCantJin()
{
    return jinetes.size();
}

cBocon::cBocon()
{
    vikingos.clear();
    jinetes.clear();
    dragones.clear();
    valhalla.clear();
    dragonesNoDomados.clear();

    for (int i = 0; i < 8; i++) 
        dragonesNoDomados.push_back(new cDragon());
}

cBocon::~cBocon()
{
    if (!vikingos.empty()) {
        list<cVikingo*>::iterator v = vikingos.begin();
        while (v != vikingos.end()) {
            if (*v != nullptr)
                delete (*v);
            v++;
        }
    }
    if (!jinetes.empty()) {
        list<cJinete*>::iterator j = jinetes.begin();
        while (j != jinetes.end()) {
            if (*j != nullptr)
                delete (*j);
            j++;
        }
    }
    if (!dragones.empty()) {
        list<cDragon*>::iterator d = dragones.begin();
        while (d != dragones.end()) {
            if (*d != nullptr)
                delete (*d);
            d++;
        }
    }
    if (!dragonesNoDomados.empty()) {
        list<cDragon*>::iterator d = dragonesNoDomados.begin();
        while (d != dragonesNoDomados.end()) {
            if(*d != nullptr)
                delete (*d);
            d++;
        }
    }
    if (!valhalla.empty()) {
        list<cPersonaje*>::iterator p = valhalla.begin();
        while (p != valhalla.end()) {
            if(*p != nullptr)
             delete (*p);
            p++;
        }
    }
    jinetes.clear();
    vikingos.clear();
    dragones.clear();
    dragonesNoDomados.clear();
    valhalla.clear();
}

void cBocon::operator+(cDragon* dragon)
{
    dragones.push_back(dragon);
}

void cBocon::operator+(cVikingo* vik)
{
    vikingos.push_back(vik);
}

void cBocon::operator+(cJinete* jin)
{
    jinetes.push_back(jin);
}

void cBocon::encuentrePaz(cDragon* perdida)
{
    list<cDragon*>::iterator it;
    for (it = dragones.begin(); it != dragones.end(); it++) {
        if ((*it)->getIdentificador() == perdida->getIdentificador()) {
            dragones.erase(it);
            break;
        }
    }
    valhalla.push_back(perdida);
}

void cBocon::encuentrePaz(cVikingo* perdida)
{
    list<cVikingo*>::iterator it;
    for (it = vikingos.begin(); it != vikingos.end(); it++) {
        if ((*it)->getNombre() == perdida->getNombre()) {
            vikingos.erase(it);
            break;
        }
    }
    valhalla.push_back(perdida);
}

void cBocon::encuentrePaz(cJinete* perdida)
{
    list<cJinete*>::iterator it;
    for (it = jinetes.begin(); it != jinetes.end(); it++) {
        if ((*it)->getNombre() == perdida->getNombre()) {
            jinetes.erase(it);
            break;
        }
    }
    valhalla.push_back(perdida);
}

//Muestra la lista de vikingos
void cBocon::enlistarVikingo()
{
    list<cVikingo*>::iterator it = vikingos.begin();

    cout << "tu lista actual de vikingos es: " << endl;

    int i = 0;
    while (it != vikingos.end()) {
        cout << i << ". " << (*it)->getNombre() << endl;
        i++;
        it++;
    }
}

//Muestra la lista de Dragones
void cBocon::enlistarDragon()
{
    list<cDragon*>::iterator it = dragones.begin();

    cout << "tu lista actual de dragones es: " << endl;

    int i = 0;
    while (it != dragones.end()) {
        cout << i << ". " << (*it)->getNombre() << endl;
        i++;
        it++;
    }
}

void cBocon::conversion(cDragon* dragon, list<cVikingo*> vikingo)
{
    list<cVikingo*>::iterator it = vikingo.begin();
    list<cVikingo*>::iterator its = vikingos.begin();
    int cant = vikingo.size();
    for (int i = 0; i < cant; i++) {
        (*this) + new cJinete((*it), dragon);
        
        while (its != vikingos.end()) {
            if ((*its)->getNombre() == (*it)->getNombre()) {
                (*it)->convertido();
                this->encuentrePaz((*it));
                break;
            }
            its++;
        }
        it++;
    }
    list<cDragon*>::iterator dr = dragones.begin();
    bool domado = false;
    while (dr != dragones.end()) {
        if ((*dr)->getIdentificador() == dragon->getIdentificador())
            domado = true;
        dr++;
    }
    if (!domado)
        *this + dragon;
}

void cBocon::trabajar()
{
    list<cVikingo*>::iterator it = vikingos.begin();

    

    while (it != vikingos.end()) {
        cBocon::cambioComida((*it)->trabajar());
        it++;
    }
    
}


cVikingo* cBocon::getVik(int i)
{
    list<cVikingo*>::iterator it = vikingos.begin();
    int j = 0;
    while (it != vikingos.end()) {
        if (j == i)
            return (*it);
        it++;
        j++;
    }

    return *(it = vikingos.begin()); //En caso de fallo, enviar el primero
}

cDragon* cBocon::getDrag(int i)
{
    list<cDragon*>::iterator it = dragones.begin();
    int j = 0;
    while (it != dragones.end() && j != i) {
        if (j == i)
            return (*it);
        it++;
        j++;
    }

    return *(it = dragones.begin()); //En caso de fallo, enviar el primero
}

cJinete* cBocon::getJin(int i)
{
    list<cJinete*>::iterator it = jinetes.begin();
    int j = 0;
    while (it != jinetes.end() && j != i) {
        if (j == i)
            return (*it);
        it++;
        j++;
    }

    return *(it = jinetes.begin()); //En caso de fallo, enviar el primero
}

//Busca en la lista de vikingos a aquellos elegidos para usarlos al llamar atacarDragones
void cBocon::elegirVikingo(int* elegidos, int n)
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

    v.unique();
    
    atacarDragones(v);
}

//Busca en la lista de dragones que tiene (En el futuro deberia de ser de jinetes) y al final llama a pelear
list<cJinete*> cBocon::elegirDragon(int elegido)
{
    list<cDragon*>::iterator it = dragones.begin();
    bool encontrado = false;
    int j = 0;
    while (it != dragones.end()) {
        if (j == elegido) {
            encontrado = true;
            break;
        }
        j++;
        it++;
    }

    list<cJinete*>::iterator ij = jinetes.begin();
    list<cJinete*> jin;
    if (!encontrado) {
        jin.clear();
        return jin;
    }

    while (ij != jinetes.end()) {
        if ((*ij)->getDragon()->getIdentificador() == (*it)->getIdentificador())
            jin.push_back((*ij));
        ij++;
    }

    jin.unique();
    return jin;
}


//Pelea entre los vikingos y los dragones
void cBocon:: atacarDragones(list<cVikingo*> vikingos)//en el main especificamos que no se puede enviar mas de 6
{
    int cantidadeVikingos = vikingos.size();

    if (cVikingo::getCantVikingos() < cantidadeVikingos || cantidadeVikingos > 6)
        return; // Exception??
    unsigned int dado;

    cBocon::cambioComida(-cantidadeVikingos);


    dado = cantidadeVikingos + rand() % (15 - cantidadeVikingos);

    int premio = 0;


    if (dado < 3) {
    }
    else if (dado < 6) {
        premio = cantidadeVikingos * 0.5;
    }
    else if (dado < 9) {
        premio = cantidadeVikingos;
    }
    else if (dado < 12 || dragonesNoDomados.empty()){
        premio = cantidadeVikingos * 2;
    }
    else {
        cDragon* d = dragonesNoDomados.front();
        list<cVikingo*> v;
        dragonesNoDomados.pop_front();
        list<cVikingo*>::iterator it = vikingos.begin();
        unsigned int i = 0;
        while (it != vikingos.end() && i < d->getCantCabezas()) {
            v.push_back((*it));
            it++;
            i++; 
        }
        conversion(d, v);
    }

    if (premio!=0) {
        list<cVikingo*>::iterator it = vikingos.begin();

        while (it != vikingos.end()) {
            (*it)->setDragonesTerminados(1);
            it++;
        }
    }

    cBocon::cambioComida(premio);
}

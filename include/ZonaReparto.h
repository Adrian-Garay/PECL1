#ifndef ZONAREPARTO_H_INCLUDED
#define ZONAREPARTO_H_INCLUDED
#include "Cola.h"
#include "Pila.h"
#include "vehiculo.h"
class ZonaReparto
{
private:
    friend class Gestor;
    friend class Cola;
    friend int main();
    Pila Camion1;
    Pila Camion2;
    int zona;
    Cola registro;


public:
    ZonaReparto();
    virtual ~ZonaReparto();

};

#endif // ZONAREPARTO_H_INCLUDED

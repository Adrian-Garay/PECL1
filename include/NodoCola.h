#ifndef NODOCOLA_H_INCLUDED
#define NODOCOLA_H_INCLUDED
#include "vehiculo.h"
#include <iostream>

class NodoCola
{
    friend class Cola;

private:
    NodoCola*siguiente;
    Vehiculo v;
public:
    NodoCola();
    NodoCola(Vehiculo v, NodoCola*sig = NULL);
    ~NodoCola();
};

#endif // NODOCOLA_H_INCLUDED

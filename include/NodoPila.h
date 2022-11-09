#ifndef NODOPILA_H_INCLUDED
#define NODOPILA_H_INCLUDED
#include "vehiculo.h"
#include <iostream>

class NodoPila
{
    friend class Pila;

private:
    Vehiculo valor;
    NodoPila* siguiente;
public:
    NodoPila();
    NodoPila(Vehiculo v, NodoPila *sig = NULL);
    ~NodoPila();
};
typedef NodoPila* pnodo;


#endif // NODOPILA_H_INCLUDED

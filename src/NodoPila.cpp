#include "../include/NodoPila.h"
#include "vehiculo.h"

NodoPila::NodoPila()
{
    valor = Vehiculo();
    siguiente = NULL;
    //ctor
}
NodoPila::NodoPila(Vehiculo v, NodoPila* sig)
{
    valor = Vehiculo();
    ;
    siguiente = sig;
}
NodoPila::~NodoPila()
{
    //dtor
}

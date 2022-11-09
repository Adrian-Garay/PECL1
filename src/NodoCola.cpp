#include "../include/NodoCola.h"
#include "vehiculo.h"

NodoCola::NodoCola()
{
    v=Vehiculo();
    siguiente=NULL;
//constructor por defecto
}
NodoCola::NodoCola (Vehiculo v, NodoCola*sig)
{
    v = Vehiculo();
    siguiente =sig;
}
NodoCola::~NodoCola()
{
//dtor
}

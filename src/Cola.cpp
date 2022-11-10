#include "../include/Cola.h"
#include "../include/NodoCola.h"
#include "vehiculo.h"
#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
Cola::~Cola() {}

void Cola::encolar(Vehiculo v)
{
    NodoCola*nuevo_nodo = new
    NodoCola (v);
    if(es_vacia())
    {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else
    {
        ultimo ->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}

Vehiculo Cola::desencolar()
{
    if (!es_vacia())
    {
        Vehiculo v = primero-> v;
        NodoCola*aux = primero;

        if((primero==ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente =NULL;
            delete(aux);
        }
        longitud--;
        return v;
    }
}

Vehiculo Cola::inicio()
{
    if (!es_vacia())
    {
        return primero->v;
    }
}

Vehiculo Cola::fin()
{
    if (!es_vacia())
    {
        return ultimo-> v;
    }
}

int Cola::get_longitud()
{
    return longitud;
}

bool Cola:: es_vacia()
{
    return ((primero == NULL) && (ultimo ==NULL));
}

void Cola::mostrarCola()
{
    NodoCola *aux = primero;
    if (es_vacia())
    {
        cout<<"Cola Vacía "<<endl;
    }
    else
    {

        cout<<"Cola fabrica longitud  = "+to_string(get_longitud()) + "\n";
        for(int i=0; i<longitud; i++)
        {


            cout<<"\n";
            cout<<"-------";
            cout<<"Coche número: "<<i+1<<endl;
            cout <<aux->v.verVehiculo()<<endl;


            aux=aux->siguiente;
        }
    }

}

void Cola::VerCima()
{
    NodoCola *aux = primero;
    if (es_vacia())
    {
        cout<<"Cola Vacía "<<endl;
    }
    else

    {
        for(int i=0; i<longitud; i++)
        {

            cout <<aux->v.verVehiculo()<<endl;
            aux=aux->siguiente;
        }

    }
}

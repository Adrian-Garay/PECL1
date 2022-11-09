#include <iostream>
#include "../include/Pila.h"
#include "../include/NodoPila.h"
#include "vehiculo.h"
using namespace std;

Pila::Pila()
{
    cima = NULL;
}

//Destructor
Pila::~Pila()
{
    while (cima) desapilar();
}

bool Pila::esVacia()
{
    return cima == NULL;
}

void Pila::apilar(Vehiculo v)
{
    pnodo nuevo = new NodoPila(v, cima);
    //comienzo de la pila nevo nodo
    cima = nuevo;
}

void Pila::desapilar()
{
    pnodo nodo; //puntero aux para manipular el nodo
    if (cima)
    {
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
    }
}

int Pila::mostrar()
{NodoPila *aux = cima;
    if(esVacia())
    {
        return NULL;
    }
    else
    {
        cout<< aux->valor.verVehiculo();
    }
}



int Pila::contar()
{
    Pila p_aux;
    Vehiculo e{};
    int contador=0;
    while (esVacia()==false)
    {
        e = Pila::cima->valor;
        p_aux.apilar(e);
        desapilar();
        contador+=1;
    }
    while (!p_aux.esVacia())
    {
        Pila::apilar(p_aux.cima->valor);
        p_aux.desapilar();
    }
    p_aux.~Pila();
    return contador;
}

Vehiculo Pila::fondo()
{

    Pila p_aux;
    Vehiculo e{};
    while (!Pila::esVacia())
    {
        e = Pila::cima->valor;
        p_aux.apilar(e);
        Pila::desapilar();
    }
    while (!p_aux.esVacia())
    {
        Pila::apilar(p_aux.cima->valor);
        p_aux.desapilar();
    }
    p_aux.~Pila();
    return e;
}
//Iterativo
void Pila::montar(Pila p1,Pila p2)  //No funciona apilar
{
    Vehiculo e;
    while(! esVacia())
    {
        e = cima->valor;
        //cout << e;
        desapilar();
        p1.apilar(e);
        cout << p2.contar();
        cout << p1.contar();

    }
}

void Pila::quitar(int n)
{
    while(n > 0)
    {
        Pila::desapilar();
        n = n-1;
    }
}

/* void Pila::quito_fondo(){
    if(!esVacia()) {
           int c=cima->valor;
           desapilar();
           if (!esVacia()){
               quito_fondo();
               apilar(c);
           }
       }
}*/

void Pila::inversa()
{
    Pila pi;
    Pila p2;
    Vehiculo e;
    //pi = p2.inversa();
    pi.apilar(cima->valor);
    while(! esVacia())
    {
        e = pi.cima->valor;
        pi.desapilar();
        apilar(e);
    }
}

void Pila::mostrarDatos()

{
    if(esVacia())
    {
        cout << "Pila vacia"<<endl;
    }
    else
    {NodoPila *aux =cima;
        while (!esVacia())
        {

            cout << aux->valor.verVehiculo()<<endl;

            aux = aux->siguiente;
            desapilar();
        }
    }
}

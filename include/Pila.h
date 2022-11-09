#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "NodoPila.h"
#include "vehiculo.h"

class Pila
{
private:
    pnodo cima;
    int tamanno ;
public:
    Pila();
    virtual~Pila();
    bool esVacia();
    void apilar(Vehiculo v);
    void desapilar();
    void mostrarDatos();

    int mostrar();
    int contar();
    Vehiculo fondo();
    void montar(Pila p1, Pila p2);
    void quitar(int n);
    void inversa();
protected:
};


#endif // PILA_H_INCLUDED

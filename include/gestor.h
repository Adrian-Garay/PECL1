#include<iostream>
#ifndef GESTOR_H
#define GESTOR_H
#include "Pila.h"
#include "Cola.h"
#include "ZonaReparto.h"
using namespace std;


class Gestor
{
public:
    Gestor();
    ~Gestor();
    //variables
    std::string NBastidor;
    std::string Modelo;
    std::string Color;
    int Concesionario;
    Vehiculo vehi;


    //funciones
    Vehiculo asignaConcesionario2(Vehiculo v, int nc);
    void crea_vehiculos(int nv);
    void muestra_almacen_fabrica();

    void muestra_zonas();
    void limpia_almacen();
    void cambioAlmacenRandTotal (int ns , int np,int nc);

    void cambioAlmacenRand(int ns, int np, int nc);
    void cambioAlmacen(int ns,int nAlmacen, int np, int);

    //Pilas y colas
    Cola Cola_fabrica; //Cola de la fabrica que contendra los automoviles

    ZonaReparto ZonaN;
    ZonaReparto ZonaE;
    ZonaReparto ZonaS;
    ZonaReparto ZonaO;

    Cola Cola_zonaN=ZonaN.registro;
    Cola Cola_zonaS=ZonaS.registro;
    Cola Cola_zonaE=ZonaE.registro;
    Cola Cola_zonaO=ZonaO.registro;

    Pila Camion1N=ZonaN.Camion1;
    Pila Camion2N=ZonaN.Camion2;
    Pila Camion1E=ZonaE.Camion1;
    Pila Camion2E=ZonaE.Camion2;
    Pila Camion1S=ZonaS.Camion1;
    Pila Camion2S=ZonaS.Camion2;
    Pila Camion1O=ZonaO.Camion1;
    Pila Camion2O=ZonaO.Camion2;





protected:

private:
};

#endif // GESTOR_H

#include "vehiculo.h"
#include <stdlib.h>
#include <time.h> // es necesario incluirla
#include<iostream>
#include<string>
#include "string.h"
using namespace std;

//Constructor para inicualizar los atributos
Vehiculo::Vehiculo()
{
    int num;


    string listaModelos[]= {"Ford Fiesta", "Toyota Yaris", "Renault Clio", "Opel Corsa", "Seat León"};
    string listaColores[]= {"Azul","Rojo","Verde","Blanco","Gris","Negro","Amarillo","Naranja"};
    for (int i=1; i<=5; i++)                                //Crea los digitos aleatorios
    {
        num = 1 + rand() % (9); //GENERA ALEATORIOS ENTRE 0 Y 9

        nBastidor=nBastidor + std::to_string(num); //convierte int a string
    }
    for (int i=0; i<=2; i++)                                //Crea las  letras aleatorias
    {
        char letras[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        num = 1 + rand() % (27 - 1);
        nBastidor=nBastidor+letras[num-1];   //Convierte str a string
    }
    modelo=listaModelos[rand() % (5)];

    color=listaColores[rand() % (8)];

    concesionario=0;

}

Vehiculo::~Vehiculo()
{
    //dtor
}

void Vehiculo::cargarVehiculo(string nBast,string mod, string col, int conce)
{
    string nBastidor = nBast;
    string modelo = mod;
    string color = col;
    int concesionario = conce;
}

string Vehiculo::devolverNBastidor()
{
    return nBastidor;
}
string Vehiculo::devolverColor()
{
    return color;
}
string Vehiculo::devolverModelo()
{
    return modelo;
}
int Vehiculo::devolverConcesionario()
{
    return concesionario;
}

string Vehiculo::verVehiculo()
{
    return( "El vehiculo tiene número de bastidor: " + devolverNBastidor() + ", modelo: " + devolverModelo() + ", color: "+ devolverColor() + ", concesionario: " +  std::to_string(devolverConcesionario())+" " + "\n" );
}

void Vehiculo::asignaConcesionario(int nc)
{
    int num;

    num = 1 + rand() % (nc); //GENERA ALEATORIOS ENTRE 0 Y 5

    Vehiculo::concesionario=num;
}


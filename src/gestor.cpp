#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "gestor.h"
#include "vehiculo.h"
#include "Cola.h"
#include <time.h> // es necesario incluirla
#include "ZonaReparto.h"

using namespace std;

Gestor::Gestor()
{
    //ctor
}

Gestor::~Gestor()
{
    //dtor
}

Vehiculo Gestor::asignaConcesionario2(Vehiculo vehi, int nc)
{
    int num;

    num = 1 + rand() % (nc); //GENERA ALEATORIOS ENTRE 0 Y 5
    //cout << num<< "";
    vehi.concesionario=num;
    return vehi;
}

void Gestor::crea_vehiculos(int nv)         //Apartado 1 y 2
{
    //Vehiculo vehiculos_cola;

    for (int i=0; i<nv; i++)
    {
        Cola_fabrica.encolar(Vehiculo());
    }
    Cola_fabrica.VerCima();
    cout<<"Se han creado: "<<nv<<" vehiculos \n";
}
void Gestor::muestra_almacen_fabrica()      //Apartado 3
{
    Cola_fabrica.mostrarCola();

}

void Gestor::muestra_zonas()      //Apartado 3
{
    cout<<"Zona Norte:\n";
    Cola_zonaN.mostrarCola();
    cout<<"Camion 1 Norte:\n";
    Camion1N.mostrarDatos();
    cout<<"Camion 2 Norte:\n";
    Camion2N.mostrarDatos();
    cout<<"\n";
    cout<<"Zona Sur:\n";

    Cola_zonaS.mostrarCola();
    cout<<"Camion 1 sur:\n";
    Camion1S.mostrarDatos();
    cout<<"Camion 2 sur:\n";
    Camion2S.mostrarDatos();
    cout<<"\n";

    cout<<"Zona Este:\n";
    Cola_zonaE.mostrarCola();
    cout<<"Camion 1 Este:\n";
    Camion1E.mostrarDatos();
    cout<<"Camion 2 Este:\n";
    Camion2E.mostrarDatos();
    cout<<"\n";
    cout<<"Zona Oeste:\n";

    Cola_zonaO.mostrarCola();
    cout<<"Camion 1 Oeste:\n";
    Camion1O.mostrarDatos();
    cout<<"Camion 2 Oeste:\n";
    Camion2O.mostrarDatos();
    cout<<"\n";
}

void Gestor::limpia_almacen()               //Apartado4
{
    if (Cola_fabrica.es_vacia())
    {
        cout<<"Cola de fabrica vacía. \n";
    }
    else
    {
        while(!Cola_fabrica.es_vacia())
        {
            Cola_fabrica.desencolar();
        }
        cout<<"Almacen de la fabrica vaciado.\n";
    }
}

void Gestor::cambioAlmacenRand(int ns, int np, int nc)          //Apartado 5
{
    int almacenRandom;
    Vehiculo mueveVehi;

    for (int i=1; i<=5; i++)                                //Crea los digitos aleatorios para el almacen aleatorio
    {
        almacenRandom = 1 + rand() % (4); //GENERA ALEATORIOS ENTRE 0 Y 4
        //cout << num<< "";

    }
    if (Cola_fabrica.es_vacia())
    {
        cout<<"Cola de fabrica esta vacía. \n";
    }
    else
    {
        for(int j=0; j<ns; j++)
        {
            vehi = Cola_fabrica.inicio();
            Cola_fabrica.desencolar();
            if (almacenRandom==1)           //Zona Norte
            {
                if (Camion1N.contar()<np)
                {
                    Camion1N.apilar(vehi);
                    cout << Camion1N.contar()<<endl;
                    //Cola_zonaN.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2O.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2N.apilar(vehi);
                        cout << Camion2N.contar()<<endl;
                        //Cola_zonaN.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
            else if (almacenRandom==2)      //Zona Sur
            {
                if (Camion1S.contar()<np)
                {
                    Camion1S.apilar(vehi);
                    cout << Camion1S.contar()<<endl;
                    //Cola_zonaS.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2S.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2S.apilar(vehi);
                        cout << Camion2S.contar()<<endl;
                        //Cola_zonaS.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
            else if (almacenRandom==3)      //Zona Este
            {
                if (Camion1E.contar()<np)
                {
                    Camion1E.apilar(vehi);
                    cout << Camion1E.contar()<<endl;
                    //Cola_zonaE.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2E.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2E.apilar(vehi);
                        cout << Camion2E.contar()<<endl;
                        //Cola_zonaE.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
            else if (almacenRandom==4)      //Zona Oeste
            {
                if (Camion1O.contar()<np)
                {
                    Camion1O.apilar(vehi);
                    cout << Camion1O.contar()<<endl;
                    //Cola_zonaO.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2O.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2O.apilar(vehi);
                        cout << Camion2O.contar()<<endl;
                        //Cola_zonaO.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< almacenRandom <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
            /*else
            {
                cout<<error<<"\n";
            }*/
        }
        cout<<"Se han movido "<< ns << " vehiculos \n";
        /**/if (Camion1N.contar()==np)
        {
            while (Camion1N.contar()!=0)
            {
                mueveVehi = Camion1N.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1N.desapilar();
                Cola_zonaN.encolar(mueveVehi);
            }
        }
        if (Camion1E.contar()==np)
        {
            while (Camion1E.contar()!=0)
            {
                mueveVehi = Camion1E.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1E.desapilar();
                Cola_zonaE.encolar(mueveVehi);
            }
        }
        if (Camion1S.contar()==np)
        {
            while (Camion1S.contar()!=0)
            {
                mueveVehi = Camion1S.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1S.desapilar();
                Cola_zonaS.encolar(mueveVehi);
            }
        }
        if (Camion1O.contar()==np)
        {
            while (Camion1O.contar()!=0)
            {
                mueveVehi = Camion1O.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1O.desapilar();
                Cola_zonaO.encolar(mueveVehi);
            }
        }
    }
}
void Gestor::cambioAlmacen(int ns, int nAlmacen, int np, int nc)        //Apartado 6
{
    Vehiculo mueveVehi;
    if (Cola_fabrica.es_vacia())
    {
        cout<<"Cola de fabrica esta vacía. \n";
    }
    else
    {
        for(int i=0; i<ns; i++)
        {
            vehi = Cola_fabrica.inicio();
            Cola_fabrica.desencolar();
            cout << vehi.verVehiculo();
            if (nAlmacen==1)           //Zona Norte
            {
                if (Camion1N.contar()<np)
                {
                    Camion1N.apilar(vehi);
                    cout << Camion1N.contar()<<endl;
                    //Cola_zonaN.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2N.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2N.apilar(vehi);
                        cout << Camion2N.contar()<<endl;
                        //Cola_zonaN.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
            else if (nAlmacen==2)       //Zona Sur
            {
                if (Camion1S.contar()<np)
                {
                    Camion1S.apilar(vehi);
                    cout << Camion1S.contar()<<endl;
                    //Cola_zonaS.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2S.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2S.apilar(vehi);
                        cout << Camion2S.contar()<<endl;
                        //Cola_zonaS.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
            else if (nAlmacen==3)       //Zona Este
            {
                if (Camion1E.contar()<np)
                {
                    Camion1E.apilar(vehi);
                    cout << Camion1E.contar()<<endl;
                    //Cola_zonaE.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2E.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2E.apilar(vehi);
                        cout << Camion2E.contar()<<endl;
                        //Cola_zonaE.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
            else if (nAlmacen==4)       //Zona Oeste
            {
                if (Camion1O.contar()<np)
                {
                    Camion1O.apilar(vehi);
                    cout << Camion1O.contar()<<endl;
                    //Cola_zonaO.encolar(vehi);
                    cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2O.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2O.apilar(vehi);
                        cout << Camion2O.contar()<<endl;
                        //Cola_zonaO.encolar(vehi);
                        cout<<"Llevados a almacen número: "<< nAlmacen <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
        }
        cout<<"Se han movido "<< ns << " vehiculos \n";
        /**/if (Camion1N.contar()==np)
        {
            while (Camion1N.contar()!=0)
            {
                mueveVehi = Camion1N.fondo();
                //mueveVehi.asignaConcesionario(nc);
                mueveVehi = asignaConcesionario2(mueveVehi, nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1N.desapilar();
                Cola_zonaN.encolar(mueveVehi);
            }
        }
        if (Camion1E.contar()==np)
        {
            while (Camion1E.contar()!=0)
            {
                mueveVehi = Camion1E.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1E.desapilar();
                Cola_zonaE.encolar(mueveVehi);
            }
        }
        if (Camion1S.contar()==np)
        {
            while (Camion1S.contar()!=0)
            {
                mueveVehi = Camion1S.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1S.desapilar();
                Cola_zonaS.encolar(mueveVehi);
            }
        }
        if (Camion1O.contar()==np)
        {
            while (Camion1O.contar()!=0)
            {
                mueveVehi = Camion1O.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion1O.desapilar();
                Cola_zonaO.encolar(mueveVehi);
            }
        }
    }
}

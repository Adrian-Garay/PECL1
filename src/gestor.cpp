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
    cout<<"  Camion 1 Norte:\n";
    Camion1N.mostrarDatos();
    cout<<"  Camion 2 Norte:\n";
    Camion2N.mostrarDatos();
    cout<<"\n";
    cout<<"Zona Sur:\n";

    Cola_zonaS.mostrarCola();
    cout<<"  Camion 1 sur:\n";
    Camion1S.mostrarDatos();
    cout<<"  Camion 2 sur:\n";
    Camion2S.mostrarDatos();
    cout<<"\n";

    cout<<"Zona Este:\n";
    Cola_zonaE.mostrarCola();
    cout<<"  Camion 1 Este:\n";
    Camion1E.mostrarDatos();
    cout<<"  Camion 2 Este:\n";
    Camion2E.mostrarDatos();
    cout<<"\n";
    cout<<"Zona Oeste:\n";

    Cola_zonaO.mostrarCola();
    cout<<"  Camion 1 Oeste:\n";
    Camion1O.mostrarDatos();
    cout<<"  Camion 2 Oeste:\n";
    Camion2O.mostrarDatos();
    cout<<"\n";
}

void Gestor::limpia_almacen()               //Apartado4
{
    if (Cola_fabrica.es_vacia())
    {
        cout<<"Cola de fabrica vac�a. \n";
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

    }
    if (Cola_fabrica.es_vacia())
    {
        cout<<"Cola de fabrica esta vac�a. \n";
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
                    cout << Camion1N.contar();
                    cout<<": Llevado a almacen n�mero: "<< almacenRandom <<"\n";
                }
                else
                {
                    if (Camion2O.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2N.apilar(vehi);
                        cout << Camion2N.contar();
                        cout<<": Llevado a almacen n�mero: "<< almacenRandom <<"\n";
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
                    cout << Camion1S.contar();
                    cout<<": Llevado a almacen n�mero: "<< almacenRandom <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2S.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2S.apilar(vehi);
                        cout << Camion2S.contar();
                        cout<<": Llevado a almacen n�mero: "<< almacenRandom <<"\n"<<"\n";
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
                    cout << Camion1E.contar();
                    cout<<": Llevado a almacen n�mero: "<< almacenRandom <<"\n";
                }
                else
                {
                    if (Camion2E.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2E.apilar(vehi);
                        cout << Camion2E.contar();
                        cout<<": Llevado a almacen n�mero: "<< almacenRandom <<"\n";
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
                    cout << Camion1O.contar();
                    cout<<": Llevado a almacen n�mero: "<< almacenRandom<<"\n";
                }
                else
                {
                    if (Camion2O.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2O.apilar(vehi);
                        cout << Camion2O.contar();
                        cout<<": Llevado a almacen n�mero: "<< almacenRandom <<"\n";
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
        if (Camion1N.contar()==np)
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
         if (Camion2N.contar()==np)
        {
            while (Camion2N.contar()!=0)
            {
                mueveVehi = Camion2N.fondo();
                mueveVehi = asignaConcesionario2(mueveVehi, nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2N.desapilar();
                Cola_zonaN.encolar(mueveVehi);
            }
        }
        if (Camion2E.contar()==np)
        {
            while (Camion2E.contar()!=0)
            {
                mueveVehi = Camion2E.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2E.desapilar();
                Cola_zonaE.encolar(mueveVehi);
            }
        }
        if (Camion2S.contar()==np)
        {
            while (Camion2S.contar()!=0)
            {
                mueveVehi = Camion2S.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2S.desapilar();
                Cola_zonaS.encolar(mueveVehi);
            }
        }
        if (Camion2O.contar()==np)
        {
            while (Camion2O.contar()!=0)
            {
                mueveVehi = Camion2O.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2O.desapilar();
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
        cout<<"Cola de fabrica esta vac�a. \n";
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
                    cout << "\nCamion1N.contar()";
                    cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n";
                }
                else
                {
                    if (Camion2N.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2N.apilar(vehi);
                        cout <<"\n Camion2N.contar()";
                        //Cola_zonaN.encolar(vehi);
                        cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n";
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
                    cout << "\n Camion1S.contar()";
                    //Cola_zonaS.encolar(vehi);
                    cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n";
                }
                else
                {
                    if (Camion2S.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2S.apilar(vehi);
                        cout << "\n Camion2S.contar()";
                        cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n";
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
                    cout <<"\n Camion1E.contar()";
                    cout<<":Llevado a almacen n�mero: "<< nAlmacen <<"\n";
                }
                else
                {
                    if (Camion2E.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2E.apilar(vehi);
                        cout << "\n Camion2E.contar()";
                        cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n";
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
                    cout << "\n Camion1O.contar()";
                    cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n";
                }
                else
                {
                    if (Camion2O.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2O.apilar(vehi);
                        cout << "\n Camion2O.contar()";
                        cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n";
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

         if (Camion2N.contar()==np)
        {
            while (Camion2N.contar()!=0)
            {
                mueveVehi = Camion2N.fondo();
                mueveVehi = asignaConcesionario2(mueveVehi, nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2N.desapilar();
                Cola_zonaN.encolar(mueveVehi);
            }
        }
        if (Camion2E.contar()==np)
        {
            while (Camion2E.contar()!=0)
            {
                mueveVehi = Camion2E.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2E.desapilar();
                Cola_zonaE.encolar(mueveVehi);
            }
        }
        if (Camion2S.contar()==np)
        {
            while (Camion2S.contar()!=0)
            {
                mueveVehi = Camion2S.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2S.desapilar();
                Cola_zonaS.encolar(mueveVehi);
            }
        }
        if (Camion2O.contar()==np)
        {
            while (Camion2O.contar()!=0)
            {
                mueveVehi = Camion2O.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2O.desapilar();
                Cola_zonaO.encolar(mueveVehi);
            }
        }
    }
}


void Gestor::cambioAlmacenRandTotal(int ns, int np, int nc)
{
    int nAlmacen;
    for (int i=1; i<=5; i++)                                //Crea los digitos aleatorios para el almacen aleatorio
    {
        nAlmacen = 1 + rand() % (4); //GENERA ALEATORIOS ENTRE 0 Y 4
        //cout << num<< "";

    }
    Vehiculo mueveVehi;
    if (Cola_fabrica.es_vacia())
    {
        cout<<"Cola de fabrica esta vac�a. \n";
    }
    else
    {while (!Cola_fabrica.es_vacia()){
        int longi= Cola_fabrica.get_longitud();
        for(int i=0; i<longi; i++)
        {
            vehi = Cola_fabrica.inicio();
            Cola_fabrica.desencolar();
            cout << vehi.verVehiculo();
            if (nAlmacen==1)           //Zona Norte
            {
                if (Camion1N.contar()<np)
                {
                    Camion1N.apilar(vehi);
                    cout <<"\n Camion1N.contar()";

                    cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2N.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2N.apilar(vehi);
                        cout << "\nCamion2N.contar()";
                        //Cola_zonaN.encolar(vehi);
                        cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
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
                    cout << "\n Camion1S.contar()";
                    //Cola_zonaS.encolar(vehi);
                    cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2S.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2S.apilar(vehi);
                        cout << "\n Camion2S.contar()";
                        //Cola_zonaS.encolar(vehi);
                        cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
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
                    cout <<"\n Camion1E.contar()";
                    cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2E.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2E.apilar(vehi);
                        cout <<"\n Camion2E.contar()";
                        cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
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
                    cout <<"\n Camion1O.contar()";
                    //Cola_zonaO.encolar(vehi);
                    cout<<": Llevado a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
                }
                else
                {
                    if (Camion2O.contar()<np)
                    {
                        cout<< "\nCamion 1 lleno, se llevan al siguiente"<<endl;
                        Camion2O.apilar(vehi);
                        cout << "\n Camion2O.contar()";
                        //Cola_zonaO.encolar(vehi);
                        cout<<": Llevados a almacen n�mero: "<< nAlmacen <<"\n"<<"\n";
                    }
                    else
                    {
                        cout<<"Camiones llenos."<<endl;
                    }
                }
            }
        }}
        cout<<"Se han movido "<< ns << " vehiculos \n";
        /**/if (Camion1N.contar()==np)
        {
            while (Camion1N.contar()!=0)
            {
                mueveVehi = Camion1N.fondo();
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

         if (Camion2N.contar()==np)
        {
            while (Camion2N.contar()!=0)
            {
                mueveVehi = Camion2N.fondo();
                mueveVehi = asignaConcesionario2(mueveVehi, nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2N.desapilar();
                Cola_zonaN.encolar(mueveVehi);
            }
        }
        if (Camion2E.contar()==np)
        {
            while (Camion2E.contar()!=0)
            {
                mueveVehi = Camion2E.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2E.desapilar();
                Cola_zonaE.encolar(mueveVehi);
            }
        }
        if (Camion2S.contar()==np)
        {
            while (Camion2S.contar()!=0)
            {
                mueveVehi = Camion2S.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2S.desapilar();
                Cola_zonaS.encolar(mueveVehi);
            }
        }
        if (Camion2O.contar()==np)
        {
            while (Camion2O.contar()!=0)
            {
                mueveVehi = Camion2O.fondo();
                mueveVehi.asignaConcesionario(nc);
                cout <<"El vehiculo final es: " <<mueveVehi.verVehiculo()<<endl;
                Camion2O.desapilar();
                Cola_zonaO.encolar(mueveVehi);
            }
        }
    }
}



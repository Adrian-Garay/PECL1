#include <iostream>
#include "include\Pila.h"
#include "include/Cola.h"
#include "vehiculo.h"
#include "gestor.h"
#include <stdlib.h>
#include <string>
#include <time.h>
#include "string.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Spanish");

    //Variables
    int menu_entrada;
    bool bucle=true;
    string error = "Operación erronea. Vuelva a intentarlo.\n";
    int nv = 20;    //Numero de coches creados
    int ns = 7;     //Numero de Coches movidos
    int nc = 5;     //Numero posible concesionarios
    int np = 10;     //Capacidad maxima de los camiones
    int nAlmacen;


    Gestor g;

    //Opciones del menú
    while(bucle)
    {
        cout<<"Indique la operación que desea realizar:\n";
        cout<<"1 -> Generar aleatoriamente la cola de automóviles disponibles en la fábrica con NV automóviles.\n";
        cout<<"2 -> Generar aleatoriamente la cola de automóviles disponibles en la fábrica solicitando NV por pantalla.\n";
        cout<<"3 -> Mostrar en pantalla los datos de la cola de automóviles disponibles en la fábrica.\n";
        cout<<"4 -> Borrar la cola de automóviles disponibles en la fábrica.\n";
        cout<<"5 -> Sacar NS automóviles del almacén de la fábrica y llevarlos a un almacén de zona aleatorio.\n";
        cout<<"6 -> Sacar NS automóviles del almacén de la fábrica y llevarlos a un almacén de zona.\n";
        cout<<"7 -> Mostrar en pantalla los datos de los almacenes de zona y registro.\n";
        cout<<"8 -> Realizar la simulación hasta finalizar los automóviles disponibles.\n";
        cout<<"0 -> Salir.\n";
        cin>>menu_entrada;

        //Primera opción
        if (menu_entrada == 1)
        {
            g.crea_vehiculos(nv);                   //genera una serie de vehículos y los mete en el almacen de la fabrica
            cout<<"\n";
        }


        //Segunda opción
        else if (menu_entrada == 2)                 //genera nv vehículos y los mete en el almacen de la fabrica
        {
            cout<<"Indique cuantos vehículos quiere generar: \n";
            cin>>nv;
            while((nv<10)||(nv>30))
            {
                cout << "Error: Debe pedir minimo 10 automoviles y como máximo 30.\n";
                cin>>nv;
            }
            g.crea_vehiculos(nv);
        }



        //Tercera opción
        else if (menu_entrada == 3)
        {

            g.muestra_almacen_fabrica();            //Muestra los automoviles almacenados en el almacen de la fabrica
            cout<<"\n";
        }


        //Cuarta opción
        else if (menu_entrada == 4)
        {
            g.limpia_almacen();                     //Borra los automoviles almacenados en el almacen de la fabrica
            cout<<"\n";
        }




        //Quinta opción
        else if (menu_entrada == 5)
        {
            //cout<<"Indique cuantos vehículos quiere eliminar: \n";
            //cin>>ns;

            if((ns<3)||(ns>8))
            {
                cout << "Error: Debe pedir minimo 3 automoviles y como máximo 8.\n";
                cin>>ns;
            }
            g.cambioAlmacenRand(ns,np,nc);

        }

        //Sexta opción
        else if (menu_entrada == 6)
        {
            cout<<"Indique cuantos vehículos quiere eliminar: \n";
            cin>>ns;
            if (ns>nv){
                cout<<"Debe ser un valor menor que "<< nv<<endl;
            }
            while((ns<3)||(ns>8))
            {
                cout << "Error: Debe pedir minimo 3 automoviles y como máximo 8.\n";
                cin>>ns;
            }
            cout<<"Indique el almacen de destino: \n";
            cin>>nAlmacen;
            while((nAlmacen<1)||(nAlmacen>4))
            {
                cout << "Error: Tiene que ser entre 1 y 4.\n";
                cin>>nAlmacen;
            }

            g.cambioAlmacen(ns,nAlmacen,np, nc);

        }

        //Septima opción
        else if (menu_entrada == 7)
        {
            cout<<"Ha elegido la séptima opción\n";

            g.muestra_zonas();
            cout<<"\n";
        }

        //Octava opción
        else if (menu_entrada == 8)
        {
            cout<<"Ha elegido la octava opción\n";
            cout<<"Ha elegido la octava opción\n";
            g.crea_vehiculos(nv);                   //genera una serie de vehículos y los mete en el almacen de la fabrica
            cout<<"\n";
            g.muestra_almacen_fabrica();            //Muestra los automoviles almacenados en el almacen de la fabrica
            cout<<"\n";
            g.cambioAlmacenRand(nv,np,nc);
            cout<<"\n";
            g.muestra_zonas();
            cout<<"\n";
        }

        //Salir del programa
        else if (menu_entrada == 0)
        {
            bucle=false;
        }

        //Texto error
        else
        {
            cout<<error<<"\n";
        }
    }


    return 0;
}


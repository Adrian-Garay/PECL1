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
    setlocale(LC_CTYPE, "Spanish");     //Mostrar caracteres exclusivos del castellano

    //Variables
    int menu_entrada;       //Variable para moverse por el menu
    bool bucle=true;        //Variable para que se ejecute el bucle siempre
    string error = "Operaci�n erronea. Vuelva a intentarlo.\n";     //Variable de error
    int nv = 20;        //Numero de coches creados
    int ns = 7;         //Numero de Coches movidos
    int nc = 5;         //Numero posible concesionarios
    int np = 10;        //Capacidad maxima de los camiones
    int nAlmacen;       //Numero del almacen
    Gestor g;       //Llamada a la clase gestor

    //Opciones del men�
    while(bucle)        //Que se ejecute el bucle hasta que se quiera salir
    {
        cout<<"Indique la operaci�n que desea realizar:\n";
        cout<<"1 -> Generar aleatoriamente la cola de autom�viles disponibles en la f�brica con NV autom�viles.\n";
        cout<<"2 -> Generar aleatoriamente la cola de autom�viles disponibles en la f�brica solicitando NV por pantalla.\n";
        cout<<"3 -> Mostrar en pantalla los datos de la cola de autom�viles disponibles en la f�brica.\n";
        cout<<"4 -> Borrar la cola de autom�viles disponibles en la f�brica.\n";
        cout<<"5 -> Sacar NS autom�viles del almac�n de la f�brica y llevarlos a un almac�n de zona aleatorio.\n";
        cout<<"6 -> Sacar NS autom�viles del almac�n de la f�brica y llevarlos a un almac�n de zona.\n";
        cout<<"7 -> Mostrar en pantalla los datos de los almacenes de zona y registro.\n";
        cout<<"8 -> Realizar la simulaci�n hasta finalizar los autom�viles disponibles.\n";
        cout<<"0 -> Salir.\n";
        cin>>menu_entrada;

        //Primera opci�n
        if (menu_entrada == 1)      //Se elige  la primera opcion
        {
            cout<<"Ha elegido la primera opci�n\n";
            cout<<"\n";

            g.crea_vehiculos(nv);       //genera una serie de veh�culos y los mete en el almacen de la fabrica
            cout<<"\n";
        }


        //Segunda opci�n
        else if (menu_entrada == 2)     //Se elige la segunda opcion
        {
            cout<<"Ha elegido la segunda opci�n\n";
            cout<<"\n";

            cout<<"Indique cuantos veh�culos quiere generar: \n";
            cin>>nv;
            while((nv<10)||(nv>30))
            {
                cout << "Error: Debe pedir minimo 10 veh�culos y como m�ximo 30.\n";
                cin>>nv;
            }
            g.crea_vehiculos(nv);       //genera una serie de veh�culos y los mete en el almacen de la fabrica
        }



        //Tercera opci�n
        else if (menu_entrada == 3)     //Se elige la tercera opcion
        {
            cout<<"Ha elegido la tercera opci�n\n";
            cout<<"\n";

            g.muestra_almacen_fabrica();            //Muestra los vehiculos almacenados en el almacen de la fabrica
            cout<<"\n";
        }


        //Cuarta opci�n
        else if (menu_entrada == 4)     //Se elige la cuarta opcion
        {
            cout<<"Ha elegido la cuarta opci�n\n";
            cout<<"\n";

            g.limpia_almacen();                     //Borra los vehiculos almacenados en el almacen de la fabrica
            cout<<"\n";
        }




        //Quinta opci�n
        else if (menu_entrada == 5)     //Se elige la quinta opcion
        {
            cout<<"Ha elegido la quinta opci�n\n";
            cout<<"Almacen de destino: \n 1:Almacen Norte \n 2:Almacen Sur  \n 3:Almacen Este \n 4:Almacen Oeste \n";
            cout<<"\n";
            if((ns<3)||(ns>8))
            {
                cout << "Error: Debe pedir minimo 3 veh�culos y como m�ximo 8.\n";
                cin>>ns;
            }
            g.cambioAlmacenRand(ns,np,nc);      //Mueve los vehiculos del almacen de fabrica a una zona aleatoria

        }

        //Sexta opci�n
        else if (menu_entrada == 6)     //Se elige la sexta opcion
        {
            cout<<"Ha elegido la sexta opci�n\n";
            cout<<"\n";

            cout<<"Indique cuantos veh�culos quiere eliminar: \n";
            cin>>ns;
            if (ns>nv){
                cout<<"Debe ser un valor menor que "<< nv<<endl;
            }
            while((ns<3)||(ns>8))
            {
                cout << "Error: Debe pedir minimo 3 veh�culos y como m�ximo 8.\n";
                cin>>ns;
                cout <<"\n";
            }
            cout<<"Indique el almacen de destino: \n 1:Almacen Norte \n 2:Almacen Sur  \n 3:Almacen Este \n 4:Almacen Oeste \n";
            cin>>nAlmacen;
            cout <<"\n";
            while((nAlmacen<1)||(nAlmacen>4))
            {
                cout << "Error: Tiene que ser entre 1 y 4.\n";
                cin>>nAlmacen;
                cout <<"\n";
            }

            g.cambioAlmacen(ns,nAlmacen,np, nc);        //Mueve los vehiculos del almacen de fabrica a una zona aleatoria

        }

        //Septima opci�n
        else if (menu_entrada == 7)     //Se elige la septima opcion
        {
            cout<<"Ha elegido la septima opci�n\n";
            cout<<"\n";

            g.muestra_zonas();      //Muestra los vehiculos almacenados en cada zona y en sus camiones asignados
            cout<<"\n";
        }

        //Octava opci�n
        else if (menu_entrada == 8)     //Se elige la octava opcion
        {
            cout<<"Ha elegido la octava opci�n\n";
            cout<<"\n";
            g.muestra_almacen_fabrica();            //Muestra los vehiculos almacenados en el almacen de la fabrica
            cout<<"------------------\n";
            g.cambioAlmacenRandTotal(ns,np,nc);     //Mueve el resto de vehiculos del almacen de fabrica a las  zonas
            cout<<"------------------\n";
            g.muestra_zonas();      //Muestra los vehiculos almacenados en cada zona y en sus camiones asignados
            cout<<"-------------------\n";
            cout << "Cola de la f�brica: \n";
            g.muestra_almacen_fabrica();        //Muestra el almacen de la fabrica
        }

        //Salir del programa
        else if (menu_entrada == 0)     //Se sale del programa
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


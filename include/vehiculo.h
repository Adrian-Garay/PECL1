#ifndef VEHICULO_H
#define VEHICULO_H
#include<string>


class Vehiculo
{
public:
    friend class Vehiculo;
    //metodos
    Vehiculo();
    ~Vehiculo();
    void cargarVehiculo(std::string nBast,std::string mod, std::string col, int conce);
    std::string devolverColor();
    std::string devolverModelo();
    std::string devolverNBastidor();
    int devolverConcesionario();
    std::string verVehiculo();
//int devolverConcesionarioAsig();
    int concesionario; //número entero entre 1 y máximo de concesionarios NC

protected:

private:
        //atributos
    std::string nBastidor;//cadena formada por 5 letras y 3 dígitos.
    std::string modelo; //se fabrican al menos 6 modelos diferentes.
    std::string color;//: se fabrican al menos 6 colores diferentes.



};

#endif // VEHICULO_H

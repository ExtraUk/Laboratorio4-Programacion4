#ifndef DTPROMO_H
#define DTPROMO_H
#include <iostream>
#include "DTFecha.h"
#include <string>
using namespace std;
#pragma once


class DTPromo {
private:
    int descuento;
    string nombre;
    string descripcion;
    DTFecha validaHasta;

public:
    DTPromo(); // falta un constructor y hay que fijarse si tiene parametros
    ~DTPromo();
    int getDescuento();
    string getNombre();
    string getDescripcion();
    DTFecha getValidaHasta();
    string toString();
};
#endif

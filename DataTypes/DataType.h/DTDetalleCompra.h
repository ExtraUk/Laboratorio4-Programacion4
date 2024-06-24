#ifndef DTDETALLECOMPRA_H
#define DTDETALLECOMPRA_H
#include <iostream>
#include <list>
#include <set>
#include "DTFecha.h"
using namespace std;
#pragma once

class DTDetalleCompra {
private:
    list<string> productos;
    int PrecioTotal;
    DTFecha FechaCompra;
public:
    DTDetalleCompra(); //hecho
    DTDetalleCompra(DTFecha fechaActual); //hecho
    void add(string producto); //hecho
    int getPrecio(); //hecho
    DTFecha getFecha(); //hecho
    list<string> getProductos(); //hecho
    void sumarPrecio(int Precio); //hrcho
    void setFecha(DTFecha fecha); //hecho
    list<string> ImprimirDetalles(); //hecho
};
#endif
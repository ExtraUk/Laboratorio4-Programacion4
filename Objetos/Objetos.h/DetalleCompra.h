#ifndef DETALLECOMPRA
#define DETALLECOMPRA
#include "../../DataTypes/DataType.h/DTFecha.h"
#include "CompraProducto.h"
#include <list>
using namespace std;
#pragma once

class DetalleCompra{
private:
    list<CompraProducto> productosComprados;
    float Precio;
    DTFecha Fecha;
public:
    void anadirCompraProducto(CompraProducto compraProd); //hecho
    void sumarPrecio(float precio); //hecho
    void setFecha(DTFecha fecha); //hecho
};

#endif
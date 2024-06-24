#ifndef CLIENTE_H
#define CLIENTE_H
#include "../../DataTypes/DataType.h/DTFecha.h"
#include "CompraProducto.h"
#include <map>
#include "Cliente.h"
#include "../../DataTypes/DataType.h/DTDetalleCompra.h"
#pragma once
class Cliente;

class Compra{
private:
    int id;
    float precioTotal;
    DTFecha fechaCompra;
    map<int, CompraProducto*>* Productos;
public:
    Compra();
    Compra(int id, map<int, CompraProducto*>* aComprar,DTDetalleCompra Detalles,Cliente * cliente);

    //busca si el producto esta en la compra
    bool perteneceCompra(int prod);

    //marca que el producto esta enviado
    void prodEnviado(int producto);

    int getId();

    DTFecha getFecha();

    map<int, CompraProducto*> getProductos();

    string toString();
};

#endif
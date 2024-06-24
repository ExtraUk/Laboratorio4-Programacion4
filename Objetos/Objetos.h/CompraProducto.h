#ifndef COMPRAPRODUCTO
#define COMPRAPRODUCTO

#include "Producto.h"

#pragma once

class CompraProducto{
private:
    int cantidad;
    bool enviado;
    Producto * producto;
public:
    //creador
    CompraProducto();

    //crea un compra-producto
    CompraProducto(int cantidad, Producto * prod);

    CompraProducto(int cantidad, Producto * prod, bool enviado);
    //destructor
    ~CompraProducto();

    //devuelve la cantidad comprada
    int getCantidad(); //hecho

    //devuelve el precio del producto
    int getPrecio(); //hecho

    //devuelve el producto
    Producto * getProducto(); //hecho

    //pone envio en true
    void envioTrue();
};

#endif
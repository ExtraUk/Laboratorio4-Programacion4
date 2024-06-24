#include "../Objetos.h/CompraProducto.h"

int CompraProducto::getCantidad()   
{
    return this->cantidad;
}

int CompraProducto::getPrecio()
{
    return this->producto->getPrecio();
}

void CompraProducto::envioTrue(){
    this->enviado = true;
}

CompraProducto::CompraProducto(int cantidad, Producto * prod)
{
    this->cantidad = cantidad;
    this->enviado = false;
    this->producto = prod;
}

CompraProducto::CompraProducto(int cantidad, Producto * prod, bool enviado)
{
    this->cantidad = cantidad;
    this->enviado = enviado;
    this->producto = prod;
}

Producto * CompraProducto :: getProducto()
{
    return this->producto;
}

CompraProducto::~CompraProducto(){}
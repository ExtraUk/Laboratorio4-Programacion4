#ifndef ICOMPRA
#define ICOMPRA

#include <iostream>
#include <list>
#include <set>
#include <string>
#include <map>
#include "../../Objetos/Objetos.h/Compra.h"
using namespace std;
#pragma once

class ICompra
{
    public:
    virtual set<Compra*> getCompras() = 0;
    virtual Compra* getCompra(int id) = 0;
    virtual set<string> listarCompras(int prod) = 0;
    virtual void marcarEnviado(int prod, int id) = 0;
    virtual DTDetalleCompra getDetalles(DTFecha fechaActual) = 0;
    virtual void ConfirmarCompra(DTDetalleCompra Detalles, Cliente* cliente) = 0;
    virtual void DescartarCompra() = 0;
    virtual map<int, CompraProducto*> getaComprar() = 0;
    virtual void AgregarCompra(Compra* compra) = 0;
};

#endif
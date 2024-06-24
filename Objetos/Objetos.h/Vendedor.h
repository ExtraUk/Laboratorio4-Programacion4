#ifndef VENDEDOR
#define VENDEDOR

#include "Producto.h"
#include "Cliente.h"
#include "Usuario.h"
#include <iostream>
#include <list>
#pragma once
using namespace std;

class Vendedor: public Usuario{
private: 
    string RUT;
    list<IObserver*> clientesSuscritos;
    set<Producto*> productos;
public:
    Vendedor(string nickname, DTFecha fechaN, string contr, string RUT);
    ~Vendedor();
    set<Producto*> getProductos();
    bool suscrito(IObserver * obs);
    void AgregarProducto(Producto* prod);
    void suscribirCliente(Cliente *cliente);
    void eliminarSuscriptor(Cliente* cliente);
    bool vendeProducto(Producto* prod);
    string toString(); //hecho
    list<IObserver*> getClientesSuscritos();
};

#endif
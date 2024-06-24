#ifndef IPRODUCTO
#define IPRODUCTO
#include <iostream>
#include <list>
#include <set>
#include <string>
#include "../../Objetos/Objetos.h/DetalleCompra.h"
#include "../../Objetos/Objetos.h/Vendedor.h"
#pragma once
using namespace std;
class DTFecha;
class DTProducto;
class DTDetalleCompra;

class ControladorProducto;

class IProducto {
    public:
        virtual Producto* NuevoProducto(string Nombre, float precio, int cantidad, string descripcion, TipoObjeto tipo) = 0;
        virtual Producto* SeleccionarProducto(int codigo) = 0;
        virtual list<string>* ListarProductos() = 0;
        virtual int CantidadProductos() = 0; //hecha
        virtual Producto * AltaProducto(int id, string nombre, string descripcion, int stock, float precio, TipoObjeto tipo, Vendedor * vendedor) = 0;
        virtual void SeleccionarMinimas(int codigo, int cantidad) = 0;
        virtual map<int, int> getMinimasSeleccionadas() = 0;
        virtual void setMinimasSeleccionadas(map<int, int> prods) = 0;
        virtual map<int, Producto*> getProductos() = 0;
};

#endif
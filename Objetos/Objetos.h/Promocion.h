#ifndef PROMOCION
#define PROMOCION

#include "../../DataTypes/DataType.h/DTFecha.h"
#include "Producto.h"
#include <iostream>
#include <list>
#include <map>
#include <set>
using namespace std;

#pragma once

class Promocion{
private:
    string nombre;
    int descuento;
    DTFecha vigencia;
    string descripcion;
    map<int, int> minimas;
    list<Producto*> Productos; 

public:
    Promocion();
    Promocion(string nombre, string descripcion, int descuento, DTFecha fecha);
    ~Promocion();
    string getNombre();
    string getDescripcion();
    DTFecha getVigencia(); //hecho
    list<Producto*> getProductos(); //hecho
    int getCantidadProducto(Producto producto); //hecho
    int getDescuento(); //hecho
    list<string> getNombreProductos(); //hecho (solo lista los nombres, pero agregar otros datos no deberia ser dificil)
    void agregarProducto(Producto * producto, int cantidad); //hecho
    void setMinimas(map<int, int> min);
    void setNombre(string nom);
    void setDescuento(int des);
    void setVigencia(DTFecha vig);
    void setDescripcion(string descr);
    void setProductos(list<Producto*> prods);
    string toString();
};

#endif
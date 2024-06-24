#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>
using namespace std;
#include "../../DataTypes/DataType.h/TipoObjeto.cpp"

#pragma once

class Producto{
private:
    int codigo;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    TipoObjeto tipo;
public:
    Producto();
    Producto(int id, string Nombre, float precio, int cantidad, string descripcion, TipoObjeto tipo);
    ~Producto();
    int getId(); //hecho
    string getNombre(); //hecho
    int getStock(); //hecho
    float getPrecio(); //hecho
    string toString();
    TipoObjeto getTipo();
    string getDescripcion();
    int getCodigo();
    void restarstock(int cantidad);
};

#endif
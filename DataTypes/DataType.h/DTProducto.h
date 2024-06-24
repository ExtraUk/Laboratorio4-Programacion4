#ifndef DTProducto_h
#define DTProducto_h
#include <iostream>
#include <string>
#include "TipoObjeto.cpp"
using namespace std;
#pragma once


class DTProducto {
private:
    int codigo;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    TipoObjeto tipo;

public:
    DTProducto(int codigo, int stock, float precio, string nombre, string descripcion, TipoObjeto tipo);
    DTProducto();
    ~DTProducto();
    int getCodigo();
    string getNombre();
    string toString();
    int getStock();
    float getPrecio();
    TipoObjeto getTipo();
    string getDescripcion();
    void setCodigo(int cod);
    void setNombre(string nom);
    void setStock(int st);
    void setPrecio(float pre);
    void setTipo(TipoObjeto tip);
    void setDescripcion(string desc);
};

#endif
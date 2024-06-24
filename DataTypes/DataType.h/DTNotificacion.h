#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H
#include "DTProducto.h"
#include <iostream>
#include <set>
#include <string>
#include <list>
using namespace std;
#pragma once


class DTNotificacion {
private:
    string nickVendedor;
    string nombrePromo;
    list<DTProducto> productos;

public:
    DTNotificacion();// falta un constructor y hay que fijarse si tiene parametros
    ~DTNotificacion();
    string getNickVendedor();
    string getNombrePromo();
    list<DTProducto> getProductos();
    string toString();
    void setNickVendedor(string nick);
    void setNombrePromo(string nomPromo);
    void setProductos(list<DTProducto> prods);
};

#endif 
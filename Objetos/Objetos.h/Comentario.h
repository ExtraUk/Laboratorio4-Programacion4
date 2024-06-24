#ifndef COMENTARIO
#define COMENTARIO
#include <iostream>
#include "Producto.h"
#include "Usuario.h"
#include "../../DataTypes/DataType.h/DTFecha.h"
#include <string>
#include <list>
using namespace std;

#pragma once


class Comentario{
private:
    int id;
    string texto;
    DTFecha fecha;
    list<Comentario*> respuestas;
    Usuario* usuario;
    Producto* producto;

public:

    Comentario(string comentario, Producto * prod, Usuario * comentador, int idComentario, DTFecha fecha1);
    ~Comentario();
    list<Comentario*> getRespuestas(); //hecho
    Usuario* getUsuario(); //hecho
    void agregarRespuesta(Comentario * respuesta); //hecho
    string getTexto();
    int getId();
    Producto* getProducto();
    list<string> getComentarios();
};

#endif
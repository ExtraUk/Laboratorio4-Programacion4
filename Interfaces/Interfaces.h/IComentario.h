#ifndef ICOMENTARIO
#define ICOMENTARIO

#include <iostream>
#include <list>
#include <set>
#include <string>
#include <map>
#include "../../Objetos/Objetos.h/Producto.h"
#include "../../Objetos/Objetos.h/Comentario.h"
using namespace std;
#pragma once

class IComentario {
    public:
        //devuelve una lista de los comentarios con sus id y sus contenidos
        virtual list<string> ListarComentariosUsuario(Usuario* usu) = 0; // hecho
        virtual void EliminarHilo() = 0;
        virtual void EliminarHilo(Comentario* respuesta) = 0;
        virtual list<string> ListarComentarios() = 0; //hecho
        virtual void Responder(string respuesta, Producto* prod, Comentario* com, DTFecha fechaActual, Usuario* comentador) = 0; // hecho 
        virtual Comentario* getComentario(int idComentario) = 0; //hecho
        virtual Comentario * ComentarioNuevo(string texto, DTFecha fecha, Producto * prod, Usuario * comentador) = 0;
        virtual list<string> Comentarios (int codigo) = 0;
        virtual Comentario* seleccionarComentario(int id) = 0;
        virtual int getcantidad() = 0;
};
#endif
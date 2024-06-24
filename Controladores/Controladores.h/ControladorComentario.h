#ifndef CONTROLADORCOMENTARIO
#define CONTROLADORCOMENTARIO

#include <iostream>
#include <list>
#include <map>
#include "../../Objetos/Objetos.h/Comentario.h"
#include "../../Objetos/Objetos.h/Usuario.h"
#include "../../Objetos/Objetos.h/Cliente.h"
#include "../../Objetos/Objetos.h/Vendedor.h"
#include "../../Interfaces/Interfaces.h/IComentario.h"
#include "../../Objetos/Objetos.h/Fabrica.h"

using namespace std;
#pragma once

class Fabrica;

class ControladorComentario: public IComentario{
private:
    static ControladorComentario * controladorComentario;
    Usuario* usuarioComentario;
    list<Cliente> clientes;
    list<Vendedor> vendedores;
    map<int,Comentario*> comentarios;
    int cantidad;
    Comentario * comentarioSeleccionado;
    ControladorComentario();
public:
    static ControladorComentario * getInstancia();

    //devuelve una lista de los comentarios con sus id y sus contenidos
    list<string> ListarComentariosUsuario(Usuario* usu); // hecho
    void EliminarHilo();
    void EliminarHilo(Comentario* respuesta);
    list<string> ListarComentarios(); //hecho

    //Responde a un comentario (falta corregir lo de la fecha actual)
    void Responder(string respuesta, Producto* prod, Comentario* com, DTFecha fechaActual, Usuario* comentador); // hecho 
    Comentario* getComentario(int idComentario); //hecho
    Comentario * ComentarioNuevo(string texto, DTFecha fecha, Producto * prod, Usuario * comentador);
    list<string> Comentarios(int codigo);
    Comentario* seleccionarComentario(int id);
    int getcantidad();
};
#endif

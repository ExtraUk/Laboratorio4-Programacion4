#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include <iostream>
#include <list>
#include <set>
#include <map>
#include "../../Objetos/Objetos.h/Comentario.h"
#include "../../DataTypes/DataType.h/DTNotificacion.h"
#include "../../DataTypes/DataType.h/DTProducto.h"
#include "../../Objetos/Objetos.h/Usuario.h"
#include "../../Objetos/Objetos.h/Cliente.h"
#include "../../Objetos/Objetos.h/Vendedor.h"
#include "../../Interfaces/Interfaces.h/IUsuario.h"
using namespace std;
#pragma once

class ControladorUsuario: public IUsuario{
private:
    static ControladorUsuario * controladorUsuario;
    map<string,Cliente*> clientes;
    map<string,Vendedor*> vendedores;
    list<Vendedor> vendedoresSeleccionados;
    string nickname;
    Cliente* cliente;
    Usuario* usuario;//va?
    Vendedor* vendedor; 
    ControladorUsuario();
public:
    //Pide el controlador de Usuarios
    static ControladorUsuario * getInstancia(); // hecha? (no habria que hacerlo con la factory?)

    //Crea un nuevo Cliente
    Cliente * NuevoCliente(string nickname, DTFecha fechaN, string contr, string dir, string city); //hecha

    //Crea un nuevo Vendedor
    Vendedor * NuevoVendedor(string nickname, DTFecha fechaN, string contr, string RUT); //hecha

    //Devuelve una lista de los vendedores en el sistema por Nickname
    list<string> ListarVendedores(); //hecha

    //Devuelve un vendedor segun el nickname
    Vendedor* getVendedor(string nickname);

    Vendedor* getVendedor();

    //Le agrega un producto a un vendedor
    void AgregarProducto(Vendedor* vend, Producto* newprod);

    //Devuelve una lista de los productos del vendedor 
    list<DTProducto> ObtenerProductosVendedor(string nickname);

    //Devuelve una lista de los nicknames de los clientes
    set<string> ListaClientes();


    //Devuelve una lista de los nickname de los usuarios
    set<string> ObtenerUsuarios(); //hecha

    void SeleccionarUsuario(string nickname); //hecha

    //lista los vendedores a los que no esta suscrito el cliente ingresado
    list<string>* ListarVendedoresNoSuscrito(string nickname); //✔

    bool SeleccionarVendedorNotificacion(string nickname); //✔

    //
    void ConfirmarSuscripcion(); //✔

    //devuelve el cliente ingresado
    Cliente* getCliente(string nickname); //hecha

    Cliente* getCliente();

    //set<DTNotificacion> ListarNotificaciones(string nickname);

    list<string>* ListarVendedoresSuscritosCliente(string nickname); //✔

    void EliminarSuscripcion(); //✔

    list<string> ListarUsuarios(); // hecha

    void SeleccionarCliente(string Nickname); //hecha

    //devuelve la cantidad de usuarios en el sistema
    int CantidadUsuarios(); //hecha

    //devuelve la cantidad de clientes en el sistema
    int CantidadClientes(); //hecha
    
    //devuelve la cantidad de vendedores en el sistema
    int CantidadVendedores();

    //devuelve la informacion del vendedor
    string InfoVendedor(DTFecha fechaActual);

    //devuelve la informacion del cliente
    string InfoCliente();

    list<DTNotificacion> ConsultaNotificaciones(string nickname);

    map<string,Cliente*> getClientes();

    Usuario* getUsuario(string nickname);

    Vendedor* SeleccionarVendedorPromo();
};

#endif
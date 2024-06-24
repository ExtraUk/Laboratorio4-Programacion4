#ifndef IUSUARIO
#define IUSUARIO

#include <iostream>
#include <list>
#include <set>
#include <string>
#include "../../Objetos/Objetos.h/Cliente.h"
#include "../../Objetos/Objetos.h/Vendedor.h"
using namespace std;
class DTProducto;
class DTVendedor;
class DTCliente;
class DTNotificacion;

class ControladorUsuario;

#pragma once

class IUsuario {
    public:
    virtual Cliente * NuevoCliente(string nickname, DTFecha fechaN, string contr, string dir, string city) = 0; //hecha

    //Crea un nuevo Vendedor
    virtual Vendedor * NuevoVendedor(string nickname, DTFecha fechaN, string contr, string RUT) = 0; //hecha

    //Devuelve una lista de los vendedores en el sistema por Nickname
    virtual list<string> ListarVendedores() = 0; //hecha

    //Devuelve un vendedor segun el nickname
    virtual Vendedor* getVendedor(string nickname) = 0;

    virtual Vendedor* getVendedor() = 0;

    //Le agrega un producto a un vendedor
    virtual void AgregarProducto(Vendedor* vend, Producto* newprod) = 0;

    //Devuelve una lista de los productos del vendedor 
    virtual list<DTProducto> ObtenerProductosVendedor(string nickname) = 0;

    //Devuelve una lista de los nicknames de los clientes
    virtual set<string> ListaClientes() = 0;

    virtual void SeleccionarCliente(string nickname) = 0; // hecha (pero guarda en usuario comentario)

    //Devuelve una lista de los nickname de los usuarios
    virtual set<string> ObtenerUsuarios() = 0; //hecha

    virtual void SeleccionarUsuario(string nickname) = 0; //hecha

    //lista los vendedores a los que no esta suscrito el cliente ingresado
    virtual list<string>* ListarVendedoresNoSuscrito(string nickname) = 0; //✔

    virtual bool SeleccionarVendedorNotificacion(string nickname) = 0; //✔

    //
    virtual void ConfirmarSuscripcion() = 0; //✔

    //devuelve el cliente ingresado
    virtual Cliente* getCliente(string nickname) = 0; //hecha

    virtual Cliente* getCliente() = 0;

    //virtual set<DTNotificacion> ListarNotificaciones(string nickname) = 0;

    virtual list<string>* ListarVendedoresSuscritosCliente(string nickname) = 0; //✔

    virtual void EliminarSuscripcion() = 0; //✔

    virtual list<string> ListarUsuarios() = 0; // hecha

    //devuelve la cantidad de usuarios en el sistema
    virtual int CantidadUsuarios() = 0; //hecha

    //devuelve la cantidad de clientes en el sistema
    virtual int CantidadClientes() = 0; //hecha

    //devuelve la cantidad de vendedores en el sistema
    virtual int CantidadVendedores() = 0;
    
    virtual map<string,Cliente*> getClientes() = 0;
    
    virtual Usuario* getUsuario(string nickname) = 0;

    virtual string InfoVendedor(DTFecha fechaActual) = 0;

    virtual string InfoCliente() = 0;
     
    virtual list<DTNotificacion> ConsultaNotificaciones(string nickname) = 0; 

    virtual Vendedor* SeleccionarVendedorPromo() = 0;
};

#endif
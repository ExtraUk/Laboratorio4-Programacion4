#ifndef COMPRA_H
#define COMPRA_H
#include "../../DataTypes/DataType.h/DTNotificacion.h"
#include "Usuario.h"
#include "../../Interfaces/Interfaces.h/IObserver.h"
#include "Compra.h"
#include <iostream>
#include <list>
#pragma once
using namespace std;

class Compra;
class DTNotificaciones;

class Cliente: public Usuario, public IObserver{
private: 
    string direccion;
    string ciudad;
    list<DTNotificacion> notificaciones;
    list<Compra*> Compras;
public:
    //creador cliente
    Cliente();

    //crea el cliente con parametros
    Cliente(string nickname, DTFecha fechaN, string contr, string dir, string city);

    //destructor cliente
    ~Cliente();

    //notificador
    void notificar(DTNotificacion notificacion);

    //lista notificaciones
    list<DTNotificacion> listarNotificaciones();

    //devuelve los datos del cliente
    string toString(); // hecho

    list<Compra*> getCompras();

    list<DTNotificacion> getNotificaciones();

    string getNickname();
};

#endif
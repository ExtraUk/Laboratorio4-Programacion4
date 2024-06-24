#include "../Objetos.h/Cliente.h"
#include "../../DataTypes/DataType.h/DTFecha.h"
#include "../Objetos.h/Compra.h"
#include "../../DataTypes/DataType.h/DTNotificacion.h"
#include <string>
#pragma once
using namespace std;

Cliente::Cliente(string nickname, DTFecha fechaN, string contr, string dir, string city){
	this->nickname = nickname;
	this->fechaNacimiento = fechaN;
	this->contrasena = contr;
	this->direccion = dir;
	this->ciudad = city;
}

string Cliente:: getNickname(){
	return this->nickname;
}

string Cliente::toString()
{
	return this->nickname + ", " + this->fechaNacimiento.toString() + ", " + this->direccion + ", " + this->ciudad;
} 

void Cliente::notificar(DTNotificacion notificacion){
	this->notificaciones.push_back(notificacion);
}

list<Compra*> Cliente::getCompras()
{
	return this->Compras;
}

list<DTNotificacion> Cliente::getNotificaciones(){
	return this->notificaciones;
}

void  Cliente :: LimpiarNotificaciones(){
	this->notificaciones.clear();
}
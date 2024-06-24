#include "../Objetos.h/Vendedor.h"
#include "../../DataTypes/DataType.h/DTFecha.h"
#include "../../Interfaces/Interfaces.h/IObserver.h"
#include <string>

Vendedor::Vendedor(string nickname, DTFecha fechaN, string contr, string RUT){
	this->nickname = nickname;
	this->fechaNacimiento = fechaN;
	this->contrasena = contr;
	this->RUT = RUT;
}

string Vendedor::getNickname(){
	return this->nickname;
} 

string Vendedor::toString(){
	return this->nickname + ", " + this->fechaNacimiento.toString() + ", " + this->RUT+ ".";
}

list<IObserver *> Vendedor::getClientesSuscritos()
{
    return clientesSuscritos;
}

bool Vendedor::suscrito(IObserver * obs){
	for(IObserver const *iObs: this->clientesSuscritos){
		if(iObs == obs) return true;
	}
	return false;
}

void Vendedor::AgregarProducto(Producto* prod){
	this->productos.insert(prod);
}

void Vendedor::suscribirCliente(Cliente* cliente){
	this->clientesSuscritos.push_back(cliente);
}

void Vendedor::eliminarSuscriptor(Cliente* cliente){
	this->clientesSuscritos.remove(cliente);
}

set<Producto*> Vendedor::getProductos(){
	return this->productos;
}

bool Vendedor::vendeProducto(Producto* prod){
	for(auto producto: this->productos){
		if(producto->getId() == prod->getId()) return true;
	}
	return false;
}

Vendedor::~Vendedor(){}

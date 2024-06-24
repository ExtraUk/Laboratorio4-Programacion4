#include "../Objetos.h/Promocion.h"
#include <set>
#include <string>
using namespace std;


Promocion::Promocion(string nombre, string descripcion, int descuento, DTFecha fecha){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->descuento = descuento;
    this->vigencia = fecha;
}

Promocion::Promocion(){}

Promocion::~Promocion(){}

list<Producto*> Promocion::getProductos() 
{
    return this->Productos;
}

int Promocion::getCantidadProducto(Producto producto){
    return this->minimas[producto.getId()];
}

DTFecha Promocion::getVigencia(){
    return this->vigencia;
}

int Promocion::getDescuento(){
    return this->descuento;
}

list<string> Promocion::getNombreProductos(){
    list<string> aDevolver;
    for (Producto *aListar :this->Productos)   
    {
        aDevolver.push_back(aListar->getNombre());
    }
    return aDevolver;
}

string Promocion::getNombre(){
    return this->nombre;
}

string Promocion::getDescripcion(){
    return this->descripcion;
}

void Promocion::agregarProducto(Producto * producto, int cantidad){
    this->Productos.push_back(producto);
    this->minimas.insert({producto->getId(), cantidad});
}

void Promocion::setMinimas(map<int, int> min)
{
    this->minimas = min;
}

void Promocion::setNombre(string nom)
{
    this->nombre = nom;
}

void Promocion::setDescuento(int des)
{
    this->descuento = des;
}

void Promocion::setVigencia(DTFecha vig)
{
    this->vigencia = vig;
}

void Promocion::setDescripcion(string descr)
{
    this->descripcion = descr;
}

void Promocion::setProductos(list<Producto *> prods)
{
    this->Productos = prods;
}

string Promocion::toString(){
    string valorRetorno = this->nombre + " " + to_string(this->descuento) +" "+ this->vigencia.toString() + " " + this->descripcion + "\n";
    for(auto i : this->Productos){
        valorRetorno += i->getNombre() + " " + to_string(this->minimas[i->getId()]) + ", ";
    }
    return valorRetorno;
}
#include "../DataType.h/DTProducto.h"
#include "../DataType.h/TipoObjeto.cpp"


DTProducto::DTProducto(int codigo, int stock, float precio, string nombre, string descripcion, TipoObjeto tipo){
  this->codigo = codigo;
  this->stock = stock;
  this->precio = precio;
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->tipo = tipo;
}

//hay que fijarse si tiene parametros

DTProducto::DTProducto() { }

DTProducto::~DTProducto() {}


string  DTProducto::getNombre() {
  return this->nombre; 
}

int DTProducto::getCodigo() {
  return this->codigo; 
}

int DTProducto::getStock() {
  return this->stock; 
}

float DTProducto::getPrecio() {
  return this->precio; 
}
string DTProducto::getDescripcion() {
    return this->descripcion;
}

void DTProducto::setCodigo(int cod)
{
  this->codigo = cod;
}

void DTProducto::setNombre(string nom)
{
  this->nombre = nom;
}

void DTProducto::setStock(int st)
{
  this->stock = st;
}

void DTProducto::setPrecio(float pre)
{
  this->precio = pre;
}

void DTProducto::setTipo(TipoObjeto tip)
{
  this->tipo = tip;
}

void DTProducto::setDescripcion(string desc)
{
  this->descripcion = desc;
}

TipoObjeto DTProducto::getTipo() {
    return this->tipo; 
}

//solo va el codigo y el nombre???????, asi esta en el diagrama
string DTProducto::toString() { 
    return this->getNombre() +" "+ to_string(this->codigo);
}



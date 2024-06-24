#include "../Objetos.h/Producto.h"
#include <sstream>
using namespace std;

static string tipoToString(TipoObjeto tipo){
    switch (tipo)
    {
    case TipoObjeto::Ropa:
        return "Ropa";
        break;
    case TipoObjeto::Electrodomestico:
        return "Electrodomestico";
        break;
    case TipoObjeto::Otro:
        return "Otro";
        break;
    default:
        return "No deberia pasar";
        break;
    }
}

Producto::Producto(){}

Producto::Producto(int id, string Nombre, float precio, int cantidad, string descripcion, TipoObjeto tipo){
    this->codigo = id;
    this->stock = cantidad;
    this->precio = precio;
    this->nombre = Nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
}

float Producto::getPrecio()   
{
    return this->precio;
}

int Producto::getId()  
{
    return this->codigo;
}

string Producto::getNombre()    
{
    return this->nombre;
}

int Producto::getStock()    
{
    return this->stock;
}

TipoObjeto Producto:: getTipo(){
    return this->tipo;
}

 string Producto:: getDescripcion(){
    return this->descripcion;
}

int Producto::getCodigo()
{
    return codigo;
}

string Producto::toString(){
    return to_string(this->codigo) + " " + this->nombre + " " + to_string(this->precio) + " " + to_string(this->stock) + " " + tipoToString(this->tipo) + " " + this->descripcion;
}

Producto::~Producto(){}

void Producto::restarstock(int cantidad){
    stock -= cantidad;
}
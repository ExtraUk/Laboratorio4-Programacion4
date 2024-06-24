#include "../DataType.h/DTNotificacion.h"
#include "../DataType.h/DTProducto.h"

//hay que fijarse si tiene parametros

DTNotificacion::DTNotificacion() { }

DTNotificacion::~DTNotificacion() {}


string DTNotificacion::getNickVendedor(){
    return this->nickVendedor;
}
string DTNotificacion::getNombrePromo(){
    return this->nombrePromo;
}
list<DTProducto> DTNotificacion::getProductos(){
    return this->productos;
}

string DTNotificacion::toString() { 
    string retornar = this->nombrePromo + " " + this->nickVendedor +" ";
    for(auto i : this->productos){
        retornar += i.getNombre() + ", ";
    }
    return retornar;
}

void DTNotificacion::setNickVendedor(string nick)
{
    this->nickVendedor = nick;
}

void DTNotificacion::setNombrePromo(string nomPromo)
{
    this->nombrePromo = nomPromo;
}

void DTNotificacion::setProductos(list<DTProducto> prods)
{
    this->productos = prods;
}
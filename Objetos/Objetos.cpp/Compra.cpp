#include "../Objetos.h/Compra.h"
#include "../Objetos.h/Cliente.h"
#include <map>


Compra::Compra(int id, map<int, CompraProducto*>* aComprar, DTDetalleCompra detalles, Cliente * cliente){
    this->id = id;
    this->fechaCompra = detalles.getFecha();
    this->precioTotal = detalles.getPrecio();
    this->Productos = aComprar;
}

Compra::Compra(){}

bool Compra::perteneceCompra(int prod){
    if(this->Productos->find(prod) != this->Productos->end()){
        return true;
    }
    else{
        return false;
    }
}

void Compra::prodEnviado(int producto){
        CompraProducto* actual = (*this->Productos)[producto];
        actual->envioTrue();
}
 
int Compra::getId(){
    return this->getId();
}

map<int, CompraProducto*> Compra::getProductos(){
    return *this->Productos;
}

DTFecha Compra::getFecha(){
    return this->fechaCompra;
}

string Compra::toString(){
    string ret = this->id + " " + this->fechaCompra.toString() + " " + "precio total: " + to_string(this->precioTotal) + "\n";
    for(auto [key, value]: *this->Productos){
        ret += value->getProducto()->toString() + ", " + to_string(value->getCantidad()) + "\n";
    }
    return ret;
}
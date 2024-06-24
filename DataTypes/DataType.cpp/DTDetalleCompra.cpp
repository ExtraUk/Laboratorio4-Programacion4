#include "../DataType.h/DTDetalleCompra.h"
#include <set>
using namespace std;

DTDetalleCompra::DTDetalleCompra(DTFecha fechaActual) {
    this->PrecioTotal = 0;
    this->FechaCompra = fechaActual;
    this->productos = new list<string>;
}

void DTDetalleCompra::add(string producto) {
    this->productos->push_back(producto);
}

int DTDetalleCompra::getPrecio() {
    return this->PrecioTotal;
}

DTFecha DTDetalleCompra::getFecha() {
    return this->FechaCompra;
}

list<string>* DTDetalleCompra::getProductos() {
    return this->productos;
}

void DTDetalleCompra::sumarPrecio(int precio) {
    this->PrecioTotal += precio;
}

void DTDetalleCompra::setFecha(DTFecha fecha) {
    this->FechaCompra = fecha;
}

set<string>* DTDetalleCompra::ImprimirDetalles() {
    set<string> *ret = new set<string>();
    for (string producto : *this->productos)  {
        ret->insert(producto + ", ");
    }
    ret->insert("fecha de compra: " + this->FechaCompra.toString());
    ret->insert("precio: " + this->PrecioTotal);
    return ret;
}
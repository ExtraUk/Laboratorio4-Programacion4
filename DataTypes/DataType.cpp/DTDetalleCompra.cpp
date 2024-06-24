#include "../DataType.h/DTDetalleCompra.h"
#include <set>
using namespace std;

DTDetalleCompra::DTDetalleCompra(DTFecha fechaActual) {
    this->PrecioTotal = 0;
    this->FechaCompra = fechaActual;
}

void DTDetalleCompra::add(string producto) {
    this->productos.push_back(producto);
}

int DTDetalleCompra::getPrecio() {
    return this->PrecioTotal;
}

DTFecha DTDetalleCompra::getFecha() {
    return this->FechaCompra;
}

list<string> DTDetalleCompra::getProductos() {
    return this->productos;
}

void DTDetalleCompra::sumarPrecio(int precio) {
    this->PrecioTotal += precio;
}

void DTDetalleCompra::setFecha(DTFecha fecha) {
    this->FechaCompra = fecha;
}

list<string> DTDetalleCompra::ImprimirDetalles() {
    list<string> ret;
    for (string producto : this->productos)  {
        ret.push_back(producto + ", ");
    }
    ret.push_back("fecha de compra: " + this->FechaCompra.toString());
    ret.push_back("precio: " + to_string(this->PrecioTotal));
    return ret;
}
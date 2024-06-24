#include "../Objetos.h/DetalleCompra.h"

void DetalleCompra::anadirCompraProducto(CompraProducto compraProd)
{
    this->productosComprados.push_back(compraProd);
}

void DetalleCompra::sumarPrecio(float precio)
{
    this->Precio += precio;
}

void DetalleCompra::setFecha(DTFecha fecha)
{
    this->Fecha = fecha;
}
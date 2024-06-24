#ifndef CONTROLADORCOMPRA
#define CONTROLADORCOMPRA
#include "../Controladores.h/ControladorProducto.h"
#include "../../DataTypes/DataType.h/DTDetalleCompra.h"
#include "../../Objetos/Objetos.h/Compra.h"
#include "../../Interfaces/Interfaces.h/ICompra.h"
#include "../../DataTypes/DataType.h/DTFecha.h"
#include <map>
#pragma once


class ControladorCompra : public ICompra{
private:
    int idactual;
    map<int,Compra*> Compras;
    Compra CompraSeleccionada;
    static ControladorCompra* controladorCompra;
    map<int, CompraProducto*> aComprar;
    ControladorCompra();
public:
    static ControladorCompra* getInstancia();

    //devuelve todas las compras
    set<Compra*> getCompras();

    Compra* getCompra(int id);

    //lista las compras del producto por código
    set<string> listarCompras(int prod);

    void marcarEnviado(int prod, int id);

    DTDetalleCompra getDetalles(DTFecha fechaActual);

    void ConfirmarCompra(DTDetalleCompra Detalle, Cliente * ClienteCompra);

    void DescartarCompra();

    map<int, CompraProducto*> getaComprar();

    void AgregarCompra(Compra* compra);

    void insertarCompraProducto(int cantidad, int idProd);
};

#endif
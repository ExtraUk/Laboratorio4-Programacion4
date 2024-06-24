#ifndef CONTROLADORPRODUCTO
#define CONTROLADORPRODUCTO
#include <iostream>
#include <list>
#include <set>
#include "../../Objetos/Objetos.h/Comentario.h"
#include "../../DataTypes/DataType.h/DTNotificacion.h"
#include "../../Objetos/Objetos.h/Usuario.h"
#include "../../Objetos/Objetos.h/Cliente.h"
#include "../../Objetos/Objetos.h/Vendedor.h"
#include "../../DataTypes/DataType.h/DTPromo.h"
#include "../../DataTypes/DataType.h/DTIdYCant.h"
#include "../../Objetos/Objetos.h/Promocion.h"
#include "../../Objetos/Objetos.h/DetalleCompra.h"
#include "../../DataTypes/DataType.h/DTProducto.h"
#include "../../Objetos/Objetos.h/Producto.h"
#include "../../Interfaces/Interfaces.h/IProducto.h"
#include <map>
using namespace std;
#pragma once

class ControladorProducto: public IProducto{
private:
    static ControladorProducto * controladorProducto;
    map<int, int> paraPromo;
    DTPromo dataPromo;
    set<Promocion> promociones;
    map<int, Producto*> productos;
    int idactual;
    list<CompraProducto> compraProductos;
    DetalleCompra detalleCompra;
    DTIdYCant SeleccionarProd;
    set<string> ListaProductoPromo;
    map<int, int> MinimasSeleccionadas;
    ControladorProducto();
public:
    //devuelve el controlador y crea uno si no existe
    static ControladorProducto * getInstancia();
    
    //crea un producto
    Producto* NuevoProducto(string Nombre, float precio, int cantidad, string descripcion, TipoObjeto tipo);
    
    //selecciona un producto y lo devuelve
    Producto* SeleccionarProducto(int codigo);

    //lista los productos por id y nombre
    list<string>* ListarProductos();

    //devuelve la cantidad de productos que hay en el sistema
    int CantidadProductos(); //hecha

    Producto * AltaProducto(int id, string nombre, string descripcion, int stock, float precio, TipoObjeto tipo, Vendedor * vendedor);

    void SeleccionarMinimas(int codigo, int cantidad);

    map<int, int> getMinimasSeleccionadas();
    
    void setMinimasSeleccionadas(map<int, int> prods);

    map<int, Producto*> getProductos();
};

#endif
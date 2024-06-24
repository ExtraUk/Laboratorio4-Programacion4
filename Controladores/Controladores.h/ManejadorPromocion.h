#ifndef MANEJADORPROMOCION
#define MANEJADORPROMOCION
#include "../../Objetos/Objetos.h/Promocion.h"
#include "../Controladores.h/ControladorProducto.h"
#include "../Controladores.h/ControladorUsuario.h"
#include "../../Interfaces/Interfaces.h/IPromocion.h"
#include "../../Objetos/Objetos.h/Fabrica.h"
#include <list>
#pragma once

class ManejadorPromocion: public IPromocion{
private:
    static ManejadorPromocion * manejadorPromocion;
    list<Promocion*> Promociones;
    Promocion* PromoSeleccionada;
    string nombreSelec;
    int descuentoSelec;
    DTFecha fechaSelec;
    string descripcionSelec;
    map<int, int> minimasSelec;
    list<Producto*> Productos;

public:
    static ManejadorPromocion * getInstancia();
    void IngresarDatosPromo(string nombre, DTFecha validaHasta, int descuento, string descripcion, map<int, int> minimas, list<Producto*> productos);
    bool PromosDisponibles(string nombre);
    list<Promocion*> ListarPromosDisponiblesPromo(DTFecha fechaActual);
    void SeleccionarPromoDisponible(string nombre);
    list<Producto*> getProductos();
    void agregarPromo(Promocion* promo);
    list<string> ListarProductosPromo();
    Promocion* getPromoSeleccionada();
    list<Promocion*> getPromociones();
    void ConfirmarPromocion();
    list<string> ListarPromosDisponibles(DTFecha fechaActual);
};

#endif
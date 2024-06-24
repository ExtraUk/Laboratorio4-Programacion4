#ifndef IPROMOCION
#define IPROMOCION
#include <set>
#include <string>
#include "../../Objetos/Objetos.h/Promocion.h"
#include <list>
using namespace std;
#pragma once

class IPromocion{
    public:
        virtual list<string> ListarProductosPromo() = 0;
        virtual void SeleccionarPromoDisponible(string nombre) = 0;
        virtual void agregarPromo(Promocion* promo) = 0;
        virtual bool PromosDisponibles(string nombre) = 0;
        virtual Promocion* getPromoSeleccionada() = 0;
        virtual list<Promocion*> getPromociones() = 0;
        virtual void IngresarDatosPromo(string nombre, DTFecha validaHasta, int descuento, string descripcion, map<int, int> minimas, list<Producto*> productos) = 0;
        virtual list<Promocion*> ListarPromosDisponiblesPromo(DTFecha fechaActual) = 0;
        virtual void ConfirmarPromocion() = 0;
        virtual list<string> ListarPromosDisponibles(DTFecha fechaActual) = 0;
        virtual bool estaEnPromocion(int id) = 0;
};
#endif
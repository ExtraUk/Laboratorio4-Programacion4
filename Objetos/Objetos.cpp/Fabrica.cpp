#include "../Objetos.h/Fabrica.h"
#include "../../Controladores/Controladores.h/ControladorUsuario.h"
#include "../../Controladores/Controladores.h/ControladorProducto.h"
#include "../../Controladores/Controladores.h/ControladorComentario.h"
#include "../../Controladores/Controladores.h/ControladorCompra.h"
#include "../../Controladores/Controladores.h/ManejadorPromocion.h"
#include "../../Interfaces/Interfaces.h/IUsuario.h"
#include "../../Interfaces/Interfaces.h/IProducto.h"

#pragma once

Fabrica::Fabrica(){}

IProducto * Fabrica::getIProducto() {
    return ControladorProducto::getInstancia();
}
IUsuario * Fabrica::getIUsuario() {
    return ControladorUsuario::getInstancia();
}
IComentario * Fabrica::getIComentario() {
    return ControladorComentario::getInstancia();
}

ICompra * Fabrica::getICompra(){
    return ControladorCompra::getInstancia();
}

IPromocion * Fabrica::getIPromocion(){
    return ManejadorPromocion::getInstancia();
}
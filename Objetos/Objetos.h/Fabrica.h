#ifndef FABRICA
#define FABRICA
#include "../../Interfaces/Interfaces.h/IComentario.h"
#include "../../Interfaces/Interfaces.h/IUsuario.h"
#include "../../Interfaces/Interfaces.h/IProducto.h"
#include "../../Interfaces/Interfaces.h/ICompra.h"
#include "../../Interfaces/Interfaces.h/IPromocion.h"

#pragma once

class Fabrica {
public:
    Fabrica();
    ~Fabrica();
    IComentario * getIComentario(); //hecho?
    IUsuario * getIUsuario(); //hecho?
    IProducto * getIProducto(); //hecho?
    ICompra * getICompra(); // falta
    IPromocion * getIPromocion();
};

#endif
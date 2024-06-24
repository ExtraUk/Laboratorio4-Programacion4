#include "ManejadorPromocion.h"
#include "DTFecha.h"
#include "DTIdYCant.h"
#include "Fabrica.h"
#include "IProducto.h"
#include "ControladorProducto.h"
#include "ControladorUsuario.h"
#include "DTNotificacion.h"
#include "IObserver.h"
#include <list>

void ManejadorPromocion :: IngresarDatosPromo(string nombre, int descuento, DTFecha vigencia, string descripcion) {
    nombreSelec = nombre;
    descuentoSelec = descuento;
    fechaSelec = vigencia;
    descripcionSelec = descripcion;
}
 
// ListarVendedores(); Lo ve porque ManejadorPromocion ve a ControladorUsuario
// ObtenerProductosVendedor(); Lo ve porque ManejadorPromocion ve a ControladorUsuario
// SeleccionarMinimas(int codigo, int cantidad); Lo ve porque ManejadorPromocion ve a ControladorProducto

void ConfirmarPromocion() {
    Promocion nuevaPromo = new Promocion();
    nuevaPromo.setNombre(nombreSelec);
    nuevaPromo.setDescuento(descuentoSelec);
    nuevaPromo.setVigencia(fechaSelec);
    nuevaPromo.setDescripcion(descripcionSelec);
    nuevaPromo.setMinimas(minimasSelec);
    nuevaPromo.setProductos(Productos);
    Promociones.insert(nuevaPromo);
    DTNotificacion noti = DTNotificacion();
    noti.setNickVendedor(nickname);
    noti.setNombrePromo(nombreSelec);
    noti.setProductos(Productos);
    for (Cliente cli : clientesSuscritos){
        notificar(noti);
    }
}



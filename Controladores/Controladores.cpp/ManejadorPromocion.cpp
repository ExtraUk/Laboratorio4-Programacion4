#include "../Controladores.h/ManejadorPromocion.h"
#include <list>

ManejadorPromocion * ManejadorPromocion::manejadorPromocion = nullptr;


static Promocion * findPromo(list<Promocion*> promociones, string nombre){
	for(auto promo: promociones){
		if(promo->getNombre() == nombre) return promo;
	}
	return nullptr;
}

ManejadorPromocion * ManejadorPromocion::getInstancia(){
	if(manejadorPromocion == nullptr){
		manejadorPromocion = new ManejadorPromocion();
	}
	return manejadorPromocion;
}

void ManejadorPromocion :: IngresarDatosPromo(string nombre, DTFecha validaHasta, int descuento, string descripcion, map<int, int> minimas, list<Producto*> productos) {
    this->nombreSelec = nombre;
    this->descuentoSelec = descuento;
    this->fechaSelec = validaHasta;
    this->descripcionSelec = descripcion;
	this->minimasSelec = minimas;
	this->Productos = productos;
}

bool ManejadorPromocion::PromosDisponibles(string nombre) {
	for (auto Promo : Promociones) {
        if(Promo->getNombre() == nombre) {
			return true;
			break;
		}
	}
	return false;
}
list<string> ManejadorPromocion::ListarPromosDisponibles(DTFecha fechaActual) {
	list<string> ListaPromo;
	for (Promocion* i : Promociones) {
        if(i->getVigencia() >= fechaActual) {
		    ListaPromo.push_back(i->getNombre()); 
		}
	}
	return ListaPromo;
}

list<Promocion*> ManejadorPromocion::ListarPromosDisponiblesPromo(DTFecha fechaActual) {
	list<Promocion*> ListaPromo;
	for (Promocion* i : Promociones) {
        if(i->getVigencia() >= fechaActual) {
		    ListaPromo.push_back(i); 
		}
	}
	return ListaPromo;
}

void ManejadorPromocion::SeleccionarPromoDisponible(string nombre) {
	PromoSeleccionada = findPromo(this->Promociones, nombre);
}

list<Producto*> ManejadorPromocion:: getProductos(){
	return Productos;
}

void ManejadorPromocion::agregarPromo(Promocion* promo){
	this->Promociones.push_back(promo);
}

list<string> ManejadorPromocion ::ListarProductosPromo() {
	list<string> ListaProductosPromo;
	for (auto prod :PromoSeleccionada->getProductos()) {
        ListaProductosPromo.push_back(prod->toString());    
	}
	return ListaProductosPromo;
}


Promocion *ManejadorPromocion::getPromoSeleccionada(){
	return PromoSeleccionada;
}

list<Promocion*> ManejadorPromocion::getPromociones(){
	return this->Promociones;
}

void ManejadorPromocion::ConfirmarPromocion() { // arreglar
    Promocion* nuevaPromo = new Promocion();
    nuevaPromo->setNombre(nombreSelec);
    nuevaPromo->setDescuento(descuentoSelec);
    nuevaPromo->setVigencia(fechaSelec);
    nuevaPromo->setDescripcion(descripcionSelec);
    nuevaPromo->setMinimas(minimasSelec);
    nuevaPromo->setProductos(Productos);
    Promociones.push_back(nuevaPromo);
    DTNotificacion noti = DTNotificacion();
	Fabrica* fab = new Fabrica();
	string nickven;
	for (string v : fab->getIUsuario()->ListarVendedores()){
		Vendedor* ven = fab->getIUsuario()->getVendedor(v);
		if(ven->vendeProducto(*Productos.begin())){
			nickven = ven->getNickname();
			break;
		}
	}
    noti.setNickVendedor(nickven);
    noti.setNombrePromo(nombreSelec);
	list<DTProducto> prods;
	for (Producto* p : Productos){
		DTProducto prod = *new DTProducto();
		prod.setNombre(p->getNombre());
		prod.setCodigo(p->getCodigo());
		prod.setDescripcion(p->getDescripcion());
		prod.setPrecio(p->getPrecio());
		prod.setStock(p->getStock());
		prod.setTipo(p->getTipo());
		prods.push_back(prod);
	}
    noti.setProductos(prods);
	Vendedor* vendedor = fab->getIUsuario()->getVendedor(nickven);
    for (IObserver* cli : vendedor->getClientesSuscritos()){
        cli->notificar(noti);
    }
}
#include "../Controladores.h/ControladorCompra.h"
#include "../Controladores.h/ControladorProducto.h"
#include "../../Objetos/Objetos.h/Fabrica.h"
#include <string>
#include <map>

ControladorCompra * ControladorCompra::getInstancia(){
	if(controladorCompra == nullptr){
		controladorCompra = new ControladorCompra();
	}
    return controladorCompra;
}

ControladorCompra * ControladorCompra::controladorCompra = nullptr;

ControladorCompra::ControladorCompra(){
    idactual = 0;
}

set<Compra*> ControladorCompra::getCompras()
{
    set<Compra*> aDevolver;
    for(auto const& [key, val] : this->Compras){
        aDevolver.insert(val);
    }
    return aDevolver;
}

Compra* ControladorCompra::getCompra(int id){
    if(this->Compras.find(id) != this->Compras.end()){
        return this->Compras[id];
    }
    else{
        return nullptr;
    }
}

set<string> ControladorCompra::listarCompras(int prod){
    set<string> aDevolver;
    for(auto const& [key, val] : this->Compras){
        if(val->perteneceCompra(prod)){
            aDevolver.insert(to_string(val->getId()) + ": " + val->getFecha().toString());
        }
    }
    return aDevolver;
}

void ControladorCompra::marcarEnviado(int prod, int id){
        Compra* actual = this->Compras[id];
        actual->prodEnviado(prod);
}

DTDetalleCompra ControladorCompra::getDetalles(DTFecha fechaActual){
    Fabrica * fab = new Fabrica();
    IPromocion * manejadorPromocion = fab->getIPromocion();
    IProducto * controladorProducto = fab->getIProducto();
    bool seCumple;
    CompraProducto * CompraProd;
    DTDetalleCompra aDevolver = DTDetalleCompra(fechaActual);
    map<int, CompraProducto*> agregados;
    for (Promocion* promo :manejadorPromocion->getPromociones())
    {
        if (promo->getVigencia() >= fechaActual)
        {
            seCumple = true;
            for(Producto* prod :promo->getProductos())
            {
                if (aComprar.find(prod->getId()) == aComprar.end())
                {
                    seCumple = false;
                    break;
                }else
                {
                    CompraProd = aComprar[prod->getId()];
                    seCumple = (seCumple && CompraProd->getCantidad() >= promo->getCantidadProducto(*prod));
                }
            }
            if(seCumple)
            {
                cout << to_string(promo->getDescuento()/100.0) << endl;
                for(Producto* prod :promo->getProductos())   
                {
                    CompraProd = aComprar[prod->getId()];
                    aDevolver.getProductos().push_back(prod->getNombre() + ": " + to_string(CompraProd->getCantidad()) + ", $" + to_string((CompraProd->getCantidad()*CompraProd->getPrecio()*(1.0-(promo->getDescuento()/100.0)))));
                    aDevolver.sumarPrecio(CompraProd->getCantidad()*CompraProd->getPrecio()*(1.0-(promo->getDescuento()/100.0)));
                    agregados.insert({prod->getId(), CompraProd});
                    aComprar.erase(prod->getId());
                }
            }
        }
    }
    for (auto const& [key, val] :aComprar)
    {
        CompraProducto * actual = val;
        aDevolver.sumarPrecio(actual->getCantidad() * actual->getPrecio());
        aDevolver.getProductos().push_back(actual->getProducto()->getNombre() + ": " + to_string(actual->getCantidad()) + ", $" + to_string(CompraProd->getCantidad()*CompraProd->getPrecio()));
        agregados.insert({key, val});
        aComprar.erase(key);
    }
    aComprar = agregados;
    return aDevolver;
}


void ControladorCompra :: ConfirmarCompra(DTDetalleCompra Detalles,Cliente *ClienteCompra)
{
    idactual++;
    Compra * nuevo = new Compra(this->idactual,&this->aComprar, Detalles, ClienteCompra);
    for (auto const& [key, val] :aComprar)
    {
        cout << to_string(key) << endl;
        val->getProducto()->restarstock(val->getCantidad());
    }
    Compras.insert({idactual,nuevo});
    DescartarCompra();
}

void ControladorCompra::DescartarCompra(){
    for(auto const& [key, val] :aComprar)
    {
        delete val;
    }
    aComprar.clear();
}

map<int, CompraProducto*> ControladorCompra :: getaComprar()
{
    return this->aComprar;
}

void ControladorCompra::insertarCompraProducto(int cantidad, int idProd){
    Fabrica * fab = new Fabrica();
    this->aComprar.insert({idProd, new CompraProducto(cantidad, fab->getIProducto()->SeleccionarProducto(idProd), false)});
}

void ControladorCompra::AgregarCompra(Compra* compra){
    this->idactual++;
    this->Compras.insert({idactual, compra});
}
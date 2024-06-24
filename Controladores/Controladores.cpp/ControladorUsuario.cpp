#include "../Controladores.h/ControladorUsuario.h"
#include "../Controladores.h/ManejadorPromocion.h"
#include "../../Objetos/Objetos.h/Fabrica.h"
#include "../../Objetos/Objetos.h/Compra.h"
#include "../../Objetos/Objetos.h/CompraProducto.h"
#include "../../Objetos/Objetos.h/Vendedor.h"
using namespace std;

Fabrica* fab = new Fabrica();

ControladorUsuario* ControladorUsuario::controladorUsuario;

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario * ControladorUsuario::getInstancia(){
	if(controladorUsuario == nullptr){
		controladorUsuario = new ControladorUsuario();
	}
	return controladorUsuario;
}

list<string> ControladorUsuario::ListarVendedores(){
	list<string> lista;
	for(auto const& [key, val] : vendedores){
		lista.push_back(val->getNickname());
	}
	return lista;
}

Vendedor* ControladorUsuario::getVendedor(string nickname){
	if(vendedores.find(nickname) != vendedores.end()){
		Vendedor* vende = vendedores[nickname];
		return vende;
	}
	else{
		return nullptr;
	}
}

void ControladorUsuario::AgregarProducto(Vendedor* vend, Producto* newprod){
	vend->AgregarProducto(newprod);
}

list<DTProducto> ControladorUsuario::ObtenerProductosVendedor(string nickname){
    list<DTProducto> ret;
	//int codigo, int stock, float precio, string nombre, string descripcion, TipoObjeto tipo
	Vendedor* v = vendedores[nickname];
	for(auto prod: v->getProductos()){
		ret.push_back(DTProducto(prod->getId(), prod->getStock(), prod->getPrecio(), prod->getNombre(), prod->getDescripcion(), prod->getTipo()));
	}
	return ret;
}

set<string> ControladorUsuario::ListaClientes(){
	set<string> aDevolver;
	for(auto const& [key, val] : clientes){;
		aDevolver.insert(key);
	}
	return aDevolver;
}

set<string> ControladorUsuario::ObtenerUsuarios()
{
	set<string> aDevolver;
	for(auto const& [key, val] : clientes){;
		aDevolver.insert(key);
	}
	for(auto const& [key, val] : vendedores){;
		aDevolver.insert(key);
	}
	return aDevolver;
}

void ControladorUsuario::SeleccionarUsuario(string nickname) {
	this->vendedor = nullptr;
	this->cliente = nullptr;
	if(getVendedor(nickname) != nullptr){
		this->vendedor = getVendedor(nickname);
	}else{
        this->cliente = getCliente(nickname);
    }
	
}

void ControladorUsuario::SeleccionarCliente(string nickname) {
	this->cliente = nullptr;
	if(getCliente(nickname) != nullptr){
		this->cliente = getCliente(nickname);
	}
	else{
		this->cliente = nullptr;
	}
}

Cliente * ControladorUsuario::getCliente(){
	return this->cliente;
}

list<string>* ControladorUsuario::ListarVendedoresNoSuscrito(string nickname){
	try{
		this->vendedoresSeleccionados.clear();
		list<string>* ret = new list<string>();
		if(this->clientes.find(nickname) == this->clientes.end()) return nullptr;
		this->cliente = this->clientes[nickname];
		for(auto [key,value]: this->vendedores){
			bool noSuscrito = !value->suscrito(this->cliente);
			if(noSuscrito){
				string nick = value->getNickname();
				ret->push_back(nick);
			}
		}
		return ret;
	}
	catch(...){
		return nullptr;
	}
}

bool ControladorUsuario::SeleccionarVendedorNotificacion(string nickname){
	try{
		if(this->vendedores.end() != this->vendedores.find(nickname)){
			for(auto vend: this->vendedoresSeleccionados){
				if(vend->getNickname() == nickname) return false;
			}
			this->vendedoresSeleccionados.push_back(this->vendedores[nickname]);
			return true;
		}
		else{
			return false;
		}
	}
	catch(...){
		return false;
	}
}

void ControladorUsuario::ConfirmarSuscripcion(){
	Cliente* cliente = this->cliente;
	for(auto vendedor: this->vendedoresSeleccionados){
		vendedor->suscribirCliente(cliente);
	}
	this->vendedoresSeleccionados.clear();
}

Cliente * ControladorUsuario::getCliente(string nickname)	
{
	if(clientes.find(nickname) != clientes.end()){
		return clientes[nickname];
	}
	else{
		return nullptr;
	}
}

list<string>* ControladorUsuario::ListarVendedoresSuscritosCliente(string nickname){
	try{
		this->vendedoresSeleccionados.clear();
		list<string>* ret = new list<string>;
		if(this->clientes.find(nickname) == this->clientes.end()) return nullptr;
		this->cliente = this->clientes[nickname];
		for(auto [key,value]: this->vendedores){
			bool suscrito = value->suscrito(this->cliente);
			if(suscrito){
				string nick = value->getNickname();
				ret->push_back(nick);
			}
		}
		return ret;
	}
	catch(...){
		return nullptr;
	}
}

Vendedor* ControladorUsuario::getVendedor(){
	return this->vendedor;
};

void ControladorUsuario::EliminarSuscripcion(){
	Cliente* cliente = this->cliente;
	for(Vendedor* vendedor: this->vendedoresSeleccionados){
		vendedor->eliminarSuscriptor(cliente);
	}
	this->vendedoresSeleccionados.clear();
}

list<string> ControladorUsuario::ListarUsuarios(){
	list<string> ListUsuarios;
	for(auto const& [key,val]: this->clientes){
		ListUsuarios.push_back(val->getNickname());
	}
	for(auto const& [key,val]: this->vendedores){
		ListUsuarios.push_back(val->getNickname());
	}
	return ListUsuarios;
}

int ControladorUsuario::CantidadUsuarios()
{
	return this->clientes.size() + this->vendedores.size();
}

int ControladorUsuario::CantidadClientes()
{
	return this->clientes.size();
}

int ControladorUsuario::CantidadVendedores()
{
	return this->vendedores.size();
}

Cliente * ControladorUsuario::NuevoCliente(string nombre, DTFecha fecha, string contrasna, string calle, string ciudad){
	if ((clientes.find(nombre) == clientes.end()) && (vendedores.find(nombre) == vendedores.end())){
		Cliente * client = new Cliente(nombre, fecha, contrasna, calle, ciudad);
		this->clientes.insert({nombre, client});
		cout << "el cliente " << nombre << " fue ingresado" << endl;
		return client;
	}
	else{
		cout << "ya existe un usuario con el nickname ingresado";
	}
}

Vendedor * ControladorUsuario::NuevoVendedor(string nombre, DTFecha fecha, string contrasna,string RUT){
	if ((clientes.find(nombre) == clientes.end()) && (vendedores.find(nombre) == vendedores.end())){
		Vendedor * vend = new Vendedor(nombre, fecha, contrasna, RUT);
		vendedores.insert({nombre,vend});
		cout << "el vendedor " << nombre << " fue ingresado" << endl;
		return vend;
	}
	else{
		cout << "ya existe un usuario con el nickname ingresado";
	}
}

string ControladorUsuario::InfoVendedor(DTFecha fechaActual){
	string infoVendedor = "Productos: ";
	for(auto producto: vendedor->getProductos()){
		infoVendedor += producto->toString() + "\n";
	}
	infoVendedor = "Promociones: ";
	for(auto promo: fab->getIPromocion()->ListarPromosDisponiblesPromo(fechaActual)){
		Producto* prod = *promo->getProductos().begin();
		for(auto [key, value] : vendedores){
			if(value->vendeProducto(prod)){
				infoVendedor = infoVendedor + promo->toString() + "\n";  
			}
		}
	}
	infoVendedor = "Informacion del Vendedor " + this->vendedor->toString() + "\n" + infoVendedor;
    return infoVendedor;
}


string ControladorUsuario::InfoCliente(){  
    string infoCliente = "Compras Realizadas: ";
	for(auto comp : cliente->getCompras()){
		infoCliente = infoCliente + comp->toString() + "\n";
	}
	infoCliente = "Informacion del Cliente: " + this->cliente->toString() + "\n" + infoCliente;
    return infoCliente;
}


list<DTNotificacion> ControladorUsuario :: ConsultaNotificaciones(string nickname){ 
	cliente  = clientes[nickname];
    list<DTNotificacion> lista = cliente->getNotificaciones();
    cliente->getNotificaciones().clear();
    return lista;    
}
void ControladorUsuario :: LimpiarNotificaciones(){
	cliente->getNotificaciones().clear();
}


map<string,Cliente*> ControladorUsuario::getClientes()
{
	return this->clientes;
}

Usuario* ControladorUsuario::getUsuario(string nickname){
	if(this->vendedores.find(nickname) != this->vendedores.end()){
		return dynamic_cast<Usuario*>(this->vendedores[nickname]);
	}
	else if(this->clientes.find(nickname) != this->clientes.end()){
		return dynamic_cast<Usuario*>(this->clientes[nickname]);
	}
	else{
		return nullptr;
	}
}


Vendedor* ControladorUsuario::SeleccionarVendedorPromo(){
	Producto* prod = *fab->getIPromocion()->getPromoSeleccionada()->getProductos().begin();
	for(auto [key, value]: vendedores){
		if(value->vendeProducto(prod)){
			vendedor = value;
		}
	}
	return vendedor;
}


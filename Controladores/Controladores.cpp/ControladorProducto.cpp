#include "../Controladores.h/ControladorProducto.h"
#include <string>

ControladorProducto::ControladorProducto(){
	this->idactual = 16;
}

ControladorProducto * ControladorProducto::controladorProducto = nullptr;

ControladorProducto * ControladorProducto::getInstancia(){
	if(controladorProducto == nullptr){
		controladorProducto = new ControladorProducto();
	}
	return controladorProducto;
}

Producto* ControladorProducto::NuevoProducto(string Nombre, float precio, int cantidad, string descripcion, TipoObjeto tipo){
	int id = this->idactual + 1;
	Producto* newprod = new Producto(id, Nombre, precio, cantidad, descripcion, tipo);
	this->productos.insert({id,newprod});
	this->idactual = id;
	return newprod;
}

Producto* ControladorProducto::SeleccionarProducto(int codigo){
	if(this->productos.find(codigo) != this->productos.end()){
		return this->productos[codigo];
	}
	else{
		return nullptr;
	}
}

list<string> ControladorProducto ::ListarProductos(){ //Si se arregla esto se arregla todo
	list<string> aDevolver;
	for(auto const&[key, val] : productos)
	{
		Producto* actual = val;
		aDevolver.push_back((to_string(val->getId())+ ": " + actual->getNombre() + ", " + to_string(val->getStock()) + " en stock"));
	}
	return aDevolver;
}



int ControladorProducto ::CantidadProductos()
{
	return productos.size();
}

Producto * ControladorProducto::AltaProducto(int id, string nombre, string descripcion, int stock, float precio, TipoObjeto tipo, Vendedor * vendedor) {
	Producto * nuevo = new Producto(id, nombre, precio, stock, descripcion, tipo);
	vendedor->AgregarProducto(nuevo);
	productos.insert({nuevo->getId(), nuevo});
	return nuevo;
}

void ControladorProducto::SeleccionarMinimas(int codigo, int cantidad)
{
	MinimasSeleccionadas.insert({codigo, cantidad}); // no se si es asi
}

map<int, int> ControladorProducto::getMinimasSeleccionadas()
{
    return MinimasSeleccionadas;
}

void ControladorProducto::setMinimasSeleccionadas(map<int, int> prods)
{
    MinimasSeleccionadas = prods;
}

map<int,Producto*> ControladorProducto::getProductos()
{
	return this->productos;
}
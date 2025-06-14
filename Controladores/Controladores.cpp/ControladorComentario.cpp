#include "../Controladores.h/ControladorComentario.h"


ControladorComentario::ControladorComentario(){
	this->cantidad = 25;
}

ControladorComentario * ControladorComentario::controladorComentario = nullptr;

ControladorComentario * ControladorComentario::getInstancia(){
	if(controladorComentario == nullptr){
		controladorComentario = new ControladorComentario();
	}
	return controladorComentario;
}

list<string> ControladorComentario::ListarComentariosUsuario(Usuario* usu)
{
    list<string> ret;
	for (auto const&[key,val] : this->comentarios) {
		if (val->getUsuario()->getNickname() == usu->getNickname()){
			ret.push_back(to_string(val->getId()) + ": " + val->getTexto());
		}
	}
	return ret;
}

list<string> ControladorComentario::ListarComentarios()
{
	list<string> aDevolver; 
	Fabrica * fab = new Fabrica();
	IProducto * controladorProd = fab->getIProducto();
	for (auto [key, val] : comentarios)
	{
		aDevolver.push_back(to_string(val->getId()) + ":" + val->getTexto());
	}
	return aDevolver;
}

void ControladorComentario::EliminarHilo()
{
	for (Comentario* res : comentarioSeleccionado->getRespuestas()){
		EliminarHilo(res);
	}
	this->comentarios.erase(comentarioSeleccionado->getId());
	delete comentarioSeleccionado; 
}

void ControladorComentario::EliminarHilo(Comentario* respuesta)
{
	for (Comentario* res : respuesta->getRespuestas()){
		EliminarHilo(res);
	}
	this->comentarios.erase(respuesta->getId());
	delete respuesta;
}

void ControladorComentario::Responder(string respuesta, Producto* prod, Comentario* com, DTFecha fechaActual,Usuario* comentador)
{
	Fabrica * fab = new Fabrica();
	this->cantidad += 1;
	Comentario *nuevo = new Comentario(respuesta, prod, comentador, this->cantidad,fechaActual);

	this->comentarios.insert({this->cantidad,nuevo});
	com->agregarRespuesta(nuevo);
}



Comentario* ControladorComentario::getComentario(int idComentario){
	if(this->comentarios.find(idComentario) != this->comentarios.end()){
		return this->comentarios[idComentario];
	}
	else{
		return nullptr;
	}
}

Comentario * ControladorComentario::ComentarioNuevo(string texto, DTFecha fecha, Producto * prod, Usuario * comentador) {
	this->cantidad++;
	Comentario * nuevo = new Comentario(texto, prod, comentador, this->cantidad, fecha);
	this->comentarios.insert({this->cantidad,nuevo});
	return nuevo;
}

list<string> ControladorComentario::Comentarios(int codigo)
{
	cout << "cuack" << endl;
	list<string> aDevolver;
	for(auto const&[key,val]:this->comentarios)
	{
		cout << val->getTexto() << endl;
		if (val->getProducto()->getCodigo() == codigo)
		{
			cout << to_string(val->getId()) + ": " + val->getTexto() << endl;
			aDevolver.push_back(to_string(val->getId()) + ": " + val->getTexto());
		}
	}
	return aDevolver;
}

Comentario* ControladorComentario::seleccionarComentario(int id)
{
	for (auto const&[key,val] : this->comentarios){
		if(key == id){
			comentarioSeleccionado = val;
			break;
		}
	}
	return comentarioSeleccionado;
}

int ControladorComentario::getcantidad(){
	return this->cantidad;
}

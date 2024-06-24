#include "../Controladores.h/ControladorComentario.h"


ControladorComentario::ControladorComentario(){}

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
			ret.push_back(val->getId() + ":" + val->getTexto());
		}
	}
	return ret;
}

list<string> ControladorComentario::ListarComentarios()
{
	/*set<string> aDevolver; 
	Fabrica * fab = new Fabrica();
	IProducto * controladorProd = fab->getIProducto();
	for (Comentario comentario : this->comentarios)
	{
		if (comentario.getProducto() == controladorProd.getProdSeleccionado())
		{
			aDevolver.add(comentario.getId() + ":" + comentario.getTexto());
		}
	}
	return aDevolver;*/
	list<string> aDevolver;
	return aDevolver;
}

void ControladorComentario::EliminarHilo()
{
	for (Comentario* res : comentarioSeleccionado->getRespuestas()){
		EliminarHilo(res);
	}
	delete comentarioSeleccionado; 
}

void ControladorComentario::EliminarHilo(Comentario* respuesta)
{
	for (Comentario* res : respuesta->getRespuestas()){
		EliminarHilo(res);
		delete respuesta;
	}
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
	list<string> aDevolver;
	Fabrica * fab = new Fabrica();
	for(auto const&[key,val]:this->comentarios)
	{
		if (val->getProducto() == fab->getIProducto()->SeleccionarProducto(codigo))
		{
			aDevolver.push_back(to_string(val->getId()) + val->getTexto());
		}
	}
	return aDevolver;
}

void ControladorComentario::seleccionarComentario(int id)
{
	for (auto const&[key,val] : this->comentarios){
		if(key == id){
			comentarioSeleccionado = val;
			break;
		}
	}
}

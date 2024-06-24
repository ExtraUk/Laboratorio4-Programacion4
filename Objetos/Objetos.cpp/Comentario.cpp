#include "../Objetos.h/Comentario.h"


Comentario::Comentario(string comentario, Producto* prod, Usuario* comentador, int cantidad, DTFecha fecha1)
{
	this->texto = comentario;
	this->producto = producto;
	this->usuario = comentador;
	this->fecha = fecha1;
	this->id = cantidad;
}
 
void Comentario::agregarRespuesta(Comentario* respuesta)
{
	this->respuestas.push_back(respuesta);
}

string Comentario::getTexto()
{
    return this->texto;
}

int Comentario::getId()
{
    return this->id;
}

list<Comentario*> Comentario::getRespuestas()	
{
	return this->respuestas;
}

Usuario* Comentario::getUsuario()	
{
	return this->usuario;
}

Producto* Comentario::getProducto()
{
	return this->producto;
}

list<string> Comentario::getComentarios(){
	list<string> comments;
	for(Comentario* &i: this->respuestas){
		comments.push_back(to_string(i->getId()) + i->getTexto());
	}
	return comments;
}

Comentario::~Comentario(){}
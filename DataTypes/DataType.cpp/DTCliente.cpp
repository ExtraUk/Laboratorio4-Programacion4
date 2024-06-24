#include "../DataType.h/DTCliente.h"
#include "../DataType.h/DTUsuario.h"

//hay que fijarse si va uno con parametros

DTCliente::DTCliente() { }

DTCliente::~DTCliente() {}

string DTCliente::toString(){ 
    return this->getNickname() + " " + this->ciudad + " " + this->direccion; }
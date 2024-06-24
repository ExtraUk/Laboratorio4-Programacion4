#include "../DataType.h/DTVendedor.h"
#include "../DataType.h/DTUsuario.h"
//hay que fijarse si va usuario.h


//hay que fijarse si lleva parametros 

DTVendedor::DTVendedor() { }

DTVendedor::~DTVendedor() {}

string  DTVendedor::getRut() {
    return this->rut; 
}

string DTVendedor::toString() { 
    return this->getNickname() + " " + this->rut;
}
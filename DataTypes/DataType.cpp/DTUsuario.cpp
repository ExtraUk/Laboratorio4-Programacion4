#include "../DataType.h/DTUsuario.h"


//hay que fijarse si pasa por parametros

DTUsuario::DTUsuario() { }

DTUsuario::~DTUsuario() {}

string  DTUsuario::getNickname() {
    return this->nickname; 
}

string DTUsuario::toString() { 
    return this->getNickname();
}
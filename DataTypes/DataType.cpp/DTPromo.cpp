#include "../DataType.h/DTPromo.h"
#include "../DataType.h/DTFecha.h"


//hay que fijarse si tiene parametros

DTPromo::DTPromo() { }

DTPromo::~DTPromo() {}

string  DTPromo::getNombre() {
    return this->nombre; 
}

int DTPromo::getDescuento() {
    return this->descuento; 
}

string DTPromo::getDescripcion() {
    return this->descripcion;
}
DTFecha DTPromo::getValidaHasta() {
    return this->validaHasta;
}

string DTPromo::toString() { 
    return this->nombre +" "+ this->descripcion + " " + this->getValidaHasta().toString()+ " " + to_string(this->getDescuento());
}
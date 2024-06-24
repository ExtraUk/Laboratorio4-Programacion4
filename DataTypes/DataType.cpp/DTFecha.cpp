#include "../DataType.h/DTFecha.h"
#include <string>

DTFecha::DTFecha(int pDia, int pMes, int pAnio) {
    this->dia = pDia;   
    this->mes = pMes;   
    this->anio = pAnio; 
}

DTFecha::DTFecha() {}

DTFecha::~DTFecha() {}

int DTFecha::getDia() {
    return this->dia; 
}

int DTFecha::getMes() {
    return this->mes; 
}

int DTFecha::getAnio() {
    return this->anio;
}

void DTFecha::setDia(int Dia) {
    this->dia = Dia;
}

void DTFecha::setMes(int Mes) {
    this->mes = Mes;
}

void DTFecha::setAnio(int Anio) {
    this->anio = Anio;
}

string DTFecha::toString() {
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio); 
}

void DTFecha::mostrarFecha() {// va aca?
    cout << this->dia << "/" << this->mes << "/" << this->anio << endl; 
}
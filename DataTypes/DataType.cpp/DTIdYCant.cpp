#include "../DataType.h/DTIdYCant.h"

DTIdYCant::DTIdYCant(int id, int cant) {
    this->id = id;
    this->cant = cant;
}

DTIdYCant::DTIdYCant() {}

int DTIdYCant::getId() {
    return this->id;
}

int DTIdYCant::getCant() {
    return this->cant;
}

void DTIdYCant::setId(int ID) {
    this->id = ID;
}

void DTIdYCant::setCant(int CANT) {
    this->cant = CANT;
}
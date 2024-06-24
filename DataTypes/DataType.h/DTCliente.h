#ifndef DTCliente_h
#define DTCliente_h
#include <iostream>
#include "DTUsuario.h"
using namespace std;
#pragma once


class DTCliente : public DTUsuario {
private:
    string direccion;
    string ciudad; 
public:
    DTCliente();
    ~DTCliente();
    string toString();
};
#endif


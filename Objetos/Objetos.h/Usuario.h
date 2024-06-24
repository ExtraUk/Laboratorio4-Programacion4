#ifndef USUARIO
#define USUARIO
#include "../../DataTypes/DataType.h/DTFecha.h"
#include <iostream>
using namespace std;

#pragma once

class Usuario {
protected:
    string nickname;
    DTFecha fechaNacimiento;
    string contrasena;

public:
    Usuario();

    //te da el nickname del usuario
    string getNickname(); //hecho

    virtual string toString() = 0; 
};

#endif
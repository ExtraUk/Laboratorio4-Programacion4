#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <iostream>
#include "DTFecha.h"
using namespace std;
#pragma once


class DTUsuario {
private:
    string nickname;
    DTFecha fechaNacimiento;
    string contrasena;

public:
    DTUsuario();
    ~DTUsuario();
    string getNickname();
    string toString();
};

#endif

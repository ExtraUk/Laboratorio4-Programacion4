#ifndef DTVendedor_h
#define DTVendedor_h
#include <iostream>
#include "DTUsuario.h"
using namespace std;
#pragma once


class DTVendedor: public DTUsuario {
private:
    string rut; 
public:
    DTVendedor();
    ~DTVendedor();
    string getRut();
    string toString();
};
#endif

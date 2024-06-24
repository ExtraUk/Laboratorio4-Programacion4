#ifndef DTIDYCANT_H
#define DTIDYCANT_H

#include <iostream>
using namespace std;
#pragma once 
// preguntar por que

class DTIdYCant {
private:
    int cant, id;
public:
    DTIdYCant(int id, int cant); //hecho
    DTIdYCant();
    int getId(); //hecho
    int getCant(); //hecho
    void setId(int ID); //hecho
    void setCant(int CANT); //hecho
};
#endif
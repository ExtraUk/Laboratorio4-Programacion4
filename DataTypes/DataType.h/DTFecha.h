#ifndef DTFecha_h
#define DTFecha_h
#include <iostream>
using namespace std;
#pragma once

class DTFecha {
private:
    int dia, mes, anio;

public:
    DTFecha(int dia, int mes, int anio); //hecho
    DTFecha(); 
    ~DTFecha();
    int getDia(); //hecho
    int getMes(); //hecho
    int getAnio(); //hecho
    void setDia(int Dia); //hecho
    void setMes(int Mes); //hecho
    void setAnio(int Anio); //hecho

    //devuelve los datos de la fecha en un string
    string toString(); //hecho

    //imprime la fecha
    void mostrarFecha(); //hecho

    //devuelve un booleano con la fecha si es mayor que la primera
    bool operator>=(const DTFecha &fecha2) const
    {
        if (anio != fecha2.anio)
        {
            return (anio > fecha2.anio);
        }
        else if (mes != fecha2.mes)
        {
            return (mes > fecha2.mes);
        }
        else if (dia >= fecha2.dia)
        {
            return (dia >= fecha2.dia);
        }
        else
            return false;
    }
};

#endif


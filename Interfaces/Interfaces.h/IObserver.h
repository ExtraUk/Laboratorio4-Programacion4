#ifndef IOBSERVER
#define IOBSERVER

#include "../../DataTypes/DataType.h/DTNotificacion.h"
#pragma once

class IObserver{
    public:
    virtual void notificar(DTNotificacion notificacion) = 0;
};

#endif
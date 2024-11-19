//
// Created by Ela labidi on 29/10/2024.
//

#ifndef P2_TRAYECTO_H
#define P2_TRAYECTO_H
#include "Coche.h"
#include "Fecha.h"
#include "PuntoRecarga.h"


class Trayecto {
private:
    int idTrayecto;
    Fecha fechainicio;
    Fecha fechaFinal;
    PuntoRecarga origin;
    PuntoRecarga destination;
    Coche* inthecar;


public:
    Trayecto(const Fecha *fI);
    Trayecto( PuntoRecarga &inicio,  PuntoRecarga &fin,const  Fecha &inicioFecha, const Fecha &finalFecha);
    ~Trayecto();
    void setfechas(Fecha& fInicio,Fecha& fFinal);
    void setCoche(Coche& c);
    void showtrayecto();
    Fecha& showfInicio(){
        return fechainicio;
    };
    int getorigin(){
        return origin.getId();
    };
    int getdestination(){
        return destination.getId();
    };
    Fecha& showfFin() {

        return fechaFinal;
    }
    Coche* getinthecar() ;
    int id_trayecto() ;
};


#endif //P2_TRAYECTO_H

//
// Created by Ela labidi on 29/10/2024.
//

#include "Trayecto.h"

Trayecto::Trayecto(const Fecha *fI) {
    fechainicio=*new Fecha(*fI);
}


Trayecto::Trayecto( PuntoRecarga &inicio,  PuntoRecarga &fin,const  Fecha &inicioFecha, const Fecha &finalFecha) {
    this->origin = inicio;
    this->destination = fin;
    this->fechainicio = inicioFecha;
    this->fechaFinal = finalFecha;
    this->idTrayecto = rand();
}

Trayecto::~Trayecto() {
    idTrayecto=0;
    inthecar= nullptr;
}

void Trayecto::setfechas(Fecha &fInicio, Fecha &fFinal) {
    fechainicio=fInicio;
    fechaFinal=fFinal;
}


void Trayecto::setCoche(Coche &c) {
    inthecar=new Coche(c);
}

void Trayecto::showtrayecto() {

    cout << "ID " << this->id_trayecto() << endl;
    cout << "Origen  " << this->getorigin() << endl;
    cout << "Destino " <<  this->getdestination() << endl;
    cout << "Coche " << this->getinthecar()->getIdMatricula() << endl;
    cout << "Fecha Inicio " << this->showfInicio() << endl;
    cout << "Fecha Fin " << this->showfFin() << endl; 
}

Coche * Trayecto::getinthecar()  {
    return inthecar;
}

int Trayecto::id_trayecto()  {
    return idTrayecto;
}

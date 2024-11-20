//
// Created by Ela labidi on 20/10/2024.
//

#include <vector>
#include "PuntoRecarga.h"
#include "Coche.h"
/*
Coche* PuntoRecarga::getMaxBateria(){
    Coche *aux = nullptr;

    multimap<int, Coche*>::iterator mayor;
    mayor = this->coches.begin();

    for ( multimap<int, Coche*>::iterator i = this->coches.begin(); i != this->coches.end(); ++i)
    {
        if(i->second->getNivelBateria() >mayor->second->getNivelBateria()) {
            mayor = i;
            aux = mayor->second;

        }
    }

    return aux;
}

UTM::UTM(const float &lat, const float &lon) {
    this->lat = lat;
    this->lon = lon;
}

float UTM::lat1() const {
    return lat;
}

float UTM::lon1() const {
    return lon;
}

bool PuntoRecarga::addCoche(Coche *c) {

    if(this->coches.size() < this->max){
        this->coches.insert({c->getNivelBateria() , c});
        c->setP(this);
        return true;
    }
    return false;
}

void PuntoRecarga::delCoche(const string &matricula) {
    multimap<int,Coche*>::iterator i;
    i=coches.begin();
    while (i!= coches.end()){
        if(i->second->getIdMatricula()==matricula){
            coches.erase(i);
        }
        i++;
    }
}

int PuntoRecarga::getNumCoches() const {
    int count = 0;

    for( multimap<int, Coche *>::const_iterator iter = this->coches.begin(); iter != this->coches.end(); ++iter) {
        count++;
    }
    return count;
}

PuntoRecarga::PuntoRecarga(): posicion(0,0) {
    this->id = 0;
    this->max = 20;
}

PuntoRecarga::PuntoRecarga(const PuntoRecarga &p): posicion(p.posicion) {
    this->id = p.id;
    this->max = p.max;
    this->coches = p.coches;
}

PuntoRecarga::PuntoRecarga(const int &id,const  UTM &posicion,const  int &max): id(id), posicion(posicion), max(max) {
}

PuntoRecarga::~PuntoRecarga() {
    this->id =0;
    this->max =0;
}

int PuntoRecarga::getId() const {
    return id;
}

void PuntoRecarga::setId(int id) {
    PuntoRecarga::id = id;
}

const UTM &PuntoRecarga::getPosicion() const {
    return posicion;
}

void PuntoRecarga::setPosicion(const UTM &posicion) {
    PuntoRecarga::posicion = posicion;
}

int PuntoRecarga::getMax() const {
    return max;
}

void PuntoRecarga::setMax(int max) {
    PuntoRecarga::max = max;
}

multimap<int, Coche *> &PuntoRecarga::getCoches()  {
    return coches;
}

void PuntoRecarga::setCoches(const multimap<int, Coche *> &coches) {
    PuntoRecarga::coches = coches;
}

PuntoRecarga & PuntoRecarga::operator=(const PuntoRecarga &f) {
    if(this != &f) {
        this->coches = f.coches;
        this->id = f.getId();
        this->posicion = f.getPosicion();
        this->max = f.getMax();
    }
    return *this;
}
*/
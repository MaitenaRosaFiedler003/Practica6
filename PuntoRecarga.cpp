//
// Created by Ela labidi on 20/10/2024.
//

#include <vector>
#include "PuntoRecarga.h"
#include "Coche.h"

Coche* PuntoRecarga::getMaxBateria(){
    Coche *aux = nullptr;


    Coche *mayor = this->chargepoint.top();

    while(!this->chargepoint.empty())
    {
        if(this->chargepoint.top()->getNivelBateria() > mayor->getNivelBateria()) {
            mayor = this->chargepoint.top();
            aux = mayor;
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

    if(this->chargepoint.size() < this->max){
        this->chargepoint.push(c);
        c->setP(this);
        return true;
    }
    return false;
}

void PuntoRecarga::delCoche(const string &matricula) {


    while (!this->chargepoint.empty()){
        if(this->chargepoint.top()->getIdMatricula()==matricula){
            this->chargepoint.pop();
        }
    }
}

int PuntoRecarga::getNumCoches() const {
   return this->chargepoint.size();
}

PuntoRecarga::PuntoRecarga(): posicion(0,0) {
    this->id = 0;
    this->max = 20;
}

PuntoRecarga::PuntoRecarga(const PuntoRecarga &p): posicion(p.posicion) {
    this->id = p.id;
    this->max = p.max;
   this->chargepoint = p.chargepoint;
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

priority_queue<Coche*> &PuntoRecarga::getCoches()  {
    return this->chargepoint;
}

void PuntoRecarga::setCoches(const priority_queue<Coche*> &coches) {
    this->chargepoint = coches;
}

PuntoRecarga & PuntoRecarga::operator=(const PuntoRecarga &f) {
    if(this != &f) {
        this->chargepoint = f.chargepoint;
        this->id = f.getId();
        this->posicion = f.getPosicion();
        this->max = f.getMax();
    }
    return *this;
}

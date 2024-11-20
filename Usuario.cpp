//
// Created by Maitena on 3/10/2024.
//

#include "Usuario.h"

const string &Usuario::getNif() const {
    return nif;
}

void Usuario::setNif(const string &nif) {
    Usuario::nif = nif;
}

const string &Usuario::getClave() const {
    return clave;
}

void Usuario::setClave(const string &clave) {
    Usuario::clave = clave;
}

const string &Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(const string &nombre) {
    Usuario::nombre = nombre;
}

const string &Usuario::getDireccion() const {
    return direccion;
}

void Usuario::setDireccion(const string &direccion) {
    Usuario::direccion = direccion;
}

Usuario::Usuario(const string &nif, const string &clave, const string &nombre, const string &direccion) : nif(nif),
                                                                                                          clave(clave),
                                                                                                          nombre(nombre),
                                                                                                          direccion(
                                                                                                                  direccion) {
    this->coche =nullptr;
    this->puntos = 100;
}

Usuario::Usuario() {
    this->coche = nullptr;
    this->nif = -1 ;
    this->puntos =100;
}

Usuario::~Usuario() {

    coche = nullptr;
}

void Usuario::decremetarPuntos(const int &retraso) {
    this->puntos= this->puntos - retraso;
}

int Usuario::get_puntos() const {
    return puntos;
}

void Usuario::set_puntos(int puntos) {
    this->puntos = puntos;
}

Coche *Usuario::getC() const {
    return coche;
}

void Usuario::setC( Coche *c) {
    this->coche = new Coche(*c);
}

bool Usuario::operator==(Usuario &otro) {
    if(this->nif == otro.nif){
        if(this->nombre == otro.nombre){
            if(this->direccion == otro.direccion){
                if(this->clave == otro.clave){
                    return true;
                }
            }
        }
    }
    return false;
}

Coche& Usuario::cogecoche() {
    // Linkreanel->alquilar(this);
     return *coche;
}

Trayecto* Usuario::crearTrayecto(PuntoRecarga &ori, PuntoRecarga &des, Fecha &fInicio, Fecha &fFin) {
    Trayecto* t=new Trayecto(ori,des,fInicio,fFin);

    return t;
}

Coche &Usuario::iniciaTrayecto(int idPuntoinicio, int idPuntoFinal, Fecha fIni, Fecha fFin) {
    return Linkreanel->alquilar(*this,idPuntoinicio,idPuntoFinal,fIni,fFin);
}

void Usuario::aparcarCoche(Coche &c, PuntoRecarga &pr, const int &retraso) {
    Linkreanel->colocarcochePR(&c,pr);
    coche= nullptr;
}


vector<Trayecto> &Usuario::getTrayectosFechasInicial(const Fecha &f) {
    vector<Trayecto>* v = new vector<Trayecto>;
    multimap<Fecha,Trayecto>::iterator i;
    i=route.begin();
    while ((i!=route.end())){
        if(i->first.mismoDia(f)){
            v->push_back(i->second);
        }
        i++;
    }
    return *v;
}
vector<Trayecto> &Usuario::getTrayectosFechasFinal(const Fecha &f) {
    vector<Trayecto>* v = new vector<Trayecto>;
    multimap<Fecha,Trayecto>::iterator i;
    i=route.begin();
    while ((i!=route.end())){

        if(i->first.mismoDia(f)){
            v->push_back(i->second);

        }
        i++;
    }
    return *v;
}

int Usuario::numTrayectos() {
    int con =0;
    for(multimap<Fecha,Trayecto>::iterator it=route.begin(); it!=route.end(); it++) {
        con++;
    }
    return con;
}

void Usuario::setTrayecto(const Trayecto &t, const Fecha &f) {
    this->route.insert({f,t});
}

std::multimap<Fecha, Trayecto> Usuario::route1()  {
    return route;
}

Trayecto * Usuario::getTrayecto(int id) {
    for(multimap<Fecha,Trayecto>::iterator it=route.begin(); it!=route.end(); it++) {
        if(it->second.id_trayecto() == id) {
            return &(it->second);
        }
    }
    return nullptr;
}

void Usuario::aparcarCoche(const Coche &c, PuntoRecarga &pr, const int &retraso) {

       /* if() { //si se paso de fecha
            this->decrementarPuntos(retraso);
        }*/
}

void Usuario::decrementarPuntos(const int &retraso) {
    this->puntos = this->puntos - retraso;
}

void Usuario::eliminarTrayectos() {
   this->route.clear();
}





//
// Created by Maitena on 3/10/2024.
//

#include "Reanelcar.h"

Usuario* Reanelcar::buscarUsrNif(const string &nif) {
    Usuario *s= nullptr;
    list<Usuario>::iterator i;
    i=users->begin();

    while(i!=users->end()){
        if(i->getNif()==nif){
           return (&(*i));
        }
        i++;
    }

    return s;
}

Coche& Reanelcar::alquilar(Usuario &usr, int idPRorigin, int idPRDestino, Fecha &fIni, Fecha &fFin) {
    PuntoRecarga *prO=buscarpunto(idPRorigin);
    PuntoRecarga *prD=buscarpunto(idPRDestino);

    Trayecto* t= usr.crearTrayecto(*prO,*prD,fIni,fFin);

    Coche* c= prO->getMaxBateria();
    usr.setC(*c);
    t->setCoche(*c);
    usr.setTrayecto(*t, fIni);


    return *c;
}


Coche* Reanelcar::buscarCochMat(const string &mat) {
    map<string,Coche>::iterator i;
    i=cars->find(mat);
    return &(i->second);
}


vector<Coche> *Reanelcar::buscarCochModelo(const std::string &mod) {
    vector<Coche>* vecCoches;
    map<string,Coche>::iterator i;
    while (i!=cars->end()){
        if(i->second.getModelo()==mod){
            vecCoches->push_back(i->second);
        }
        i++;
    }
    return vecCoches;
}


list<Usuario>* Reanelcar::buscarUsrNomb(const string &nom) {

    list<Usuario>* l=new list<Usuario> ;
    list<Usuario>::iterator i =users->begin();
    while(i!=users->end()){
        if(i->getNombre().substr(0, nom.size()) == nom.substr(0,nom.size())){
            Usuario* u=new Usuario(*i);
            l->push_back(*u);
        }
        i++;
    }

    return l;
}


Reanelcar::Reanelcar( map<string,Coche> *coches,  list<Usuario> *usuarios,vector<PuntoRecarga>* PR) {
    this->users = usuarios;
    this->cars = coches;
    this->sites=PR;
}

bool Reanelcar::colocarcochePR(Coche *c, PuntoRecarga &pr) {
    return pr.addCoche(c);
}

void Reanelcar::setpuntorecarga(vector<PuntoRecarga> *p) {
    this->sites = p;
}

PuntoRecarga* Reanelcar::buscarpunto(int id) {

    PuntoRecarga* pr=  nullptr;
    vector<PuntoRecarga>::iterator i1;
    i1=sites->begin();
    while(i1!=sites->end()) {
        if(id==i1->getId()){
            pr = &(*i1);
            return pr;
        }
        i1++;
    }
    return pr;
}

void Reanelcar::setpuntorecarga(PuntoRecarga *p) {
    sites->push_back(*p);
}

PuntoRecarga& Reanelcar::obtenerPRmenoscoche() {
    vector<PuntoRecarga>::iterator i;
    i=sites->begin();
    int menornumcoches=i->getNumCoches();
    PuntoRecarga* menosPR= &(*i);
    i++;
    while(i!=sites->end()){
        if(i->getNumCoches()<menornumcoches){
            menornumcoches=i->getNumCoches();
            menosPR=&(*i);
        }
        i++;
    }
    return *menosPR;
}
vector<pair<Usuario, Trayecto>>* Reanelcar::trayectosEnFecha(const Fecha &f) {
    vector<pair<Usuario, Trayecto>> *trayectos = new vector<pair<Usuario, Trayecto>>();
   vector<Trayecto> trayecto_user;

    for(list<Usuario>::iterator i= this->users->begin(); i != this->users->end(); i++) {
        trayecto_user = i->getTrayectosFechasInicial(f);

        for(vector<Trayecto>::iterator tr= trayecto_user.begin(); tr != trayecto_user.end(); tr++  ) {

            if(tr->showfInicio().mismoDia(f)) {
                trayectos->push_back(std::make_pair(*i, *tr));
            }
        }
    }
    return trayectos;
}

Usuario * Reanelcar::buscarUsrNifTHash(const string &nif) {
   return  this->usersNif->buscar(this->usersNif->djb2(nif));
}

bool Reanelcar::borrarUsuarioHash(const string &nif) {
    //primero lo buscamos antes de borrar asi primero borramos su info relacionada
    Usuario *s = this->buscarUsrNifTHash(nif);
    s->eliminarTrayectos();
    s->setC(nullptr);
    this->usersNif->borrar(this->usersNif->djb2(nif));
}
